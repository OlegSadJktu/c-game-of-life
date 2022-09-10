#include <stdlib.h>
#include <string.h>

static const int EXPAND = 2;

typedef struct Vector {
    int size;
    int busy;
    void **data;
} Vector;

static void realocate_data(Vector *vec) {
    if (vec->busy != vec->size) {
        exit(1);
    }
    int newSize = vec->size * EXPAND * sizeof(*(vec->data));
    void *oldData = vec->data;
    vec->data = realloc(vec->data, newSize);
    vec->size *= EXPAND;
    free(oldData);
}

void add_data(Vector *vec, void *data) {

}

void 

Vector *create_vector() {
    Vector *vec = malloc(sizeof(Vector));
    int size = 8;
    vec->size = size;
    vec->busy = 0;
}
