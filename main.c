#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"


void write256Constant(Chunk *chunk) {
    for (int i = 0; i <= 256; ++i) {
        writeConstant(chunk, 100 + i, 123);
    }
}


int main() {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    writeConstant(&chunk, 1.2, 123);
    writeConstant(&chunk, 3.4, 123);
    writeChunk(&chunk, OP_ADD, 123);

    writeConstant(&chunk, 5.6, 123);

    writeChunk(&chunk, OP_DIVIDE, 123);
    writeChunk(&chunk, OP_NEGATE, 123);

//    write256Constant(&chunk);

    writeChunk(&chunk, OP_RETURN, 123);
    printLines(&chunk.lines);

    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}

