#include <stdio.h>

typedef struct dot {
    float x;
    float y;
} dot;

float test_dot(dot d1, dot d2, dot dd) {
    float x = (d1.x - dd.x) * (d2.y - d1.y) - (d2.x - d1.x) * (d1.y - dd.y);
    return x;
}

int main() {
    dot d1, d2, d3, dd;
    scanf("%f%f", &d1.x, &d1.y);
    scanf("%f%f", &d2.x, &d2.y);
    scanf("%f%f", &d3.x, &d3.y);
    scanf("%f%f", &dd.x, &dd.y);
    int yesno = 0;
   //printf("%f\n", test_dot(d1, d2, d3));
    if(test_dot(d1, d2, dd)>0 && test_dot(d2, d3, dd)>0 && test_dot(d3, d1, dd)>0)
        yesno = 1;
    else if(test_dot(d1, d2, dd)<0 && test_dot(d2, d3, dd)<0 && test_dot(d3, d1, dd)<0)
        yesno = 1;
    else yesno = 0;
    if (yesno)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}