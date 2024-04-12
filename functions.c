#include <string.h>
#include <stdlib.h>

void Execute(char *command)
{
    system(command);
}

void AddUser(char *userName)
{
    char command[500];
    strcpy(command, "sudo useradd ");
    strcat(command, userName);
    Execute(command);
}

void DelUser(char *userName)
{
    char command[500];
    strcpy(command, "sudo userdel ");
    strcat(command, userName);
    Execute(command);
}

void ChangePassword(char *userName)
{
    char command[500];
    strcpy(command, "sudo passwd ");
    strcat(command, userName);
    Execute(command);
}

void AssignUser(char *userName, char *groupName)
{
    char command[500];
    strcpy(command, "sudo usermod -a -G ");
    strcat(command, groupName);
    strcat(command, " ");
    strcat(command, userName);
    Execute(command);
}

void AddGroup(char *groupName)
{
    char command[500];
    strcpy(command, "sudo groupadd ");
    strcat(command, groupName);
    Execute(command);
}

void DeleteGroup(char *groupName)
{
    char command[500];
    strcpy(command, "sudo groupdel ");
    strcat(command, groupName);
    Execute(command);
}

void ChangeUserName(char *oldUsername, char *newUsername)
{
    char command[500];
    strcpy(command, "sudo usermod -l ");
    strcat(command, newUsername);
    strcat(command, " ");
    strcat(command, oldUsername);
    Execute(command);
}