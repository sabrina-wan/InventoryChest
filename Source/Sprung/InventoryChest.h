// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "InventoryChest.generated.h"


UCLASS()
class SPRUNG_API AInventoryChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY()
	UUserWidget* InventoryWidget;

	UFUNCTION(BlueprintNativeEvent)
	void OpenChest(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

};
