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
    if (protossFleetStr[i] == 'p')

      vectorPush(&battleField->protossFleet, &Phoenix);

    if (protossFleetStr[i] == 'c')
    {
      vectorPush(&battleField->protossFleet, &Carrier);
    }
  }
}

/*void startBattle(BattleField *battleField)
{
  while (true)
  {
    if (processTerranTurn(battleField))
    {
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField))
    {
      printf("PROTOSS has won!\n");
      break;
    }
  }
}*/

/*void deinit(BattleField *battleField)
{
}

bool processTerranTurn(BattleField *battleField)
{
  return false;
}

bool processProtossTurn(BattleField *battleField)
{
  return false;
}*/
