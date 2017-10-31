// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

#pragma once

#include "UObject/Interface.h"
#include "INT_ReactsToGaze_CPP.generated.h"

UINTERFACE(Blueprintable)
class LIVESTREAMVR_API UINT_ReactsToGaze_CPP : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class LIVESTREAMVR_API IINT_ReactsToGaze_CPP
{
	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR")
	void RespondsToGaze();
};