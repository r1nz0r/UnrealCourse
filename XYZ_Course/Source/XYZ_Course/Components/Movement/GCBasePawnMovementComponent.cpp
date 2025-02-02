// Fill out your copyright notice in the Description page of Project Settings.


#include "GCBasePawnMovementComponent.h"

void UGCBasePawnMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                 FActorComponentTickFunction* ThisTickFunction)
{
	if (ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector PendingInput = GetPendingInputVector().GetClampedToMaxSize(1.0f);
	Velocity = PendingInput * MaxSpeed;
	ConsumeInputVector();

	if (bEnableGravity)
	{
		FHitResult HitResult;
		FVector StartPoint = UpdatedComponent->GetComponentLocation();
		float TraceDepth = 10.f;
		float SphereRadius = UpdatedComponent->Bounds.SphereRadius / 2;
		float LineTraceLength = SphereRadius + TraceDepth;
		FVector EndPoint = StartPoint - LineTraceLength * FVector::UpVector;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(GetOwner());

		bool bWasFalling = bIsFalling;
		FCollisionShape Sphere = FCollisionShape::MakeSphere(SphereRadius);
		bIsFalling = !GetWorld()->SweepSingleByChannel(HitResult, StartPoint, EndPoint, FQuat::Identity,
		                                               ECC_Visibility, Sphere, CollisionParams);
		if (bIsFalling)
		{
			VerticalVelocity += GetGravityZ() * FVector::UpVector * DeltaTime;
		}
		else if (bWasFalling && VerticalVelocity.Z < 0.f)
		{
			VerticalVelocity = FVector::ZeroVector;
		}
	}

	Velocity += VerticalVelocity;
	const FVector DeltaMovement = Velocity * DeltaTime;

	if (!DeltaMovement.IsNearlyZero(1e-6f))
	{
		const FQuat Rot = UpdatedComponent->GetComponentQuat();
		FHitResult Hit(1.f);
		SafeMoveUpdatedComponent(DeltaMovement, Rot, true, Hit);

		if (Hit.IsValidBlockingHit())
		{
			HandleImpact(Hit, DeltaTime, DeltaMovement);
			// Try to slide the remaining distance along the surface.
			SlideAlongSurface(DeltaMovement, 1.f - Hit.Time, Hit.Normal, Hit, true);
		}
	}

	UpdateComponentVelocity();
}

void UGCBasePawnMovementComponent::JumpStart()
{
	VerticalVelocity = InitialJumpVelocity * FVector::UpVector;
}
