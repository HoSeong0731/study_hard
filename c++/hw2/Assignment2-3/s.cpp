#include <iostream>

using namespace std;

int main()
{
    int row, column;                            //Variable to receive value
    int Row, Column;                            //Variable to store values
    int i, j;
    int x = 0, y = -1, turn = 1;                //saving array coordinates, redirecting
    int num = 1;
    int max = 0;

    cout << "please input 2D array size: ";		//Received row, column
    cin >> row;
    cin >> column;
    if (row < 0 or row > 10 or column < 0 or column > 10) { //exception processing
        cout << "error!" << endl;
        return 0;
    }
    int** arr = new int*[row];          //two-dimensional array dynamic allocation
    for (int i = 0; i < row; i++) {
        arr[i] = new int[column];
    }
    max = row * column;             //maximum value

    Row = row;                      //Copy Value
    Column = column;                //Copy Value


    while (num != max + 1)          //Repeat until less than the maximum value
    {
        for (i = 1; i <= Column; i++)   //row-to-column interaction algorithm
        {
            y += turn;
            arr[x][y] = num;
            num++;
        }
        Row--;          //row reduction 

        for (i = 1; i <= Row; i++)  //row-to-column interaction algorithm
        {
            x += turn;
            arr[x][y] = num;
            num++;
        }
        turn *= -1;     //directional change of direction
        Column--;       //column reduction
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)    //Output
        {
            cout.width(3);
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}