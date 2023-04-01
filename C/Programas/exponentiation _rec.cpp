#include <stdio.h>

int exponenciacao(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else {
        return base * exponenciacao(base, expoente-1);
    }
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


