#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int sorter(int possb) {
    int random, nrandom, choosen;
    float chance;
    
    srand(time(NULL)); // Generate seed for rand() based on your PC time.
    printf("possibility: %d\n", possb);
    random = rand() % 100; // Generate random number in the range 0-99.
    printf("random: %d\n", random);
    chance = 100.0 / (float)(possb - 1); // Chance of getting any number.
    printf("chance: %f \n", chance);
    
    nrandom = 0;
    choosen = 0;
    
    while (nrandom <= random) { // Look for the range.
        nrandom = nrandom + chance;
        choosen++; 	
    }
    
    return choosen;
}

int main() {
    char element[100], celement[100];
    int possibility, choosen, cont;
    
    printf("Hi! I'm the number sorter. How many elements do you want to sort?\n");
    scanf(" %d", &possibility);
    choosen = sorter(possibility);
    printf("Type %d elements:\n", possibility);
    
    cont = 0;
    while (cont != possibility) { // Scan all elements, then store the chosen one based on the index received from sorter().
        scanf(" %[^\n]", element);
        if (cont == choosen - 1) {
            strcpy(celement, element);
        }
        cont++;
    }
    
    printf("Chosen element: %s\n", celement);
    
    return 0;
}
