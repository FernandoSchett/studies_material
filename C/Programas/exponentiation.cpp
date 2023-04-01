#include <stdio.h>

int exponenciacao(int base, int expoente) {
    int resultado = 1;
    
    while (expoente > 0) {
        resultado *= base;
        expoente--;
    }
    
    return resultado;
}

int main() {
    int base, expoente, resultado;
    
    printf("Digite a base: ");
    scanf("%d", &base);
    
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    resultado = exponenciacao(base, expoente);
    
    printf("%d elevado a %d é igual a %d", base, expoente, resultado);
    
    return 0;
}
