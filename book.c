#include <stdio.h>
#include <string.h>

struct book
{
    int code;
    char name[30];
    char publisher[30];
};

void read();
void write();
int home();

int main()
{
    home();
    return 0;
}

int home()
{
    char response[10];
    printf("\n*************Welcome to Our Book store*************\n");
    printf("Do you want to write or read data or exit?\n");
    scanf("%s", response);
    if (strcmp(response, "write") == 0 || strcmp(response, "Write") == 0)
    {
        write();
    }
    else if (strcmp(response, "read") == 0 || strcmp(response, "Read") == 0)
    {
        read();
    }
    else
    {
        printf("******************exited********************\n");
        return 0;
    }
}

void read()
{
    FILE *fptr;
    char c;
    fptr = fopen("book.txt", "r");
    if (fptr == NULL)
    {
        printf("File does not exist or cannot be opened\n");
        return;
    }
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    home();
}

void write()
{
    FILE *ptr;
    struct book s[100];
    char YN[5];
    ptr = fopen("book.txt", "a");
    if (ptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int i = 0;
    while (1) {
        printf("Book %d:\n", i + 1);
        printf("Book code: ");
        scanf("%d", &s[i].code);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Publisher: ");
        scanf("%s", s[i].publisher);

        fprintf(ptr, "\n\t%d\t%s\t%s", s[i].code, s[i].name, s[i].publisher);

        printf("Do you want to add another book data? \nyes\nno\n");
        scanf("%s", YN);
        if (strcmp(YN, "No") == 0 || strcmp(YN, "no") == 0)
        {
            fclose(ptr);
            home();
            return;
        }
        i++;
    }
}
