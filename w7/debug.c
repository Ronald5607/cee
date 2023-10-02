#include <stdarg.h>
#include <stdio.h>


int GLOBAL_DEBUG_LEVEL = 0;

void set_debug_level(int debug_level) {
    GLOBAL_DEBUG_LEVEL = debug_level;
}

int dprintf(int debug_level, const char *fmt, ...) {
    int count = 0;
    if (debug_level <= GLOBAL_DEBUG_LEVEL) {
        va_list args;
        va_start(args, fmt);

        count += fprintf(stderr, "DBG%d ", debug_level);
        count += vfprintf(stderr, fmt, args);
        va_end(args);
    }
    return count;
}