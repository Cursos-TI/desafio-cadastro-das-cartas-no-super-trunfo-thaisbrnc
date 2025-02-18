#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países

//declaraçao das variaveis
typedef struct carta
{
    char codigo[4];
    char estado[25];
    char cidade[25];
    unsigned int populacao;
    float area;
    double pib;
    int qtdePontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

//declaração do nó para salvar as cartas
typedef struct node{
    Carta *carta;
    struct node* prox;
} Node;

char opcao = 'S';
char letra = 65;
int num = 1;
char cod[4] = "";
Node *head = NULL;

//declaração dos metodos
float calcularDensidadePopulacional(unsigned int pop, float area);
float calcularPibPerCapita(double pib, unsigned int pop);
void exibirCarta(Carta *carta);
Node *inserirNaLista(Carta *carta);
void imprimirLista(void);

//gera codigo das cartas
char* gerarCodigo(void){
    if(num == 5){
        letra++;
        num = 1;
    }
    /*if(letra == 73){
        return 0;
    }*/
    cod[0] = letra;
    cod[1] = '0';
    cod[2] = num + '0';
    cod[3] = '\0';

    num++;

    return cod;
}

//inicializa atributos de carta
int construtor(Carta *carta) {
    if(carta == NULL)     
        return 0;

    char *cods = gerarCodigo();
    /*if(strcmp(cods, 'I')){
        printf("\nCods %s", cods);
        printf("\nTodas as cartas já foram registradas.\n");
        return 0;
    }*/

    strcpy(carta->codigo, cods);
    bzero(carta->estado, 25);
    bzero(carta->cidade, 25);
    carta->populacao = 0;
    carta->area = 0.0;
    carta->pib = 0.0;
    carta->qtdePontosTuristicos = 0;
    carta->densidadePopulacional = 0;
    carta->pibPerCapita = 0;
    return 1;
}

float calcularDensidadePopulacional(unsigned int pop, float area){
    return (float) pop / area;
}

float calcularPibPerCapita(double pib, unsigned int pop){
    return (float) pib / pop;
}

//solicita e armazena os dados
int cadastrarCarta(Carta *carta){
    if (construtor(carta) == 0)
        return 0;

    //printf("\nInforme o código (Formato A01): ");
    //scanf(" %[^\n]", carta->codigo); 
    printf("\nInforme o Estado: ");
    scanf(" %[^\n]", carta->estado); //lê caracteres enquanto nao forem quebra de linha
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);
    printf("Informe o número da população: ");
    scanf(" %u", &carta->populacao);
    printf("Informe a área em km²: ");
    scanf(" %f", &carta->area);
    printf("Informe o PIB: ");
    scanf(" %lf", &carta->pib);
    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d", &carta->qtdePontosTuristicos);
    carta->densidadePopulacional = calcularDensidadePopulacional(carta->populacao, carta->area);
    carta->pibPerCapita = calcularPibPerCapita(carta->pib, carta->populacao);
}

// Exibição dos Dados das Cartas:
void exibirCarta(Carta *carta){
    printf("\n------------------------------------------------\n");
    printf("Código: %s\n", carta->codigo);
    printf("Estado: %s\n", carta->estado);
    printf("Nome: %s\n", carta->cidade);
    printf("População: %u\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: R$ %.2lf\n", carta->pib);
    printf("Quantidade de pontos turísticos: %d\n", carta->qtdePontosTuristicos);
    printf("Densidade Populacional: %.2f pessoas/km²\n", carta->densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta->pibPerCapita);
    printf("------------------------------------------------\n");
}

Node *inserirNaLista(Carta *carta)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp != NULL){
        temp->carta = carta;
        temp->prox = head;
        head = temp;
        printf("\nCarta cadastrada com sucesso:");
        return head;
    }
    else{
        printf("\nNão foi possível cadastrar a carta. Tente novamente.");
    }
    free(temp);
}

void imprimirLista(void)
{
    printf("\nListando todas as cartas: ");
    Node *temp = head;
    while (temp != NULL)
    {
        exibirCarta(temp->carta);
        temp = temp->prox;
    }
    
    /*
    for (Node *atual = head; atual != NULL; atual = atual->prox)
    {
        printf("\nHead Atual: %s", atual->carta->cidade);
        exibirCarta(atual->carta);
    }
    */

    /*
    Node *temp;
    temp = lista->prox;
 
    while(temp != NULL){
        exibirCarta(temp->carta);
        temp = temp->prox;
    }
    */
}

