// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemiga.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/monsters/Achates__Lost_Ark_/Achates__Lost_Ark_.Achates__Lost_Ark_'"));
	// Create the mesh component
	NaveEnemigaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	NaveEnemigaMesh->SetupAttachment(RootComponent);
	NaveEnemigaMesh->SetSimulatePhysics(false);
	NaveEnemigaMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = NaveEnemigaMesh;

	NaveEnemigaMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
}

void ANaveEnemiga::MoveDown(float DeltaTime)
{
	/*FVector NewLocation = GetActorLocation() + FVector(0.0f, -Speed, 0.0f) * DeltaTime;
	SetActorLocation(NewLocation);*/

		// Define la amplitud y la frecuencia del movimiento lateral
	float Amplitude = 50.0f;
	float Frequency = 0.05f;

	// Calcula el desplazamiento lateral basado en el tiempo
	float LateralOffset = Amplitude * FMath::Cos(Frequency * GetWorld()->TimeSeconds);

	// Calcula la nueva ubicación con el desplazamiento lateral
	FVector NewLocation = GetActorLocation() + FVector(LateralOffset, -Speed, 0.0f) * DeltaTime;

	// Establece la nueva ubicación
	SetActorLocation(NewLocation);
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector TargetLocation = FVector(-270.0f, -630.0f, 160.0f);
	FVector Direction = TargetLocation - FVector(-260.0f, -630.0f, 160.0f);
	float DistanceToTarget = FVector::Dist(TargetLocation, FVector(-260.0f, -630.0f, 160.0f));
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




