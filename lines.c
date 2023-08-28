//
// Created by Meqdad on 8/22/2023.
//

#include "value.h"
#include "chunk.h"
#include "memory.h"
#include "lines.h"

void initLinesArray(LinesArray *lines) {
    lines->capacity = 0;
    lines->current = -2;
    lines->RLE = NULL;
}

void writeLine(LinesArray *lines, int line) {
    if (lines->capacity < lines->current + 1 + 2) {
        int oldCapacity = lines->capacity;
        lines->capacity = GROW_CAPACITY(oldCapacity);
        lines->RLE = GROW_ARRAY(int, lines->RLE, oldCapacity, lines->capacity);
        for (int i = oldCapacity; i < lines->capacity; i++) {
            lines->RLE[i] = -1;
        }
    }

    if (lines->current == -2 || line != lines->RLE[lines->current + 1]) {
        lines->current += 2;
        lines->RLE[lines->current] += 1;
        lines->RLE[lines->current + 1] = line;
    }
    lines->RLE[lines->current] += 1;
}

int getLine(LinesArray *lines, int offset) {
    int index = 0;
    while (offset >= lines->RLE[index]) {
        offset -= lines->RLE[index];
        index += 2;
    }
    return lines->RLE[++index];
}

void freeLines(LinesArray *lines) {
    FREE_ARRAY(int, lines->RLE, lines->capacity);
    initLinesArray(lines);
}