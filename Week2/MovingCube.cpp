// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"

// Sets default values
AMovingCube::AMovingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentTime += DeltaTime;

	FVector movingVector(0, 0, DeltaTime * MovingPhase);
	AddActorLocalOffset(movingVector);

	if (CurrentTime >= TimeBetweenSwitch)
	{
		CurrentTime = 0;
		MovingPhase *= -1;
	}

}

