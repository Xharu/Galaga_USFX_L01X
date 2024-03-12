// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"

class ANaveEnemiga;
class ANaveEnemigaCaza;
class ANaveEnemigaTransporte;

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_L01GameMode();

public:
	ANaveEnemiga* NaveEnemiga01;
	ANaveEnemigaCaza* NaveEnemigaCaza1;
	ANaveEnemigaTransporte* NaveEnemigaTransporte1;

	TArray<ANaveEnemiga*> vectorNaveEnemiga;
	TArray<ANaveEnemigaCaza*> vectorNaveEnemigaCaza;
	TArray<ANaveEnemigaTransporte*> vectorNaveEnemigaTransporte;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};



