#include <stdio.h>
/***************************************************
* int check_amount(float total, float paid)
* checks if the payment is >= the purchase cost
* Parameters:
* total: the purchase total
* paid: the payment amount
* Returns:
* 1 if the payment is sufficient, 0 if the payment is insufficient
************************************************/
int check_amount(float total, float paid);

/***************************************************
* void print_formatted(float change)
* Calculates the breakdown of change into number of bills and coins
* Parameters:
* change: amount of change owed to customer
************************************************/
void print_formatted(float change);

//main function to execute
int main(void){
    float total, paid;
    //prompt user for purchase total and amount paid
    printf("Input purchase total:\n");
    scanf("%f", &total);

    printf("Input amount paid:\n");
    scanf("%f", &paid);

    //check if payment is >= purchase total to see if payment is sufficient
    if (!check_amount(total, paid)) {
        //if payment is insufficient print "Insufficient payment" and exit the program
        printf("Insufficient payment.\n");
        return 1;
    }

    //if payment is sufficient calculate difference between amount paid and purchase total
    float change = paid - total;

    //Print formatted breakdown of change into bills and coins
    print_formatted(change);
    return 0;
    }

    int check_amount(float total, float paid) {
        //return 1 if payment is sufficient
        return paid >= total;
    }

    void print_formatted(float change) {
        //set variables for each dollar bill and coin
        int five_dollar, one_dollar, quarters, dimes, nickels, pennies;

        //convert change into cents
        int cents = (int)(change * 100);

        //determine number of $5 bills
        five_dollar = cents / 500;
        //calculate remaining change and update cents
        cents %= 500;

        //determine number of $1 bills
        one_dollar = cents / 100;
        //calculate remaining change and update cents
        cents %=100;

        //calculate number of quarters
        quarters = cents / 25;
        //calculate remaining change and update cents
        cents %= 25;

        //calculate number of dimes
        dimes = cents / 10;
        //calculate remaining change and update cents
        cents %= 10;

        //calculate number of nickels
        nickels = cents / 5;
        //calculate remaining change and update cents
        cents %= 5;

        //calculate number of pennies
        pennies = cents;

    //print amount owed in change and quantity of each bill and coin
    printf("Your change is $%.2f\n", change);
        if (five_dollar > 0) printf("  %d - 5D\n", five_dollar);
        if (one_dollar > 0) printf("  %d - 1D\n", one_dollar);
        if (quarters > 0) printf("  %d - Q\n", quarters);
        if (dimes > 0) printf("  %d - D\n", dimes);
        if (nickels > 0) printf("  %d - N\n", nickels);
        if (pennies > 0) printf("  %d - P\n", pennies);
    }