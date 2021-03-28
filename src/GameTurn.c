#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameTurn.h"
#include "BattleField.h"
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"
#include "Attacks.h"

void TakeTurn(Vector *Attacker, Vector *Defender, int TurnCounter){
    RechargeShield(Attacker);
    
    for (int i = 0; i < vectorGetSize(Attacker); i++){
        if (vectorGetSize(Defender) == 0){
            break;
        }
        else{
            Attack(Attacker, Defender, i, TurnCounter);
        }
    }
}

void Attack(Vector *Attacker, Vector *Defender, int index, int turn){
    Ship *Attacking_Ship = vectorGet(Attacker, index);
    Ship *Defending_Ship = vectorBack(Defender);
    int Damage = CalculateDamage(Attacker, Defender, index, turn);
    
    if (!strcmp((*Attacking_Ship).name, "Carrier")){
        CarrierAttack(Attacking_Ship, Defending_Ship, index, Defender, Damage);
    }
    else if (!strcmp((*Attacking_Ship).name, "Phoenix")){
        TerranTakeDamage(Defending_Ship, Damage);
    }
    else if (!strcmp((*Attacking_Ship).name, "Viking") || !strcmp((*Attacking_Ship).name, "BattleCruser")){
        ProtossTakeDamage(Defending_Ship, Damage);
    }
    
    if (Defending_Ship->health <= 0){
        free(Defending_Ship);
        vectorDelete(Defender, vectorGetSize(Defender) - 1);
        printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender));
        return;
    }
}