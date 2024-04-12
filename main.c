
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menus.c"
#define MAX 100

// gcc -o main main.c user.c
int main(void)
{
    char op;
    int ans;
    char username[MAX], newUserName[MAX], groupname[MAX];

    do
    {
        op = menu();

        switch (op)
        {
        case 'a':

            break;
        case 'b':

            break;
        case 'c':

            break;
        case 'd':

            break;
        case 'e':
            printf("exit successfully");
            break;

        default:
            printf("this option NOT exist");
            break;
        }

        printf("\n");
    } while (op != 'e');
}
