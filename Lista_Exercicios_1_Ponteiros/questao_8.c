#include <stdio.h>

void calcular(float a, float b, float *soma, float *sub, float *mult, float *div) {
    *soma = a + b;
    *sub = a - b;
    *mult = a * b;
    if (b != 0) *div = a / b;
    else *div = 0;
}

int main() {
    float x, y;
    printf("Digite dois numeros: ");
    scanf("%f %f", &x, &y);

    float soma, sub, mult, div;
    calcular(x, y, &soma, &sub, &mult, &div);

    printf("Soma: %.2f\nSubtracao: %.2f\nMultiplicacao: %.2f\nDivisao: %.2f\n",
           soma, sub, mult, div);

    return 0;
}
