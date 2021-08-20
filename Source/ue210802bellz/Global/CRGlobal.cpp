////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\Global\CRGlobal.cpp
////////////////////////////////////////////////////////////////////////////////
#include "CRGlobal.h"
#include "Kismet/GameplayStatics.h"

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() static float UCRGlobal::CastCToF()
////////////////////////////////////////////////////////////////////////////////
float UCRGlobal::CastCToF(float afC) {
    return (- afC);
} // CastCToF()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() static float UCRGlobal::CastZToU()
//
// We call righthanded Z as "Z"
// We call lefthanded Z (Unreal-Z) as "U" (as in "up")
//
// Likewise, coordinates wrt Earth are a righthanded E,S,F (East,South,Floor)
// Lefthanded expressions might use E,S,C (Ceiling = - Floor)
////////////////////////////////////////////////////////////////////////////////
float UCRGlobal::CastZToU(float afZ) {
    return (- afZ);
} // CastZToU()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() static UCRGameinstance* UCRGlobal::GetGameinstance()
//
// Access this application's derived-class form of the gameinstance (a global singleton)
////////////////////////////////////////////////////////////////////////////////
UCRGameinstance* UCRGlobal::GetGameinstance(const UObject* apoObjectInWorld) {
    return (UCRGameinstance*)(UGameplayStatics::GetGameInstance(apoObjectInWorld));
} // GetGameinstance()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() static ACRL0BookLevelpawn* UCRGlobal::GetL0BookLevelpawn()
//
// This accessor may only be called while the L0Book level is open
////////////////////////////////////////////////////////////////////////////////
ACRL0BookLevelpawn* UCRGlobal::GetL0BookLevelpawn(const UObject* apoObjectInWorld, int32 aiIndexPlayer) {
    return (ACRL0BookLevelpawn*)(UGameplayStatics::GetPlayerController(apoObjectInWorld, aiIndexPlayer)->GetPawn());
} // GetL0BookLevelpawn()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() static ACRL0BookLevelstate* UCRGlobal::GetL0BookLevelstate()
//
// This accessor may only be called while the L0Book level is open
////////////////////////////////////////////////////////////////////////////////
ACRL0BookLevelstate* UCRGlobal::GetL0BookLevelstate(const UObject* apoObjectInWorld) {
    return (ACRL0BookLevelstate*)(UGameplayStatics::GetGameState(apoObjectInWorld));
} // GetL0BookLevelstate()
