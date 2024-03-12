// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

	NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing
     // Crear varias naves enemigas
    for (int i = 0; i < 8; i++)
    {
        FVector ubicacionNave2 = FVector(-30.0f, -630.0f + (i * 350), 160.0f);
       /* FVector ubicacionNave1 = FVector(-150.0f , -630.0f + (i * 350), 160.0f);*/
        FVector ubicacionNaveCaza = FVector(-150.0f, -630.0f + (i * 350), 160.0f);
        FVector ubicacionNave = FVector(-270.0f, -630.0f + (i * 350), 160.0f); // Ajusta el espaciado entre las naves enemigas según sea necesario
        FVector ubicacionNaveTransporte = FVector(-395.0f, -630.0f + (i * 350), 160.0f);
        FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

        UWorld* const World = GetWorld();
        if (World != nullptr)
        {
         /*   FVector EscalaRelativa(0.1f, 0.1f, 0.1f);*/
            ANaveEnemiga* NuevaNaveEnemiga = World->SpawnActor<ANaveEnemiga>(ubicacionNave, rotacionNave);
            NuevaNaveEnemiga->Speed = 10.0f;
            /*ANaveEnemiga* NuevaNaveEnemiga1 = World->SpawnActor<ANaveEnemiga>(ubicacionNave1, rotacionNave);
            NuevaNaveEnemiga1->Speed = 10.0f;*/
            ANaveEnemigaCaza* NuevaNaveEnemigaCaza = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNaveCaza, rotacionNave);
            NuevaNaveEnemigaCaza->Speed = 10.0f;
            ANaveEnemiga* NuevaNaveEnemiga2 = World->SpawnActor<ANaveEnemiga>(ubicacionNave2, rotacionNave);
            NuevaNaveEnemiga2->Speed = 10.0f;
            ANaveEnemigaTransporte* NuevaNaveEnemigaTransporte = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveTransporte, rotacionNave);
            NuevaNaveEnemigaTransporte->Speed = 10.0f;
            // Puedes realizar configuraciones adicionales para la nave enemiga aquí si es necesario

            // Agregar la nave enemiga al vector o array si es necesario
         /*   vectorNavesEnemigas.Add(NuevaNaveEnemiga);*/
        }
    }
}
