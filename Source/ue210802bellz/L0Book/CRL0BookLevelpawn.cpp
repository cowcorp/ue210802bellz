////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\L0Book\CRL0BookLevelpawn.cpp
////////////////////////////////////////////////////////////////////////////////
#include "CRL0BookLevelpawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Misc/OutputDeviceNull.h"
#include "PaperSpriteComponent.h"
#include "../Global/CRGlobal.h"
#include "CRL0BookLevelstate.h"

constexpr int32 SIZE_ATTACK = 3;
constexpr int32 SIZE_WEAPON = 3;

////////////////////////////////////////////////////////////////////////////////
// public ACRL0BookLevelpawn::ACRL0BookLevelpawn()
////////////////////////////////////////////////////////////////////////////////
ACRL0BookLevelpawn::ACRL0BookLevelpawn() : ACharacter() {
    // Receive a Tick() event once per frame
    PrimaryActorTick.bCanEverTick = true;

    // Don't tie this pawn's transform to the controller's transform
    bUseControllerRotationRoll  = false;
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw   = false;

    // Configure the capsule-component to approximate the levelpawn's shape (for detecting collisions with other objects)
    GetCapsuleComponent()->InitCapsuleSize(42.0F, 96.0F);

    // When you move this levelpawn's position in the E,S plane, cause ACharacter to gradually turn its articulated shape (so that it eventually faces the direction of motion)
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0F, 540.0F, 0.0F);

    // Configure the character-movement-component that is inherited from ACharacter, so that the levelpawn's jumps initially move this fast upwards (before gravity reduces that upwards velocity)
    GetCharacterMovement()->JumpZVelocity = 600.0F;

    // While in the middle of a jump, retard (down to 20% of ordinary) any attmpted movements of the levelpawn in E and S directions
    GetCharacterMovement()->AirControl = 0.2F;

    // Create a weapon as a rigid-body-component which is attached to a socket at the levelpawn's right hand
    m_poComponentWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("m_poComponentWeapon"));
    m_poComponentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("socketHandRightWeapon"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> goComponentWeapon0Shape(TEXT("StaticMesh'/Game/bellz/Rigids/L0BookWeapon0/Shapes/bellzL0BookWeapon0Shape.bellzL0BookWeapon0Shape'"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> goComponentWeapon1Shape(TEXT("StaticMesh'/Game/bellz/Rigids/L0BookWeapon1/Shapes/bellzL0BookWeapon1Shape.bellzL0BookWeapon1Shape'"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> goComponentWeapon2Shape(TEXT("StaticMesh'/Game/bellz/Rigids/L0BookWeapon2/Shapes/bellzL0BookWeapon2Shape.bellzL0BookWeapon2Shape'"));
    m_poComponentWeapon0Shape = goComponentWeapon0Shape.Object;
    m_poComponentWeapon1Shape = goComponentWeapon1Shape.Object;
    m_poComponentWeapon2Shape = goComponentWeapon2Shape.Object;
    m_iIndexWeapon = 0;
    m_poComponentWeapon->SetStaticMesh(m_poComponentWeapon0Shape);

    // Be able to see the levelpawn's shape by using a springarm so that the camera is usually 300 Unreal-centimeters behind (-300,0,0) the levelpawn's shape
    // Allow the springarm (thus, affecting springarm and camera) to be transformed relative to the whole levelpawn: Tie that springarm-transform so that its rotations always match the controller's aim direction
    m_poComponentCamera    = CreateDefaultSubobject<UCameraComponent>(   TEXT("m_poComponentCamera"));
    m_poComponentSpringarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("m_poComponentSpringarm"));
    m_poComponentSpringarm->AttachToComponent(RootComponent,          FAttachmentTransformRules::KeepRelativeTransform);
    m_poComponentCamera->   AttachToComponent(m_poComponentSpringarm, FAttachmentTransformRules::KeepRelativeTransform, USpringArmComponent::SocketName);
    m_poComponentSpringarm->TargetArmLength = 300.0F;
    m_poComponentSpringarm->bUsePawnControlRotation = true;
    m_poComponentCamera->   bUsePawnControlRotation = false;

    // Create the sprite-component that is at the levelpawn's origin, but rotates with the springarm (so that it is always visible)
    m_poComponentSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("m_poComponentSprite"));
    m_poComponentSprite->AttachToComponent(m_poComponentSpringarm, FAttachmentTransformRules::KeepRelativeTransform);

    // Initialize state that is specific to this levelpawn (if the game had been multiplayer, each levelpawn would have had its own)
    m_yAttacking   = false;
    m_iHealth      = 100;
    m_iIndexAttack = SIZE_ATTACK;
} // ACRL0BookLevelpawn()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputactionAttack()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputactionAttack() {
    // Refuse to begin an attack if we are already in the middle of another attack
    if (m_yAttacking) return;

    // Assume that making an attack causes a bit of injury to yourself
    DamageHealth(5);
    if (m_iHealth <= 0) return;

    // Take turns through the possible attack animations
    m_iIndexAttack++;
    if (m_iIndexAttack >= SIZE_ATTACK) m_iIndexAttack = 0;
    m_yAttacking = true;
    return;
} // HandleInputactionAttack()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputactionChangeWeapon()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputactionChangeWeapon() {
    // Refuse to change weapons if we are dead
    if (m_iHealth <= 0) return;

    // Refuse to change weapons if we are currently in the middle of attacking
    if (m_yAttacking) return;

    // Cycle through the options for a weapon's rigid-body shape
    m_iIndexWeapon++;
    if (m_iIndexWeapon >= SIZE_WEAPON) m_iIndexWeapon = 0;
    switch (m_iIndexWeapon) {
    case 0: m_poComponentWeapon->SetStaticMesh(m_poComponentWeapon0Shape); break;
    case 1: m_poComponentWeapon->SetStaticMesh(m_poComponentWeapon1Shape); break;
    case 2: m_poComponentWeapon->SetStaticMesh(m_poComponentWeapon2Shape); break;
    }
    return;
} // HandleInputactionChangeWeapon()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputactionJump()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputactionJump() {
    // Refuse to jump if we are dead
    if (m_iHealth <= 0) return;

    // Refuse to jump if we are currently in the middle of attacking
    if (m_yAttacking) return;

    // On ACharacter's next update step, cause it to temporarily adjust the levelpawn's F coordinate in a up-then-down motion
    Jump();
} // HandleInputactionJump()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputaxisAimRS()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputaxisAimRS(bool ayNeg, float afPercent) {
    const float fTopspeedDegreeRSPerSec = 90.0F;
    const float fSecPerFrame = GetWorld()->GetDeltaSeconds();
    if (ayNeg) AddControllerPitchInput(- (afPercent / 100.0F) * fTopspeedDegreeRSPerSec * fSecPerFrame);
    else       AddControllerPitchInput(  (afPercent / 100.0F) * fTopspeedDegreeRSPerSec * fSecPerFrame);
} // HandleInputaxisAimRS()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputaxisAimRF()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputaxisAimRF(bool ayNeg, float afPercent) {
    const float fTopspeedDegreeRFPerSec = 180.0F;
    const float fSecPerFrame = GetWorld()->GetDeltaSeconds();
    if (ayNeg) AddControllerYawInput(- (afPercent / 100.0F) * fTopspeedDegreeRFPerSec * fSecPerFrame);
    else       AddControllerYawInput(  (afPercent / 100.0F) * fTopspeedDegreeRFPerSec * fSecPerFrame);
} // HandleInputaxisAimRF()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputaxisMoveAlongAimingForward()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputaxisMoveAlongAimingForward(bool ayNeg) {
    // Refuse to move if we are dead
    if (m_iHealth <= 0) return;

    // Refuse to move if we are currently in the middle of attacking
    if (m_yAttacking) return;

    // Consider RF-rotational-component of the controller's current "aim" transform; rotate a "forward-vector" (X,Y,Z=1,0,0) by that RF, to obtain a "forward" direction in the E,S plane
    FRotator oRotator = Controller->GetControlRotation();
    oRotator.Roll = 0.0F;
    oRotator.Pitch = 0.0F;
    FVector fffDirectionES0 = oRotator.RotateVector(FVector(1.0F, 0.0F, 0.0F));

    // Move this levelpawn in that direction
    if (ayNeg) fffDirectionES0 = - fffDirectionES0;
    AddMovementInput(fffDirectionES0);
} // HandleInputaxisMoveAlongAimingForward()

