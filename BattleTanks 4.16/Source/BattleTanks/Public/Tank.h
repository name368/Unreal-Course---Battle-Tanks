// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

//Forward declarations
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);// , float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;


private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

public:
	/**Projectile launch speed, how far projectile can be shot*/
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.0;
	
};
