#include <stdio.h>
#include<string.h>
int main() {
    printf("Welcome to Food Thingies!\n");

    // food data
    int noOfFoods = 3;
    char food[][15] = {"Pizza","Pasta","Salad"};
    int noTypes[] = {3,2,4};
    char types[3][4][17] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
            {"Chicken alfredo", "Mac&cheese "},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    double prices[3][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };
    int nodrinks = 5;
    char drinks[][30] = {"Coca-cola","Fanta","Lipton", "Water", "No, thanks!"};
    double drinksPrices[] = {5, 5, 5, 4, 0};

    //user input
    char Username[20];
    char Password[20];
    int choice, foodChoice, typeChoice;
    int nodrinksChosen = 0;
    int chosendrinks[3];
    int drinksChoice;
    int state =0;
    int order = 0;
    int cutlery;
    char info[50];
    while(!order) {
        switch (state) {
            case 0: {
                // Input personal data
                printf("Please sign in to continue!\n");
                printf("---Username:\n");
                gets(Username);
                printf("---Password:\n");
                gets(Password);
                state++;
                break;
            }
            case 1: {
                // Choose the food
                printf("Please choose the food you feel like eating today:\n");
                for (int i = 0; i < noOfFoods; i++) {
                    putchar('a' + i);
                    printf(") %s\n", food[i]);
                }
                printf("%c) Go back\n", 'a' + noOfFoods);
                choice = getchar();
                // consume new line
                getchar();
                if (choice == 'a' + noOfFoods) {
                    state--;
                    break;
                }
                foodChoice = choice - 'a';
                state++;
                break;
            }
            case 2: {
                // Choose the type
                printf("Please choose the type of %s\n", food[foodChoice]);
                for (int i = 0; i < noTypes[foodChoice]; i++) {
                    putchar('a' + i);
                    printf(") %s (%.2f)\n", types[foodChoice][i], prices[foodChoice][i]);
                }
                printf("%c) Go back\n", 'a' + noTypes[foodChoice]);
                choice = getchar();
                // consume new line
                getchar();
                if (choice == 'a' + noTypes[foodChoice]) {
                    state--;
                    break;
                }
                typeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                // Choose the drinks
                printf("Please choose a drink to go with your %s\n", food[foodChoice]);
                for (int i = 0; i < nodrinks; i++) {
                    putchar('a' + i);
                    printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
                }
                printf("%c) Go back\n", 'a' + nodrinks + 1);

                choice = getchar();
                getchar();
                if (choice == 'a' + nodrinks) {
                    state--;
                    break;
                }
                nodrinksChosen = 0;
                drinksChoice = choice - 'a';
                state++;
                break;
            }

            case 4:{
                //cutlery
                printf("Do you want cutlery?\n");
                printf("a) Yes\n");
                printf("b) No, thanks!\n");
                printf("c) Go back\n");
                choice=getchar();
                if(choice=='c')
                {
                    state--;
                    break;
                }
                else
                    if(choice=='a')
                        cutlery=1;
                    else
                        cutlery=0;

                state++;
                break;
            }

            case 5:
            {
                //ad info
                printf("Any additional info?\n ");
                gets(info);
                gets(info);
                state++;

                break;
            }
            case 6:{
                // order
                printf("This is your order:\n");
                printf("-------------\n");
                printf("Name: %s\n", Username);
                printf("Food items:\n");
                printf("--- %s (%.2f)\n", types[foodChoice][typeChoice], prices[foodChoice][typeChoice]);
                if(drinksChoice!=4)
                {
                    printf("--- %s: (%.2f)\n", drinks[drinksChoice], drinksPrices[drinksChoice]);
                }
                if(cutlery==1)
                    printf("Cutlery: Yes\n");
                else
                    printf("Cutlery: No\n");
                if(strcmp(info, "")!=0)
                    printf("Additional info: %s\n", info);
                printf("Payment amount: %.2f\n", prices[foodChoice][typeChoice] + drinksPrices[drinksChoice]);
                printf("-------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    order = 1;
                } else {
                    state-=2;
                }
                getchar();
                break;
            }
        }
    }
    return 0;
}