////////////////////////////////////////////////////////////////////////////////
// public void ACRL0BookLevelpawn::HandleInputaxisMoveAlongAimingRight()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleInputaxisMoveAlongAimingRight(bool ayNeg) {
    // Refuse to move if we are dead
    if (m_iHealth <= 0) return;

    // Refuse to move if we are currently in the middle of attacking
    if (m_yAttacking) return;

    // Consider RF-rotational-component of the controller's current "aim" transform; rotate a "right-vector" (X,Y,Z=0,1,0) by that RF, to obtain a "right" direction in the E,S plane
    FRotator oRotator = Controller->GetControlRotation();
    oRotator.Roll = 0.0F;
    oRotator.Pitch = 0.0F;
    FVector fffDirectionES0 = oRotator.RotateVector(FVector(0.0F, 1.0F, 0.0F));

    // Move this levelpawn in that direction
    if (ayNeg) fffDirectionES0 = - fffDirectionES0;
    AddMovementInput(fffDirectionES0);
} // HandleInputaxisMoveAlongAimingRight()

////////////////////////////////////////////////////////////////////////////////
// public virtual void ACRL0BookLevelpawn::Tick()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::Tick(float afDeltaSec) {
    ACharacter::Tick(afDeltaSec);
} // Tick()

////////////////////////////////////////////////////////////////////////////////
// protected virtual void ACRL0BookLevelpawn::SetupPlayerInputComponent()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::SetupPlayerInputComponent(UInputComponent* apoComponentInput) {
    ACharacter::SetupPlayerInputComponent(apoComponentInput);
    apoComponentInput->BindAction("LevelstateInputactionAttack",       IE_Pressed, this, &ACRL0BookLevelpawn::HandleLevelstateInputactionAttack);
    apoComponentInput->BindAction("LevelstateInputactionChangeWeapon", IE_Pressed, this, &ACRL0BookLevelpawn::HandleLevelstateInputactionChangeWeapon);
    apoComponentInput->BindAction("LevelstateInputactionJump",         IE_Pressed, this, &ACRL0BookLevelpawn::HandleLevelstateInputactionJump);
    apoComponentInput->BindAxis("LevelstateInputaxisAimRSBinary",            this, &ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRSBinary);
    apoComponentInput->BindAxis("LevelstateInputaxisAimRSPercent",           this, &ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRSPercent);
    apoComponentInput->BindAxis("LevelstateInputaxisAimRFBinary",            this, &ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRFBinary);
    apoComponentInput->BindAxis("LevelstateInputaxisAimRFPercent",           this, &ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRFPercent);
    apoComponentInput->BindAxis("LevelstateInputaxisMoveAlongAimingForward", this, &ACRL0BookLevelpawn::HandleLevelstateInputaxisMoveAlongAimingForward);
    apoComponentInput->BindAxis("LevelstateInputaxisMoveAlongAimingRight",   this, &ACRL0BookLevelpawn::HandleLevelstateInputaxisMoveAlongAimingRight);
} // SetupPlayerInputComponent()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::DamageHealth()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::DamageHealth(int32 aiDamage) {
    // Do nothing if we are already dead
    if (m_iHealth <= 0) return;

    // Reduce our health
    m_iHealth -= aiDamage;
    if (m_iHealth <= 0) m_iHealth = 0;

    // Rely on the a derived (blueprint) class to display an effect to signal that we've taken damage
    FOutputDeviceNull oNull;
    CallFunctionByNameWithArguments(TEXT("ShowSpriteBlood"), oNull, nullptr, true);
} // DamageHealth()

