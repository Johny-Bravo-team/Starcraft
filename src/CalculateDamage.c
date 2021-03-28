#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalculateDamage.h"
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"

int CalculateDamage(Vector *Attacker, Vector *Defender, int index, int turn){
    Ship *Attacking_Ship = vectorGet(Attacker, index);
    Ship *Defending_Ship = vectorBack(Defender);

    if (!strcmp(Attacking_Ship->name, "Viking")){
        if (!strcmp(Defending_Ship->name, "Phoenix")){
            return (VIKING_DAMAGE * 2);
        }
        else{
            return (VIKING_DAMAGE);
        }
    };

    if (!strcmp (Attacking_Ship->name, "BattleCruser")){
        if (turn % YAMATO_CANNON_LOADING_TURNS == 0){
            return (BATTLE_CRUISER_DAMAGE * 5);
        }
        else{
            return (BATTLE_CRUISER_DAMAGE);
        }
    };

    if (!strcmp(Attacking_Ship->name, "Phoenix")){
        return (PHOENIX_DAMAGE);
    };

    if (!strcmp(Attacking_Ship->name, "Carrier")){
        return (CARRIER_DAMAGE);
    };

    return 0;
}