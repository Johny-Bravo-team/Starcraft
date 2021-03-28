#ifndef GAMETURN_H
#define GAMETURN_H

#include "Vector.h"
#include "Ships.h"

void TakeTurn(Vector *Attacker, Vector *Defender, int TurnCounter);
void RechargeShield(Vector *Defender);
void Attack(Vector *Attacker, Vector *Defender, int index, int turn);

#endif /*GAMETURN_H*/