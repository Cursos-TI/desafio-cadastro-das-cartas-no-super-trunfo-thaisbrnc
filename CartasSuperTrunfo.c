#include <stdio.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

//declaraçao das variaveis
char opcao = 'S';
typedef struct carta
{
    char estado[25];
    char codigo[4];
    char cidade[25];
    unsigned int populacao;
    float area;
    double pib;
    int qtdePontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} TClasse;

//declaração do nó para salvar as cartas
typedef struct node {
    TClasse carta;
    struct node* prox;
} Node;

//declaração dos metodos para calcular densidade populacional, pib per capita e exibir carta
float calcularDensidadePopulacional(unsigned int pop, float area);
float calcularPibPerCapita(double pib, unsigned int pop);
int exibirCarta(TClasse carta);

//inicializa atributos
int construtor(TClasse *carta) {
    if(carta == NULL)     
        return 0;
 
    carta->estado[25] = *"";
    carta->codigo[4] = *"";
    carta->cidade[25] = *"";
    carta->populacao = 0;
    carta->area = 0.0;
    carta->pib = 0.0;
    carta->qtdePontosTuristicos = 0;
    carta->densidadePopulacional = 0;
    carta->pibPerCapita = 0;
    return 1;
}

//cria nó com carta cadastrada
Node *criarNode(TClasse carta){
    Node *novoNode;
    novoNode = calloc(1, sizeof(struct node));
    novoNode->carta = carta;
    novoNode->prox = NULL;
    return novoNode;
}

float calcularDensidadePopulacional(unsigned int pop, float area){
    return (float) pop / area;
}

float calcularPibPerCapita(double pib, unsigned int pop){
    return (float) pib / pop;
}

//solicita, armazena e exibe os dados
Node *cadastrarCarta(TClasse *carta){
    printf("\nInforme o Estado: ");
    scanf(" %[^\n]", carta->estado); //lê caracteres enquanto nao forem quebra de linha
    printf("Informe o código (Formato A01): ");
    scanf(" %[^\n]", carta->codigo); 
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
    
    Node *novoNode = criarNode(*carta);

    if(novoNode != NULL){
        printf("\nCarta cadastrada com sucesso:\n");
        exibirCarta(novoNode->carta);
    }

    return novoNode;
}

// Exibição dos Dados das Cartas:
int exibirCarta(TClasse carta){
    printf("\n------------------------------------------------\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.cidade);
    printf("População: %u\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2lf\n", carta.pib);
    printf("Quantidade de pontos turísticos: %d\n", carta.qtdePontosTuristicos);
    printf("Densidade Populacional: %.2f pessoas/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
    printf("------------------------------------------------\n");

    return 1;
}

//comparar cartas
void compararCartas(){
    char cod1[4], cod2[4];
    printf("\nInforme o código da primeira carta a ser comparada: ");
    scanf(" %[^\n]", cod1);
    printf("\nInforme o código da segunda carta a ser comparada: ");
    scanf(" %[^\n]", cod2);

    TClasse carta1;
    TClasse carta2;

    //fazer busca das cartas na lista

    exibirCarta(carta1);
    exibirCarta(carta2);
}

int main() {
    TClasse carta;

    if (construtor(&carta) == 0)
        return 0;

    printf("Bem vindo ao Super Trunfo!\nVamos iniciar com o cadastro das cartas.\n");

    do{
        Node *novaCarta = cadastrarCarta(&carta);

        printf("\nCadastrar nova carta? (Digite 'S' para Sim e 'N' para Não): ");
        scanf(" %c", &opcao);
    } while(opcao == 'S' || opcao == 's');

    /*
    printf("\n****************************************************************");
    printf("\nAgora que as cartas foram cadastradas, você pode iniciar o jogo!\n");

    do{
        compararCartas();

        printf("\nFazer nova comparação? (Digite 'S' para Sim e 'N' para Não): ");
        scanf(" %c", &opcao);
    } while(opcao == 'S' || opcao == 's');
    */

    return 0;
}