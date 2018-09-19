#include <stdio.h>
#include <malloc.h>

int mat_print(float **matrix, int str, int stb) {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stb; j++)
            printf("%f ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}

float** mat_trnsp(float **matrix, int str, int stb){
    float **matrix_t = malloc(stb * sizeof(float *));
    for (int i = 0; i < stb; i++) {
        matrix_t[i] = malloc(str * sizeof(float));
    }

    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stb; j++)
            matrix_t[j][i] = matrix[i][j];
    }
//    mat_print(matrix_t, stb, str);
//    printf("\n");
    return matrix_t;
}

int main() {
    int stb, str;
    scanf("%d%d", &stb, &str);
    float **matrix = malloc(str * sizeof(float *));
    for (int i = 0; i < str; i++) {
        matrix[i] = malloc(stb * sizeof(float));
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stb; j++)
            scanf("%f", &matrix[i][j]);
    }
    mat_print(matrix, str, stb);
    printf("\n");
    float ** matrix_t = mat_trnsp(matrix, str, stb);
    int str_t = stb, stb_t = str;
    mat_print(matrix_t, str_t, stb_t);
    printf("\n");
    //printf("Hello, World!\n");
    for (int i = 0; i < str; i++) {
        free(matrix[i]);
    }
    for (int i = 0; i < str_t; i++) {
        free(matrix_t[i]);
    }
    free(matrix);
    free(matrix_t);
    return 0;
}