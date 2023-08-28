//
// Created by Meqdad on 8/22/2023.
//

#ifndef CLOX_LINES_H
#define CLOX_LINES_H

#include "value.h"
#include "common.h"

typedef struct {
    int capacity;
    int current;
    int *RLE;
} LinesArray;

void initLinesArray(LinesArray *lines);
void writeLine(LinesArray *lines, int line);
int getLine(LinesArray *lines, int offset);
void freeLines(LinesArray* lines);

#endif //CLOX_LINES_H
