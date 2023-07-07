#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

char words[10][15] = {"mango", "banana","cube","pineapple", "peach","Avocado", "computer","library", "bangladesh", "puzzle"} ;
char *word;
char *guess;
int size;
void createword()
{
    int index= rand()%10;
    word= words[index];
    size= strlen(word);
    guess= (char*) malloc( size+1 * sizeof(char) ) ;
    int i=0;
    while( i<size)
    {
        guess[i]= '-';
        i++;
    }
    guess[i] = '\0' ;
    printf("length of the word is : %d \n", size) ;
    printf("Guess a letter of the word: %s \n", guess) ;
}

int letterControl(char letter )
{
    int i=0, result=0;
    while( i<size )
    {
        if( letter == word[i] )
        {
            guess[i] = letter;
            result=1;
        }
        i++;
    }
    printf("\n");
    return result;
}
int wordControl()
{
    int i=0;
    int result=1;
    while( i<size )
    {
        if( guess[i] =='-' )
        {
            result=0;
        }
        i++;
    }
    printf("Guess a letter in the word %s\n", guess) ;
    return result;
}

void tabledraw(int n )
{
    system("cls");
    green();
    printf("\n\n\t\tNOW PLAYING HANGMAN GAME \n\n")   ;
    reset();
    if(n==1 )
    {
        printf("You have 8 life left");
    }

    if(n==2 )
    {
        printf("You have 7 life left");
    }
    if(n==3 )
    {
        printf("You have 6 life left");
    }
    if(n==4 )
    {
        printf("You have 5 life left");
    }
    if(n==5 )
    {
        printf("You have 4 life left");
    }
    if(n==6 )
        {
            printf("You have 3 life left");
        }
    if(n== 7 )
        {
            printf("You have 2 life left");
        }
    if(n== 8 ){
            printf("You have 1 life left");
        }
    if(n== 9 )
        {
            red();
            printf("Sorry, you're hanged. The word is %s\n\n", word);
        }
        printf("\n\n");
    }
    //color codes
void green()
{
    printf("\033[1;32m");
}
void reset()
{
    printf("\033[0m");
}
void red()
{
    printf("\033[1;31m");
}
void blue()
{
    printf("\033[0;34m");
}
int main()
{
        system("cls");
        blue();
        printf("\n\t************WELCOME************\n");
        reset();
        green();
        printf("\n\t*********HANGMAN*********\n\n" );
        reset();
        srand(time(0)) ;
        createword();
        char letter;
        int piece=0, result1, result2 ;
        while( piece<9 )
        {
            piece++;
            printf("Enter a letter  : ") ;
            scanf(" %c", &letter) ;
            if(letterControl(letter) )
                piece--;

                tabledraw(piece);

            if(wordControl() )
            {
                green();
                printf("CONGRATULATIONS, YOU WON! The word is %s",word);
                break;
            }
        }
        getch();
        return 0;
}
