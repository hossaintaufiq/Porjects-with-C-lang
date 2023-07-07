#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    printf("Welcome to randoml selection and Question answer\n");
    printf("**************************************************");
    printf("\n\nEnter the name list to choose:\n");
    char student1[30],student2[30],student3[30],student4[30],student5[30],student6[30],student7[30],student8[30],student9[30],student10[30],student11[30],student12[30];
    const char *string_table[] = {
    gets(student1),
    gets(student2),
    gets(student3),
    gets(student4),
    gets(student5),
    gets(student6),
    gets(student7),
    gets(student8),
    gets(student9),
    gets(student10),
    gets(student11),
    gets(student12)
    };
    int table_size = 12;
    srand(time(NULL));
    for (int i = 1; i <= 1; ++i)
    {
        const char *rand_string = string_table[rand() % table_size];
        printf("%s,would you please answer the question?",  rand_string);
    }

    return 0;
}
