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
    ACRL0BookLevelstate();
    void HandleInputactionAttack(      int32 aiIndexPlayer);
    void HandleInputactionChangeWeapon(int32 aiIndexPlayer);
    void HandleInputactionJump(        int32 aiIndexPlayer);
    void HandleInputaxisAimRS(                 int32 aiIndexPlayer, bool ayNeg, float afPercent);
    void HandleInputaxisAimRF(                 int32 aiIndexPlayer, bool ayNeg, float afPercent);
    void HandleInputaxisMoveAlongAimingForward(int32 aiIndexPlayer, bool ayNeg);
    void HandleInputaxisMoveAlongAimingRight(  int32 aiIndexPlayer, bool ayNeg);

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ACRL0BookLevelstate") bool m_yInputEnabled;
}; // class ACRL0BookLevelstate
