// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "DataWrappers/ChaosVDParticleDataWrapper.h"



// Sets default values
AItem::AItem()
{
 	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	PrimaryActorTick.bCanEverTick = true;	// 기본적으로 false - 부모액터에서 사용될수도 있기에 
	RotationSpeed = 90.0f;
	
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	OnItemPickedUP();
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ( !FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f,RotationSpeed * DeltaTime,0.0f));
	}
	
}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}













