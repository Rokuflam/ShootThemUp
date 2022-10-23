// Shoot Them Up Game, All Rights Reserved.


#include "Animations/STUAnimNotify.h"


void USTUAnimNotify::Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	OnNotified.Broadcast(MeshComp);
	Super::Notify(MeshComp, Animation);
}
