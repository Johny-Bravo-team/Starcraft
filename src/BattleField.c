#include <string.h>
#include <stdio.h>
#include "BattleField.h"
#include "Vector.h"
#include "Ships.h"
#include "GameTurn.h"

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
  vectorInit(&battleField->terranFleet, 1); //change the one to variable

  for (size_t i = 0; i < strlen(terranFleetStr); i++)
  {
    vectorPush(&battleField->terranFleet, ShipInitTerran(terranFleetStr[i]));
  }
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{

  vectorInit(&battleField->protossFleet, 1); /*leek-ва*/

  for (size_t i = 0; i < strlen(protossFleetStr); i++)
  {
    vectorPush(&battleField->protossFleet, ShipInitProtoss(protossFleetStr[i]));
  }
}

void startBattle(BattleField *battleField)
{
  int TurnCounter = 1;
  while (true)
  {
    TakeTurn(&battleField->terranFleet, &battleField->protossFleet, TurnCounter);
    Ship *Protoss = vectorGetLast(&battleField->protossFleet);
    if (vectorIsEmpty(&battleField->protossFleet))
    {
      printf("TERRAN has won!\n");
      break;
    }
    printf("Last Protoss AirShip with ID: %ld has %d health and %d shield left\n", vectorGetSize(&battleField->protossFleet) - 1, Protoss->health, Protoss->shield);

    TakeTurn(&battleField->protossFleet, &battleField->terranFleet, TurnCounter);
    Ship *Terran = vectorGetLast(&battleField->terranFleet);
    if (vectorIsEmpty(&battleField->terranFleet))
    {
      printf("PROTOSS has won!\n");
      break;
    }
    printf("Last Terran AirShip with ID: %ld has %d health left\n", vectorGetSize(&battleField->terranFleet) - 1, Terran->health);

    TurnCounter++;
  }
}

void deinit(BattleField *battleField)
{
  vectorFree(&battleField->protossFleet);
  vectorFree(&battleField->terranFleet);
}
