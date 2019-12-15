#include <stdio.h>
#define MAX_FOOD_NAME 50
// Created by Lenovo on 11/6/2019.

void displayFoodOptions(int noOfFoods, char **foods){
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < noOfFoods; i++) {
        putchar('a' + i);
        printf(") %s\n", foods[i]);
    }
    printf("%c) Go back\n", 'a' + noOfFoods);
}

void displayFoodType(int noOfTypes, char food[], char **types, double *prices){
    printf("Please choose the type of %s\n", food);
    for (int i = 0; i < noOfTypes; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", types[i], prices[i]);
    }
    printf("%c) Go back\n", 'a' + noOfTypes);
}

void displayDrinks(char **foods, int foodChoice, int noOfDrinks, char **drinks, double *drinksPrices){
    printf("Please choose a drink to go with your %s\n", foods[foodChoice]);
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        if(i!=noOfDrinks-1)
            printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
        else
            printf(") %s\n", drinks[i]);
    }
    printf("%c) Go back\n", 'a' + noOfDrinks);
}

//

