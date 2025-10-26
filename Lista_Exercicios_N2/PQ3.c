#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <float.h> 

typedef struct Node {
    double value;       
    struct Node *prox;
} Node;

typedef struct Stack {
    Node *topo;
} Stack;


Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memoria para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    stack->topo = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return (stack->topo == NULL);
}

void push(Stack* stack, double value) {
    Node* novo_no = (Node*) malloc(sizeof(Node));
    if (novo_no == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memoria para o no da pilha.\n");
        freeStack(stack); 
        exit(EXIT_FAILURE);
    }
    novo_no->value = value;
    novo_no->prox = stack->topo;
    stack->topo = novo_no;
}

double pop(Stack* stack) {
    if (isEmpty(stack)) {
        return DBL_MAX; 
    }
    
    Node* temp = stack->topo;
    double valor = temp->value;
    stack->topo = temp->prox;
    free(temp);
    
    return valor;
}

void freeStack(Stack* stack) {
    Node* atual = stack->topo;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(stack);
}

double evaluateRPN(char* expression) {
    Stack* stack = createStack();
    
    char* token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            
            double valor = atof(token);
            push(stack, valor); 
        
        } 
        else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            
            double val2 = pop(stack);
            double val1 = pop(stack);

            if (val1 == DBL_MAX || val2 == DBL_MAX) {
                fprintf(stderr, "Erro: Expressao malformada (operandos insuficientes para o operador '%s').\n", token);
                freeStack(stack);
                exit(EXIT_FAILURE);
            }

            double resultado;

            switch (token[0]) {
                case '+':
                    resultado = val1 + val2;
                    break;
                case '-':
                    resultado = val1 - val2; 
                    break;
                case '*':
                    resultado = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        fprintf(stderr, "Erro: Tentativa de divisao por zero.\n");
                        freeStack(stack);
                        exit(EXIT_FAILURE);
                    }
                    resultado = val1 / val2;
                    break;
            }
            push(stack, resultado);
        } else {
            fprintf(stderr, "Erro: Token invalido na expressao: '%s'\n", token);
            freeStack(stack);
            exit(EXIT_FAILURE);
        }
        
        token = strtok(NULL, " "); 
    }

    double resultado_final = pop(stack);

    if (!isEmpty(stack)) {
        fprintf(stderr, "Erro: Expressao malformada (operandos em excesso).\n");
        freeStack(stack);
        exit(EXIT_FAILURE);
    }

    freeStack(stack); 
    return resultado_final;
}


int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Uso: %s \"expressao_rpn\"\n", argv[0]);
        fprintf(stderr, "Exemplo: %s \"5 1 2 + 4 * + 3 -\"\n", argv[0]); 
        return EXIT_FAILURE;
    }

    char* expressao = (char*) malloc(strlen(argv[1]) + 1);
    strcpy(expressao, argv[1]);
    
    double resultado = evaluateRPN(expressao);

    printf("Resultado: %.2f\n", resultado); 

    free(expressao); 
    return EXIT_SUCCESS;
}
