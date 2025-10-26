#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
} Data;

typedef struct {
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data dataAniversario;
} Contato;

typedef struct elemento {
    Contato info;
    struct elemento *prox;
} Elemento;


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Contato ler_contato() {
    Contato c;
    printf("Digite o nome (max 40): ");
    fgets(c.nome, 41, stdin);
    c.nome[strcspn(c.nome, "\n")] = 0;

    printf("Digite o telefone (max 15): ");
    fgets(c.telefone, 16, stdin);
    c.telefone[strcspn(c.telefone, "\n")] = 0;

    printf("Digite o celular (max 15): ");
    fgets(c.celular, 16, stdin);
    c.celular[strcspn(c.celular, "\n")] = 0;

    printf("Digite o email (max 40): ");
    fgets(c.email, 41, stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    printf("Digite a data de aniversario (DD MM): ");
    scanf("%d %d", &c.dataAniversario.dia, &c.dataAniversario.mes);
    limpar_buffer();

    return c;
}

void imprimir_contato(Contato c) {
    printf("----------------------------------------\n");
    printf("Nome: %s\n", c.nome);
    printf("Telefone: %s\n", c.telefone);
    printf("Celular: %s\n", c.celular);
    printf("Email: %s\n", c.email);
    printf("Aniversario: %02d/%02d\n", c.dataAniversario.dia, c.dataAniversario.mes);
    printf("----------------------------------------\n");
}

Elemento* cria_agenda() {
    return NULL;
}

Elemento* insere_contato(Elemento *lista, Contato c) {
    Elemento *novo_no = (Elemento*) malloc(sizeof(Elemento));
    if (novo_no == NULL) {
        printf("Erro: Nao foi possivel alocar memoria.\n");
        return lista;
    }
    novo_no->info = c;
    novo_no->prox = NULL;

    if (lista == NULL) {
        return novo_no;
    }

    Elemento *aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo_no;
    return lista;
}

void lista_contatos(Elemento *lista) {
    if (lista == NULL) {
        printf("Agenda vazia.\n");
        return;
    }
    
    printf("\n--- Lista de Contatos ---\n");
    Elemento *aux = lista;
    while (aux != NULL) {
        imprimir_contato(aux->info);
        aux = aux->prox;
    }
}

Elemento* busca_contato(Elemento *lista, char* nome) {
    Elemento *aux = lista;
    while (aux != NULL) {
        if (strcmp(aux->info.nome, nome) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

Elemento* remove_contato(Elemento *lista, char* nome) {
    Elemento* anterior = NULL;
    Elemento* atual = lista;

    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato '%s' nao encontrado.\n", nome);
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } 
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Contato '%s' removido com sucesso.\n", nome);
    return lista;
}

void atualiza_contato(Elemento *lista, char* nome) {
    Elemento *encontrado = busca_contato(lista, nome);

    if (encontrado == NULL) {
        printf("Contato '%s' nao encontrado.\n", nome);
        return;
    }

    printf("Contato encontrado. Insira os novos dados:\n");
    encontrado->info = ler_contato();
    
    printf("Contato '%s' atualizado com sucesso.\n", nome);
}

Elemento* remove_duplicados(Elemento* lista) {
    if (lista == NULL) return NULL;

    int duplicados_removidos = 0;
    Elemento *atual = lista;

    while (atual != NULL) {
        Elemento *anterior_verificador = atual;
        Elemento *verificador = atual->prox;
        char *nome_atual = atual->info.nome;

        while (verificador != NULL) {
            if (strcmp(nome_atual, verificador->info.nome) == 0) {
                Elemento *no_para_liberar = verificador;
                anterior_verificador->prox = verificador->prox;
                verificador = verificador->prox; 
                free(no_para_liberar);
                duplicados_removidos++;
            } else {
                anterior_verificador = verificador;
                verificador = verificador->prox;
            }
        }
        atual = atual->prox; 
    }
    
    if (duplicados_removidos > 0) {
         printf("%d duplicado(s) removido(s).\n", duplicados_removidos);
    } else {
         printf("Nenhum duplicado encontrado.\n");
    }

    return lista;
}


Elemento* libera_agenda(Elemento *lista) {
    Elemento *aux = lista;
    while (aux != NULL) {
        Elemento *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    printf("Agenda liberada.\n");
    return NULL;
}


int main() {
    Elemento *minha_agenda = cria_agenda();
    int opcao = 0;
    char nome_busca[41];

    do {
        printf("\n--- Menu Agenda ---\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Remover Duplicados\n"); 
        printf("7. Sair\n");               
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch(opcao) {
            case 1:
                printf("\n[Inserir Contato]\n");
                Contato novo = ler_contato();
                minha_agenda = insere_contato(minha_agenda, novo);
                printf("Contato inserido com sucesso!\n");
                break;
            case 2:
                printf("\n[Listar Contatos]\n");
                lista_contatos(minha_agenda);
                break;
            case 3:
                printf("\n[Buscar Contato]\n");
                printf("Digite o nome para busca: ");
                fgets(nome_busca, 41, stdin);
                nome_busca[strcspn(nome_busca, "\n")] = 0;
                
                Elemento *encontrado = busca_contato(minha_agenda, nome_busca);
                if (encontrado != NULL) {
                    printf("Contato encontrado:\n");
                    imprimir_contato(encontrado->info);
                } else {
                    printf("Contato '%s' nao encontrado.\n", nome_busca);
                }
                break;
            case 4:
                printf("\n[Editar Contato]\n");
                printf("Digite o nome do contato a editar: ");
                fgets(nome_busca, 41, stdin);
                nome_busca[strcspn(nome_busca, "\n")] = 0;
                atualiza_contato(minha_agenda, nome_busca);
                break;
            case 5:
                printf("\n[Remover Contato]\n");
                printf("Digite o nome do contato a remover: ");
                fgets(nome_busca, 41, stdin);
                nome_busca[strcspn(nome_busca, "\n")] = 0;
                minha_agenda = remove_contato(minha_agenda, nome_busca);
                break;
            case 6: 
                printf("\n[Remover Duplicados]\n");
                minha_agenda = remove_duplicados(minha_agenda);
                break;
            case 7: 
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7); 

    minha_agenda = libera_agenda(minha_agenda);

    return 0;
}
