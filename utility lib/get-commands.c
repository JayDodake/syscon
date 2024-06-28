#include <stdio.h>

void getCommands() {
    FILE *fp;
    char buffer[1055];

    fp = fopen("E:\\projects\\syscon\\libs\\get-commands.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
}
