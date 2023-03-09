#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int centsValue;
    do
    {
        centsValue = get_int("Insert number of cents: ");
    }
    while (!(centsValue >= 0));

    return centsValue;
}

int calculate_quarters(int cents)
{
    int reminder = cents % 25;
    int numQuarters = (cents - reminder) / 25;
    return numQuarters;
}

int calculate_dimes(int cents)
{
    int reminderFromCents = cents % 25;
    int reminderFromDimes = reminderFromCents % 10;
    int numDimes = (reminderFromCents - reminderFromDimes) / 10;
    return numDimes;
}

int calculate_nickels(int cents)
{
    int reminderFromCents = cents % 25;
    int reminderFromDimes = reminderFromCents % 10;
    int reminderFromNickels = reminderFromDimes % 5;
    int numNickels = (reminderFromDimes - reminderFromNickels) / 5;
    return numNickels;
}

int calculate_pennies(int cents)
{
    int reminderFromCents = cents % 25;
    int reminderFromDimes = reminderFromCents % 10;
    int numPennies = reminderFromDimes % 5;
    return numPennies;
}
