#include <string.h>
#include <stdlib.h>
char command[500];

void Execute(char *command)
{
    system(command);
}

void ListUsers()
{
    strcpy(command, "getent passwd ");
    Execute(command);
}

void AddUser(char *userName)
{

    strcpy(command, "sudo useradd -m "); // -m make home directory
    strcat(command, userName);
    Execute(command);
}

void DelUser(char *userName)
{

    strcpy(command, "sudo userdel -r "); // -r delete the user directory
    strcat(command, userName);
    Execute(command);
}

void ChangePassword(char *userName)
{

    strcpy(command, "sudo passwd ");
    strcat(command, userName);
    Execute(command);
}

void AssignUser(char *userName, char *groupName)
{

    strcpy(command, "sudo usermod -a -G ");
    strcat(command, groupName);
    strcat(command, " ");
    strcat(command, userName);
    Execute(command);
}

void ListGroups()
{
    strcpy(command, "getent group ");
    Execute(command);
}

void AddGroup(char *groupName)
{

    strcpy(command, "sudo groupadd ");
    strcat(command, groupName);
    Execute(command);
}

void DeleteGroup(char *groupName)
{

    strcpy(command, "sudo groupdel ");
    strcat(command, groupName);
    Execute(command);
}

void ChangeUserName(char *oldUsername, char *newUsername)
{

    strcpy(command, "sudo usermod -l ");
    strcat(command, newUsername);
    strcat(command, " ");
    strcat(command, oldUsername);
    Execute(command);
}