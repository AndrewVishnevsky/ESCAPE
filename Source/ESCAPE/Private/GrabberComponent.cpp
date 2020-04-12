// Andrew Vishnevsky 2020

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "GrabberComponent.h"


#define OUT

// Sets default values for this component's properties
UGrabberComponent::UGrabberComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber is ready!"));
	
}


// Called every frame
void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player viewpoint
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation);


	UE_LOG(LogTemp, Warning, TEXT("Location:%s, Rotation:%s"), 
		*PlayerViewPointLocation.ToString(), 
		*PlayerViewPointRotation.ToString());
	//Ray-cast out

	//Check trace line hit
}

