#include <string.h>
#include <stdlib.h>
char command[500];

// return zero if there is no error
/**
 *
 * @returns int 0 if there is no an error, else return non-zero value (the code of error)
 *
 */
int Execute(char *command)
{
    return system(command);
}

int ListUsers()
{
    strcpy(command, "getent passwd ");
    return Execute(command);
}

int AddUser(char *userName)
{

    strcpy(command, "sudo useradd -m "); // -m make home directory
    strcat(command, userName);
    return Execute(command);
}

int DelUser(char *userName)
{

    strcpy(command, "sudo userdel -r "); // -r delete the user directory
    strcat(command, userName);
    strcat(command, " >/dev/null 2>&1");
    return Execute(command);
}

int ChangePassword(char *userName)
{

    strcpy(command, "sudo passwd ");
    strcat(command, userName);
    return Execute(command);
}

int AssignUser(char *userName, char *groupName)
{
    strcpy(command, "sudo usermod -a -G ");
    strcat(command, groupName);
    strcat(command, " ");
    strcat(command, userName);
    return Execute(command);
}

int ListGroups()
{
    strcpy(command, "getent group ");
    return Execute(command);
}

int AddGroup(char *groupName)
{

    strcpy(command, "sudo groupadd ");
    strcat(command, groupName);
    return Execute(command);
}

int DeleteGroup(char *groupName)
{

    strcpy(command, "sudo groupdel ");
    strcat(command, groupName);
    return Execute(command);
}

int ChangeUserName(char *oldUsername, char *newUsername)
{

    strcpy(command, "sudo usermod -l ");
    strcat(command, newUsername);
    strcat(command, " ");
    strcat(command, oldUsername);
    return Execute(command);
}

// ================

/**
 *
 * return zero if user exist
 *
 */
int checkUserExist(char *username)
{
    strcpy(command, "id -u ");
    strcat(command, username);

    strcat(command, " >/dev/null 2>&1");

    return Execute(command);
}

/**
 *
 * return zero if group exist
 *
 */
int checkGroupExist(char *groupName)
{
    char command[100] = "getent group ";

    strcat(command, groupName);

    strcat(command, " >/dev/null 2>&1");

    return system(command);
}