void exibirCarta1(Carta *carta1){
    printf("\nCarta 1: Código: %s", carta1->codigo);
    printf(" - Estado: %s", carta1->estado);
    printf(" - Cidade: %s", carta1->cidade);
}

void exibirCarta2(Carta *carta2){
    printf("\nCarta 2: Código: %s", carta2->codigo);
    printf(" - Estado: %s", carta2->estado);
    printf(" - Cidade: %s", carta2->cidade);
}

void compararCartas(void){
    char cod1[4] = "", cod2[4] = "";
    opcao = 0;

    printf("\n1. Informe o código da primeira carta a ser comparada: ");
    scanf(" %[^\n]", cod1);
    printf("\n2. Informe o código da segunda carta a ser comparada: ");
    scanf(" %[^\n]", cod2);
    printf("\n3. Selecione a propriedade que deseja comparar: ");
    printf("\na. População\nb. Área\nc. PIB\nd. Número de pontos turísticos\ne. Densidade populacional\nf. PIB per capita");
    printf("\nOpção: ");
    scanf(" %c", &opcao);

    Carta *carta1 = (Carta *) malloc(sizeof(Carta));
    Carta *carta2 = (Carta *) malloc(sizeof(Carta));

    //fazer busca das cartas na lista
    for (Node *atual = head; atual != NULL; atual = atual->prox)
    {
        printf("\nCarta atual cod: %s", atual->carta->codigo);

        int sucesso1 = 1, sucesso2 = 1;
        for(int i = 0; i < 4; i++){
            if(atual->carta->codigo[i] != cod1[i]){
                sucesso1 = 0;
                break;
            }
        }
        for(int i = 0; i < 4; i++){
            if(atual->carta->codigo[i] != cod2[i]){
                sucesso2 = 0;
                break;
            }
        }
        if(sucesso1 == 1){
            printf("\nCarta 1 recebe carta atual");
            carta1 = atual->carta;
        }
        if(sucesso2 == 1){
            printf("\nCarta 2 recebe carta atual\n");
            carta2 = atual->carta;
        }
    }
    
    //comparar conforme opçao de propriedade escolhida
    switch(opcao){
        case 'a':
            exibirCarta1(carta1);
            printf(" - População: %u", carta1->populacao);
            exibirCarta2(carta2);
            printf(" - População: %u", carta2->populacao);

            if(carta1->populacao > carta2->populacao){
                printf("\n***********************************************************");
                printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
            }
            if(carta1->populacao < carta2->populacao){
                printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
            }
            if(carta1->populacao == carta2->populacao){
                printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
            }

            break;
        case 'b':
            exibirCarta1(carta1);
            printf(" - Área: %.2f", carta1->area);
            printf(" km²");
            exibirCarta2(carta2);
            printf(" - Área: %.2f", carta2->area);
            printf(" km²");

            if(carta1->area > carta2->area){
                printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
            }
            if(carta1->area < carta2->area){
                printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
            }
            if(carta1->area == carta2->area){
                printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
            }

            break;
        case 'c':
            exibirCarta1(carta1);
            printf(" - PIB: R$ %.2lf", carta1->pib);
            exibirCarta2(carta2);
            printf(" - PIB: R$ %.2lf", carta2->pib);

            if(carta1->pib > carta2->pib){
                printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
            }
            if(carta1->pib < carta2->pib){
                printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
            }
            if(carta1->pib == carta2->pib){
                printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
            }

            break;  
        case 'd':
            exibirCarta1(carta1);
            printf(" - Número de pontos turísticos: %d", carta1->qtdePontosTuristicos);
            exibirCarta2(carta2);
            printf(" - Número de pontos turísticos: %d", carta2->qtdePontosTuristicos);
            
            if(carta1->qtdePontosTuristicos > carta2->qtdePontosTuristicos){
                printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
            }
            if(carta1->qtdePontosTuristicos < carta2->qtdePontosTuristicos){
                printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
            }
            if(carta1->qtdePontosTuristicos == carta2->qtdePontosTuristicos){
                printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
            }

            break;
        case 'e':
            exibirCarta1(carta1);
            printf(" - Densidade populacional: %.2f", carta1->densidadePopulacional);
            printf(" pessoas/km²");
            exibirCarta2(carta2);
            printf(" - Densidade populacional: %.2f", carta2->densidadePopulacional);
            printf(" pessoas/km²");

            if(carta1->densidadePopulacional < carta2->densidadePopulacional){
                printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
            }
            if(carta1->densidadePopulacional > carta2->densidadePopulacional){
                printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
            }
            if(carta1->densidadePopulacional == carta2->densidadePopulacional){
                printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
            }

            break;
        case 'f':
            exibirCarta1(carta1);
            printf(" - PIB per capita: R$ %.2f", carta1->pibPerCapita);
            exibirCarta2(carta2);
            printf(" - PIB per capita: R$ %.2f", carta2->pibPerCapita);

            if(carta1->pibPerCapita > carta2->pibPerCapita){
                printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
            }
            if(carta1->pibPerCapita < carta2->pibPerCapita){
                printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
            }
            if(carta1->pibPerCapita == carta2->pibPerCapita){
                printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
            }

            break;
        default:
            printf("\n\nOpção inválida.\n");
    }

    //limpa variaveis utilizadas na comparaçao
    bzero(cod1, 4);
    bzero(cod2, 4);
    carta1 = NULL;
    carta2 = NULL;
}

