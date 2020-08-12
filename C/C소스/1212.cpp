#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE	 (4)
#define DIR_SIZE	 (8)

typedef enum _Direction {
	LUP = 0, UP, RUP,
	LEFT,/*	MID	 */	RIGHT,
	LDOWN, DOWN, RDOWN
} Direction;

const int dirX[DIR_SIZE] = {
		-1,		0,		1,
		-1,	  /*0*/		1,
		-1,		0,		1
};

const int dirY[DIR_SIZE] = {
		-1,	   -1,	   -1,
		0,	  /*0*/		0,
		1,	    1,	    1
};

typedef struct _Array {
	int* offset;

	int length;
	int height;
} Array, *LPArray;

void MakeArray(LPArray lpArr, int len, int high)
{
	lpArr->offset = (int*)malloc(len * high * sizeof(int));

	lpArr->length = len;
	lpArr->height = high;
}

extern inline int* AccessArray(LPArray lpArr, int x, int y)
{
	return (lpArr->offset + (y * lpArr->length) + x);
}

void ReleaseArray(LPArray lpArr)
{
	free(lpArr->offset);
}

int main(void)
{
	Array place;
	int i, j, k;
	int biggest;
	int number;
	int numA, numB;

	srand((unsigned int)time(NULL));

	MakeArray(&place, MAX_SIZE, MAX_SIZE);

	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			number = rand() % 31;
			*AccessArray(&place, j, i) = number;

			printf("%d ", number);
		}

		printf("\n");
	}

	biggest = *AccessArray(&place, 0, 0) * *AccessArray(&place, 0, 1);
	for (i = 0; i < MAX_SIZE; i++)	//Y-Axis
	{
		for (j = 0; j < MAX_SIZE; j++)	//X-Axis
		{
			for (k = 0; k < DIR_SIZE; k++)	//Direction
			{
				if ((dirX[k] + j) >= 0 && (dirX[k] + j) < MAX_SIZE)
				{
					if ((dirY[k] + i) >= 0 && (dirY[k] + i) < MAX_SIZE)
					{
						numA = (*AccessArray(&place, dirX[k] + j, dirY[k] + i));
						numB = (*AccessArray(&place, j, i));

						number = numA * numB;

						if (number > biggest)
							biggest = number;
					}
				}
			}
		}
	}

	printf("%d \n", biggest);

	ReleaseArray(&place);

	return 0;
}
