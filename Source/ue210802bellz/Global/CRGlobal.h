////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\Global\CRGlobal.h
////////////////////////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////////////////////////
// The Unreal framework and base class should be included first
////////////////////////////////////////////////////////////////////////////////
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////
class UCRGameinstance;
class ACRL0BookLevelstate;

////////////////////////////////////////////////////////////////////////////////
// The RTTI should be included last
////////////////////////////////////////////////////////////////////////////////
#include "CRGlobal.generated.h"

////////////////////////////////////////////////////////////////////////////////
// UCLASS() class UE210802BELLZ_API UCRGlobal
////////////////////////////////////////////////////////////////////////////////
UCLASS() class UE210802BELLZ_API UCRGlobal : public UBlueprintFunctionLibrary {
GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure, Category="UCRGlobal") static float                CastZToU(float afZ);
    UFUNCTION(BlueprintPure, Category="UCRGlobal") static UCRGameinstance*     GetGameinstance(UObject* apoObjectInWorld);
    UFUNCTION(BlueprintPure, Category="UCRGlobal") static ACRL0BookLevelstate* GetL0BookLevelstate(UObject* apoObjectInWorld);
}; // class UCRGlobal
