// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMoveActor::AMoveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("'/Game/LowerSector_Mod/Models/Bot/SM_Bottington.SM_Bottington'"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	
	originPos = GetActorLocation();
}

// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector p0 = GetActorLocation();
	FVector v;

	float chkDist = (originPos - p0).Length();
	if (chkDist > MoveRange) {
		bSwitch = !bSwitch;
	}
	if (bSwitch) {
		v = GetActorForwardVector() * MoveSpeed;
	}
	else {
		v = -GetActorForwardVector() * MoveSpeed;
	}
	FVector p = p0 + v * DeltaTime;

	SetActorLocation(p);
}

