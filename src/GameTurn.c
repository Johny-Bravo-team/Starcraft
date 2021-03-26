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
short ProgressTurn(short TurnCounter)
{
    return (TurnCounter++);
}

void ProtossTakeDamage(Vector *Defender, int Damage)
{
    int TrueDamage = 0;
    Protoss_ship *DamagedShip = Defender;
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
    Terran_ship *DamagedShip = Defender;
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
    Ship *Defending_Ship = vectorGetLast(Defender);
    Damage = CalculateDamage(Attacker, Defender, index, turn);
    if (!strcmp((*Attacking_Ship).name, "Phoenix") || !strcmp((*Attacking_Ship).name, "Carrier"))
    {
        TerranTakeDamage(Defending_Ship, Damage);
    }

    if (!strcmp((*Attacking_Ship).name, "Viking") || !strcmp((*Attacking_Ship).name, "BattleCruiser"))
    {
        ProtossTakeDamage(Defending_Ship, Damage);
    }
    /*Leak possible - call Mario & Luigy*/
    if (Defending_Ship->health <= 0)
    {

        vectorDelete(Defender, vectorGetSize(Defender) - 1);
        return;
    }
}

void TakeTurn(Vector *Attacker, Vector *Defender)
{
    static int TurnCounter = 0;
    ProgressTurn(TurnCounter);
    for (int i = 0; i < vectorGetSize(Attacker); i++)
    {
        Attack(Attacker, Defender, i, TurnCounter);
    }
}
