// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class SPA_ROTATEPLATFORM_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, Category="Option|Value")
	float MoveSpeed = 350.0f;

	UPROPERTY(EditAnywhere, Category = "Option|Value")
	float MoveRange = 400;

	bool bSwitch = false;

	FVector originPos;
};
