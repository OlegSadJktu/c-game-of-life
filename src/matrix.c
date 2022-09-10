#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct someStruct someStruct;

typedef struct MatrixCell {
    struct MatrixCell *left, *right, *top, *bottom;
    void *data;

} MatrixCell;

typedef struct MatrixColumn {
    MatrixCell *first, *last;
} MatrixColumn;

typedef struct MatrixRow {
    MatrixCell *first, *last;
} MatrixRow;

typedef struct Matrix {
    int size;
    MatrixRow **rows;
    MatrixColumn **cols;
} Matrix;

Matrix *create_matrix(int a) {
    return NULL;
}

