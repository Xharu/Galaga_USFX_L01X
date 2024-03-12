// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	// Create the mesh component
	NaveEnemigaTransporteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh2"));
	NaveEnemigaTransporteMesh->SetStaticMesh(ShipMesh.Object);
	NaveEnemigaTransporteMesh->SetupAttachment(RootComponent);
	NaveEnemigaTransporteMesh->SetSimulatePhysics(false);
	NaveEnemigaTransporteMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = NaveEnemigaTransporteMesh;

	NaveEnemigaTransporteMesh->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
}
void ANaveEnemigaTransporte::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector TargetLocation = FVector(-395.0f, -630.0f, 160.0f);
	FVector Direction = TargetLocation - FVector(-375.0f, -630.0f, 160.0f);
	float DistanceToTarget = FVector::Dist(TargetLocation, FVector(-375.0f, -630.0f, 160.0f));
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