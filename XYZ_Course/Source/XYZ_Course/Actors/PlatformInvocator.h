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
	APlatformInvocator();
protected:
	virtual void BeginPlay() override;

	//Needs to be called from blueprint child class
	UFUNCTION(BlueprintCallable)	
	void Invoke();
public:	
	virtual void Tick(float DeltaTime) override;
	
	FOnPlatformInvocatorActivated OnPlatformInvocatorActivated;
};
