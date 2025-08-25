#include <stdio.h>

int main() {
    int x = 42;
    int *p = &x;

    printf("Valor da variavel x: %d\n", x);
    printf("Endereco da variavel x: %p\n", (void*)&x);
    printf("Valor do ponteiro p (endereco): %p\n", (void*)p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;
}
