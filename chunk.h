#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"
#include "lines.h"

typedef enum {
    OP_CONSTANT,
    OP_CONSTANT_LONG,
    OP_RETURN,
} OpCode;

typedef struct {
    int capacity;
    int count;
    uint8_t *code;
    Lines lines;
    ValueArray constants;

} Chunk;


void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
void writeConstant(Chunk* chunk, Value value, int line);
int addConstant(Chunk *chunk, Value value);


#endif //CLOX_CHUNK_H
