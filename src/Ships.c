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

void ShipInit(char shipLetter)
{
    if (shipLetter == 'p')
    { /*phoenix protoss*/
        Phoenix.name = "Phoenix";
        Phoenix.health = PHOENIX_HEALTH;
        Phoenix.shield = PHOENIX_SHIELD;
        Phoenix.damage = PHOENIX_DAMAGE;
        return AllocProttosShip();
    }

    if (shipLetter == 'c')
    { /*carrier protoss*/
        Carrier.name = "Carrier";
        Carrier.health = CARRIER_HEALTH;
        Carrier.shield = CARRIER_SHIELD;
        Carrier.damage = CARRIER_DAMAGE;
        return &Carrier;
    }

    if (shipLetter == 'v')
    { /*viking from Terran*/
        Viking.name = "Viking";
        Viking.health = VIKING_HEALTH;
        Viking.damage = VIKING_DAMAGE;
        return &Viking;
    }

    if (shipLetter == 'b') /*BattleCruiser from Terran*/
    {
        BattleCruiser.name = "BattleCruiser";
        BattleCruiser.health = BATTLE_CRUISER_HEALTH;
        BattleCruiser.damage = BATTLE_CRUISER_DAMAGE;
        return &BattleCruiser;
    }
}

int CalculateDamage(Vector *Attacker, Vector *Defender, int index, int turn)
{
    Ship *Attacking_Ship = (Ship *)malloc(sizeof(Ship));
    Ship *Defending_Ship = (Ship *)malloc(sizeof(Ship));
    Attacking_Ship = vectorGet(Attacker, index);
    Defending_Ship = vectorGet(Defender, index);

    if (Attacking_Ship->name == "Viking")
    {
        if (Defending_Ship->name == Phoenix.name)
        {
            return (VIKING_DAMAGE * 2);
        }
        else
        {
            return (VIKING_DAMAGE);
        }
    };

    if (Attacking_Ship->name == "BattleCruiser")
    {
        if (!(turn % 5))
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
    Ship *Ship = vectorGetLast(Defender);
    if (!strcmp(Ship->name, "Phoenix")){
        Ship->shield += PHOENIX_SHIELD_REGENERATE_RATE;
    }
    else if (!strcmp(Ship->name, "Carrier")){
        Ship->shield += CARRIER_SHIELD_REGENERATE_RATE;
    }
}
