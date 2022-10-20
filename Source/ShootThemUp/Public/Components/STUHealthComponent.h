// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeathSugnature);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USTUHealthComponent();

	FOnDeathSugnature OnDeath;
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable)
	bool IsDead() const { return FMath::IsNearlyZero(Health); }

	float GetHealth() const { return Health; }


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
	bool AutoHeal = true;

	UPROPERTY(
		EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (ClampMin = "0.0", ClampMax = "1.0", EditCondition = "AutoHeal"))
	float HealUpdateTime = 0.3f;

	UPROPERTY(
		EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (ClampMin = "0.0", ClampMax = "60.0", EditCondition = "AutoHeal"))
	float HealDelay = 3.0f;

	UPROPERTY(
		EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (ClampMin = "0.0", ClampMax = "100.0", EditCondition = "AutoHeal"))
	float HealModifier = 5.0f;

	virtual void BeginPlay() override;

private:
	float Health = 0.0f;
	FTimerHandle HealTimerHandle;

	UFUNCTION()
	void OnTakeAnyDamage(
		AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	void HealUpdate();

	void SetHealth(float NewHealth);
};
