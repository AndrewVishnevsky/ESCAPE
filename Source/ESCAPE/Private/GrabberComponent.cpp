// Andrew Vishnevsky 2020

#include "DrawDebugHelpers.h"
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

	//Checking a physics handle component

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		//Physics handle is found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Physics handle component no found! In: %s"), *GetOwner()->GetName());
	}

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component found %s"), *GetOwner()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component not found! %s"), *GetOwner()->GetName());
	}
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


	//UE_LOG(LogTemp, Warning, TEXT("Location:%s, Rotation:%s"), 
		//*PlayerViewPointLocation.ToString(), 
		//*PlayerViewPointRotation.ToString());
	//Draw a line from player showing the reach

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() *100;
	
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.f,
		0,
		5.f
		);

	FHitResult Hit;
	//Ray-cast out
	FCollisionQueryParams TraceParams(FName(TEXT("")),false,GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECC_PhysicsBody),
		TraceParams
	);

	AActor * HitActor= Hit.GetActor();
	if (HitActor)
	{ 
		UE_LOG(LogTemp, Error, TEXT("We are reach %s"), *(HitActor->GetName()));
	}
	

	//Check trace line hit
}

