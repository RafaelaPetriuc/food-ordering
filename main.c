#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "food.h"
#include "information.h"
#include "preferences.h"
#define MAX_FOOD_NAME 50
#define MAX_TYPE_FOOD 50
#define MAX_LINE 50
#define LOAD_DATA "Please load the data"
int main() {
    //char food[][MAX_FOOD_NAME] = {"Pizza","Pasta","Salad"};
    char drinks[][30] = {"Coca-cola","Fanta","Lipton", "Water", "No, thanks!"};
    char Username[20], info[50], Password[20];
    //char types[3][4][17] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                           // {"Chicken alfredo", "Mac&cheese "},
                          //  {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    //double prices[3][4] = {
          //  {21, 23, 19},
           // {23, 21},
           // {23, 22, 19, 21}};
    double drinksPrices[6] = {5, 5, 5, 4, 0};
    int noOfFoods = 3, noTypes[] = {3,2,4}, nodrinks = 5, choice, foodChoice, typeChoice, drinksChoice, state =0, order = 0, cutlery;

    int noOfNewFoods;
    char ** line, ** food, *** types;
    double ** prices;
    const char delim[6]=" :()-";
    char *token;
    int * noOfTypes;

    while(!order) {
        switch (state) {
            case 0: {
                printf("%s\n", LOAD_DATA);
                scanf("%d", &noOfNewFoods);
                getchar();
                line= (char**)malloc(noOfNewFoods* sizeof(char*));
                food= (char**)malloc(noOfNewFoods* sizeof(char*));
                types = (char***)malloc(noOfNewFoods* sizeof(char **));
                prices = (char **)malloc(noOfNewFoods* sizeof(char*));
                for(int i=0;i<noOfNewFoods;i++){
                    line[i]= (char*)malloc(MAX_LINE* sizeof(char));
                    food[i]= (char*)malloc(MAX_LINE* sizeof(char));
                    types[i]= (char**)malloc(MAX_TYPE_FOOD * sizeof(char*));
                    gets(line[i]);
                    int isFood=0, isType=0, j=0;
                    token=strtok(line[i], delim);
                    while(token!=NULL){
                        if(isFood==0){
                            strcpy(food[i], token);
                            isFood=1;
                        } else
                            if(isType==0){
                                types[i][j]= (char *)malloc(MAX_TYPE_FOOD * sizeof(char));
                                strcpy(types[i][j], token);
                                isType=1;
                                printf("%s\n", types[i][j]);
                                j++;
                        }
                            else{
                                prices[i] = (double *)malloc(noOfNewFoods* sizeof(double));
                                prices[i][j]= atof(token);
                                printf("%.2lf\n", prices[i][j]);
                                isType=0;
                            }
                        token=strtok(NULL,delim);
                    }
                }

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