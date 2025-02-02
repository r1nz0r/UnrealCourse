// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveCameraActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AInteractiveCameraActor::AInteractiveCameraActor()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CameraInteractionVolume"));
	BoxComponent->SetBoxExtent(FVector(500.f, 500.f, 500.f));
	BoxComponent->SetCollisionObjectType(ECC_WorldDynamic);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxComponent->SetupAttachment(RootComponent);
}

void AInteractiveCameraActor::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AInteractiveCameraActor::OnBeginOverlap);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AInteractiveCameraActor::OnEndOverlap);
}

void AInteractiveCameraActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                             const FHitResult& SweepResult)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (!IsValid(PlayerController))
	{
		return;
	}

	FViewTargetTransitionParams TransitionToCameraParams;
	TransitionToCameraParams.BlendTime = TransitionToCameraTime;
	PlayerController->SetViewTarget(this, TransitionToCameraParams);
}

void AInteractiveCameraActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (!IsValid(PlayerController))
	{
		return;
	}
	APawn* Pawn = PlayerController->GetPawn();

	if (!IsValid(Pawn))
	{
		return;
	}

	FViewTargetTransitionParams TransitionToPawnParams;
	TransitionToPawnParams.BlendTime = TransitionToPawnTime;
	TransitionToPawnParams.bLockOutgoing = true;
	PlayerController->SetViewTarget(Pawn, TransitionToPawnParams);	
}
