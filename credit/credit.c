#include <cs50.h>
#include <stdio.h>

// Define a preproccessor (macros) to calculate the length of a string
#define len(a) sizeof(a) / sizeof(a[0])

int main(int argc, char *argv[])
{
 //Initialize variables
    long cardNumber = get_long("Credit Card No.: ");
    int count = 0;
    long cardCopy = cardNumber; //Creates a copy of the given Credit Card Number to calculate the length (or units) of the number

//Counts how many units does the number have
    while (cardCopy > 1)
    {
        cardCopy = cardCopy / 10;
        count++;
    }

//Initialize an array with the size of the given number
    int listOfDigits[count];

//Parse the number into an inverted array (something like cardNumber[::-1])
    do
    {
        for (int digitPosition = 0; digitPosition < count; digitPosition++)
        {
            int numberByUnit = cardNumber % 10; //Takes the last digit
            listOfDigits[digitPosition] = numberByUnit; //Insert the current digit into an array position (digitPosition)
            cardNumber /= 10; //Delete the last unit (digit) from the number
            // printf("\ndigitPosition: %d, numberByUnit: %d, CardNumber: %ld\n", digitPosition, numberByUnit, cardNumber); //Debug printing
        }

    }
    while (cardNumber > 1);

//Print how many units does the given number has
    // printf("\nCantidad de dígitos: %i\n", count);

////////////////////////////////// ///////////////
//Card emisor company detection and validation//
/////////////////////////////////////////////////

int digitsSum = 0; //Initialize the variable that will store the digits sum
int tempDigit = 0;// initialize a temporary variable to store the sum in progress

for (int n = 0; n < (len(listOfDigits) / 2); n++)
{
    tempDigit = 2 * listOfDigits[(2 * n) + 1]; //takes the second last number and so on of the list and multiply them by 2

//Check if the digit multiplied by 2 has just 1 digit, if not, separate the digits and add it together
    if (tempDigit > 9)
    {
        int tempSubDigit = tempDigit % 10;
        tempDigit = tempSubDigit + tempDigit / 10;
    }

//Make the sum of the multiplied by 2 digits
    digitsSum = digitsSum + tempDigit;

    // printf("n value: %i, pos value: %i, temp digit: %i, Sum: %i\n", n, (2 * n) + 1, tempDigit, digitsSum);
}

// printf("\nNon multiplied\n");

//Sum all of the non-multiplied by 2 digits and add them together with the sum of the multiplied by 2 digits
for (int n = 0; n <= (len(listOfDigits) / 2); n++)
{
    tempDigit = listOfDigits[2 * n];
    digitsSum = digitsSum + tempDigit;
    // printf("n value: %i, pos value: %i, temp digit: %i, Sum: %i\n", n, (2 * n), tempDigit, digitsSum);
}

//Calculate de modulo 10 to valid if card is legit (digitsSum must be divisible by 10)
int mod10 = digitsSum % 10;

// printf("Sum: %i\n", digitsSum);

//Validates the type of credit card considering the constrains
if (len(listOfDigits) == 15 && ((listOfDigits[count - 1] == 3) && ((listOfDigits[count - 2] == 4) || (listOfDigits[count - 2] == 7))) && mod10 == 0)
{
    printf("AMEX\n");
}
else if ((len(listOfDigits) == 13 || len(listOfDigits) == 16) && listOfDigits[count - 1] == 4 && mod10 == 0)
{
    printf("VISA\n");
}
else if ((len(listOfDigits) == 16) && ((listOfDigits[count - 1] == 5) && ((listOfDigits[count - 2] >= 1) && (listOfDigits[count - 2] <= 5))) && mod10 == 0)
{
    printf("MASTERCARD\n");
}
else
{
    printf("INVALID\n");
}
}
