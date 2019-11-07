#include <stdio.h>
#include<string.h>
// Created by Lenovo on 11/6/2019.

void InputPersonalData(char Username[], char Password[]){
    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(Username);
    printf("---Password:\n");
    gets(Password);
}

void displayOrderFood(char Username[], char types[], char drinks[], double drinksPrices, double prices){
    printf("This is your order:\n");
    printf("-------------\n");
    printf("Name: %s\n", Username);
    printf("Food items:\n");
    printf("--- %s (%.2f)\n", types, prices);
    if(drinksPrices!=0)
    {
        printf("--- %s: (%.2f)\n", drinks, drinksPrices);
    }
}

void displayOrderPreferences(int cutlery, char info[50], double prices, double drinksPrices){
    if(cutlery==1)
        printf("Cutlery: Yes\n");
    else
        printf("Cutlery: No\n");
    if(strcmp(info, "")!=0)
        printf("Additional info: %s\n", info);
    printf("Payment amount: %.2f\n", prices + drinksPrices);
    printf("-------------\n");
}

int getChoiceIndex(int noOfFoods, int *state){
    int choiceIndex;
    char choice = getchar();
    getchar();
    if (choice == 'a' + noOfFoods) {
        (*state)--;
    }else{
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

//

