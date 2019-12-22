//
// Created by Lenovo on 11/6/2019.
//

#ifndef FOOD_ORDERING_INFORMATION_H
#define FOOD_ORDERING_INFORMATION_H
typedef struct _user{
    char *Password;
    char *Username;
} user;

void InputPersonalData(user *u);

void displayOrderFood(char Username[], char types[], char drinks[], double drinksPrices, double prices);
void displayOrderPreferences(int cutlery, char info[50], double prices, double drinksPrices);

int getChoiceIndex(int noOfFoods, int *state);


user createUser();

#endif //FOOD_ORDERING_INFORMATION_H
