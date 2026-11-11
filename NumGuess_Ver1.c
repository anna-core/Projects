#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int secret_num,guess;
    int attempts,choice;
    int highscore=0;

    srand(time(0));//Sets the seed
    printf("\n\033[1;36mWELCOME TO THE NUMBER GUESSING GAME\033[0m\n");

    do
    {   attempts=0;
        secret_num=rand()%100+1;//Selects the random number
        printf("\nI have selected a number between 1 & 100.CAN YOU GUESS IT??\n(The number can be 1 or 100 too)\n\n");
        
        do
        {
            printf("Enter your guess: ");
            scanf("%d",&guess);
            attempts++;

            if(guess<1 || guess>100){
                printf("The guess should be numbers from 1 to 100 my dear...\n\n");
            }

            else if(guess>secret_num){
                printf("Nah bro.Go lower...\n\n");
            }

            else if(guess<secret_num){
                printf("Nope.Go higher my brother.Try again...\n\n");
            }

            else{
                printf("\n\033[1;32mYayyy!!YOU WON!!Congratulations!!\033[0m\n");
                printf("Number of attempts: %d\n",attempts);
            }
        }while(guess!=secret_num);

        if(highscore==0 || attempts<highscore){
            highscore=attempts;
            printf("\n\033[1;32mNEW HIGH SCORE!!!\033[0m\n");
        }

        printf("\nCurrent High Score: %d\n\n",highscore);
        printf("==============================================================");
        printf("\nMENU:\n\n1.Play Again\n2.Exit\n");
        printf("==============================================================");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        if(choice!=1 && choice!=2){
            printf("Invalid choice.Enter your choice once again: ");
            scanf("%d",&choice);
        }

    }while(choice==1);

    printf("\n\033[1;36mThanks for Playing...!\033[0m\n"); 
    printf("Your Final High Score: %d attempts\n\n",highscore);

    return 0;
}