////////////////////////////////////////////////////////////////////////////////
// ue210802bellz\Source\ue210802bellz\L0Book\CRL0BookLevelpawn.h
////////////////////////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////////////////////////
// The Unreal framework and base class should be included first
////////////////////////////////////////////////////////////////////////////////
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////
class UCameraComponent;
class UPaperSpriteComponent;
class USpringArmComponent;

////////////////////////////////////////////////////////////////////////////////
// The RTTI should be included last
////////////////////////////////////////////////////////////////////////////////
#include "CRL0BookLevelpawn.generated.h"

////////////////////////////////////////////////////////////////////////////////
// UCLASS() class UE210802BELLZ_API ACRL0BookLevelpawn
////////////////////////////////////////////////////////////////////////////////
UCLASS() class UE210802BELLZ_API ACRL0BookLevelpawn : public ACharacter {
GENERATED_BODY()
public:
    ACRL0BookLevelpawn();
    void         HandleInputactionAttack();
    void         HandleInputactionChangeWeapon();
    void         HandleInputactionJump();
    void         HandleInputaxisAimRS(                 bool ayNeg, float afPercent);
    void         HandleInputaxisAimRF(                 bool ayNeg, float afPercent);
    void         HandleInputaxisMoveAlongAimingForward(bool ayNeg);
    void         HandleInputaxisMoveAlongAimingRight(  bool ayNeg);
    virtual void Tick(float afDeltaSec);
protected:
    virtual void SetupPlayerInputComponent(UInputComponent* apoComponentInput);
private:
    void  DamageHealth(int32 aiDamage);
    int32 FindIndexPlayerThis() const;
    void  HandleLevelstateInputactionAttack();
    void  HandleLevelstateInputactionChangeWeapon();
    void  HandleLevelstateInputactionJump();
    void  HandleLevelstateInputaxisAimRSBinary(           float afInputaxis);
    void  HandleLevelstateInputaxisAimRSPercent(          float afInputaxis);
    void  HandleLevelstateInputaxisAimRFBinary(           float afInputaxis);
    void  HandleLevelstateInputaxisAimRFPercent(          float afInputaxis);
    void  HandleLevelstateInputaxisMoveAlongAimingForward(float afInputaxis);
    void  HandleLevelstateInputaxisMoveAlongAimingRight(  float afInputaxis);

public:
    UPROPERTY(EditAnywhere,    BlueprintReadWrite, Category="ACRL0BookLevelpawn") bool                    m_yAttacking;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category="ACRL0BookLevelpawn") UCameraComponent*      m_poComponentCamera;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category="ACRL0BookLevelpawn") USpringArmComponent*   m_poComponentSpringarm;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ACRL0BookLevelpawn") UPaperSpriteComponent*  m_poComponentSprite;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category="ACRL0BookLevelpawn") UStaticMeshComponent*  m_poComponentWeapon;
    UPROPERTY(EditAnywhere,    BlueprintReadWrite, Category="ACRL0BookLevelpawn") int32                   m_iHealth;
    UPROPERTY(EditAnywhere,    BlueprintReadWrite, Category="ACRL0BookLevelpawn") int32                   m_iIndexAttack;
    UPROPERTY(EditAnywhere,    BlueprintReadWrite, Category="ACRL0BookLevelpawn") int32                   m_iIndexWeapon;
private:
    UStaticMesh* m_poComponentWeapon0Shape;
    UStaticMesh* m_poComponentWeapon1Shape;
    UStaticMesh* m_poComponentWeapon2Shape;
}; // class ACRL0BookLevelpawn
