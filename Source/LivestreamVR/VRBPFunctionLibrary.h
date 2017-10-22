// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRBPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LIVESTREAMVR_API UVRBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "VR")
	static void MoveActor(AActor* ActorToMove, USceneComponent* MovementReference, float Speed, FRotator ForwardRotation);
	
	UFUNCTION(BlueprintCallable, Category = "VR")
	static void MoveActor360(AActor* ActorToMove, float AxisX, float AxisY, float Speed);

};
