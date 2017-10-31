// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GazeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGazeHit, FHitResult, OutHit);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIVESTREAMVR_API UGazeComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGazeComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VR")
	bool bIsGazing = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VR")
	bool bDrawDebug = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VR")
	float GazeDistance = 500.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VR")
	FVector HMDOffset = FVector(0.f, 0.f, 25.f);

	UPROPERTY(BlueprintAssignable, Category = "VR")
	FOnGazeHit OnGazeHit;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
