#include <stdio.h>

int fibonacci(int n) {
    int resultado, anterior = 0, atual = 1;
    
    if (n == 0) {
        return anterior;
    }
    
    for (int i = 1; i < n; i++) {
        resultado = anterior + atual;
        anterior = atual;
        atual = resultado;
    }
    
    return atual;
}

int main() {
    int numero, resultado;
    
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);
    
    resultado = fibonacci(numero);
    
    printf("O %d° número da sequência de Fibonacci é %d", numero, resultado);
    
    return 0;
}

