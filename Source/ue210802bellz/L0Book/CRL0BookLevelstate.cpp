////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\L0Book\CRL0BookLevelstate.cpp
////////////////////////////////////////////////////////////////////////////////
#include "CRL0BookLevelstate.h"

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputactionAttack()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputactionAttack() {
    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputactionAttack()"));
    return;
} // HandleInputactionAttack()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputactionChangeWeapon()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputactionChangeWeapon() {
    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputactionChangeWeapon()"));
    return;
} // HandleInputactionChangeWeapon()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputactionJump()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputactionJump() {
    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputactionJump()"));
    return;
} // HandleInputactionJump()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputaxisAccelerateRY()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisAccelerateRY(bool ayNeg) {
    if (ayNeg) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisAccelerateRY(-)"));
    else       GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisAccelerateRY(+)"));
    return;
} // HandleInputaxisAccelerateRY()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputaxisAccelerateRZ()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisAccelerateRZ(bool ayNeg) {
    if (ayNeg) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisAccelerateRZ(-)"));
    else       GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisAccelerateRZ(+)"));
    return;
} // HandleInputaxisAccelerateRZ()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputaxisMoveX()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisMoveX(bool ayNeg) {
    if (ayNeg) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveX(-)"));
    else       GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveX(+)"));
    return;
} // HandleInputaxisMoveX()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputaxisMoveY()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisMoveY(bool ayNeg) {
    if (ayNeg) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveY(-)"));
    else       GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveY(+)"));
    return;
} // HandleInputaxisMoveY()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputaxisMoveRY()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisMoveRY(bool ayNeg) {
    if (ayNeg) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveRY(-)"));
    else       GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveRY(+)"));
    return;
} // HandleInputaxisMoveRY()

////////////////////////////////////////////////////////////////////////////////
// public UFUNCTION() void ACRL0BookLevelstate::HandleInputaxisMoveRZ()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisMoveRZ(bool ayNeg) {
    if (ayNeg) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveRZ(-)"));
    else       GEngine->AddOnScreenDebugMessage(INDEX_NONE, 30.0F, FColor::Blue, TEXT("Triggered ACRL0BookLevelstate::HandleInputaxisMoveRZ(+)"));
    return;
} // HandleInputaxisMoveRZ()
