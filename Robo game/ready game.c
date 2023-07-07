#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

char box[15][15];
int i,j;
int position[2]= {0,0};
int Dead = 0;
int Win = 0;
int main()
{
    details();
    character_box();
    displaybox();
    input();

    getch();
    return 0;
}
//Information and the details
 void details()
{
     blue();
    char senta[]="*********************WELCOME TO ROBO GAME *******************\n\n*************GAME RULES*************";

     int x;
     int size;
     size=strlen(senta);
     for(x=0;x<size;x++)
    {
        Sleep(25);
        printf("%c",senta[x]);
    }
    green();
    char rule[]="\n01.In this game you are playing as a ROBOT('R')who want to reach the winning point(W).\n02.You can move up('W'), down('S'), left('A') or right('D').\n03.If you go for the Bomb('*') you'll be dead.\n";
    for(x=0;x<197;x++)
    {
        Sleep(20);
        printf("%c",rule[x]);
    }
    reset();
    yellow();
    char start[]="***** START PLAYING *******\n\n";
    for(x=0;x<30;x++)
    {
        Sleep(30);
        printf("%c",start[x]);
    }
}
//The frame of the Game
void character_box()
{

    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
        box[i][j]='-';
        }
    }
    box[0][0] ='R';
    box[13][13] = 'W';
    box[0][5] = '*';
    box[7][0] = '*';
    box[3][12] = '*';
    box[13][11] = '*';
    box[12][2] = '*';
    box[11][10] = '*';
    box[2][9] = '*';
    box[14][4] = '*';
    box[0][11] = '*';
    box[7][11] = '*';
    box[14][1] = '*';
    box[10][12] = '*';
    box[11][0] = '*';
    box[5][14] = '*';
    box[11][6] = '*';
    box[10][0] = '*';
    box[5][10] = '*';
    box[13][0] = '*';
    box[6][13] = '*';
    box[13][7] = '*';
    box[9][9] = '*';
    box[0][14] = '*';
    box[14][14] = '*';
    box[10][5] = '*';
    box[14][9] = '*';
    box[8][14] = '*';
    box[10][2] = '*';
    box[11][8] = '*';
    box[12][13] = '*';
    box[1][11] = '*';
    box[9][3] = '*';
    box[0][7] = '*';
    box[1][1] = '*';
    box[1][3] = '*';
    box[2][2] = '*';
    box[2][5] = '*';
    box[2][7] = '*';
    box[3][1] = '*';
    box[3][3] = '*';
    box[4][2] = '*';
    box[4][5] = '*';
    box[4][8] = '*';
    box[5][1] = '*';
    box[5][4] = '*';
    box[5][7] = '*';
    box[6][3] = '*';
    box[6][6] = '*';
    box[7][2] = '*';
    box[7][4] = '*';
    box[7][8] = '*';
    box[8][1] = '*';
    box[8][5] = '*';
    box[8][7] = '*';

}
//Stracture of the game
void displaybox()
{
    if(Dead==1)
    {
        red();
        printf("\n ------GAME OVER---------");
        reset();
        return;
    }
    else if(Win==1)
    {
        green();
        printf("\n --------BOYAAHHHH!!-----------");
        reset();

    }
    else
    {
        for(i=0; i<15; i++)
        {
            for(j=0; j<15; j++)
            {
                switch(box[i][j])
                {
                case '*':
                    red();
                    break;
                case 'W':
                    yellow();
                    break;
                case 'R':
                    cyan();
                    break;
                default:
                   purple();
                    break;
                }
                printf(" %c ",box[i][j]);
                reset();
            }
            printf("\n");
        }
    }

}
//Controls: All the input of the game takes in here
void input()
{
    char key;
    do
    {
        if(Dead==1 || Win==1)
            break;
        printf("\nEnter Your movement key:\n");
        scanf("%c",&key);
        switch(key)
        {
        case 'w':
        {
            if(box[position[0]-1][position[1]] == '*')
            {
                Dead = 1;
                break;
            }
            else if(box[position[0]-1][position[1]] == 'W')
            {
                Win = 1;
                break;
            }
            else if(position[0]!=0)
            {
                box[position[0]][position[1]]='-';
                position[0]=position[0]-1;
            }
            break;
        }
        case 's':
        {
            if(box[position[0]+1][position[1]] == '*')
            {
                Dead = 1;
                break;
            }
            else if(box[position[0]+1][position[1]] == 'W')
            {
                Win = 1;
                break;
            }
            else if(position[0]!=15-1)
            {
                box[position[0]][position[1]]='-';
                position[0]=position[0]+1;
            }
            break;
        }
        case 'a':
        {
            if(box[position[0]][position[1]-1] == '*')
            {
                Dead = 1;
                break;
            }
            else if(box[position[0]][position[1]-1] == 'W')
            {
                Win = 1;
                break;
            }
            else if(position[1]!=0)
            {
                box[position[0]][position[1]]='-';
                position[1]=position[1]-1;
            }
            break;
        }
        case 'd':
        {
            if(box[position[0]][position[1]+1] == '*')
            {
                Dead = 1;
                break;
            }
            else if(box[position[0]][position[1]+1] == 'W')
            {
                Win = 1;
                break;
            }
            else if(position[1]!=15-1)
            {
                box[position[0]][position[1]]='-';
                position[1]=position[1]+1;
            }
            break;
        }
        case '0':
        {
            Dead = 1;
        }
        }
        box[position[0]][position[1]]='R';
         system("cls");
        displaybox();
    }
    while(Dead != 1 || Win!=1);

}

//color code
void reset()
{
    printf("\033[0m");
}

void purple()
{
    printf("\033[1;35m");
}

void cyan()
{
    printf("\033[1;36m");
}

void green()
{
    printf("\033[1;32m");
}

void yellow()
{
    printf("\033[1;33m");
}

void red()
{
    printf("\033[1;31m");
}
void blue()
{
    printf("\033[0;34m");
}
void white()
{
    printf("\033[0;37m");
}

