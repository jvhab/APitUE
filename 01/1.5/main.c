#include <stdio.h>

int main() {
    const int num_32 = 2147483647;
    float result = (num_32 / 100) / (60 * 60 * 24);
    printf("Result: %f days", result);
    return 0;
}