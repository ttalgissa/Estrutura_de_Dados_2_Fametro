#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);

    troca(&x, &y);

    printf("Valores trocados: x = %d, y = %d\n", x, y);
    return 0;
}
