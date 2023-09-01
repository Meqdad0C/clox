#include "memory.h"
#include "chunk.h"
#include "value.h"
#include "lines.h"

void initChunk(Chunk *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
    initLinesArray(&chunk->lines);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    writeLine(&chunk->lines, line);
    chunk->code[chunk->count] = byte;
    chunk->count++;
}

void writeConstant(Chunk *chunk, int index, int line) {
    if (index <= 0xFF) {
        writeChunk(chunk, OP_CONSTANT, line);
        writeChunk(chunk, index, line);
        return;
    }
    writeChunk(chunk, OP_CONSTANT_LONG, line);
    writeChunk(chunk, (uint8_t) (index & 0xFF), line);
    writeChunk(chunk, (uint8_t) ((index >> 8) & 0xFF), line);
    writeChunk(chunk, (uint8_t) ((index >> 16) & 0xFF), line);
}


int addConstant(Chunk *chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}

void freeChunk(Chunk *chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeLines(&chunk->lines);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

