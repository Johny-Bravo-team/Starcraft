#ifndef GAMETURN_H
#define GAMETURN_H

#include "Vector.h"
#include "Ships.h"


short ProgressTurn(short TurnCounter);
void RechargeShield(Vector *Defender);
void ProtossTakeDamage(Vector *Defender, int Damage);
void TerranTakeDamage(Vector *Defender, int Damage);
void TakeTurn(Vector *Attacker, Vector *Defender);

#endif /*GAMETURN_H*/