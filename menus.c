#include <stdio.h>

char menu()
{
    char ans;
    printf("select an option to do:\n");
    printf("a. Manage users.\n");
    printf("b. Manage groups.\n");
    printf("c. Change account information (username and/or password)\n");
    printf("d. Assign specific users to specific groups.\n");
    printf("e. Exit\n");
    printf("answer: ");

    scanf(" %c", &ans);
    return ans;
}

int userMenu()
{
    int ans;
    printf("\n1 => add user\n");
    printf("2 => delete user\n");
    printf("3 => list user\n");
    printf("0 => back\n");
    printf("answer: ");
    scanf("%i", &ans);

    return ans;
}

int groupMenu()
{
    int ans;
    printf("\n1 => add group\n");
    printf("2 => delete group\n");
    printf("3 => list groups\n");
    printf("0 => back\n");
    printf("answer: ");
    scanf("%i", &ans);

    return ans;
}

int ChangeAccountInfoMenu()
{
    int ans;
    printf("\n1 => change username\n");
    printf("2 => change password\n");
    printf("0 => back\n");
    printf("answer: ");
    scanf("%i", &ans);

    return ans;
}