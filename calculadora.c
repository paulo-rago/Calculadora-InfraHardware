 // Aluno: Paulo Ricardo Costa Rago - Turma: A
 // email: prcr@cesar.school


#include <stdio.h>
#include <stdlib.h>

void base2(int numero);
void base8(int numero);
void bcd(int numero);
void complemento2(int numero);
void decFloat(double numero);
void decDouble(double numero);

int main() {
    int opcao, numero;
    double numero_real;

    printf("Escolha uma conversão:\n");
    printf("1 - Base 10 para Base 2, Base 8 e BCD\n");
    printf("2 - Base 10 para Base com sinal (Complemento de 2) com 16 bits\n");
    printf("3 - Converter real em decimal para Float e Double\n");

    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao >= 1 && opcao <= 2) {
        printf("Digite um número inteiro: ");
        scanf("%d", &numero);
    } else if (opcao == 3) {
        printf("Digite um número real: ");
        scanf("%lf", &numero_real);
    } else {
        printf("Opção inválida!\n");
        return 1;
    }

    switch (opcao) {
        case 1:
            base2(numero);
            base8(numero);
            bcd(numero);
            break;
        // case 2:
            // complemento2(numero);
            break;
        // case 3:
           // decFloat(numero_real);
           // decDouble(numero_real);
           // break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}

void base2(int numero) {
    printf("Conversão de %d para base 2:\n", numero);
    int binario[32], i = 0;

    if (numero == 0) {
        printf("0\n");
        return;
    }

    while (numero > 0) {
        binario[i] = numero % 2;
        numero = numero / 2;
        i++;
    }

    printf("Resultado em binário: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
    printf("\n");
}

void base8(int numero) {
    printf("Conversão de %d para base 8:\n", numero);
    int octal[32], i = 0;

    if (numero == 0) {
        printf("0\n");
        return;
    }

    while (numero > 0) {
        octal[i] = numero % 8;
        numero = numero / 8;
        i++;
    }

    printf("Resultado em octal: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n");
}

void bcd(int numero) {
    printf("Conversão de %d para BCD:\n", numero);
    int digito;

    if (numero == 0) {
        printf("0000\n");
        return;
    }

    while (numero > 0) {
        digito = numero % 10;
        for (int i = 3; i >= 0; i--) {
            printf("%d", (digito >> i) & 1);
        }
        printf(" ");
        numero = numero / 10;
    }
    printf("\n");
}