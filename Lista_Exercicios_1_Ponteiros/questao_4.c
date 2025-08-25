#include <stdio.h>

void dobrar(int *num) {
    *num = *num * 2;
}

int main() {
    int x;
    printf("Digite um numero: ");
    scanf("%d", &x);

    dobrar(&x);

    printf("Dobro: %d\n", x);
    return 0;
}
