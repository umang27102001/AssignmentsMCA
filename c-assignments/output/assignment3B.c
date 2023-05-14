#include <stdio.h>

int main() {
    int a = 10;
    float b = 2.5;
    char c = 'a';

    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %c\n", c);

    int sum = a + c;
    float product = a * b;
    char ans = a + 'A';

    printf("sum = %d\n", sum);
    printf("product = %f\n", product);
    printf("result = %c\n", ans);

    return 0;
}