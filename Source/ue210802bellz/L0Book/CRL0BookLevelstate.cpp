////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\L0Book\CRL0BookLevelstate.cpp
////////////////////////////////////////////////////////////////////////////////
#include "CRL0BookLevelstate.h"
#include "../Global/CRGlobal.h"
#include "CRL0BookLevelpawn.h"

////////////////////////////////////////////////////////////////////////////////
// public ACRL0BookLevelstate::ACRL0BookLevelstate()
////////////////////////////////////////////////////////////////////////////////
ACRL0BookLevelstate::ACRL0BookLevelstate() : AGameStateBase() {
    m_yInputEnabled = true;
} // ACRL0BookLevelstate()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputactionAttack()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputactionAttack(int32 aiIndexPlayer) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputactionAttack();
    return;
} // HandleInputactionAttack()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputactionChangeWeapon()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputactionChangeWeapon(int32 aiIndexPlayer) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputactionChangeWeapon();
    return;
} // HandleInputactionChangeWeapon()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputactionJump()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputactionJump(int32 aiIndexPlayer) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputactionJump();
    return;
} // HandleInputactionJump()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputaxisAimRS()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisAimRS(int32 aiIndexPlayer, bool ayNeg, float afPercent) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputaxisAimRS(ayNeg, afPercent);
    return;
} // HandleInputaxisAimRS()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputaxisAimRF()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisAimRF(int32 aiIndexPlayer, bool ayNeg, float afPercent) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputaxisAimRF(ayNeg, afPercent);
    return;
} // HandleInputaxisAimRF()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputaxisMoveAlongAimingForward()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisMoveAlongAimingForward(int32 aiIndexPlayer, bool ayNeg) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputaxisMoveAlongAimingForward(ayNeg);
    return;
} // HandleInputaxisMoveAlongAimingForward()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelstate::HandleInputaxisMoveAlongAimingRight()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelstate::HandleInputaxisMoveAlongAimingRight(int32 aiIndexPlayer, bool ayNeg) {
    // Allow most input to be collectively disabled
    if (! m_yInputEnabled) return;

    // Cause this event to be handled by the same levelpawn which caused the input
    UCRGlobal::GetL0BookLevelpawn(this, aiIndexPlayer)->HandleInputaxisMoveAlongAimingRight(ayNeg);
    return;
} // HandleInputaxisMoveAlongAimingRight()
