// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

#include "GazeComponent.h"


// Sets default values for this component's properties
UGazeComponent::UGazeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called every frame
void UGazeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Implement gaze function

	// Check if we're gazing
	if (bIsGazing)
	{
		// Check if we need to draw a debug line
		if (bDrawDebug)
		{
			// Draw a debug line 
			UKismetSystemLibrary::DrawDebugLine(this,
				this->GetComponentLocation() + HMDOffset,
				this->GetComponentLocation() + (this->GetComponentRotation().Vector() * GazeDistance),
				FColor(255.f, 0.f, 0.f),
				0.f,
				15.f);
		}

		// Do a line trace
		FHitResult OutHit;
		bool bHasHit = GetWorld()->LineTraceSingleByChannel(OutHit, this->GetComponentLocation(),
			this->GetComponentLocation() + (this->GetComponentRotation().Vector() * GazeDistance),
			ECollisionChannel::ECC_Visibility
			);


		// Check if we have a hit
		if (bHasHit && OutHit.GetActor()->IsValidLowLevel())
		{
			//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Turquoise, TEXT("A hit from C++"), false);
			//UE_LOG(LogTemp, Warning, TEXT("TEST"));

			OnGazeHit.Broadcast(OutHit);
		}
	}
		
}

