#include <iostream>
using namespace std; 

void print_tic_tac_toe(void);

char ttt[3][3]; //Global variable, state in which all are initialized as null.

int main(void)
{
	int x, y, play = 1; //x, y is the coordinate point, play is the variable that tells you who the current player is.
	int count = 0;      //If the winning condition is not met when the count is 9.
	char player = 'O';  //The first player is coded to be 1 ("O") followed by 2 ("X")
	print_tic_tac_toe();//Print out the first game.

	while (1) {
        cout << "[Play " << play % 2 << "] Enter your location[x y]:";  //input value 
		scanf_s("%d", &x);
		scanf_s("%d", &y);

		if (x == -1 || y == -1) {                       //Determine if the value is normal
			cout << "tic-tac-toe 종료 !!" << endl;
			break;
		}
		if ((x > 2 || x < 0) || (y > 2 || y < 0)) {     //Determine if the value is normal
			cout << "범위를 벗어났습니다." << endl;
			continue;
		}
        if (ttt[y][x] != NULL){                         //Not Null = Stones already placed.
            cout << "이미 둔 곳입니다" << endl;
            continue;
        }

		if (ttt[y][x] == NULL) {
            if (player == 'O') {    //Player 1
				ttt[y][x] = 'O';
				print_tic_tac_toe();
				count++;
				player = 'X';
			}
			else {                  //Player 2 
				ttt[y][x] = 'X';
				print_tic_tac_toe();
                count++;
                player = 'O';
		    }
        }

        if (ttt[0][0] == 'O' and ttt[0][1] == 'O' and ttt[0][2] == 'O') {       //Player 1 winning conditions
            printf("Winner is[Player 1]");
            break;
        }
        else if (ttt[1][0] == 'O' and ttt[1][1] == 'O' and ttt[1][2] == 'O') {
            printf("Winner is[Player 1]"); 
            break;
        }
        else if (ttt[2][0] == 'O' and ttt[2][1] == 'O' and ttt[2][2] == 'O') {
            printf("Winner is[Player 1]");
            break;
        }
        else if (ttt[0][0] == 'O' and ttt[1][0] == 'O' and ttt[2][0] == 'O') {
            printf("Winner is[Player 1]");
            break;
        }
        else if (ttt[0][1] == 'O' and ttt[1][1] == 'O' and ttt[2][1] == 'O') {
            printf("Winner is[Player 1]");
            break;
        }
        else if (ttt[0][2] == 'O' and ttt[1][2] == 'O' and ttt[2][2] == 'O') {
            printf("Winner is[Player 1]");
            break;
        }
        else if (ttt[0][0] == 'O' and ttt[1][1] == 'O' and ttt[2][2] == 'O') {
            printf("Winner is[Player 1]");
            break;
        }
        else if (ttt[0][2] == 'O' and ttt[1][1] == 'O' and ttt[2][0] == 'O') {
            printf("Winner is[Player 1]");
            break;
        }  

        if (ttt[0][0] == 'X' and ttt[0][1] == 'X' and ttt[0][2] == 'X') {       //Player 2 winning conditions
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[1][0] == 'X' and ttt[1][1] == 'X' and ttt[1][2] == 'X') {
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[2][0] == 'X' and ttt[2][1] == 'X' and ttt[2][2] == 'X') {
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[0][0] == 'X' and ttt[1][0] == 'X' and ttt[2][0] == 'X') {
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[0][1] == 'X' and ttt[1][1] == 'X' and ttt[2][1] == 'X') {
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[0][2] == 'X' and ttt[1][2] == 'X' and ttt[2][2] == 'X') {
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[0][0] == 'X' and ttt[1][1] == 'X' and ttt[2][2] == 'X') {
            printf("Winner is[Player 2]");
            break;
        }
        else if (ttt[0][2] == 'X' and ttt[1][1] == 'X' and ttt[2][0] == 'X') {
            printf("Winner is[Player 2]");
            break;
        } 

        if (count == 9) {
            printf("Draw");
            break;
        }   //draw 
	}       // end while 
	return 0;
}

void print_tic_tac_toe(void)
{
	int i;
	printf(" X 0   1   2\n");
	printf("Y ---|---|--- \n");
	for (i = 0; i < 3; i++) {
		printf("%d  %c | %c | %c  \n", i, ttt[i][0], ttt[i][1], ttt[i][2]);
		printf("  ---|---|--- \n");
	}
}