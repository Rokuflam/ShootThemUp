// Shoot Them Up Game, All Rights Reserved.

#include "STUGameModeBase.h"

void ASTUGameModeBase::BeginPlay()
{
	int32 Variable = 0;
	for (int32 i = 0; i < 10; ++i)
	{
		UE_LOG(LogTemp, Display, TEXT("index %s"), i);
	}
}