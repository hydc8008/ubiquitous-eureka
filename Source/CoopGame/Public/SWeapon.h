// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

UCLASS()
class COOPGAME_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon();
	UFUNCTION(BlueprintCallable,Category = "Weapon")
	void Fire();

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "weapon")
	TSubclassOf<UDamageType> DamageType;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class USkeletalMeshComponent *SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Weapon")
	TSubclassOf<class USkeletalMeshComponent> SkeletalMeshComponentClass;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
