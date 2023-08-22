#include "common.h"
#include "chunk.h"
#include "debug.h"



int main() {
    Chunk chunk;
    initChunk(&chunk);

    for (int i = 0; i <= 256; ++i) {
        writeConstant(&chunk, 1.2, 123);
    }
    writeChunk(&chunk, OP_RETURN, 123);

    printLines(&chunk.lines);
    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}

