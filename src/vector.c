#include <stdlib.h>
#include <string.h>

static const int EXPAND = 2;

typedef struct Vector {
    int size;
    int busy;
    int dataSize;
    void **data;
} Vector;

static void realocate_data(Vector *vec) {
    if (vec->busy != vec->size) {
        exit(1);
    }
    int newSize = vec->size * EXPAND * vec->dataSize;
    vec->data = realloc(vec->data, newSize);
    vec->size *= EXPAND;
}

void *get_data(Vector *vec, int pos) {
    if (pos < vec->busy) {
        return vec->data[pos];
    }
    exit(1);
}

void add_data(Vector *vec, void *data) {
    if (vec->size == vec->busy) {
        realocate_data(vec);
    }
    vec->data[vec->busy] = data;
    vec->busy += 1;
}

Vector *create_vector(const int dataSize) {
    Vector *vec = malloc(sizeof(Vector));
    int size = 8;
    vec->size = size;
    vec->busy = 0;
    vec->dataSize = dataSize;
    vec->data = calloc(size, dataSize);
    return vec;
}
