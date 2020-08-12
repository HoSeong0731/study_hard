//7장 52쪽  
#include<stdio.h>
void print_tic_tac_toe(void);
//전열변수 global variable, 자동 초기화  
char ttt[3][3];

int main(void)
{
	int x, y;
	char player = 'O';
	//print_tic_tac_toe();

	while (1) {
		printf("(x,y) 좌표 (종료 -1,-1):");
		scanf("%i,%i", &x, &y);

		if (x == -1 || y == -1) {
			printf("tic-tac-toe 종료 !!\n");
			break;
		}
		if ((x > 2 || x < 0) || (y > 2 || y < 0)) {
			printf("범위를 벗어났습니다.\n");
			continue;
		}


		if (ttt[x][y] == NULL) {
			if (player == 'O') {
				ttt[x][y] = 'O';
				print_tic_tac_toe();
				player = 'X';
				if (ttt[0][0] == 'O') {
					if (ttt[0][1] == 'O') {
						if (ttt[0][2] == 'O') {
							printf("O가 승자입니다!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'O') {
							if (ttt[2][0] == 'O') {
								printf("O가 승자입니다!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'O') {
								if (ttt[2][2] == 'O') {
									printf("O가 승자입니다!");
									break;
								}
							}
						}
					}
				}
				else {
					if (ttt[0][1] == 'X') {
						if (ttt[0][2] == 'X') {
							printf("X가 승자입니다!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'X') {
							if (ttt[2][0] == 'X') {
								printf("X가 승자입니다!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'X') {
								if (ttt[2][2] == 'X') {
									printf("X가 승자입니다!");
									break;
								}
							}
						}
					}
				}
			}
			else {  //player='X'인 경우  
				ttt[x][y] = 'X';
				print_tic_tac_toe();
				player = 'O';
				if (ttt[0][0] == 'O') {
					if (ttt[0][1] == 'O') {
						if (ttt[0][2] == 'O') {
							printf("O가 승자입니다!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'O') {
							if (ttt[2][0] == 'O') {
								printf("O가 승자입니다!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'O') {
								if (ttt[2][2] == 'O') {
									printf("O가 승자입니다!");
									break;
								}
							}
						}
					}
				}
				else {
					if (ttt[0][1] == 'X') {
						if (ttt[0][2] == 'X') {
							printf("X가 승자입니다!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'X') {
							if (ttt[2][0] == 'X') {
								printf("X가 승자입니다!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'X') {
								if (ttt[2][2] == 'X') {
									printf("X가 승자입니다!");
									break;
								}
							}
						}
					}
				}
			}
		}
		else {//ttt[x][y] != NULL 인 경우 
			printf("이미 둔 곳입니다\n");
			continue;
		}

	}// end while

	return 0;
}

void print_tic_tac_toe(void)
{
	int i;
	for (i = 0; i < 3; i++) {
		printf("---|---|--- \n");
		printf(" %c | %c | %c  \n", ttt[i][0], ttt[i][1], ttt[i][2]);
	}
	printf("---|---|--- \n");

	return;
}


/*
#include <stdio.h>
int main(void)
{
    int board[3][3] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 }; // 게임 보드, 각 칸의 번호
    int player = 0; // player ID 0,1 두명의 플레이어
    int x, y; // 착수 위치
    int choice = 0; // 진행한 횟수   
 
    int Bingo(int ary[3][3], int n); // 승패 결정 함수 선언
 
    while (1) // 별다른 조건없이 무한반복
    {
        // 착수 위치 입력
        do
        {
            printf("player [%d]의 착수 위치(x,y)를 입력하시오 : ", player);
            scanf("%d %d", &x, &y); // 착수 위치 입력받기
 
            if (board[x][y] < 11 || x>2 || x<0 || y>2 || y<0) {
                printf("\n잘못된 입력입니다. 다시 입력하세요.\n\n");
            } // 잘못된 입력값을 받기위한 조건문
 
        } while (board[x][y] < 11 || x>2 || x<0 || y>2 || y<0); // 입력값이 정확하면 빠져나옴
 
        choice++; // 진행한 횟수 1증가
 
        if (player == 0) {
            board[x][y] = 1; // player 0은 보드판에 1을 입력
            player = 1; //플레이어 전환
        }
 
        else {
            board[x][y] = 2; // player 1은 보드판에 2를 입력
            player = 0; // 플레이어 전환
        }
 
        printf("\n");
 
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 1) {
                    printf("%c", 'O'); // 보드판 숫자가 1이면 O
                }
                else if (board[i][j] == 2) {
                    printf("%c", 'X'); // 보드판 숫자가 2이면 X
                }
                else {
                    printf("*"); // 나머지 숫자면 *
                }
            }
            printf("\n");
        } // 보드판 출력
 
          // 빙고 여부
        int result = Bingo(board, choice); // 승패 결정 함수 호출
        if (result == 0) //승패가 결정되는 경우
        {
            if (player == 0) {
                printf("player [1] 승리!!\n");
            }
            else {
                printf("player [0] 승리!!\n");
            }
            break;
        } // 마지막으로 둔 플레이가 승리하게 됨
 
        else if (result == 1) // 무승부가 되는 경우
        {
            printf("무승부 입니다.\n");
            break;
        }
        else if (result == 2) // 경기를 계속 진행하는 경우
        {
            printf("\n");
        }
    }
}
 
int Bingo(int ary[3][3], int n) {
 
    if ((ary[0][0] == ary[1][1] && ary[0][0] == ary[2][2]) || (ary[0][2] == ary[1][1] && ary[0][2] == ary[2][0])) {
        return 0;
    } //대각선으로 빙고가 생기는지 확인
 
    for (int line = 0; line <= 2; line++) {
        if ((ary[line][0] == ary[line][1] && ary[line][0] == ary[line][2]) || (ary[0][line] == ary[1][line] && ary[0][line] == ary[2][line])) {
            return 0;
        } //가로, 세로줄로 빙고가 생기는지 확인, line은 각 가로, 세로줄의 줄 번호 
    }
 
    if (n == 9) {
        return 1;
    } //시행횟수가 9번이면 무승부로 결정
 
}// 승패 결정 함수 정의
*/