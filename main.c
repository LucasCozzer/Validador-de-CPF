#include <stdio.h>
#include <string.h>
#include <ctype.h>
// importação das bibliotecas padrões do sistema

// funções para verificações de formatos
int is_lencpf(char *cpf); // contém 11 digitos?
int is_numericcpf(char *cpf); // são númericos
int is_valid(char *cpf); // verificar se é inválido '111.111.111-11'

// funções para calculo digito
int primary_dig(char *cpf); // calcula o primeiro digito
int second_dig(char *cpf, int primary_dig); // calcula o segundo digito


// main
int main (int argc, char **argv) {

    // entrada CPF
    char *cpf = *(argv + 1); // conter o CPF
    // verificações
    if (!is_lencpf(cpf) || !is_numericcpf(cpf) || is_valid(cpf)) {
        printf("CPF invalido\n");
        return 1;
    }

    if ((cpf[strlen(cpf) - 2] - '0') == primary_dig(cpf) && (cpf[strlen(cpf) - 1] - '0') == second_dig(cpf, primary_dig(cpf))) {
        printf("CPF e valido\n");
        return 0;
    } else {
        printf("CPF invalido\n");
        return 1;
    }

}

// funções para verificações de formatos
int is_lencpf (char *cpf) {
    return strlen(cpf) == 14 || strlen(cpf) == 11 ? 1 : 0;
}

int is_numericcpf(char *cpf) {
    for (int i = 0; *(cpf + i); i++)
        if (!isdigit(*(cpf + i)) && !ispunct(*(cpf + i))) return 0;
    return 1;
}

int is_valid(char *cpf) {
    return (!strcmp(cpf, "111.111.111-11")) || (!strcmp(cpf, "11111111111")) ? 1 : 0;
}




// funções para verificação de digitos

int primary_dig(char *cpf) {

    int result_calc = 0; // conter o multiplicação dos 9 primeiros digitos do cpf

    if (strlen(cpf) == 14) {
        for (int i = 10, m = 2; *(cpf + i); i--){
            if (i < 0) {
                return result_calc % 11 >= 2 ? 11 - (result_calc % 11) : 0;
            }
            if (!ispunct(*(cpf + i))) {
                result_calc += (*(cpf + i) - '0') * m;
                m++;
            } 
        }
    } else {
        for (int i = 8, m = 2; *(cpf + i); i--){
            if (i < 0) {
                return result_calc % 11 >= 2 ? 11 - (result_calc % 11) : 0;
            }
            result_calc += (*(cpf + i) - '0') * m;
            m++;
        }
    }
}


int second_dig(char *cpf, int primary_dig) {
    int result_calc = primary_dig * 2; // conter o multiplicação dos 9 primeiros digitos do cpf

    if (strlen(cpf) == 14) {
        for (int i = 10, m = 3; *(cpf + i); i--){
            if (i < 0) {
                return result_calc % 11 >= 2 ? 11 - (result_calc % 11) : 0;
            }
            if (!ispunct(*(cpf + i))) {
                result_calc += (*(cpf + i) - '0') * m;
                m++;
            } 
        }
    } else {
        for (int i = 8, m = 3; *(cpf + i); i--){
            if (i < 0) {
                return result_calc % 11 >= 2 ? 11 - (result_calc % 11) : 0;
            }
            result_calc += (*(cpf + i) - '0') * m;
            m++;
        }
    }
}
