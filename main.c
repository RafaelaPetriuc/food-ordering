#include <stdio.h>
#include "food.h"
#include "information.h"
#include "preferences.h"
#define MAX_FOOD_NAME 17
int main() {
    char food[][MAX_FOOD_NAME] = {"Pizza","Pasta","Salad"};
    char drinks[][30] = {"Coca-cola","Fanta","Lipton", "Water", "No, thanks!"};
    char Username[20], info[50], Password[20];
    char types[3][4][17] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                            {"Chicken alfredo", "Mac&cheese "},
                            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    double prices[3][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}};
    double drinksPrices[6] = {5, 5, 5, 4, 0};
    int noOfFoods = 3, noTypes[] = {3,2,4}, nodrinks = 5, choice, foodChoice, typeChoice, drinksChoice, state =0, order = 0, cutlery;
    while(!order) {
        switch (state) {
            case 0: {
                InputPersonalData(Username, Password);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoods, food);
                foodChoice= getChoiceIndex( noOfFoods, &state);
                break;
            }
            case 2: {
                displayFoodType( noTypes[foodChoice],  food[foodChoice], types[foodChoice], prices[foodChoice]);
                typeChoice= getChoiceIndex( noOfFoods, &state);
                break;
            }
            case 3: {
                displayDrinks( food, foodChoice, nodrinks, drinks, drinksPrices);
                drinksChoice= getChoiceIndex( nodrinks, &state);
                break;
            }
            case 4:{
                displayCutlery();
                cutlery= getChoiceIndex(2, &state)+1;
                break;
            }
            case 5:
            {
                displayAdInfo(info);
                state++;
                break;
            }
            case 6:{
                displayOrderFood(Username, types[foodChoice][typeChoice], drinks[drinksChoice], drinksPrices[drinksChoice], prices[foodChoice][typeChoice]);
                displayOrderPreferences(cutlery, info, prices[foodChoice][typeChoice], drinksPrices[drinksChoice]);
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    order = 1;
                }
                else {state-=2;}
                getchar();
                break;
            }
        }
    }
    return 0;
}