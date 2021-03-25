#include <stdio.h>
#include "Defines.h"
#include "Ships.h"
#include "Vector.h"


Protoss_ship Phoenix = {"Phoenix", PHOENIX_HEALTH, PHOENIX_SHIELD, PHOENIX_DAMAGE};
Protoss_ship Carrier = {"Carrier", CARRIER_HEALTH, CARRIER_SHIELD, CARRIER_DAMAGE};

Terran_ship Viking = {"Viking", VIKING_HEALTH, VIKING_DAMAGE};
Terran_ship BattleCruiser = {"Battlecruiser", BATTLE_CRUISER_HEALTH, BATTLE_CRUISER_DAMAGE};

/**
 * @brief Check for special abilities of ships based on enemy and defender and turn
 * 
 * @param Attacker - The attacking fleet ship type
 * @param Defender - The defending fleet ship type
 * @param index - The element index in the fleet
 * @param turn - The combat turn we are at
 * @return int - Returns the damage number
 */

/*int CalculateDamage(Vector *Attacker, Vector *Defender, int index, int turn){
    Ship Attacking_Ship = vectorGet(Attacker, index);
    Ship Defending_Ship = vectorGet(Defender, index);      
  
    if (Attacking_Ship == Viking){
        if(Defending_Ship == Phoenix){
            return (VIKING_DAMAGE * 2);
        } else {
            return (VIKING_DAMAGE);
        }
    };

    if (Attacking_Ship == BattleCruiser){
        if (!(turn%5)){
            return (BATTLE_CRUISER_DAMAGE * 5);
        } else {
            return (BATTLE_CRUISER_DAMAGE);
        }
    };

    if (Attacking_Ship == Phoenix){
        return (PHOENIX_DAMAGE);
    };

    if (Attacking_Ship == Carrier){
        return CARRIER_DAMAGE;
    };

}

*/