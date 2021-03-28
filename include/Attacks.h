#ifndef ATTACKS_H
#define ATTACKS_H

#include "Vector.h"
#include "Ships.h"

void CarrierAttack(Ship *Attacking_Ship, Ship *Defending_Ship, int index, Vector *Defender, int Damage);
void ProtossTakeDamage(Ship *DefendingShip, int Damage);
void TerranTakeDamage(Ship *DefendingShip, int Damage);

#endif /*ATTACKS_H*/