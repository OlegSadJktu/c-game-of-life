#include "vector.c"

typedef struct Position {
    int x, y;
} Position;

typedef struct DynamicMCRoot {

    Vector *main;

} DynamicMCRoot;

typedef struct DynamicMatrixCell {
    struct DynamicMatrixCell *left, *right, *top, *bottom;
} DynamicMatrixCell;


