#include "libs/string.c"
#include "utility lib/get-commands.c"
#include "utility lib/help.c"

int main()
{
    string command;
    while (1)
    {
        printf("Enter command :>");
        command = inputString();
        if (compareStringsN(command, "exit"))
        {
            break;
        }
        else if (compareStringsN(command, "get-commands")){
            getCommands();
        }
        else if (compareStringsN(command, "help"))
        {
            help();
        }
        else if (compareStringsN(command, "clear"))
        {
            system("cls");
        }
    }
    return 0;
}