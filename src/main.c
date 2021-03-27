#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BattleField.h"
#include "Vector.h"

int main()
{
  const int initialCapacity = 1;
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  scanf("%s %s", terranFleet, protossFleet);

  BattleField battleField;
  generateTerranFleet(&battleField, terranFleet, initialCapacity);
  generateProtossFleet(&battleField, protossFleet, initialCapacity);
  startBattle(&battleField);
  deinit(&battleField);

  return EXIT_SUCCESS;
}