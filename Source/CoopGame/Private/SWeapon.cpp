// Fill out your copyright notice in the Description page of Project Settings.


#include "SWeapon.h"

#include "DrawDebugHelpers.h"

// Sets default values
ASWeapon::ASWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	RootComponent = SkeletalMeshComponent;
}

void ASWeapon::Fire()
{
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FRotator EyeRotator;
		FVector EyeLocation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotator);
		FVector TraceEnd = EyeLocation + (EyeRotator.Vector() * 1000);
		FHitResult Hit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(MyOwner);
		Params.AddIgnoredActor(this);
		Params.bTraceComplex = true;
		if (GetWorld()->LineTraceSingleByChannel(Hit,EyeLocation,TraceEnd,ECollisionChannel::ECC_Visibility))
		{
			
		}
		DrawDebugLine(GetWorld(),EyeLocation,TraceEnd,FColor::Red,false,1,0,1);
	}
	
}

// Called when the game starts or when spawned
void ASWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

