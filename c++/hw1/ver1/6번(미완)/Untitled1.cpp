//7�� 52��  
#include<stdio.h>
void print_tic_tac_toe(void);
//�������� global variable, �ڵ� �ʱ�ȭ  
char ttt[3][3];

int main(void)
{
	int x, y;
	char player = 'O';
	//print_tic_tac_toe();

	while (1) {
		printf("(x,y) ��ǥ (���� -1,-1):");
		scanf("%i,%i", &x, &y);

		if (x == -1 || y == -1) {
			printf("tic-tac-toe ���� !!\n");
			break;
		}
		if ((x > 2 || x < 0) || (y > 2 || y < 0)) {
			printf("������ ������ϴ�.\n");
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
							printf("O�� �����Դϴ�!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'O') {
							if (ttt[2][0] == 'O') {
								printf("O�� �����Դϴ�!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'O') {
								if (ttt[2][2] == 'O') {
									printf("O�� �����Դϴ�!");
									break;
								}
							}
						}
					}
				}
				else {
					if (ttt[0][1] == 'X') {
						if (ttt[0][2] == 'X') {
							printf("X�� �����Դϴ�!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'X') {
							if (ttt[2][0] == 'X') {
								printf("X�� �����Դϴ�!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'X') {
								if (ttt[2][2] == 'X') {
									printf("X�� �����Դϴ�!");
									break;
								}
							}
						}
					}
				}
			}
			else {  //player='X'�� ���  
				ttt[x][y] = 'X';
				print_tic_tac_toe();
				player = 'O';
				if (ttt[0][0] == 'O') {
					if (ttt[0][1] == 'O') {
						if (ttt[0][2] == 'O') {
							printf("O�� �����Դϴ�!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'O') {
							if (ttt[2][0] == 'O') {
								printf("O�� �����Դϴ�!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'O') {
								if (ttt[2][2] == 'O') {
									printf("O�� �����Դϴ�!");
									break;
								}
							}
						}
					}
				}
				else {
					if (ttt[0][1] == 'X') {
						if (ttt[0][2] == 'X') {
							printf("X�� �����Դϴ�!");
							break;
						}
					}
					else { //ttt[0][1]="X"
						if (ttt[1][0] == 'X') {
							if (ttt[2][0] == 'X') {
								printf("X�� �����Դϴ�!");
								break;
							}
						}
						else {
							if (ttt[1][1] == 'X') {
								if (ttt[2][2] == 'X') {
									printf("X�� �����Դϴ�!");
									break;
								}
							}
						}
					}
				}
			}
		}
		else {//ttt[x][y] != NULL �� ��� 
			printf("�̹� �� ���Դϴ�\n");
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
    int board[3][3] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 }; // ���� ����, �� ĭ�� ��ȣ
    int player = 0; // player ID 0,1 �θ��� �÷��̾�
    int x, y; // ���� ��ġ
    int choice = 0; // ������ Ƚ��   
 
    int Bingo(int ary[3][3], int n); // ���� ���� �Լ� ����
 
    while (1) // ���ٸ� ���Ǿ��� ���ѹݺ�
    {
        // ���� ��ġ �Է�
        do
        {
            printf("player [%d]�� ���� ��ġ(x,y)�� �Է��Ͻÿ� : ", player);
            scanf("%d %d", &x, &y); // ���� ��ġ �Է¹ޱ�
 
            if (board[x][y] < 11 || x>2 || x<0 || y>2 || y<0) {
                printf("\n�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n\n");
            } // �߸��� �Է°��� �ޱ����� ���ǹ�
 
        } while (board[x][y] < 11 || x>2 || x<0 || y>2 || y<0); // �Է°��� ��Ȯ�ϸ� ��������
 
        choice++; // ������ Ƚ�� 1����
 
        if (player == 0) {
            board[x][y] = 1; // player 0�� �����ǿ� 1�� �Է�
            player = 1; //�÷��̾� ��ȯ
        }
 
        else {
            board[x][y] = 2; // player 1�� �����ǿ� 2�� �Է�
            player = 0; // �÷��̾� ��ȯ
        }
 
        printf("\n");
 
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 1) {
                    printf("%c", 'O'); // ������ ���ڰ� 1�̸� O
                }
                else if (board[i][j] == 2) {
                    printf("%c", 'X'); // ������ ���ڰ� 2�̸� X
                }
                else {
                    printf("*"); // ������ ���ڸ� *
                }
            }
            printf("\n");
        } // ������ ���
 
          // ���� ����
        int result = Bingo(board, choice); // ���� ���� �Լ� ȣ��
        if (result == 0) //���а� �����Ǵ� ���
        {
            if (player == 0) {
                printf("player [1] �¸�!!\n");
            }
            else {
                printf("player [0] �¸�!!\n");
            }
            break;
        } // ���������� �� �÷��̰� �¸��ϰ� ��
 
        else if (result == 1) // ���ºΰ� �Ǵ� ���
        {
            printf("���º� �Դϴ�.\n");
            break;
        }
        else if (result == 2) // ��⸦ ��� �����ϴ� ���
        {
            printf("\n");
        }
    }
}
 
int Bingo(int ary[3][3], int n) {
 
    if ((ary[0][0] == ary[1][1] && ary[0][0] == ary[2][2]) || (ary[0][2] == ary[1][1] && ary[0][2] == ary[2][0])) {
        return 0;
    } //�밢������ ���� ������� Ȯ��
 
    for (int line = 0; line <= 2; line++) {
        if ((ary[line][0] == ary[line][1] && ary[line][0] == ary[line][2]) || (ary[0][line] == ary[1][line] && ary[0][line] == ary[2][line])) {
            return 0;
        } //����, �����ٷ� ���� ������� Ȯ��, line�� �� ����, �������� �� ��ȣ 
    }
 
    if (n == 9) {
        return 1;
    } //����Ƚ���� 9���̸� ���ºη� ����
 
}// ���� ���� �Լ� ����
*/