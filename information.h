//
// Created by Lenovo on 11/6/2019.
//

#ifndef FOOD_ORDERING_INFORMATION_H
#define FOOD_ORDERING_INFORMATION_H

void InputPersonalData(char Username[], char Password[]);

void displayOrderFood(char Username[], char types[], char drinks[], double drinksPrices, double prices);
void displayOrderPreferences(int cutlery, char info[50], double prices, double drinksPrices);

int getChoiceIndex(int noOfFoods, int *state);

#endif //FOOD_ORDERING_INFORMATION_H
