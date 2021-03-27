#include <stdio.h>
#include <stdlib.h>
#include "GameTurn.h"
#include "BattleField.h"
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"
#include <string.h>

/**
 * @brief Increments the turn counter and returns the current turn of the game
 * 
 * @param TurnCounter - Takes as parameter the variable holding the turn
 * @return short - Increments the variable and returns the new turn count
 */

void ProtossTakeDamage(Vector *Defender, int Damage)
{

    int TrueDamage = 0;
    Protoss_ship *DamagedShip = (Protoss_ship*)Defender;
    TrueDamage = Damage - DamagedShip->shield;
    DamagedShip->shield -= Damage;
    if (DamagedShip->shield < 0)
    {
        DamagedShip->shield = 0;
    }
    if (TrueDamage < 0)
    {
        TrueDamage = 0;
    }

    DamagedShip->health -= TrueDamage;
}

void TerranTakeDamage(Vector *Defender, int Damage)
{
    if (Defender == NULL)
    {
        return;
    }
    Terran_ship *DamagedShip = (Terran_ship*)Defender;
    if (Damage < 0)
    {
        Damage = 0;
    }
    DamagedShip->health -= Damage;
}

void Attack(Vector *Attacker, Vector *Defender, int index, int turn)
{
    int Damage = 0;
    Ship *Attacking_Ship = vectorGet(Attacker, index);
    Ship *Defending_Ship = vectorBack(Defender);
    Damage = CalculateDamage(Attacker, Defender, index, turn);
    if (!strcmp((*Attacking_Ship).name, "Carrier") && (*Attacking_Ship).health == CARRIER_HEALTH)
    {
        for (int i = 1; i <= MAX_INTERCEPTORS; i++)
        {
            if (Defending_Ship->health <= 0)
            {
                printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender) - 1);
                vectorDelete(Defender, vectorGetSize(Defender) - 1);
                if (vectorGetSize(Defender) == 0)
                {
                    return;
                }
            }
            Defending_Ship = vectorBack(Defender);
            TerranTakeDamage((Vector*)Defending_Ship, Damage);
        }
    }
    else if (!strcmp((*Attacking_Ship).name, "Carrier") && (*Attacking_Ship).health < CARRIER_HEALTH)
    {
        for (int i = 1; i <= DAMAGED_STATUS_INTERCEPTORS; i++)
        {
            if (Defending_Ship->health <= 0)
            {
                printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender) - 1);
                vectorDelete(Defender, vectorGetSize(Defender) - 1);
                if (vectorGetSize(Defender) == 0)
                {
                    return;
                }
            }
            Defending_Ship = vectorBack(Defender);
            TerranTakeDamage((Vector*)Defending_Ship, Damage);
        }
    }
    if (!strcmp((*Attacking_Ship).name, "Phoenix"))
    {
        TerranTakeDamage((Vector*)Defending_Ship, Damage);
    }
    if (!strcmp((*Attacking_Ship).name, "Viking") || !strcmp((*Attacking_Ship).name, "BattleCruser"))
    {
        ProtossTakeDamage((Vector*)Defending_Ship, Damage);
    }
    /*Leak possible - call Mario & Luigy*/
    if (Defending_Ship->health <= 0)
    {
        vectorDelete(Defender, vectorGetSize(Defender) - 1);
        printf("%s with ID: %d killed enemy airship with ID: %d\n", Attacking_Ship->name, index, vectorGetSize(Defender));
        return;
    }
}

void TakeTurn(Vector *Attacker, Vector *Defender, int TurnCounter)
{
    RechargeShield(Attacker);
    for (int i = 0; i < vectorGetSize(Attacker); i++)
    {
        if (vectorGetSize(Defender) == 0)
        {
            break;
        }
        else
        {
            Attack(Attacker, Defender, i, TurnCounter);
        }
    }
}
