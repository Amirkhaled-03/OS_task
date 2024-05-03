
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menus.c"
#include "functions.c"
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

        case 'a': // Manage User
            ans = userMenu();
            if (ans == 1 || ans == 2 || ans == 3)
            {
                if (ans != 3)
                {
                    printf("enter username: ");
                    scanf("%s", username);
                }

                if (ans == 1) // add user
                {
                    AddUser(username);
                }
                else if (ans == 2) // del user
                {
                    DelUser(username);
                }
                else
                {
                    ListUsers();
                }
            }
            else
            {
                printf("this option NOT exist");
            }
            break;

        case 'b': // Manage Group
            ans = groupMenu();
            if (ans == 1 || ans == 2 || ans == 3)
            {
                if (ans != 3)
                {
                    printf("enter group name: ");
                    scanf("%s", groupname);
                }
                if (ans == 1) // add group
                {
                    AddGroup(groupname);
                }
                else if (ans == 2) // del group
                {
                    DeleteGroup(groupname);
                }
                else
                {
                    ListGroups();
                }
            }
            else
            {
                printf("this option NOT exist");
            }
            break;

        case 'c': // change acc info
            ans = ChangeAccountInfoMenu();
            if (ans == 1 || ans == 2)
            {
                printf("enter username: ");
                scanf("%s", username);
                if (ans == 1) // username
                {
                    printf("enter new username: ");
                    scanf("%s", newUserName);
                    ChangeUserName(username, newUserName);
                }
                else // password
                {
                    ChangePassword(username);
                }
            }
            else
            {
                printf("this option NOT exist");
            }
            break;

        case 'd': // assign user to group
            printf("enter username: ");
            scanf("%s", username);

            printf("enter groupname: ");
            scanf("%s", groupname);

            AssignUser(username, groupname);
            break;

        case 'e': // exit
            printf("exit successfully");
            break;

        default:
            printf("this option NOT exist");
            break;
        }

        printf("\n");
    } while (op != 'e');
}
