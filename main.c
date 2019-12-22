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
#define FILE_PATH "../datafood.txt"

void readFood(FILE *f, char foodName[], int * noOfTypes);

void readTypes(FILE *f, double *prices, char **types);

void readDrinks(FILE *f, double *prices, char **drinks);

void appendChartAtBeginning(char *str, char c);

void readFoodWithTypes(FILE *foodDataFile, int *noOfFoodsAddr, char ***foodsAddr, int **noOfTypesAddr,
                       char ****typesAddr, double ***pricesAddr);

void read_Drinks(FILE *foodDataFile, int *noOfDrinksAddr, char ***drinksAddr, double **drinksPricesAddr);

void readData(FILE *foodDataFile, int *noOfFoodsAddr, char ***foodsAddr, int **noOfTypesAddr,
              char ****typesAddr, double ***pricesAddr,
              int *noOfDrinksAddr, char ***drinksAddr, double **drinksPricesAddr);

void freeData(int noOfFoods, char **foods, int *noOfTypes,
              char ***types, double **prices,
              int noOfDrinks, char **drinks, double *drinksPrices);

int main() {

    FILE * foodDataFile;
    foodDataFile = fopen(FILE_PATH, "r");
    if(foodDataFile==NULL){
        perror("File could not be open");
        exit(-1);
    }

    char  info[50];
    int choice, foodChoice, typeChoice, drinksChoice=0, state=0, order=0, cutlery;

    int noOfFoods = 3;
    char **foods;
    int *noOfTypes;
    char ***types;
    double **prices;
    int noOfDrinks;
    char **drinks;
    double *drinksPrices;

    readData(foodDataFile, &noOfFoods, &foods, &noOfTypes,
    &types, &prices,
    &noOfDrinks, &drinks, &drinksPrices);

    user u = createUser();
    fclose(foodDataFile);
    while(!order) {
        switch (state) {
            case 0: {
                InputPersonalData(&u);
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
    freeData(noOfFoods, foods, noOfTypes,types, prices,
                   noOfDrinks, drinks, drinksPrices);

    return 0;
}

void readFood(FILE *f, char foodName[], int * noOfTypes){
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line)-1]='\0';
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

void readTypes(FILE *f, double *prices, char **types){
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line)-1]='\0';
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

void readDrinks(FILE *f, double *prices, char **drinks){
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line)-1]='\0';
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

void readFoodWithTypes(FILE *foodDataFile, int *noOfFoodsAddr, char ***foodsAddr, int **noOfTypesAddr,
        char ****typesAddr, double ***pricesAddr){
    int noOfFoods = 3;
    printf("%s\n", LOAD_DATA);
    fscanf(foodDataFile, "%d", &noOfFoods);
    fgetc(foodDataFile);
    char **foods = (char**) malloc(noOfFoods * sizeof(char *));
    int *noOfTypes = (int *) malloc(noOfFoods * sizeof(int));
    char ***types = (char ***) malloc(noOfFoods * sizeof(char **));
    double **prices = (double **) malloc(noOfFoods * sizeof(double *));
    for(int i=0;i<noOfFoods;i++){
        foods[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        readFood(foodDataFile, foods[i], &noOfTypes[i]);
        types[i] = (char **) malloc(noOfTypes[i] * sizeof(char *));
        prices[i] = (double *) malloc(noOfTypes[i] * sizeof(double));
        for( int j=0;j<noOfTypes[i];j++){
            types[i][j] = (char *) malloc(MAX_TYPE_FOOD * sizeof(char));
        }
        readTypes(foodDataFile, prices[i], types[i]);
    }
    *noOfFoodsAddr = noOfFoods;
    *foodsAddr = foods;
    *noOfTypesAddr = noOfTypes;
    *typesAddr = types;
    *pricesAddr = prices;
}

void read_Drinks(FILE *foodDataFile, int *noOfDrinksAddr, char ***drinksAddr, double **drinksPricesAddr){
    int noOfDrinks;
    fscanf(foodDataFile, "%d", &noOfDrinks);
    fgetc(foodDataFile);
    char **drinks = (char **) malloc(noOfDrinks * sizeof(char *));
    double *drinksPrices = (double *) malloc(noOfDrinks * sizeof(double));
    fscanf(foodDataFile, "%d", &noOfDrinks);
    for(int i=0;i<noOfDrinks;i++){
        drinks[i] = (char *) malloc(MAX_DRINK * sizeof(char));
    }
    readDrinks(foodDataFile, drinksPrices, drinks);
    *noOfDrinksAddr = noOfDrinks;
    *drinksAddr = drinks;
    *drinksPricesAddr = drinksPrices;
}

void readData(FILE *foodDataFile, int *noOfFoodsAddr, char ***foodsAddr, int **noOfTypesAddr,
              char ****typesAddr, double ***pricesAddr,
              int *noOfDrinksAddr, char ***drinksAddr, double **drinksPricesAddr){
    readFoodWithTypes(foodDataFile, noOfFoodsAddr, foodsAddr, noOfTypesAddr,
    typesAddr, pricesAddr);
    read_Drinks(foodDataFile, noOfDrinksAddr, drinksAddr, drinksPricesAddr);
}

void freeData(int noOfFoods, char **foods, int *noOfTypes,
              char ***types, double **prices,
              int noOfDrinks, char **drinks, double *drinksPrices){
    for(int i=0;i<noOfFoods;i++){
        for(int j=0;j<noOfTypes[i];i++){
            free(types[i][j]);
        }
        free(foods[i]);
        free(types[i]);
        free(prices[i]);

    }
    free(foods);
    free(noOfTypes);
    free(types);
    free(prices);
    for(int i=0;i<noOfDrinks;i++){
        free(drinks[i]);
    }
    free(drinks);
    free(drinksPrices);
}