int cadastrarDadosIniciais(Carta *carta, Node *novoNode){
    if (construtor(carta) == 0)
        return 0;

    strcpy(carta->estado, "Paraná");
    strcpy(carta->cidade, "Cascavel");
    carta->populacao = 320000;
    carta->area = 140;
    carta->pib = 1100200300;
    carta->qtdePontosTuristicos = 12;
    carta->densidadePopulacional = calcularDensidadePopulacional(320000, 140);
    carta->pibPerCapita = calcularPibPerCapita(1100200300, 320000);
    novoNode = inserirNaLista(carta);
    //exibirCarta(novoNode->carta);
    
    if (construtor(carta) == 0)
        return 0;

    strcpy(carta->estado, "Santa Catarina");
    strcpy(carta->cidade, "Chapecó");
    carta->populacao = 350000;
    carta->area = 160;
    carta->pib = 2100200300;
    carta->qtdePontosTuristicos = 16;
    carta->densidadePopulacional = calcularDensidadePopulacional(350000, 160);
    carta->pibPerCapita = calcularPibPerCapita(2100200300, 350000);
    novoNode = inserirNaLista(carta);
    //exibirCarta(novoNode->carta);

    if (construtor(carta) == 0)
        return 0;

    strcpy(carta->estado, "Paraná");
    strcpy(carta->cidade, "Toledo");
    carta->populacao = 150000;
    carta->area = 120;
    carta->pib = 1200300400;
    carta->qtdePontosTuristicos = 10;
    carta->densidadePopulacional = calcularDensidadePopulacional(150000, 120);
    carta->pibPerCapita = calcularPibPerCapita(1200300400, 150000);
    novoNode = inserirNaLista(carta);
    //exibirCarta(novoNode->carta);
}

int main() {
    char opc = '0';
    Node *novoNode = (Node *) malloc(sizeof(Node));
    Carta *carta = (Carta *) malloc(sizeof(Carta));

    cadastrarDadosIniciais(carta, novoNode);
    
    imprimirLista();

    printf("\n***********************************************************");
    printf("\n                Bem vindo ao Super Trunfo!                 ");
    printf("\n***********************************************************\n");
    printf("\nSelecione uma opção: \n1. Cadastrar cartas\n2. Jogar\n3. Sair");
    printf("\nOpção: ");
    scanf(" %c", &opc);

    switch (opc)
    {
        case '1':
            printf("\n***********************************************************");
            printf("\n                    Cadastro das cartas                    \n");

            //cadastra a carta
            if(cadastrarCarta(carta) != 0){
                do{
                    //insere o nó na lista encadeada
                    novoNode = inserirNaLista(carta);
                    //se o node não for nulo exibe a carta cadastrada
                    if(novoNode != NULL){
                        exibirCarta(novoNode->carta);
                    }

                    printf("\nCadastrar nova carta? (Digite 'S' para Sim e 'N' para Não): ");
                    scanf(" %c", &opcao);
                } while(opcao == 'S' || opcao == 's');
            }
            //voltar ao menu principal
            

            break;

        case '2':
            printf("\n***********************************************************");
            printf("\n                   Vamos iniciar o jogo!                   \n");

            do{
                //solicita dados, compara as cartas e exibe o resultado
                compararCartas();

                printf("\nJogar novamente? (Digite 'S' para Sim e 'N' para Não): ");
                scanf(" %c", &opcao);
            } while(opcao == 'S' || opcao == 's');

            break;

        case '3':
            printf("Encerrando o jogo...");

            break;
    
        default:
            break;
    }
    
    //libera o espaço alocado para o nó
    free(novoNode);

    return 0;
}