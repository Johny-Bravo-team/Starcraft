#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"

Protoss_ship Phoenix;
Protoss_ship Carrier;

Terran_ship Viking;
Terran_ship BattleCruiser;

/**
 * @brief Check for special abilities of ships based on enemy and defender and turn
 * 
 * @param Attacker - The attacking fleet ship type
 * @param Defender - The defending fleet ship type
 * @param index - The element index in the fleet
 * @param turn - The combat turn we are at
 * @return int - Returns the damage number
 */

Protoss_ship *AllocProttosShip(void)
{
    Protoss_ship *shipPtr = NULL;
    shipPtr = (Protoss_ship *)malloc(sizeof(Protoss_ship));

    if (NULL == shipPtr)
    {
        printf("Allocation memory failed !\n");
        exit(EXIT_FAILURE);
    }

    return shipPtr;
}

Terran_ship *AllocTerransShip(void)
{
    Terran_ship *shipPtr = NULL;
    shipPtr = (Terran_ship *)malloc(sizeof(Terran_ship));

    if (NULL == shipPtr)
    {
        printf("Allocation memory failed !\n");
        exit(EXIT_FAILURE);
    }

    return shipPtr;
}

Protoss_ship *ShipInitProtoss(char shipLetter)
{
    Protoss_ship *shipPtr = NULL;
    
    if (shipLetter == 'p')
    { /*phoenix protoss*/
        shipPtr = AllocProttosShip();
        shipPtr->name = "Phoenix";
        shipPtr->health = PHOENIX_HEALTH;
        shipPtr->shield = PHOENIX_SHIELD;
        shipPtr->damage = PHOENIX_DAMAGE;
        return shipPtr;
    }

    if (shipLetter == 'c')
    { /*carrier protoss*/
        shipPtr = AllocProttosShip();
        shipPtr->name = "Carrier";
        shipPtr->health = CARRIER_HEALTH;
        shipPtr->shield = CARRIER_SHIELD;
        shipPtr->damage = CARRIER_DAMAGE;
        return shipPtr;
    }
}
Terran_ship *ShipInitTerran(char shipLetter)
{
    Terran_ship *shipPtr = NULL;

    if (shipLetter == 'v')
    { /*viking from Terran*/
        shipPtr = AllocProttosShip();
        shipPtr->name = "Viking";
        shipPtr->health = VIKING_HEALTH;
        shipPtr->damage = VIKING_DAMAGE;
        return shipPtr;
    }

    if (shipLetter == 'b') /*BattleCruiser from Terran*/
    {
        shipPtr = AllocProttosShip();
        shipPtr->name = "BattleCruser";
        shipPtr->health = BATTLE_CRUISER_HEALTH;
        shipPtr->damage = BATTLE_CRUISER_DAMAGE;
        return shipPtr;
    }
}

int CalculateDamage(Vector *Attacker, Vector *Defender, int index, int turn)
{
    Ship *Attacking_Ship = (Ship *)malloc(sizeof(Ship));
    Ship *Defending_Ship = (Ship *)malloc(sizeof(Ship));
    Attacking_Ship = vectorGet(Attacker, index);
    Defending_Ship = vectorBack(Defender);

    if (Attacking_Ship->name == "Viking")
    {
        if (Defending_Ship->name == "Phoenix")
        {
            return (VIKING_DAMAGE * 2);
        }
        else
        {
            return (VIKING_DAMAGE);
        }
    };

    if (Attacking_Ship->name == "BattleCruser")
    {
        if (turn % YAMATO_CANNON_LOADING_TURNS == 0)
        {
            return (BATTLE_CRUISER_DAMAGE * 5);
        }
        else
        {
            return (BATTLE_CRUISER_DAMAGE);
        }
    };

    if (Attacking_Ship->name == "Phoenix")
    {
        return (PHOENIX_DAMAGE);
    };

    if (Attacking_Ship->name == "Carrier")
    {
        return (CARRIER_DAMAGE);
    };
}

void RechargeShield(Vector *Defender)
{
    Ship *Ship = vectorBack(Defender);
    if (!strcmp(Ship->name, "Phoenix"))
    {   
        Ship->shield += PHOENIX_SHIELD_REGENERATE_RATE;
        if(Ship->shield > PHOENIX_SHIELD)
        {
            Ship->shield = PHOENIX_SHIELD;
        }
    }
    else if (!strcmp(Ship->name, "Carrier") && Ship->shield < CARRIER_SHIELD)
    {
        Ship->shield += CARRIER_SHIELD_REGENERATE_RATE;
        if(Ship->shield > CARRIER_SHIELD)
        {
            Ship->shield = CARRIER_SHIELD;
        }
    }
}
