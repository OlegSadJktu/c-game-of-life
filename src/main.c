#include <stdio.h>
#include "vector.h"


typedef struct SimpleData {
    int first, second, third;
    int *p, *secp;
} SimpleData;

void print_data(SimpleData *data) {
    printf("data => (%i, %i, %i, %p, %p)\n", 
            data->first, data->second, data->third, data->p, data->secp);
}

int main(int argc, char **argv) {
    struct Vector *vec = create_vector(sizeof(SimpleData));

    const int size = 10;
    SimpleData sd = {1,2,3, (int*) 4};

    add_data(vec, &sd);

    return 0;
}
