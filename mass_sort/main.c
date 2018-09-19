#include <stdio.h>
#include <malloc.h>

int main() {
    int i;
    scanf("%d", &i);
    float *xx = malloc(i * sizeof(float));
    int test = 1;
    float save;
    for (int j = 0; j < i; j++)
        scanf("%f", &xx[j]);
    while (test != 0) {
        test = 0;
        for (int j = 0; j < i - 1; j++) {
            if (xx[j] > xx[j + 1]) {
                save = xx[j];
                xx[j] = xx[j + 1];
                xx[j + 1] = save;
                test++;
            }
        }
    }
    for (int j = 0; j < i; j++)
        printf("%f ", xx[j]);
    free(xx);
    printf("\n");
    printf("Hello, World!\n");
    return 0;
}