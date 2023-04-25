// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/ScalingCube1.h"

AScalingCube1::AScalingCube1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Mesh, ensure the component declared in the header is added to the class. 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	// Make the mesh the RootComponent. Other components you add will be placed on this by default. 
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AScalingCube1::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AScalingCube1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime += DeltaTime;
	CurrentScale += ScalingSpeed * DeltaTime;

	SetActorScale3D(FVector(CurrentScale));

	if (CurrentTime >= TimeBetweenSwitch)
	{
		CurrentTime = 0;
		ScalingSpeed *= -1;
	}
}



