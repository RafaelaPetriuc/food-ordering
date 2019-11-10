#include <stdio.h>
#define MAX_FOOD_NAME 17
// Created by Lenovo on 11/6/2019.

void displayFoodOptions(int noOfFoods, char food[][MAX_FOOD_NAME]){
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < noOfFoods; i++) {
        putchar('a' + i);
        printf(") %s\n", food[i]);
    }
    printf("%c) Go back\n", 'a' + noOfFoods);
}

void displayFoodType(int noTypes, char food[], char types[][MAX_FOOD_NAME], double prices[]){
    printf("Please choose the type of %s\n", food);
    for (int i = 0; i < noTypes; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", types[i], prices[i]);
    }
    printf("%c) Go back\n", 'a' + noTypes);
}

void displayDrinks(char food[][MAX_FOOD_NAME], int foodChoice, int nodrinks, char drinks[][30], double drinksPrices[6]){
    printf("Please choose a drink to go with your %s\n", food[foodChoice]);
    for (int i = 0; i < nodrinks; i++) {
        putchar('a' + i);
        if(i!=nodrinks-1)
            printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
        else
            printf(") %s\n", drinks[i]);
    }
    printf("%c) Go back\n", 'a' + nodrinks);
}

//

