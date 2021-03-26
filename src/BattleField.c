#include <string.h>
#include <stdio.h>
#include "BattleField.h"
#include "Vector.h"
#include "Ships.h"

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
  vectorInit(&battleField->terranFleet, 1); /*leek-ва*/

  for (int i = 0; i < strlen(terranFleetStr); i++)
  {
    if (terranFleetStr[i] == 'v')
    {
      ShipInit(terranFleetStr[i]);
      vectorPush(&battleField->terranFleet, &Viking);
    }
    if (terranFleetStr[i] == 'b')
    {
      vectorPush(&battleField->terranFleet, &BattleCruiser);
    }
  }

  /*
for (int i = 0; i < strlen(terranFleetStr); i++){
printf ("%s", vectorGet(terranFleet, i);
}
*/
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{

  vectorInit(&battleField->protossFleet, 1); /*leek-ва*/

  for (int i = 0; i < strlen(protossFleetStr); i++)
  {
    ShipInit(protossFleetStr[i]);
    if (protossFleetStr[i] == 'p')

      vectorPush(&battleField->protossFleet, &Phoenix);

    if (protossFleetStr[i] == 'c')
    {
      vectorPush(&battleField->protossFleet, &Carrier);
    }
  }
}

void startBattle(BattleField *battleField)
{
  while (true)
  {
    TakeTurn(&battleField->terranFleet, &battleField->protossFleet);
    Ship *Protoss = vectorGetLast(&battleField->protossFleet);
    printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", vectorGetSize(&battleField->protossFleet)-1, Protoss->health, Protoss->shield);
    if (vectorIsEmpty(&battleField->protossFleet))
    {
      printf("terran wins\n");
      break;
    }

    TakeTurn(&battleField->protossFleet, &battleField->terranFleet);
    Ship *Terran = vectorGetLast(&battleField->terranFleet);
    printf("Last Terran AirShip with ID: %d has %d health\n", vectorGetSize(&battleField->terranFleet)-1, Terran->health);
    if (vectorIsEmpty(&battleField->terranFleet))
    {
      printf("protos wins\n");
      break;
    }
  }
}

void deinit(BattleField *battleField)
{
  vectorFree(&battleField->protossFleet);
  vectorFree(&battleField->terranFleet);
}

bool processTerranTurn(BattleField *battleField)
{
  return false;
}

bool processProtossTurn(BattleField *battleField)
{
  return false;
}
