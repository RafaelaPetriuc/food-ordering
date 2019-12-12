//
// Created by Lenovo on 11/6/2019.
//
#define MAX_FOOD_NAME 50
#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H

void displayFoodOptions(int noOfFoods, char **foods);
void displayFoodType(int noOfTypes, char food[], char **types, double *prices);
void displayDrinks(char **foods, int foodChoice, int noOfDrinks, char **drinks, double *drinksPrices);

#endif //FOOD_ORDERING_FOOD_H
