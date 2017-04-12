//Purpose: Two players battle in the classic game tic tac toe until one is proclaimed victor!

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void print_grid(char board[3][3]);
int didwin(char board[3][3]);

int main(void)
{
	int i = 0;
	int j = 0;
	int player = 0;
	int lead = 0;
	int nrows = 0;
	int ncols = 0;
	int winner = 0;
	char again='q';
	char three_X_three[3][3];
  
  while(winner == '\0') 	// Winner = 0
  {
	for(i = 0; i < 3; i++) 
	{
	  for(j = 0; j<3; j++) 
	  {
		three_X_three[i][j] = '\0';
	  }
	}
	
	for( i = 0; i < 9 && winner==0; i++)
	  { 
		print_grid(three_X_three);
	player = i%2 + 1;
	
	if(player==1)
	{
	  printf("\n Player %d, please enter the number of the square "
		 "where you want to place your %c: ",player,'X');
	}
	else if(player==2) 
	{
	  printf("\n Player %d, please enter the number of the square "
		 "where you want to place your %c: ", player,'O');
	}
	scanf("%d", &lead);
	lead--;
	ncols = lead%4;
	lead = lead - ncols;
	nrows = lead/3;  
	
	if(lead < 0 || lead > 16 || three_X_three[nrows][ncols]=='X' || three_X_three[nrows][ncols]=='O') 
	{
	  printf("Space is already taken, please try again");	
	  i--;
	}
	else 
	{
		three_X_three[nrows][ncols] = (player == 1) ? 'X' : 'O';
	}
	winner = didwin(three_X_three);
	  }
	if(winner != '\0') 
	{
	  printf("Winner was %c! Good job.\n",winner);
	  printf("Do you want to play again? y/n: ");
	  while(!(again == 'y' || again == 'n')) 
	  {
		scanf("%c",&again);
	  }
	  if(again == 'y') 
	  {
		winner = '\0';
		again = 'q';
	  }
	}
	else 
	{
	  printf("No winner this round. Try again.");
	}
  }
  return 0;
}
void print_grid(char board[3][3]) 
{
  int i,j;
  printf("\n\n");
  for(i = 0; i < 3; i++) 
  {
	for(j = 0; j < 3; j++) 
	{
	  if(board[i][j] == '\0') 
	  {
		printf(" %2d ", 3*(i)+(j+1));
	  }
	  else 
	  {
		printf(" %c  ", board[i][j]);
	  }
	  if(j!=3) 
	  { 
		printf("|"); 
	  }
	}
	
	if(i != 3) 
	{
	  printf("\n-------------------\n");
	}
  }
}

int didwin(char board[3][3]) 
{
  int i,j;
  char current;
  char winner = '\0';

  //Iter over rows to check for winner
  for(i = 0; i<3; i++) 
  {
	current = board[i][0];
	for(j = 0; j < 3; j++) 
	{
	  if(board[i][j] != current) 
	  {
		current = '\0';
	  }
	}
	if(current != '\0') 
	{
	  winner = current;
	}
  }

  //Iter over columns
  for(i = 0; i<3; i++) 
  {
	current = board[0][i];
	for(j = 0; j < 3; j++) 
	{
	  if(board[j][i] != current) 
	  {
		current = '\0';
	  }
	}
	
	if(current != '\0') 
	{
	  winner = current;
	}
  }

  //Iter over diagonals
  current = board[0][0];
  for(i = 0; i < 3; i++) 
  {
	if(board[i][i] != current) 
	{
	  current = '\0';
	}
  }
  
  if(current != '\0') 
  {
	winner = current;
  }
  
  current = board[0][3];
  for(i = 0; i <3; i++) 
  {
	if(board[i][3-i] != current) 
	{
	  current = '\0';
	}
  }
  if(current != '\0') 
  {
	winner = current;
  }
  return winner;
}