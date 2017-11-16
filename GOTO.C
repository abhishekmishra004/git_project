#include<stdio.h>
#include<conio.h>
#include<windows.h>

int point1=0,point2=0;
char choice1,choice2,game[9];
void position(int input);
int play(char choice);
int winning(char,int);




void gotoxy(short x, short y)
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 



int main()
  {
    char y_or_n;
    int i,j;
again:
    system("cls");
    printf(
	      "\n\t\tWelcome to two player tic tac toe game..."
	      "\n\t Here are some rules:\n"
	      "\t1. The movement is controled by the numbers like\n"
	      "\n\t  1|  2|  3\n\t -----------\n\t  4|  5|  6\n\t -----------\n\t  7|  8|  9\n"
	       "\t       * Press the number in where you want to give the value."
           "\n\t2. please try to give the correct values. \n"
	       "\n\t3. Any one who make the first combination of X/O wins all the best :-). \n"
	       
	  );
      printf("\n\n\tPress 'Y/y' to play or 'N/n' for exiting :");
      scanf("%c",&y_or_n);
      if(y_or_n == 'y' || y_or_n == 'Y')
	   {
	      printf("\n\tEnter player 1 choice X or O :") ;
	      scanf(" %c", &choice1);
	      play(choice1);
	   }
      else if(y_or_n == 'n' || y_or_n == 'N')
	   return 0;
      else
	    goto again;
	    gotoxy(0,16);     // Displaying the value of matrix
	  
    return 0;
  }




  int play(char choice1)
  { 	
  replay:
	char more,win_player;
	int win=1,input=0,turn=0,i=0;
	for(int a=0;a<9;a++)
	   game[a]=a+1;
    system("cls");
    printf("\n\n\t\tlets start the game:\n");
    if(choice1 == 'o')
      choice2='x';
    else
      choice2='o';
    printf("\n\tplayer1(%c) point:%d",choice1,point1);
    printf("\t\t\tplayer2(%c) point:%d",choice2,point2);
    printf("\n\n\t\t  1|  2|  3\n\t\t-----------\n\t\t  4|  5|  6\n\t\t-----------\n\t\t  7|  8|  9\n\n");
    while(win == 1 && i<9)
    {


	if((turn %2)==0)   // will run for player 1
	{

		gotoxy(4,12);
		printf("\n\tPlayer 1 input(and press enter):");
		scanf(" %d", &input);
		position(input);
		printf("%c",choice1);
		turn++;
		i++;
		win=winning(choice1,input);
        if(win == 2)
        {
		   win_player=choice1;
		   point1++;
	    }
	}
	else      // will run for player 2
	{

		gotoxy(4,13);
		printf("\n\tPlayer 2 input(and press enter):");
		scanf("%d",&input);
		gotoxy(19,12);
		position(input);
		printf("%c",choice2);
		turn++;
		i++;
		win=winning(choice2,input);
        if(win == 2)
		{
            win_player=choice2;
            point2++;
        }
		}
	}
	
	if(win == 2)
	{
		gotoxy(5,15);
        printf("\nPlayer who wins selected %c option :-)",win_player); 
        printf("\nDo you want to play again(y/n):");
		scanf(" %c", &more);
		if(more == 'y' || more == 'Y')
		   goto replay;
		else
		 return 0;
	}
	else if(i == 9)
	{
		gotoxy(5,15);
		printf("\n Match draw Do you want to play again(y/n):");
		scanf(" %c", &more);
		if(more == 'y' || more == 'Y')
		   goto replay;
		else
		 return 0;
	}  
	  
	  
	
    getch();
    return 0;
  }




  void position(int input) // moving the cursiour position for x and o in printf statement
  {
	if(input==1)
	  gotoxy(18,6);
	else if(input== 2)
	  gotoxy(22,6);
	else if(input==3)
	  gotoxy(26,6);
	else if(input==4)
	  gotoxy(18,8);
	else if(input==5)
	  gotoxy(22,8);
	else if(input==6)
	  gotoxy(26,8);
	else if(input==7)
	  gotoxy(18,10);
	else if(input==8)
	  gotoxy(22,10);
	else
	  gotoxy(26,10) ;
  }





  int winning(char choice,int input) // winning condition
{

	int send=2,i,j;

			    //inputing the data in game[3][3] matrix
	if(input == 1)
	  game[0]=choice;
   else if(input == 2)
	  game[1]=choice;
   else	if(input == 3)
	  game[2]=choice;
   else if(input == 4)
	  game[3]=choice;
   else if(input == 5)
	  game[4]=choice;
   else if(input == 6)
	  game[5]=choice;
   else  if(input == 7)
	  game[6]=choice;
   else if(input == 8)
	  game[7]=choice;
    else
	  game[8]=choice;



			  //wining logic

      
	if(game[0] == game[1] && game[1] == game[2])
		return send;
	else if(game[3] == game[4] && game[4] == game[5])
		return send;
	else if(game[6] == game[7] && game[7] == game[8])
		return send;
	else if(game[0] == game[3] && game[3] == game[6])
		return send;
	else if(game[1] == game[4] && game[4] == game[7])
		return send;
	else if(game[2] == game[5] && game[5] == game[8])
		return send;
	else if(game[0] == game[4] && game[4]  == game[8])
		return send;
	else if(game[2] == game[4] && game[4]== game[6])
		return send;
	else
		return 1;

   }
