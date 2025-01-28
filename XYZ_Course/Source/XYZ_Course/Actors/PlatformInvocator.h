// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformInvocator.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlatformInvocatorActivated);

UCLASS()
class XYZ_COURSE_API APlatformInvocator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformInvocator();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)	
	void Invoke();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FOnPlatformInvocatorActivated OnPlatformInvocatorActivated;
};
