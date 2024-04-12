#include <string.h>
#include <stdlib.h>


Execute(char *command)
{
    system(command);
}


AddUser(char *userName)
{
    char command[500];
    strcpy(command,"sudo useradd ");
    strcat(command,userName);
    Execute(command);
}

DelUser(char *userName)
{
    char command[500];
    strcpy(command,"sudo userdel ");
    strcat(command,userName);
    Execute(command);
}

ChangePass(char *userName)
{
    char command[500];
    strcpy(command,"sudo passwd ");
    strcat(command,userName);
    Execute(command);
}

AssignUser(char *userName, char *groupName)
{
    char command[500];
    strcpy(command,"sudo usermod -a -G ");
    strcat(command,groupName);
    strcat(command, " ");
    strcat(command,userName);
    Execute(command);
}

