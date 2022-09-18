#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Simple Program For Manipulating Strings by Mohamed Mostafa

// Functions Declaration
int charcounter(string userinput);
void extract(void);
void lowercase(void);
void uppercase(void);

int main(void)
{
    int input;
    // UI
    printf("-------------------------------------------------------> Strings Manipulator <-------------------------------------------------------\n\n");

    printf("\n (1) Extract Domain Name From Long URLS (Ex. www.google.com)\n\n (2) Count Characters In String\n\n (3) Lowercase Text\n\n (4) Uppercase Text\n\n");
    //input Conditions
    do{input = get_int("Choose: ");}while(input < 1 || input > 4);
    if(input == 1 ){extract();}
    else if(input == 2){string text = get_string("\n\n[*] Enter Text: ");int count = charcounter(text);printf("\n[-] Characters Number Is: %i\n\n",count);}
    else if(input == 3){lowercase();}
    else if(input == 4){uppercase();}

    char question;
    do
    {
        question = get_char("\n[-] Do You Wish To Do Another Operation? (Y / N): ");
        if(question == 'y' || question == 'Y')
        {
            main();
        }
        else if(question == 'N' || question == 'n')
        {
            printf("\n[*] String Manipulator Has Been Terminated :(\n\n");
        }
    }while(question != 'Y' && question != 'y' && question != 'n' && question != 'N');
}

void extract(void)
{
    string input = get_string("\n\n[*] Enter URL To Extract Domain Name: ");
    int x = 0;
    printf("\n\n[-] Domain: ");
    while(input[x] != '/')
    {
        printf("%c",input[x]);
        x++;
    }
    printf("\n\n");
}

int charcounter(string userinput)
{
    int x = 0;
    while(userinput[x] != '\0')
    {
        x++;
    }
    return x;
}

void lowercase(void)
{
    string input = get_string("\n\n[*] Enter Lowercase Text To Switch It To Uppercase: ");
    printf("\n\n[-] Uppercase: ");
    for(int x = 0; x < strlen(input);x++)
    {
        if(input[x] >= 'a' && input[x] <= 'z')
        {
            printf("%c",input[x] - 32);
        }
    }
    printf("\n\n");
}

void uppercase(void)
{
    string input = get_string("\n\n[*] Enter Uppercase Text To Switch it To Lowercase: ");
    printf("\n\n[-] Lowercase: ");
    for(int x = 0; x < strlen(input);x++)
    {
        if(input[x] >= 'A' && input[x] <= 'Z')
        {
            printf("%c",input[x] + 32);
        }
    }
    printf("\n\n");

}

