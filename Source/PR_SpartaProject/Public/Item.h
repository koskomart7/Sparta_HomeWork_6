// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"


UCLASS()
class PR_SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;
	
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;

	UFUNCTION(blueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "Item|Properties")	
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUP();
};

// 생성자 - 객체가 메모리에 생길때 딱 한번 호출
// PostInitializeComponents() - 액터의 모든 컴포넌트가 생성, 초기화된 뒤 자동 호출 - 컴포넌트 간 데이터 상호작용
//                              ( 컴포넌트 사이의 의존관계 설정 )
// BeginPlay() - 배치 (spawn) 직후

// Tick(float DeltaTime) - 매 프레임마다 호출 ( 성능 이슈 - 로직 구성에 신중 )

// Destroyed() - Destroy() 함수를 직접 호출하여 액터를 제거하기 직전에 호출 (리소스 정리)
// EndPlay() - 게임 종료, 파괴 , 레벨전환
