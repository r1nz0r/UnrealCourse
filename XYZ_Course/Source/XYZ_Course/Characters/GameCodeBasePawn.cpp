// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCodeBasePawn.h"
#include "Components/SphereComponent.h"
#include "XYZ_Course/Components/Movement/GCBasePawnMovementComponent.h"

AGameCodeBasePawn::AGameCodeBasePawn()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionComponent->SetSphereRadius(50.f);
	CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	SetRootComponent(CollisionComponent);

	//MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("Movement component"));
	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UGCBasePawnMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->SetUpdatedComponent(CollisionComponent);
}

void AGameCodeBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameCodeBasePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameCodeBasePawn::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGameCodeBasePawn::Jump);
}

void AGameCodeBasePawn::MoveForward(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGameCodeBasePawn::MoveRight(float Value)
{	
	if (Value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGameCodeBasePawn::Jump()
{
	checkf(MovementComponent->IsA<UGCBasePawnMovementComponent>(),
		TEXT("AGameCodeBasePawn::Jump() Jump can work only with UGCBasePawnMovementComponent"));
	UGCBasePawnMovementComponent* BaseMovement = StaticCast<UGCBasePawnMovementComponent*>(MovementComponent);
	BaseMovement->JumpStart();
}
