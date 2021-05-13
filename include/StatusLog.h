#ifndef STATUSLOG_H
#define STATUSLOG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "Ships.h"

const char* functionName_g;
int  functionLine_g;
char* functionFile_g;
FILE* logFile_g;

void statusFileLoad(void);
void setLogVariables(const char *funcName, int lineNumber, char *fileName);
void statusLogger(void);
void checkNullObject(void *obj ,const char *funcName, int lineNumber, char *fileName);
void checkNoMemory(void *obj ,const char *funcName, int lineNumber, char *fileName);
void wrongInput(const char *funcName, int lineNumber, char *fileName);

#endif /* STATUSLOG_H */