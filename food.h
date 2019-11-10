//
// Created by Lenovo on 11/6/2019.
//
#define MAX_FOOD_NAME 17
#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H

void displayFoodOptions(int noOfFoods, char food[][MAX_FOOD_NAME]);
void displayFoodType(int noTypes, char food[], char types[][MAX_FOOD_NAME], double prices[]);
void displayDrinks(char food[][MAX_FOOD_NAME], int foodChoice, int nodrinks, char drinks[][30], double drinksPrices[6]);

#endif //FOOD_ORDERING_FOOD_H
