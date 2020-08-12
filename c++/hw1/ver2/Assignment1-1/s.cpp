#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    //system("mode con cols=9000 lines=9000");
    int len = 1;	//variable to determine the length of an index value
    int input = 0;	//Variables that receive values from users  
    int count = 1;	//repeats Len by the value of the number entered by the user.
    int i, j, k; 	//Variables for use in repeating statements 
    while (1)		//repeated statement receiving normal value input
    {
        cout << "Enter the power of 3(range = 3~2187): ";
        cin >> input;

        if (input <= 2187 and input >= 3)
            break;

        cout << "올바르지 않은 값입니다. 프로그램을 종료합니다.";
        return 0;
    }

    if (input == 3) {   //translates the value to match the condition when the value is correct.
        input = 1;
    }
    else if (input == 9) {
        input = 2;
    }
    else if (input == 27) {
        input = 3;
    }
    else if (input == 81) {
        input = 4;
    }
    else if (input == 243) {
        input = 5;
    }
    else if (input == 729) {
        input = 6;
    }
    else if (input == 2187) {
        input = 7;
    }
    else {
        cout << "올바르지 않은 값입니다. 프로그램을 종료합니다.";
        return 0;
    }


    for (len = 1; count <= input; count++) { 	//multiply the input value to len. 
        len = len * 3;
    }

    for (i = 0; i < len; i++)		//the length of a vertical length of equal to the input of 3.
    {
        for (j = 0; j < len; j++)  //the width of a vertical width of equal to the input of 3.
        {
            for (k = len / 3; k; k /= 3)
                if ((j % (k * 3)) / k == 1 and (i % (k * 3)) / k == 1)
                    break;
            cout << (k ? " " : "#");
        }
        cout << endl;
    }
    system("PAUSE");
    Sleep(1000); //1 second stop
    return 0;

}
