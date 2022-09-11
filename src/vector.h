#include "./vector.c"

struct Vector;

static void realocate_data(Vector *vec);

void *get_data(Vector *vec, int pos);

void add_data(Vector *vec, void *data);

Vector *create_vector(const int dataSize);
