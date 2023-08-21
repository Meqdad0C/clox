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
} Lines;

void initLines(Lines *line);
void writeLine(Lines *lines, int line);
int getLine(Lines *lines, int offset);
void freeLines(Lines* lines);

#endif //CLOX_LINES_H
