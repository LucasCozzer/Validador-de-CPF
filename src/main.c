#include <stdio.h>
#include <string.h>
#include <ctype.h>
// importação das bibliotecas padrões do sistema

// funções para verificações de formatos
int is_lencpf(const char *cpf); // contém 11 digitos?
int is_numericcpf(const char *cpf); // são númericos
int is_valid(const char *cpf); // verificar se é inválido '111.111.111-11'

// funções para calculo digito
int calculate_digit(const char * cpf, int length);






// main
int main (int argc, char **argv) {

    // entrada CPF
    char *cpf = *(argv + 1); // conter o CPF
    // verificações
    if (!is_lencpf(cpf) || !is_numericcpf(cpf) || is_valid(cpf)) {
        printf("CPF invalido\n");
        return 1;
    }

    int primary_dig = calculate_digit(cpf, 9);
    int second_dig = calculate_digit(cpf, 10);  

    if ((cpf[strlen(cpf) == 14 ? 12 : 9] - '0') == primary_dig && (cpf[strlen(cpf) == 14 ? 13 : 10] - '0') == second_dig) {
        printf("CPF e valido\n");
        return 0;
    } else {
        printf("CPF invalido\n");
        return 1;
    }

}





// funções para verificações de formatos
int is_lencpf (const char *cpf) {
    int count = 0;
    for (int i = 0; cpf[i]; i++) {
        if (isdigit(cpf[i])) {
            count++;
        }
    }
    return count == 11;
}



int is_numericcpf(const char *cpf) {
    for (int i = 0; *(cpf + i); i++)
        if (!isdigit(*(cpf + i)) && cpf[i] != '.' && cpf[i] != '-') return 0;
    return 1;
}




int is_valid(const char *cpf) {
    return (!strcmp(cpf, "111.111.111-11")) || (!strcmp(cpf, "11111111111")) ? 1 : 0;
}






// funções para verificação de digitos

int calculate_digit(const char * cpf, int length) {
    int sum = 0; // armazena a soma
    int weigth = length + 1; // 

    for (int i = 0, count = 0; count < length; i++) {
        if (isdigit(cpf[i])) {
            sum += (cpf[i] - '0') * weigth--;
            count++;
        }
    }

    int result = sum % 11;

    return (result < 2) ? 0 : 11 - result; 
}
