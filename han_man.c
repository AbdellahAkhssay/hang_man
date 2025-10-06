#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_letter(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
void draw_hangman(int tr)
{
    switch(tr){
        case 6:
            printf("\n +---+\n     |\n     |\n     |\n    ===\n");
            break;
        case 5:
            printf("\n +---+\n O   |\n     |\n     |\n    ===\n");
            break;
        case 4:
            printf("\n +---+\n O   |\n |   |\n     |\n    ===\n");
            break;
        case 3:
            printf("\n +---+\n O   |\n/|   |\n     |\n    ===\n");
            break;
        case 2:
            printf("\n +---+\n O   |\n/|\\  |\n     |\n    ===\n");
            break;
        case 1:
            printf("\n +---+\n O   |\n/|\\  |\n/    |\n    ===\n");
            break;
        case 0:
            printf("\n +---+\n O   |\n/|\\  |\n/ \\  |\n    ===\n");
            break;
    }
}

int main()
{
    char word[50];
    char display[50];
    char input[50];
    int tries = 6;
    int correct = 0;
    int len;

    printf("Enter the secret word (max 50 chars): ");
    scanf("%49s", word);

    len = count_letter(word);
    for (int i = 0; i < len; i++)
        display[i] = '_';
    display[len] = '\0';

    system("cls");

    printf("Try to guess the word!\n");
    while (tries > 0 && correct < len)
    {
        draw_hangman(tries);
        printf("\nWord: %s\n", display);
        printf("Tries left: %d\n", tries);
        printf("Enter a letter or try to guess the word: ");
        scanf("%49s", input);

        if (count_letter(input) == 1)
        {
            char guess = tolower(input[0]);
            int found = 0;
            for (int i = 0; i < len; i++)
            {
                if (tolower(word[i]) == guess && display[i] == '_')
                {
                    display[i] = word[i];
                    correct++;
                    found = 1;
                }
            }
            if (!found)
            {
                printf("Wrong guess!\n");
                tries--;
            }
        }
        else
        {
#ifdef _WIN32
            if (stricmp(input, word) == 0)
#else
            if (strcasecmp(input, word) == 0)
#endif
            {
                strcpy(display, word);
                correct = len;
                break;
            }
            else
            {
                printf("Wrong word guess!\n");
                tries--;
            }
        }
    }

    if (correct == len)
    {
        printf("\nCongratulations! You found the word: %s\n", word);
    }
    else
    {
        draw_hangman(0);
        printf("\nGame Over! The word was: %s\n", word);
    }

    return 0;
}
