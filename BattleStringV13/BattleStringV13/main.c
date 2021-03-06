#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// BATTLESTRING by Esteban Marin

int main()
{
	srand(time(NULL));
	char randxlvl, lvl, i, j;
	char shotx = 8;
	char shield = 20;
	int score = 0;

	printf("-----WELCOME TO BATTLESTRING----- by Esteban Marin\n\n");
	Sleep(1000);
	printf("You must destroy the enemy ships by firing from 1 to 8\n\n");
	Sleep(1000);
	printf("You can shoot two bullets to the maximum.");
	Sleep(1000);
	printf("GOOD LUCK!!!\n\n");
	Sleep(1000);
	printf("== PRESS ENTER KEY! ==");
	getchar();

	lvl = 25;
	// BATTLE MAP
	char battlemap[13][10] = {
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-' },
		{ ' ', '1', '2', '3', '4', '5', '6', '7', '8', ' ' },
	};


	do
	{
		system("cls");
		// MAP printing
		printf("     BATTLEMAP\n");
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 10; j++)
			{
				printf("%c ", battlemap[i][j]);
			}
			printf("\n");

		}

		// Crash
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (battlemap[i][j] == 'V' && battlemap[i + 1][j] == '*')
				{
					battlemap[i][j] = ' ';
					battlemap[i + 1][j] = ' ';
					score += 10;
				}
			}
		}
		
		// SHOOT & LIFES
		for (j = 1; j < 9; j++)
		{
			if (battlemap[0][j] == '*')
			{
				battlemap[11][j] = ' ';
			}
		}
		
		//Movement of the bullet
		for (i = 1; i < 13; i++)
		{
			for (j = 1; j < 9; j++)
			{
				if (battlemap[i][j] == '*')
				{
					battlemap[i - 1][j] = '*';
					battlemap[i][j] = ' ';
				}
			}
		}
		
		//Top bullet removed
		for (j = 1; j < 9; j++)
		{
			if (battlemap[0][j] == '*')
			{
				battlemap[0][j] = ' ';
			}
		}
		
		printf("SCORE        SHIELD");
		printf("\n%i    \t\t  %i\nX: ", score, shield);
		
		//Bullets fired
		scanf_s("%i%i", &shotx1, &shotx2);
		battlemap[11][shotx1] = '*';
		battlemap[11][shotx2] = '*';



		// ENEMY MOVEMENT
		for (i = 10; i > -1; i--)
		{
			for (j = 1; j < 9; j++)
			{
				if (battlemap[i][j] == 'V')
				{
					battlemap[i + 1][j] = 'V';
					battlemap[i][j] = ' ';
				}
			}
		}
		
		/// Enemy generator & LEVEL RISING
		if (lvl == 25)
		{
			battlemap[0][7] = 'V';
		}

		for (j = 1; j < 9; j++)
		{
			randxlvl = rand() % lvl;
			if (randxlvl == 1)
			{
				battlemap[0][j] = 'V';
			}
		}
		if (lvl != 2)
		{
			lvl--; // THIS LINE RISE THE ENEMIES' SPAWNING CHANGE
		}
		/// PLAYER HIT & LIFES
		for (j = 1; j < 9; j++)
		{
			if (battlemap[11][j] == 'V')
			{
				shield--;
				battlemap[11][j] = ' ';
			}
		}
		
		//GAME OVER
		if (shield <= 0)
		{
			system("cls");
			shield = 0;
			for (j = 1; j < 9; j++)
			{
				battlemap[2][j] = '-';
				battlemap[5][j] = '-';
			}
			battlemap[3][1] = ' ';
			battlemap[3][2] = ' ';
			battlemap[3][3] = 'G';
			battlemap[3][4] = 'A';
			battlemap[3][5] = 'M';
			battlemap[3][6] = 'E';
			battlemap[3][7] = ' ';
			battlemap[3][8] = ' ';
			battlemap[4][1] = ' ';
			battlemap[4][2] = ' ';
			battlemap[4][3] = 'O';
			battlemap[4][4] = 'V';
			battlemap[4][5] = 'E';
			battlemap[4][6] = 'R';
			battlemap[4][7] = ' ';
			battlemap[4][8] = ' ';
			
			//GAME OVER PRINTING
			printf("     BATTLEMAP\n");
			for (i = 0; i < 13; i++)
			{
				for (j = 0; j < 10; j++)
				{
					printf("%c ", battlemap[i][j]);
				}
				printf("\n");
			}
			printf("SCORE        SHIELD");
			printf("\n%i    \t\t  0\n", score);

			getchar();
			exit(0);
		}
	} while (shield >= -3);



	getchar();
	return 0;
}
