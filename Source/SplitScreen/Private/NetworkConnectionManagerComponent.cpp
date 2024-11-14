// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkConnectionManagerComponent.h"

#include "SocketSubsystem.h"


// Sets default values for this component's properties
UNetworkConnectionManagerComponent::UNetworkConnectionManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNetworkConnectionManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNetworkConnectionManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
											  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UNetworkConnectionManagerComponent::GetLocalIP()
{
	/// Get the local IP address of the user via  UNetConnection in player controller

	bool bCanBindAll = false;
	TSharedPtr<FInternetAddr> LocalIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBindAll);

	FString LocalIpStr = LocalIp->ToString(false);

	return LocalIpStr;
}