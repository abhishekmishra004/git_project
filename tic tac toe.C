#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <unistd.h>
int point1=0,point2=0;
char choice1,choice2;
int position(int input,char game[]);
int play(char choice,char game[]);
int winning(char,int,char game[]);






void gotoxy(short x, short y)
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 


void loading()
{
	system("cls");
	gotoxy(12,12);
	printf("loading please wait!!\n");
	gotoxy(12,13);
	for(int i=0;i<8;i++)
	{
		printf(" :");
		sleep(1);
	}
}



int main()
  {
    char y_or_n;
    char game[]={'1','2','3','4','5','6','7','8','9'};
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
	       "\n\t4. If you had Win the game Then It will resume again \n"
	       
	       
	  );	  
      printf("\n\n\tPress 'Y/y' to play or 'N/n' for exiting :");
      scanf("%c",&y_or_n);
      if(y_or_n == 'y' || y_or_n == 'Y')
	   {
	      printf("\n\tEnter player 1 choice X or O :") ;
	      scanf(" %c", &choice1);
	      if(choice1 == 'x' || choice1 == 'o' || choice1 == 'X' || choice1 == 'O'){
	        loading();
			play(choice1,game);
	       }
	      else
		    goto again; 
	   }
      else if(y_or_n == 'n' || y_or_n == 'N')
	   return 0;
      else
	    goto again;
	    gotoxy(0,16);     // Displaying the value of matrix
	  
    return 0;
  }




  int play(char choice1,char game[])
  { 
    	
	char more,win_player;
	int win=1,input=0,turn=0,draw=0,check;

    system("cls");
    printf("\n\n\t\tlets start the game:\n");
    if(choice1 == 'o')
      choice2='x';
    else
      choice2='o';
    printf("\n\tplayer1(%c) point:%d",choice1,point1);
    printf("\t\t\tplayer2(%c) point:%d",choice2,point2);
    printf("\n\n\t\t  1|  2|  3\n\t\t-----------\n\t\t  4|  5|  6\n\t\t-----------\n\t\t  7|  8|  9\n\n");
    while(win == 1 && draw<9)
    {

    player1:
	if((turn %2)==0)   // will run for player 1
	{

		gotoxy(4,12);
		printf("\n\tPlayer 1 input(and press enter):");
		scanf(" %1d", &input);
		check=position(input,game);
		if(check == 1)
		   printf("%c",choice1);
		else
		   goto player1;   
		turn++;
		draw++;
		win=winning(choice1,input,game);
        if(win == 2)
        {
		   win_player=choice1;
		   point1++;
	    }
	}
	else      // will run for player 2
	{
     player2:
		gotoxy(4,13);
		printf("\n\tPlayer 2 input(and press enter):");
		scanf("%1d",&input);
		gotoxy(19,12);
		check=position(input,game);
		if (check==1)
		    printf("%c",choice2);
		else
		   goto player2;    
		turn++;
		draw++;
		win=winning(choice2,input,game);
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
        printf("\nPlayer who wins selected %c option (press enter):-)",win_player); 
        getch();
		main();
		
	}
	else if(draw == 9)
	{
		gotoxy(5,15);
		printf("\n Match draw Do you want to play again(y/n):");
		getch();
		main();
	}  
	  
	  
	
    getch();
    return 0;
  }




  int position(int input,char game[]) // moving the cursiour position for x and o in printf statement
  {
  	
	if(input==1 && game[0] =='1')
	{
	  gotoxy(18,6);
	  return 1;}
	  
	else if(input== 2 && game[1] =='2')
	{
	  gotoxy(22,6);
	  return 1;}
	  
	else if(input==3 && game[2] =='3')
	{
	  gotoxy(26,6);
	  return 1;}
	  
	else if(input==4&& game[3] =='4')
	{
	  gotoxy(18,8);
	  return 1;}
	  
	else if(input==5 && game[4] =='5')
	{
	  gotoxy(22,8);
	  return 1;}
	  
	else if(input==6 && game[5] =='6')
	{
	  gotoxy(26,8);
	  return 1;}
	  
	else if(input==7 && game[6] =='7')
	{
	  gotoxy(18,10);
	  return 1;}
	  
	else if(input==8 && game[7] =='8')
	{
	  gotoxy(22,10);
	  return 1;}
	else if(input == 9 && game[8] =='9')
	  {
	  gotoxy(26,10) ;
	  return 1;}
     
  }




  int winning(char choice,int input,char game[]) // winning condition
{


	int send=2,i,j;

			    //inputing the data in game[3][3] matrix
	if(input == 1 ){
	  if(game[0] =='1')
	      game[0]=choice;}
	      
	      
   else if(input == 2 ){
        if(game[1] =='2' )
	      game[1]=choice;}
	      
	      
   else	if(input == 3){
        if (game[2] =='3')
	      game[2]=choice;}
	      
	      
   else if(input == 4){
        if (game[3] =='4')
          game[3]=choice;}
          
          
   else if(input == 5){
        if(game[4] =='5' )
	      game[4]=choice;}
	      
	      
   else if(input == 6){
        if(game[5] =='6' )
	      game[5]=choice;}
	      
	      
   else if(input == 7){
        if(game[6] =='7' )
	      game[6]=choice;}
	      
	      
   else if(input == 8){
        if (game[7] =='8')
	      game[7]=choice;}
	      
	      
    else 
	    {
		 if(game[8] =='9')
	        game[8]=choice;
	     }



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
