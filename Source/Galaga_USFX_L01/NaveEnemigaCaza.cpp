// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	// Create the mesh component
	NaveEnemigaCazaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh1"));
	NaveEnemigaCazaMesh->SetStaticMesh(ShipMesh.Object);
	NaveEnemigaCazaMesh->SetupAttachment(RootComponent);
	NaveEnemigaCazaMesh->SetSimulatePhysics(false);
	NaveEnemigaCazaMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = NaveEnemigaCazaMesh;

	NaveEnemigaCazaMesh->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
}
void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector TargetLocation = FVector(-150.0f, -630.0f, 160.0f);
	FVector Direction = TargetLocation - FVector(-130.0f, -630.0f, 160.0f);
	float DistanceToTarget = FVector::Dist(TargetLocation, FVector(-130.0f, -630.0f, 160.0f));
	float DeltaMove = Speed * GetWorld()->DeltaTimeSeconds;


	if (DeltaMove > DistanceToTarget)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(TargetLocation);
	}
	else
	{
		// Mueve el objeto en la dirección calculada
		this->AddActorWorldOffset(Direction * DeltaMove);
	}
}
