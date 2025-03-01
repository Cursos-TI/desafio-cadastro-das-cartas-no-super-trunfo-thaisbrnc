#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Cadastro das Cartas

//declaraçao das variaveis
typedef struct carta
{
    char codigo[4];
    char estado;
    char cidade[25];
    unsigned int populacao;
    float area;
    double pib;
    int qtdePontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

//declaração dos metodos
float calcularDensidadePopulacional(unsigned int pop, float area);
float calcularPibPerCapita(double pib, unsigned int pop);
Carta cadastrarCarta(Carta carta);
void exibirCarta(Carta carta);

float calcularDensidadePopulacional(unsigned int pop, float area){
    return (float) pop / area;
}

float calcularPibPerCapita(double pib, unsigned int pop){
    return (float) pib / pop;
}

//solicita e armazena os dados
Carta cadastrarCarta(Carta carta){
    printf("\nInforme o Estado (1 letra): ");
    scanf(" %c", &carta.estado); 
    printf("Informe o código (2 dígitos): ");
    scanf(" %[^\n]", &carta.codigo[1]); //salva os digitos a partir do indice 1, pois o 0 é reservado ao estado
    carta.codigo[0] = carta.estado; //indice 0 recebe a letra informada no estado
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta.cidade); //lê caracteres enquanto nao forem quebra de linha
    printf("Informe o número da população: ");
    scanf(" %u", &carta.populacao);
    printf("Informe a área em km²: ");
    scanf(" %f", &carta.area);
    printf("Informe o PIB: ");
    scanf(" %lf", &carta.pib);
    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d", &carta.qtdePontosTuristicos);
    //chama os metodos que calculam densidade populacional e pib per capita e passa os resultados para as propriedades
    carta.densidadePopulacional = calcularDensidadePopulacional(carta.populacao, carta.area);
    carta.pibPerCapita = calcularPibPerCapita(carta.pib, carta.populacao);

    return carta;
}

// Exibição dos Dados das Cartas
void exibirCarta(Carta carta){
    //valida se dado da carta está vazio e assim nao exibe a carta
    if(carta.estado == '\0'){
        printf("\nCarta não cadastrada.\n");
        return;
    }

    printf("\n------------------------------------------------\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.cidade);
    printf("População: %u\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2lf\n", carta.pib);
    printf("Quantidade de pontos turísticos: %d\n", carta.qtdePontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
    printf("------------------------------------------------\n");
}

int main(void) {
    //inicializa structs de carta
    Carta carta1 = {0};
    Carta carta2 = {0};

    printf("\n***********************************************************");
    printf("\n                Bem vindo ao Super Trunfo!                 ");
    printf("\n***********************************************************\n");
    printf("\n                    Cadastro das cartas                    \n");

    //chama o metodo para cadastrar a carta 1
    carta1 = cadastrarCarta(carta1);
    //exibe os dados da carta 1
    printf("\n\nCarta 1: ");
    exibirCarta(carta1);

    //chama o metodo para cadastrar a carta 2
    carta2 = cadastrarCarta(carta2);
    //exibe os dados da carta 2
    printf("\n\nCarta 2: ");
    exibirCarta(carta2);
    
    return 0;
}
