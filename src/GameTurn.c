#include <stdio.h>
#include <stdlib.h>
#include "GameTurn.h"
#include "BattleField.h"
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"
#include <string.h>
#include <StatusLog.h>

/**
 * @brief Increments the turn counter and returns the current turn of the game
 * 
 * @param TurnCounter - Takes as parameter the variable holding the turn
 * @return short - Increments the variable and returns the new turn count
 */

void ProtossTakeDamage(Ship *DefendingShip, int Damage){
    int TrueDamage = 0;
    Protoss_ship *DamagedShip = (Protoss_ship*)DefendingShip;  
    TrueDamage = Damage - DamagedShip->shield;
    DamagedShip->shield -= Damage;

    if (DamagedShip->shield < 0){
        DamagedShip->shield = 0;
    }

    if (TrueDamage < 0){
        TrueDamage = 0;
    }

    DamagedShip->health -= TrueDamage;
}

void TerranTakeDamage(Ship *DefendingShip, int Damage){
    if (DefendingShip == NULL)
    {
        return;
    }
    Terran_ship *DamagedShip = (Terran_ship*) DefendingShip;
    if (Damage < 0)
    {
        Damage = 0;
    }
    DamagedShip->health -= Damage;
}

void Attack(Vector *Attacker, Vector *Defender, int index, int turn){
    int Damage = CalculateDamage(Attacker, Defender, index, turn);
    Ship *Attacking_Ship = vectorGet(Attacker, index);
    Ship *Defending_Ship = vectorBack(Defender);

    checkNullObject(Attacking_Ship ,__func__, __LINE__, __FILE__);
    checkNullObject(Defending_Ship ,__func__, __LINE__, __FILE__);

    if (!strcmp((*Attacking_Ship).name, "Carrier") && (*Attacking_Ship).health == CARRIER_HEALTH){//if carier is max healt attack whit 8 interseptors
        for (int i = 1; i <= MAX_INTERCEPTORS; i++) {
            if (Defending_Ship->health <= 0) {
                free(Defending_Ship);
                printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index,
                vectorGetSize(Defender) - 1);
                
                vectorDelete(Defender, vectorGetSize(Defender) - 1);
                if (vectorGetSize(Defender) == 0) {
                    return;
                }
            }
            Defending_Ship = vectorBack(Defender);
            TerranTakeDamage(Defending_Ship, Damage);
        }
    }
    else if (!strcmp((*Attacking_Ship).name, "Carrier") && (*Attacking_Ship).health < CARRIER_HEALTH) {
        for (int i = 1; i <= DAMAGED_STATUS_INTERCEPTORS; i++) {
            if (Defending_Ship->health <= 0) {
                free(Defending_Ship);
                printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index,
                vectorGetSize(Defender) - 1);

                vectorDelete(Defender, vectorGetSize(Defender) - 1);
                if (vectorGetSize(Defender) == 0){
                    return;
                }
            }
            Defending_Ship = vectorBack(Defender);
            TerranTakeDamage(Defending_Ship, Damage);
        }
    }
    if (!strcmp((*Attacking_Ship).name, "Phoenix")){
        TerranTakeDamage(Defending_Ship, Damage);
    }
    if (!strcmp((*Attacking_Ship).name, "Viking") || !strcmp((*Attacking_Ship).name, "BattleCruser")){
        ProtossTakeDamage(Defending_Ship, Damage);
    }

    if (Defending_Ship->health <= 0){
        free(Defending_Ship);
        vectorDelete(Defender, vectorGetSize(Defender) - 1);
        printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender));
        return;
    }
}

void TakeTurn(Vector *Attacker, Vector *Defender, int TurnCounter) {
    RechargeShield(Attacker);
    for (int i = 0; i < vectorGetSize(Attacker); i++) {
        if (vectorGetSize(Defender) == 0){
            break;
        }
        else {
            Attack(Attacker, Defender, i, TurnCounter);
        }
    }
}