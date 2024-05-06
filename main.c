
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

            switch (ans)
            {
            case 1: // add user
                printf("enter username: ");
                scanf("%s", username);

                if (checkUserExist(username) != 0) // username NOT exist
                {
                    if (AddUser(username) == 0)
                        printf("user %s added successfully", username);
                    else
                        printf("Command execution failed\n");
                }
                else
                    printf("this username is exist CAN NOT add user with this username");

                break;

            case 2: // delete user
                printf("enter username: ");
                scanf("%s", username);
                if (checkUserExist(username) == 0) // username  exist
                {
                    if (DelUser(username) == 0)
                        printf("user %s deleted successfully\n", username);
                    else
                        printf("Command execution failed\n");
                }
                else
                    printf("this username is NOT exist CAN NOT delete");
                break;

            case 3: // list users
                if (ListUsers() != 0)
                    printf("Command execution failed\n");
                break;

            case 0: // back
                break;

            default:
                printf("INVALID option");
                break;
            }
            break;

        case 'b': // Manage Group
            ans = groupMenu();

            switch (ans)
            {
            case 1: // add group
                printf("enter group name: ");
                scanf("%s", groupname);

                if (checkGroupExist(groupname) != 0) // group NOT exist
                {
                    if (AddGroup(groupname) == 0)
                        printf("group %s added successfully\n", groupname);
                    else
                        printf("Command execution failed\n");
                }
                else
                    printf("there is a group with this name can not add this group");

                break;

            case 2: // delete group
                printf("enter group name: ");
                scanf("%s", groupname);

                if (checkGroupExist(groupname) == 0) // group  exist
                {
                    if (DeleteGroup(groupname) == 0)
                        printf("group %s deleted successfully\n", groupname);
                    else
                        printf("Command execution failed\n");
                }
                else
                    printf("this group is NOT exist CAN NOT delete");
                break;

            case 3: // list groups
                if (ListGroups() != 0)
                    printf("Command execution failed\n");
                break;

            case 0: // back
                break;

            default:
                printf("INVALID option");
                break;
            }
            break;

        case 'c': // change acc info
            ans = ChangeAccountInfoMenu();

            switch (ans)
            {
            case 1: // change username
                printf("enter username: ");
                scanf("%s", username);
                if (checkUserExist(username) == 0) // username exist
                {
                    printf("enter new username: ");
                    scanf("%s", newUserName);
                    if (checkUserExist(newUserName) != 0) // new username NOT exist,can change it
                    {
                        if (ChangeUserName(username, newUserName) == 0)
                            printf("username changed successfully from %s to %s", username, newUserName);
                        else
                            printf("Command execution failed\n");
                    }
                    else
                        printf("the new user name is exist select other username\n");
                }
                else
                    printf("there is NO user name with is name\n");

                break;

            case 2: // change password
                printf("enter username: ");
                scanf("%s", username);

                if (checkUserExist(username) == 0) // username  exist
                {
                    if (ChangePassword(username) == 0)
                    {
                        printf("password changed successfully");
                    }
                    else
                        printf("Command execution failed\n");
                }
                else
                    printf("this username is NOT exist CAN NOT change password");

                break;

            case 0: // back
                break;

            default:
                printf("INVALID option");
                break;
            }
            break;

        case 'd': // assign user to group
            printf("enter username: ");
            scanf("%s", username);

            printf("enter groupname: ");
            scanf("%s", groupname);
            if (checkUserExist(username) == 0 && checkGroupExist(groupname) == 0) // are exist
            {
                if (AssignUser(username, groupname) == 0)
                    printf("user %s added to the group %s successfully\n", username, groupname);
                else
                    printf("Command execution failed\n");
            }
            else
                printf("CAN NOT assign user to this group");
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
