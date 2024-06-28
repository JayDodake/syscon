#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define string struct MyString *

// Define the custom string structure
struct MyString
{
    char *data;
    size_t length;
};

// Function to initialize a string
struct MyString *createString(const char *initialData)
{
    struct MyString *newString = (struct MyString *)malloc(sizeof(struct MyString));
    if (newString == NULL)
    {
        return NULL;
    }
    newString->length = strlen(initialData);
    newString->data = (char *)malloc((newString->length + 1) * sizeof(char));
    if (newString->data == NULL)
    {
        free(newString);
        return NULL;
    }
    strcpy(newString->data, initialData);
    return newString;
}

// Function to free the string
void freeString(struct MyString *str)
{
    if (str != NULL)
    {
        free(str->data);
        free(str);
    }
}

// Function to concatenate two strings
void concatenateString(struct MyString *str1, const struct MyString *str2)
{
    str1->data = (char *)realloc(str1->data, str1->length + str2->length + 1);
    if (str1->data == NULL)
    {
        return;
    }
    strcat(str1->data, str2->data);
    str1->length += str2->length;
}


// Function to get the length of the string
size_t getStringLength(const struct MyString *str)
{
    return str->length;
}

// Function to access character at a specific position in the string
char getCharAt(const struct MyString *str, size_t index)
{
    if (index < str->length)
    {
        return str->data[index];
    }
    else
    {
        return '\0';
    }
}

// Function to compare two strings
int compareStrings(const struct MyString *str1, const struct MyString *str2)
{
    if (strcmp(str1->data, str2->data) == 0)
    {
        return 1;
    }
    return 0;
}

int compareStringsN(const struct MyString *str1, const char *str2)
{

    if (strcmp(str1->data, str2) == 0)
    {
        return 1;
    }
    return 0;
}

// Function to clear the content of the string
void clearString(struct MyString *str)
{
    str->data[0] = '\0';
    str->length = 0;
}

// Function to take input string from keyboard
struct MyString *inputString()
{
    char buffer[1024]; // Assuming a maximum input size of 1024 characters
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        // error reading input
        return NULL;
    }
    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';
    return createString(buffer);
}
