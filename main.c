
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menus.c"
#define MAX 100

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
            ans = userMenu();

            if (ans == 1 || ans == 2)
            {
                printf("enter username: ");
                scanf("%s", username);
                if (ans == 1)
                {
                }
                else if (ans == 2)
                {
                }
            }
            else
            {
                printf("this option NOT exist");
            }

            break;
        case 'b':
            ans = groupMenu();
            if (ans == 1 || ans == 2)
            {
                printf("enter group name: ");
                scanf("%s", groupname);
                if (ans == 1)
                {
                }
                else if (ans == 2)
                {
                }
            }
            else
            {
                printf("this option NOT exist");
            }
            break;
        case 'c':
            ans = ChangeAccountInfoMenu();
            if (ans == 1 || ans == 2)
            {
                printf("enter username: ");
                scanf("%s", username);
                if (ans == 1)
                {
                    printf("enter new username: ");
                    scanf("%s", newUserName);
                    changeUserName(username, newUserName);
                }
                else if (ans == 2)
                {
                    changePassword(username);
                }
            }
            else
            {
                printf("this option NOT exist");
            }
            break;
        case 'd':
            printf("enter username: ");
            scanf("%s", username);

            printf("enter username: ");
            scanf("%s", groupname);

            assignUserToGroup(username, groupname);
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
