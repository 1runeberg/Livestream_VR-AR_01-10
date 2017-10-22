// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

#include "VRBPFunctionLibrary.h"

void UVRBPFunctionLibrary::MoveActor(AActor* ActorToMove, USceneComponent* MovementReference, float Speed, FRotator ForwardRotation)
{
	if (ActorToMove->IsValidLowLevel())
	{
		// Setup rotation to be used in this function
		FRotator NewRotation;

		// Check if we have a movement reference, if so use it as the direction
		if (MovementReference->IsValidLowLevel())
		{
			NewRotation = MovementReference->GetComponentRotation();
		}
		else
		{
			NewRotation = ForwardRotation;
		}

		// Move the Actor to new position
		ActorToMove->SetActorLocationAndRotation(
			ActorToMove->GetActorLocation() + NewRotation.Vector() * Speed,
			ActorToMove->GetActorRotation()
		);


	}
}


void UVRBPFunctionLibrary::MoveActor360(AActor* ActorToMove, float AxisX, float AxisY, float Speed)
{
	if (ActorToMove->IsValidLowLevel())
	{
		if (AxisX != 0 || AxisY != 0)
		{
			MoveActor(
				ActorToMove,
				nullptr,
				Speed,
				FRotator(
					ActorToMove->GetActorRotation().Pitch,
					(180.f) / PI * FMath::Atan2(AxisX, AxisY * -1.f),
					ActorToMove->GetActorRotation().Roll
				)
			);
		}
	}
}