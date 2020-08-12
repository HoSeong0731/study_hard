#include <iostream> 
#include <fstream>  
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int array_size = 1000;
 	char * array = new char[array_size];
 	int position = 0; 
  
 	ifstream fin("ciphertext.txt"); 
  	if(fin.is_open()){  
	  //cout << "File Opened successfully!!!. Reading data from file into array" << endl;
  		while(!fin.eof() and position < array_size){
		  fin.get(array[position]);
		  position++;
		  }
		array[position-1] = '\0';     
	  	//cout << "Displaying Array..." << endl << endl;
	  	for(int i = 0; array[i] != '\0'; i++){     
	  		 printf("%d", itoa(array[i],,16));
			}
	}else{
	  cout << "파일이 열리지 않습니다." << endl;
	  return 0; 
	}
 	return 0;
}
