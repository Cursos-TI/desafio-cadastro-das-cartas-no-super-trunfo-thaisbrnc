#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

//declaraçao das variaveis
    char codigo[4] = "";
    char nome[25] = "";
    int populacao = 0;
    float area = 0.0;
    float pib = 0.0;
    int qtdePontosTuristicos = 0;
    float densidadePopulacional = 0;
    float pibPerCapita = 0;
    char opcao = 'S';

//solicita e armazena os dados
void cadastrarCarta(){
    printf("\nInforme o código (Formato A01): ");
    //sobre formato utilizado nos scanf: pula whitespace (' ', '\t' e '\n')
    //lê um caracter X que não é whitespace
    //pula todos os caracteres até achar um '\n' (o '\n' fica no buffer e é consumido no próximo scanf)
    scanf(" %s%*[^\n]", &codigo); 
    printf("Informe o nome da cidade: ");
    scanf(" %s%*[^\n]", &nome);
    printf("Informe o número da população: ");
    scanf(" %d%*[^\n]", &populacao);
    printf("Informe a área em km²: ");
    scanf(" %f%*[^\n]", &area);
    printf("Informe o PIB: ");
    scanf(" %f%*[^\n]", &pib);
    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d%*[^\n]", &qtdePontosTuristicos);
}

//calcular densidade populacional e pib per capita
void calcularDados(){
    densidadePopulacional = (float) populacao / area;
    pibPerCapita = (float) pib / populacao;
}

// Exibição dos Dados das Cartas:
void exibirCarta(){
    printf("\nCarta cadastrada com sucesso:\n");
    printf("Código: %s\n", codigo);
    printf("Nome: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Quantidade de pontos turísticos: %d\n", qtdePontosTuristicos);
    printf("Densidade Populacional: %.2f\n", densidadePopulacional);
    printf("PIB per capita: %.2f\n", pibPerCapita);
    printf("---------------------------------------------------------\n");
}

int main() {
    printf("Bem vindo ao Super Trunfo!\nVamos iniciar com o cadastro das cartas.\n");
    
    do{
        cadastrarCarta();
        calcularDados();
        exibirCarta();

        printf("\nCadastrar nova carta? (Digite S para Sim e N para Não): ");
        scanf(" %c", &opcao);
    } while(opcao == 'S' || opcao == 's');

    return 0;
}