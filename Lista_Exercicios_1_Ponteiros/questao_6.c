#include <stdio.h>
#include <ctype.h>

int ehVogal(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

void contarVogaisConsoantes(char *str, int *vogais, int *consoantes) {
    *vogais = *consoantes = 0;
    while (*str != '\0') {
        if (isalpha(*str)) {
            if (ehVogal(*str)) (*vogais)++;
            else (*consoantes)++;
        }
        str++;
    }
}

int main() {
    char str[200];
    printf("Digite uma frase: ");
    fgets(str, sizeof(str), stdin);

    int v, c;
    contarVogaisConsoantes(str, &v, &c);

    printf("Vogais: %d, Consoantes: %d\n", v, c);
    return 0;
}
