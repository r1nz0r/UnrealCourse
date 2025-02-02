// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GCBasePawnMovementComponent.generated.h"

UCLASS()
class XYZ_COURSE_API UGCBasePawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	void JumpStart();
	
protected:
	UPROPERTY(EditAnywhere)
	float MaxSpeed = 1200.f;
	
	UPROPERTY(EditAnywhere)
	float InitialJumpVelocity = 500.f;

	UPROPERTY(EditAnywhere)
	bool bEnableGravity = true;
	
private:
	FVector VerticalVelocity = FVector::ZeroVector;
	bool bIsFalling;
};
