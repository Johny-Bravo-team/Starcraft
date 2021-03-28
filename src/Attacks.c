#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameTurn.h"
#include "BattleField.h"
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"
#include "Attacks.h"

void CarrierAttack(Ship *Attacking_Ship, Ship *Defending_Ship, int index, Vector *Defender, int Damage){
    if ((*Attacking_Ship).health == CARRIER_HEALTH){
        for (int i = 1; i <= MAX_INTERCEPTORS; i++){
            if (Defending_Ship->health <= 0){
                free(Defending_Ship);
                printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender) - 1);
                vectorDelete(Defender, vectorGetSize(Defender) - 1);
                if (vectorGetSize(Defender) == 0){
                    return;
                }
            }
            Defending_Ship = vectorBack(Defender);
            TerranTakeDamage(Defending_Ship, Damage);
        }
    }
    else if ((*Attacking_Ship).health < CARRIER_HEALTH){
        for (int i = 1; i <= DAMAGED_STATUS_INTERCEPTORS; i++){
            if (Defending_Ship->health <= 0){
                free(Defending_Ship);
                printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender) - 1);
                vectorDelete(Defender, vectorGetSize(Defender) - 1);
                if (vectorGetSize(Defender) == 0){
                    return;
                }
            }
            Defending_Ship = vectorBack(Defender);
            TerranTakeDamage(Defending_Ship, Damage);
        }
    }
}

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