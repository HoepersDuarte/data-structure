#include <stdio.h>

/*
Este exemplo motra uma calculadora básica
*/

int menu(void);

int main(){
    int op; // variavel de leitura de opção do menu
    op = menu();
    while (op != 0){
        printf("informe o valor 1: ");
        scanf("%f", &valor1);
        printf("Informe o valor 2: ")
        scanf("&f", &valor2) ;
        switch(op) {
            case 1:
                printf("Vou somar\n");
                printf("A soma de %.2f e %.2f é %.2f", valor1, valor2)
                break;
            case 2:
                printf("Vou subtrair\n");
                printf("A diferença entre %.2f e %.2f é %.2f", valor1, valor2)
                break;
            case 3:
                printf("Vou multiplicar\n");
                printf("O produto de %.2f e %.2f é %.2f", valor1, valor2)
                break;
            case 4:
                printf("Vou dividir\n");
                printf("A divisão de %.2f por %.2f é %.2f", valor1, valor2)
                break;
            default:
                printf("Você digitou opção inválida.");
                break;
    }
    getchar();
    op = menu();
}
    return 0;
}

int menu(){
    system("clear");
    int opcao= 0;
    printf("======================================================\n");
    printf(" --------------- Operação com dois valors ----------- \n");
    printf("1 - Soma\n");
    printf("2 - Subtrai\n");
    printf("3 - Multiplica\n");
    printf("4 - Divide\n");
    printf("5 - Sair\n");
    printf("\n\n Opção -->");
    scanf("%d", &opcao);
    return opcao;
}
