#include <stdio.h>
#include <cs50.h>
// #include <string.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau(int letters, int sentences, int words);

int main(void)
{
    string text = get_string("Enter text here: ");

    // Get the index
    int index = coleman_liau(count_letters(text), count_sentences(text), count_words(text));


    // Coleman Liau
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
        printf("Grade %i\n", index);
    }

    return 0;
}

int count_letters(string text)
{
    // int n = strlen(text);
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i])) count++;
    }

    return count;
}

int count_words(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i])) count++;
    }

    /* Assuming a two word sentence has one space, then count is space + 1
     * Moses Bomera; number of spaces plus 1, (space (1) + 1 = 2 )
     */
    count++;

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') count++;
    }

    return count;
}

int coleman_liau(int letters, int sentences, int words)
{
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    int index = floor(0.0588 * L - 0.296 * S - 15.8);

    return index;
}