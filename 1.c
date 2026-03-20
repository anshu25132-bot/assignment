#include <stdio.h>
#include <string.h>

#define MAX 100

char backStack[MAX][100];
char forwardStack[MAX][100];

int backTop = -1;
int forwardTop = -1;

char current[100] = "";

void pushBack(char url[])
{
    backTop++;
    strcpy(backStack[backTop], url);
}

void pushForward(char url[])
{
    forwardTop++;
    strcpy(forwardStack[forwardTop], url);
}

void popBack(char url[])
{
    strcpy(url, backStack[backTop]);
    backTop--;
}

void popForward(char url[])
{
    strcpy(url, forwardStack[forwardTop]);
    forwardTop--;
}

void clearForward()
{
    forwardTop = -1;
}

void printHistory()
{
    int i;

    printf("\nBROWSER HISTORY:\n");

    for(i = 0; i <= backTop; i++)
    {
        printf("%s\n", backStack[i]);
    }

    if(strlen(current) > 0)
        printf("%s\n", current);
}

int main()
{
    char input[100];

    printf("A new browsing session has started\n");

    while(1)
    {
        if(strlen(current) == 0)
            printf("\nCURRENT PAGE: NEW SESSION\n");
        else
            printf("\nCURRENT PAGE: %s\n", current);

        if(backTop == -1)
            printf("BACK (NO PREVIOUS PAGES)\n");
        else
            printf("BACK\n");

        if(forwardTop == -1)
            printf("NEXT (NO FURTHER PAGES)\n");
        else
            printf("NEXT\n");

        printf("Enter URL / BACK / NEXT / PRINT HISTORY:\n");

        fgets(input,100,stdin);
        input[strcspn(input,"\n")] = 0;

        if(strcmp(input,"BACK") == 0)
        {
            if(backTop == -1)
            {
                printf("No previous pages\n");
            }
            else
            {
                pushForward(current);
                popBack(current);
            }
        }

        else if(strcmp(input,"NEXT") == 0)
        {
            if(forwardTop == -1)
            {
                printf("No further pages\n");
            }
            else
            {
                pushBack(current);
                popForward(current);
            }
        }

        else if(strcmp(input,"PRINT HISTORY") == 0)
        {
            printHistory();
        }

        else
        {
            if(strlen(current) > 0)
                pushBack(current);

            strcpy(current,input);

            clearForward();
        }
    }

    return 0;
}