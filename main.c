#include "common.h"
#include "chunk.h"
#include "debug.h"

void test_OP_RETURN(Chunk* chunk);
void test_OP_CONSTANT(Chunk* chunk);

int main() {
    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2); // Offset in the Constant Pool
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant,123);

    writeChunk(&chunk, OP_RETURN,123);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}
