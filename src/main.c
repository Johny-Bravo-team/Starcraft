#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BattleField.h"
#include "Vector.h"
#include "StatusLog.h"

int main()
{
  statusFileLoad();
  const int initialCapacity = 1;
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  scanf("%s %s", terranFleet, protossFleet);

  BattleField battleField;
  generateTerranFleet(&battleField, terranFleet, initialCapacity);
  statusLogger();

  generateProtossFleet(&battleField, protossFleet, initialCapacity);
  statusLogger();

  startBattle(&battleField);
  statusLogger();

  deinit(&battleField);
  statusLogger();

  fclose(logFile_g);
  return EXIT_SUCCESS;
}