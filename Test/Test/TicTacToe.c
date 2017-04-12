#include <stdio.h>

void clear_board(int grid[3][3]);
void display_board(int grid[3][3]);
int place_move(int player, int grid[3][3]);
//void check_win(int player, char ** grid[]);
char piece = 0;



void clear_board(int grid[3][3])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] =  '_' ;
		}
	}
}


int main (void)
{

	int grid[3][3] = { 0 };
	int player = 0;
	int winner = 0;
	

	printf("Welcome to Tic Tac Toe. \n");
	while (winner == 0)
	{
		clear_board(grid);			// Passes the grid to the clear_board function
		display_board(grid);		// Passes the grid to the display_board function
		printf("X goes first. Please select a grid location. \n");
		//scanf();
		place_move(player,grid);	// Passes the player and grid to the place_move function
		
		getchar();
		return 0;
	}

	
	
	//for (int i = 0; i < 3; i++)		// Clear the array
	//{
	//	for (int j = 0; j < 3; j++)
	//		grid[i][j] = '0';
	//}
}

int place_move(int player, int grid[3][3])
{
	int i = 0;
	int j = 0;
	if (player = 0)		//Player X
	{
		//piece = 'X';
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid[i][j] = 'X';
			}
		}
	}
	else if (player == 1)
	{

	}
	else
	{

	}
}


//void check_win(int player, char ** board[3][3])
//{
//	return 0;
//}


void display_board(int grid[3][3])
{
	int i = 0;
	int j = 0;
	printf("\n\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] == '_')
			{
				printf(" %2d ", 3 * (i)+(j + 1));
			}
			else
			{
				printf(" %c  ", grid[i][j]);
			}
			if (j != 3)
			{
				printf("|");
			}
		}

		if (i != 3)
		{
			printf("\n---------------\n");
		}
	}
//return 0;
}