#include <stdio.h>
#include <stdlib.h>

char ValidateEntry(){
    char ShipCode = 'a';
    while (scanf("%c", &ShipCode)!=1){
        printf("Please enter a numerical value. Letters and special characters are not accepted.\n");
        printf("Float numbers are trunkated to integers.\n");
        fflush(stdin);
    }
    fflush(stdin);
    return ShipCode;
}