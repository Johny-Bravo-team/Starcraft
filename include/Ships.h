#ifndef PROTOSS_FLEET_H
#define PROTOSS_FLEET_H
#include "Vector.h"

typedef struct
{
    char *name;
    int health;
    int shield;
    int damage;
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
    int shield;
    int damage;
} Ship;

extern Protoss_ship Phoenix;
extern Protoss_ship Carrier;
extern Terran_ship Viking;
extern Terran_ship BattleCruiser;
int CalculateDamage(Vector *Attacker, Vector *Defender, int index, int turn);
#endif /*PROTOSS_FLEET_H*/