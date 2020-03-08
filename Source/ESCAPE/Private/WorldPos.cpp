// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPos.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPos::UWorldPos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPos::BeginPlay()
{
	Super::BeginPlay();

	//FString Log = TEXT("Hello everyone to my FIRST GAME!!!");
	//FString* PrtLog = &Log;

	//Log.Len();

	//(*PrtLog).Len();
	//PrtLog->Len();

	//UE_LOG(LogTemp, Warning, TEXT("%s"), **PrtLog);

	//UE_LOG(LogTemp, Warning, TEXT("This is a Yellow Warning test message!"));
	//UE_LOG(LogTemp, Error, TEXT("This is a Red Error test message!"));
	//UE_LOG(LogTemp, Log, TEXT("This is a Grey log test message!"));
	FString ObjName{};
	ObjName=GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjName);

	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjectPosition);
	
	
}


// Called every frame
void UWorldPos::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

