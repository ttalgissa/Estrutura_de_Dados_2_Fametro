#include <stdio.h>
#include <string.h>

void inverterString(char *str) {
    char *inicio = str;
    char *fim = str + strlen(str) - 1;
    while (inicio < fim) {
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover \n do fgets
    str[strcspn(str, "\n")] = '\0';

    inverterString(str);

    printf("Invertida: %s\n", str);
    return 0;
}