////////////////////////////////////////////////////////////////////////////////
// private int32 ACRL0BookLevelpawn::FindIndexPlayerThis() const
////////////////////////////////////////////////////////////////////////////////
int32 ACRL0BookLevelpawn::FindIndexPlayerThis() const {
    int32 iReturnValue = 0;
    while (UCRGlobal::GetL0BookLevelpawn(this, iReturnValue) != this) {
        iReturnValue++;
        if (iReturnValue > 16) return -1;
    }
    return iReturnValue;
} // FindIndexPlayerThis()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputactionAttack()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputactionAttack() {
    UCRGlobal::GetL0BookLevelstate(this)->HandleInputactionAttack(FindIndexPlayerThis());
} // HandleLevelstateInputactionAttack()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputactionChangeWeapon()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputactionChangeWeapon() {
    UCRGlobal::GetL0BookLevelstate(this)->HandleInputactionChangeWeapon(FindIndexPlayerThis());
} // HandleLevelstateInputactionChangeWeapon()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputactionJump()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputactionJump() {
    UCRGlobal::GetL0BookLevelstate(this)->HandleInputactionJump(FindIndexPlayerThis());
} // HandleLevelstateInputactionJump()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRSBinary()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRSBinary(float afInputaxis) {
    const float fBinaryPercent = 25.0F;
    if (     afInputaxis < -0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRS(FindIndexPlayerThis(), true,  fBinaryPercent);
    else if (afInputaxis >  0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRS(FindIndexPlayerThis(), false, fBinaryPercent);
} // HandleLevelstateInputaxisAimRSBinary()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRSPercent()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRSPercent(float afInputaxis) {
    const float fInputaxisFullspeed = 2.0F;
    if (afInputaxis < -0.1F) {
        float fPercent = -100.0F * afInputaxis / fInputaxisFullspeed;
        if (fPercent >= 100.0F) fPercent = 100.0F;
        UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRS(FindIndexPlayerThis(), true, fPercent);
    }
    else if (afInputaxis >  0.1F) {
        float fPercent = 100.0F * afInputaxis / fInputaxisFullspeed;
        if (fPercent >= 100.0F) fPercent = 100.0F;
        UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRS(FindIndexPlayerThis(), false, fPercent);
    }
} // HandleLevelstateInputaxisAimRSPercent()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRFBinary()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRFBinary(float afInputaxis) {
    const float fBinaryPercent = 25.0F;
    if (     afInputaxis < -0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRF(FindIndexPlayerThis(), true,  fBinaryPercent);
    else if (afInputaxis >  0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRF(FindIndexPlayerThis(), false, fBinaryPercent);
} // HandleLevelstateInputaxisAimRFBinary()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRFPercent()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputaxisAimRFPercent(float afInputaxis) {
    const float fInputaxisFullspeed = 4.0F;
    if (afInputaxis < -0.1F) {
        float fPercent = -100.0F * afInputaxis / fInputaxisFullspeed;
        if (fPercent >= 100.0F) fPercent = 100.0F;
        UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRF(FindIndexPlayerThis(), true, fPercent);
    }
    else if (afInputaxis >  0.1F) {
        float fPercent = 100.0F * afInputaxis / fInputaxisFullspeed;
        if (fPercent >= 100.0F) fPercent = 100.0F;
        UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisAimRF(FindIndexPlayerThis(), false, fPercent);
    }
} // HandleLevelstateInputaxisAimRFPercent()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputaxisMoveAlongAimingForward()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputaxisMoveAlongAimingForward(float afInputaxis) {
    if (     afInputaxis < -0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisMoveAlongAimingForward(FindIndexPlayerThis(), true);
    else if (afInputaxis >  0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisMoveAlongAimingForward(FindIndexPlayerThis(), false);
} // HandleLevelstateInputaxisMoveAlongAimingForward()

////////////////////////////////////////////////////////////////////////////////
// private void ACRL0BookLevelpawn::HandleLevelstateInputaxisMoveAlongAimingRight()
////////////////////////////////////////////////////////////////////////////////
void ACRL0BookLevelpawn::HandleLevelstateInputaxisMoveAlongAimingRight(float afInputaxis) {
    if (     afInputaxis < -0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisMoveAlongAimingRight(FindIndexPlayerThis(), true);
    else if (afInputaxis >  0.1F) UCRGlobal::GetL0BookLevelstate(this)->HandleInputaxisMoveAlongAimingRight(FindIndexPlayerThis(), false);
} // HandleLevelstateInputaxisMoveAlongAimingRight()
