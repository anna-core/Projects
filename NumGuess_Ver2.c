//Project: Number Guessing Game_Version 2
//Author : Anna Roy
//Date   : 13/11/2026
/*Description:
    This is a number guesssing game where the player guesses a randomly generated number.The range of number is chosen according to selected difficulty.

    New Features:
    -Added 3 difficulty levels:Easy,Medium and Hard.The maximum number that the computer generates for guessing will be based on this difficulty level.

    What I newly learned:
    -More ANSI escape codes for terminal colours and formatting
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{   
    int maxnum;
    int secret_num,guess;
    int attempts,choice,d;
    int highscore=0;

    srand(time(0));//Sets the seed
    printf("\n\033[1;36mWELCOME TO THE NUMBER GUESSING GAME\033[0m\n");

    do
    {   
        //To select difficulty level
        printf("\033[1;34m\nDifficulty Levels:\033[0m\n");
        printf("\033[3;32m1.Easy\033[0m\n\033[3;33m2.Medium\033[0m\n\033[3;31m3.Hard\033[0m\n");
        printf("\033[34mChoose your difficulty level: \033[0m");
        scanf("%d",&d);

        //To select the maximum number based on difficulty level
        switch(d){
            case 1:
                maxnum=50;
                break;
            case 2:
                maxnum=100;
                break;
            case 3:
                maxnum=500;
                break;
            default:
                printf("Invalid choice.Medium level selected as default.\n");
                maxnum=100;
        }

        attempts=0;
        secret_num=rand()%maxnum+1;//Selects the random number
        printf("\033[36m\nI have selected a number between 1 & %d.CAN YOU GUESS IT??\n(The number can be 1 or %d too)\n\n\033[0m",maxnum,maxnum);
        
        do
        {
            printf("Enter your guess: ");
            scanf("%d",&guess);
            attempts++;

            if(guess<1 || guess>maxnum){
                printf("The guess should be numbers from 1 to %d my dear...\n\n",maxnum);
            }

            else if(guess>secret_num){
                printf("Nah bro.Go lower...\n\n");
            }

            else if(guess<secret_num){
                printf("Nope.Go higher my brother.Try again...\n\n");
            }

            else{
                printf("\n\033[1;32mYayyy!!YOU WON!!Congratulations!!\033[0m\n");
                printf("\033[34mNumber of attempts: %d\033[0m\n",attempts);
            }
        }while(guess!=secret_num);

        if(highscore==0 || attempts<highscore){
            highscore=attempts;
            printf("\n\033[1;32mNEW HIGH SCORE!!!\033[0m\n");
        }

        printf("\n\033[35mCurrent High Score: %d\033[0m\n\n",highscore);
        printf("==============================================================");
        printf("\n\033[1;36mMENU:\033[0m\n\033[1;32m1.Play Again\033[0m\n\033[1;31m2.Exit\033[0m\n");
        printf("==============================================================");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        while(choice!=1 && choice!=2){
            printf("Invalid choice.Enter your choice once again: ");
            scanf("%d",&choice);
        }

    }while(choice==1);

    printf("\n\033[1;36mThanks for Playing...!\033[0m\n"); 
    printf("\033[1;36mYour Final High Score: %d attempts\033[0m\n\n",highscore);

    return 0;
}
