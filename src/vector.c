#include <stdlib.h>
#include <string.h>

static const int EXPAND = 2;



static struct Vector {
    int size;
    int busy;
    int dataSize;
    void **data;
} Vector;

struct VectorWrapper {
    struct Vector *vector;
};

static void realocate_data(struct Vector *vec) {
    if (vec->busy != vec->size) {
        exit(1);
    }
    int newSize = vec->size * EXPAND * vec->dataSize;
    vec->data = realloc(vec->data, newSize);
    vec->size *= EXPAND;
}

void *get_data(struct Vector *vec, int pos) {
    if (pos < vec->busy) {
        return vec->data[pos];
    }
    exit(1);
}

void add_data(struct Vector *vec, void *data) {
    if (vec->size == vec->busy) {
        realocate_data(vec);
    }
    vec->data[vec->busy] = data;
    vec->busy += 1;
}

void set_value(struct Vector *vec, void *data, int pos) {
    void *d = vec->data[pos];
    if (d == NULL && data == NULL) {
        return;
    }
    if (d != NULL) {
        vec->busy++;
    }
    if (data == NULL) {
        vec->busy--;
    }
    vec->data[pos] = data;

}

struct Vector *create_vector(const int dataSize) {
    struct Vector *vec = malloc(sizeof(struct Vector));
    int size = 8;
    vec->size = size;
    vec->busy = 0;
    vec->dataSize = dataSize;
    vec->data = calloc(size, dataSize);
    return vec;
}
