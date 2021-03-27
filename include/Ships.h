#ifndef SHIPS_H
#define SHIPS_H
#include "Vector.h"

typedef struct
{
    char *name;
    int health;
    int damage;
    int shield;
} Protoss_ship;

typedef struct
{
    char *name;
    int health;
    int damage;

} Terran_ship;

typedef struct
{
    char *name;
    int health;
    int damage;
    int shield;
} Ship;

extern Protoss_ship Phoenix;
extern Protoss_ship Carrier;
extern Terran_ship Viking;
extern Terran_ship BattleCruiser;

int CalculateDamage(Vector *Attacker, Vector *Defender, int index, int turn);
void ShipInit(char shipLetter);
Terran_ship *AllocTerransShip(void);
Protoss_ship *AllocProttosShip(void);
void RechargeShield(Vector *Defender);
Terran_ship *ShipInitTerran(char shipLetter);
Protoss_ship *ShipInitProtoss(char shipLetter);

#endif /*SHIPS_H*/