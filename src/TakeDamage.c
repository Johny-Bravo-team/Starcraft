#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameTurn.h"
#include "BattleField.h"
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"
#include "Attacks.h"
#include "TakeDamage.h"

void ProtossTakeDamage(Ship *DefendingShip, int Damage){
    if (DefendingShip == NULL){
        return;
    }

    int TrueDamage = 0;
    Protoss_ship *DamagedShip = (Protoss_ship*)DefendingShip;  
    TrueDamage = Damage - DamagedShip->shield;
    if (TrueDamage < 0){
        TrueDamage = 0;
    }

    DamagedShip->shield -= Damage;
    if (DamagedShip->shield < 0){
        DamagedShip->shield = 0;
    }

    DamagedShip->health -= TrueDamage;
}

void TerranTakeDamage(Ship *DefendingShip, int Damage){
    if (DefendingShip == NULL){
        return;
    }

    Terran_ship *DamagedShip = (Terran_ship*) DefendingShip;
    if (Damage < 0){
        Damage = 0;
    }
    DamagedShip->health -= Damage;
}