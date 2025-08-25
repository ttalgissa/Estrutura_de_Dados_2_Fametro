# Respostas – Questões Teóricas (Ponteiros em C)

## Questão 1
Qual das seguintes afirmações sobre ponteiros em C é VERDADEIRA?  

**Resposta:** b) Um ponteiro armazena o endereço de memória de uma variável.  

---

## Questão 2
O que o operador `*` (asterisco) faz quando usado na frente de uma variável do tipo ponteiro que já foi inicializada?  

**Resposta:** d) Acessa (dereferencia) o valor armazenado no endereço de memória para o qual o ponteiro aponta.  

---

## Questão 3
Para que serve a função `malloc()` da biblioteca `<stdlib.h>`?  

**Resposta:** c) Para alocar um bloco de memória de um tamanho especificado em bytes e retornar um ponteiro para o início desse bloco.  

---

## Questão 4
Considere a função `void modifica(int *a, int b)` que altera o valor da variável para a qual `a` aponta.  
Como seria a chamada correta desta função na `main` para modificar uma variável `int num = 5;`?  

```c
int num = 5;
modifica(&num, num);
