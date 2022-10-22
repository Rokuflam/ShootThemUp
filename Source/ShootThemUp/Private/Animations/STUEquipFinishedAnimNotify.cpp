// Shoot Them Up Game, All Rights Reserved.


#include "Animations/STUEquipFinishedAnimNotify.h"


void USTUEquipFinishedAnimNotify::Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) 
{
	OnNotified.Broadcast(MeshComp);
	Super::Notify(MeshComp, Animation);
}
