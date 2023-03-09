#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int wordCounter(string text);
int sentenceCounter(string text);
int letterCounter(string text);
void gradePrinter(int index);

int main(void)
{
    float index;
    float L, S;
    string text = get_string("Text: ");
    float numWords = wordCounter(text);
    float numSentence = sentenceCounter(text);
    float numLetter = letterCounter(text);

    //Calculate the average number of letter per 100 words
    L = (numLetter / numWords) * 100.0 ;

    //Calculate the number of sentence per 100 words
    S = (numSentence / numWords) * 100.0;

    index = 0.0588 * L - 0.296 * S - 15.8;

    // printf("Words: %f, Sentence: %f; Letter: %f\n", numWords, numSentence, numLetter);
    // printf("L: %f and S: %f\n", L, S);

    //This function compare the index value and returns the grade
    gradePrinter(round(index));

}

int wordCounter(string text)
//Counts how many spaces there are and add 1 to get the number of words
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == (char)* " ")
        {
            n++;
        }
    }
    return n + 1;
}

int sentenceCounter(string text)
//Counts how many special symbols like ".", "!", "?", '"', etc... there are in the text to get the number of sentences
{
    int s = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == (char)* "." || text[i] == (char)* "!" || text[i] == (char)* "?")
        {
            s++;
        }
        if ((text[i] == (char)* "." || text[i] == (char)* "!" || text[i] == (char)* "?" || text[i] == (char)* "\"")
           && text[i + 1] == (char)* "\0")
        {
            s -= 1;
        }
    }
    return s + 1;
}

int letterCounter(string text)
//Check if the letters are Uppercase or Lowercase and if they are, It adds 1 to a variable
{
    int l = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            l++;
        }
    }
    return l;
}

void gradePrinter(int index)
//This function compare the index value and returns the grade
{
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}