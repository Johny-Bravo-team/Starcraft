#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Ships.h"
#include "BattleField.h"
#include "Vector.h"

int main()
{
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  FILE * file = fopen("test.txt","a+");
  scanf("%s %s", &terranFleet, &protossFleet);

  BattleField battleField;
  generateTerranFleet(&battleField, terranFleet);
  generateProtossFleet(&battleField, protossFleet);
  //CalculateDamage(&battleField.terranFleet, &battleField.protossFleet, 1, 1);
  startBattle(&battleField);
  deinit(&battleField);
  
  return EXIT_SUCCESS;
}
