#include "StatusLog.h"
#include "Ships.h"

void statusFileLoad(void){
    functionName_g = NULL;
    functionLine_g = 0;
    functionFile_g = NULL;
    logFile_g = NULL;

    logFile_g = fopen("status.txt", "w");

    if (NULL == logFile_g){
        perror("Could not open error log: ");
    }
}

void setLogVariables(const char *funcName, int lineNumber, char *fileName) {
    functionName_g = funcName;
    functionLine_g = lineNumber;
    functionFile_g = fileName;
}

void statusLogger(void){
    if (NULL == logFile_g){
        return;
    }

    fprintf(logFile_g, "Function: %s at file %s, line %d return \"%s\" -- %d\n", functionName_g, functionFile_g, 
    (functionLine_g - 2), strerror(errno), errno);
}


void checkNullObject(Ship *shipPtr ,const char *funcName, int lineNumber, char *fileName) {
    if (shipPtr == NULL){
        setLogVariables(funcName, lineNumber, fileName);
        
        fprintf(logFile_g, "Function: %s at file %s, line %d - Vector returned NULL object!\n", functionName_g,
        functionFile_g, functionLine_g);

        fclose(logFile_g);

        exit(EFAULT); 
    }
}

void checkNoMemory(Ship *shipPtr ,const char *funcName, int lineNumber, char *fileName) {
    if (NULL == shipPtr){
        setLogVariables(funcName, lineNumber, fileName);

        printf("Protoss ship memory allocation failed !\n");

        fprintf(logFile_g, "Function: %s at file %s, line %d - memory allocation failed!\n", functionName_g,
        functionFile_g, functionLine_g);
        
        fclose(logFile_g);

        exit(ENOMEM);
    }
}

void checkInput(const char *funcName, int lineNumber, char *fileName) {
    setLogVariables(funcName, lineNumber, fileName);

    fprintf(logFile_g, "Function: %s at file %s, line %d - Incorrect ship string input!\n", functionName_g,
    functionFile_g, functionLine_g);
    
    fclose(logFile_g);
    
    exit(EINVAL);
}
