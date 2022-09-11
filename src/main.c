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
    SimpleData *sd;
    for (int i = 0; i < size; i++) {
        sd = malloc(sizeof(sd));// {i, i+1, i+2, i+3};
        sd->first = i;
        sd->second = i+1;
        sd->third = i+2;
        sd->p = &(sd->first);
        print_data(sd);

        add_data(vec, sd);
    }
    for (int i = 0; i < size; i++) {
        print_data(get_data(vec, i));
    }
    return 0;

    /* printf("%i\n", vec->dataSize); */
    /* printf("size array => %i  busy array => %i\n", vec->size, vec->busy); */
    for (int i = 0; i < 100; i++) {
        SimpleData *sd = get_data(vec, i);
        printf("%i\n", sd->first);
        /* printf("data => %i %i", sd->first, sd->second); */
    }
    return 0;
}
