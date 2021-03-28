#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"

/**
 * @brief Check for special abilities of ships based on enemy and defender and turn
 * 
 * @param Attacker - The attacking fleet ship type
 * @param Defender - The defending fleet ship type
 * @param index - The element index in the fleet
 * @param turn - The combat turn we are at
 * @return int - Returns the damage number
 */

Protoss_ship *AllocProttosShip(void){
    Protoss_ship *shipPtr = NULL;
    shipPtr = (Protoss_ship *)malloc(sizeof(Protoss_ship));

    if (NULL == shipPtr){
        printf("Allocation memory failed !\n");
        exit(EXIT_FAILURE);
    }

    return shipPtr;
}

Terran_ship *AllocTerransShip(void){
    Terran_ship *shipPtr = NULL;
    shipPtr = (Terran_ship *)malloc(sizeof(Terran_ship));

    if (NULL == shipPtr){
        printf("Allocation memory failed !\n");
        exit(EXIT_FAILURE);
    }

    return shipPtr;
}

Protoss_ship *ShipInitProtoss(char shipLetter){
    Protoss_ship *shipPtr = NULL;

    if (shipLetter == 'p'){ /*phoenix protoss*/
        shipPtr = AllocProttosShip();
        shipPtr->name = "Phoenix";
        shipPtr->health = PHOENIX_HEALTH;
        shipPtr->shield = PHOENIX_SHIELD;
        shipPtr->damage = PHOENIX_DAMAGE;
        return shipPtr;
    }

    if (shipLetter == 'c'){ /*carrier protoss*/
        shipPtr = AllocProttosShip();
        shipPtr->name = "Carrier";
        shipPtr->health = CARRIER_HEALTH;
        shipPtr->shield = CARRIER_SHIELD;
        shipPtr->damage = CARRIER_DAMAGE;
        return shipPtr;
    }

    return NULL;
}

Terran_ship *ShipInitTerran(char shipLetter){
    Terran_ship *shipPtr = NULL;

    if (shipLetter == 'v'){ 
        shipPtr = AllocTerransShip();
        shipPtr->name = "Viking";
        shipPtr->health = VIKING_HEALTH;
        shipPtr->damage = VIKING_DAMAGE;
        return shipPtr;
    }

    if (shipLetter == 'b'){ 
        shipPtr = AllocTerransShip();
        shipPtr->name = "BattleCruser";
        shipPtr->health = BATTLE_CRUISER_HEALTH;
        shipPtr->damage = BATTLE_CRUISER_DAMAGE;
        return shipPtr;
    }

    return NULL;
}