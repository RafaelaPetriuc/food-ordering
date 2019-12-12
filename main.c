#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "food.h"
#include "information.h"
#include "preferences.h"

#define MAX_TYPE_FOOD 50
#define MAX_LINE 50
#define MAX_DRINK 50
#define LOAD_DATA "Please load the data"

void readFood(char foodName[], int * noOfTypes);

void readTypes(double *prices, char **types);

void readDrinks(double *prices, char **drinks);

void appendChartAtBeginning(char *str, char c);

int main() {
    //char food[][MAX_FOOD_NAME] = {"Pizza","Pasta","Salad"};
    //char drinks[][30] = {"Coca-cola","Fanta","Lipton", "Water", "No, thanks!"};
    char Username[20], info[50], Password[20];
    //char types[3][4][17] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                           // {"Chicken alfredo", "Mac&cheese "},
                          //  {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    //double prices[3][4] = {
          //  {21, 23, 19},
           // {23, 21},
           // {23, 22, 19, 21}};
    //double drinksPrices[6] = {5, 5, 5, 4, 0};
    int choice, foodChoice, typeChoice, drinksChoice=0, state=0, order=0, cutlery;

    int noOfFoods = 3;
    printf("%s\n", LOAD_DATA);
    scanf("%d", &noOfFoods);
    getchar();
    char **foods = (char**) malloc(noOfFoods * sizeof(char *));
    int *noOfTypes = (int *) malloc(noOfFoods * sizeof(int));
    char ***types = (char ***) malloc(noOfFoods * sizeof(char **));
    double **prices = (double **) malloc(noOfFoods * sizeof(double *));
    for(int i=0;i<noOfFoods;i++){
        foods[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        readFood(foods[i], &noOfTypes[i]);
        types[i] = (char **) malloc(noOfTypes[i] * sizeof(char *));
        prices[i] = (double *) malloc(noOfTypes[i] * sizeof(double));
        for( int j=0;j<noOfTypes[i];j++){
            types[i][j] = (char *) malloc(MAX_TYPE_FOOD * sizeof(char));
        }
        readTypes(prices[i], types[i]);
    }

    int noOfDrinks;
    scanf("%d", &noOfDrinks);
    char **drinks = (char **) malloc(noOfFoods * sizeof(char *));
    double *drinksPrices = (double *) malloc(noOfFoods * sizeof(double));
    scanf("%d", &noOfDrinks);
    for(int i=0;i<noOfDrinks;i++){
        drinks[i] = (char *) malloc(MAX_DRINK * sizeof(char));
    }
    readDrinks(drinksPrices, drinks);

    while(!order) {
        switch (state) {
            case 0: {
                InputPersonalData(Username, Password);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoods, foods);
                foodChoice= getChoiceIndex( noOfFoods, &state);
                break;
            }
            case 2: {
                displayFoodType( noOfTypes[foodChoice],  foods[foodChoice], types[foodChoice], prices[foodChoice]);
                typeChoice= getChoiceIndex( noOfFoods, &state);
                break;
            }
            case 3: {
                displayDrinks( foods, foodChoice, noOfDrinks, drinks, drinksPrices);
                drinksChoice= getChoiceIndex( noOfDrinks, &state);
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

    for(int i=0;i<noOfFoods;i++){
        for(int j=0;j<noOfTypes[i];i++){
            free(types[i][j]);
        }
        free(foods[i]);
        free(types[i]);
        free(prices[i]);
        free(drinks[i]);
    }
    free(foods);
    free(noOfTypes);
    free(types);
    free(prices);
    free(drinks);
    free(drinksPrices);
    return 0;
}

void readFood(char foodName[], int * noOfTypes){
    char line[MAX_LINE];
    gets(line);
    const char delim[2]=":";
    char *token;
    token=strtok(line, delim);
    strcpy(foodName, token);
    token=strtok(NULL,delim);
    *noOfTypes= atoi(token);
}

void appendChartAtBeginning(char *str, char c){
    int len= strlen(str)+1;
    memmove(str+1,str,len);
    str[0]=c;
}

void readTypes(double *prices, char **types){
    char line[MAX_LINE];
    gets(line);
    appendChartAtBeginning(line, ' ');
    char *token=strtok(line, "(");
    int k=0;
    while(token!=NULL){
        token=strtok(NULL, "-");
        strcpy(types[k], token);
        token=strtok(NULL, ")");
        sscanf(token, "%lf", &prices[k]);
        k++;
        token=strtok(NULL, "(");
    }
}

void readDrinks(double *prices, char **drinks){
    char line[MAX_LINE];
    gets(line);
    appendChartAtBeginning(line, ' ');
    char *token=strtok(line, "(");
    int k=0;
    while(token!=NULL){
        token=strtok(NULL, "-");
        strcpy(drinks[k], token);
        token=strtok(NULL, ")");
        sscanf(token, "%lf", &prices[k]);
        k++;
        token=strtok(NULL, "(");
    }
}