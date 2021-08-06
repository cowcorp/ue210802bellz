////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\L0Book\CRL0BookLevelstate.h
////////////////////////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////////////////////////
// The Unreal framework and base class should be included first
////////////////////////////////////////////////////////////////////////////////
#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

////////////////////////////////////////////////////////////////////////////////
// The RTTI should be included last
////////////////////////////////////////////////////////////////////////////////
#include "CRL0BookLevelstate.generated.h"

////////////////////////////////////////////////////////////////////////////////
// UCLASS() class UE210802BELLZ_API ACRL0BookLevelstate
////////////////////////////////////////////////////////////////////////////////
UCLASS() class UE210802BELLZ_API ACRL0BookLevelstate : public AGameStateBase {
GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputactionAttack();
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputactionChangeWeapon();
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputactionJump();
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputaxisAccelerateRY(bool ayNeg);
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputaxisAccelerateRZ(bool ayNeg);
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputaxisMoveX(bool ayNeg);
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputaxisMoveY(bool ayNeg);
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputaxisMoveRY(bool ayNeg);
    UFUNCTION(BlueprintCallable, Category="ACRL0BookLevelstate") void HandleInputaxisMoveRZ(bool ayNeg);
}; // class ACRL0BookLevelstate
