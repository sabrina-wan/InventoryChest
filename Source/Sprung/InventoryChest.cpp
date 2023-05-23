// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryChest.h"

// Sets default values
AInventoryChest::AInventoryChest()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);	
	MeshComponent->OnClicked.AddDynamic(this, &AInventoryChest::OpenChest);

}

// Called when the game starts or when spawned
void AInventoryChest::BeginPlay()
{
	Super::BeginPlay();

	if (!InventoryWidgetClass) {
		return;
	}
	
	// if the inventory widget is set, the chest should create one at BeginPlay
	InventoryWidget = CreateWidget<UUserWidget>(GetWorld(), InventoryWidgetClass);
	InventoryWidget->AddToViewport();
	InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
}

void AInventoryChest::OpenChest_Implementation(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	if (!InventoryWidget) {
		return;

	}
	InventoryWidget->SetVisibility(ESlateVisibility::Visible);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(UGameplayStatics::GetPlayerController(GetWorld(), 0), InventoryWidget);
}

