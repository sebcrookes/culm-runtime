#include <stdio.h>

#include <stdint.h>

#include "memspace.h"
#include "runtime.h"

/**
 * This main function is only used when running the runtime as a
 * standalone executable, and not when used as a library.
 */
int main(void) {

    /* === Reading in the .culm file === */

    FILE* file = fopen("test.culm", "r");

    if (file == NULL) {
        perror("Error opening code file");
        return 1;
    }

    // Getting the size of the file

    fseek(file, 0, SEEK_END);

    uint64_t size = ftell(file);

    fseek(file, 0, SEEK_SET);

    uint8_t* memory = memspace_init(size, 0, 0);

    fread((void*) memory, 1, size, file);

    fclose(file);

    runtime_state_t* runtime = runtime_init(memory, size, 0, 0);

    runtime_step(runtime);

    runtime_step(runtime);
    
    return 0;
}
