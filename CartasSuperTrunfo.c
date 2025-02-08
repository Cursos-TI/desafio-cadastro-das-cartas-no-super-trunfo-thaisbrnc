#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

//declaraçao das variaveis
char estado[25] = "";
char codigo[4] = "";
char nome[25] = "";
unsigned int populacao = 0;
float area = 0.0;
double pib = 0.0;
int qtdePontosTuristicos = 0;
float densidadePopulacional = 0;
float pibPerCapita = 0;
char opcao = 'S';

//solicita e armazena os dados
void cadastrarCarta(){
    printf("\nInforme o Estado: ");
    scanf(" %[^\n]", estado); //lê caracteres enquanto nao forem quebra de linha
    printf("Informe o código (Formato A01): ");
    scanf(" %[^\n]", codigo); 
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", nome);
    printf("Informe o número da população: ");
    scanf(" %u", &populacao);
    printf("Informe a área em km²: ");
    scanf(" %f", &area);
    printf("Informe o PIB: ");
    scanf(" %lf", &pib);
    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d", &qtdePontosTuristicos);
}

//calcular densidade populacional e pib per capita
void calcularDados(){
    densidadePopulacional = (float) populacao / area;
    pibPerCapita = (float) pib / populacao;
}

// Exibição dos Dados das Cartas:
void exibirCarta(){
    printf("\n------------------------------------------------\n");
    printf("Carta cadastrada com sucesso:\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome: %s\n", nome);
    printf("População: %u\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: R$ %.2lf\n", pib);
    printf("Quantidade de pontos turísticos: %d\n", qtdePontosTuristicos);
    printf("Densidade Populacional: %.2f pessoas/km²\n", densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita);
    printf("------------------------------------------------\n");
}

int main() {
    printf("Bem vindo ao Super Trunfo!\nVamos iniciar com o cadastro das cartas.\n");
    
    do{
        cadastrarCarta();
        calcularDados();
        exibirCarta();

        printf("\nCadastrar nova carta? (Digite 'S' para Sim e 'N' para Não): ");
        scanf(" %c", &opcao);
    } while(opcao == 'S' || opcao == 's');

    return 0;
}