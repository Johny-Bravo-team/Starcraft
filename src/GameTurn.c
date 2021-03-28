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

