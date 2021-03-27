#ifndef GAMETURN_H
#define GAMETURN_H

#include "Vector.h"
#include "Ships.h"


short ProgressTurn(short TurnCounter);
void RechargeShield(Vector *Defender);
void ProtossTakeDamage(Ship *DefendingShip, int Damage);
void TerranTakeDamage(Ship *DefendingShip, int Damage);
void TakeTurn(Vector *Attacker, Vector *Defender, int TurnCounter);

#endif /*GAMETURN_H*/