#include <iostream>
#include <string>

using namespace std;
char* my_str(char* str, char* strSearch, char* strChange) {
	int count = 0, S_count = 0, i = 0, temp = 0, C_count = 0;
	char point[100] = { NULL, };
	int sub_i = 0;
	char result[100] = { NULL, };

	cout << "변경된 결과는 다음과 같습니다." << endl;

	for (i = 0; strSearch[i] != NULL ; i++) {	//search의 크기
		S_count++;
	}

	for (i = 0; str[i] != NULL; i++) {		//str의 크기
		count++;
	}

	for (i = 0; strChange[i] != NULL; i++) {
		C_count++;
	}

	for (i = 0; i < count; i++) {			//단어 찾기 알고리즘.
		if (str[i] == strSearch[0]) {
			for (sub_i = 1; sub_i <= S_count; sub_i++) {
				if (str[i + sub_i] != strSearch[sub_i]) {
					break;
				}
			}
			temp = i;	//i값 copy
			if (sub_i == S_count) {
				for (sub_i = 0; sub_i < S_count; sub_i++) {
					point[sub_i] = str[sub_i+i];
					
					//cout << point[sub_i];
					
				}
			}
			else {
				cout << "일치하는 문자열이 없습니다.";
				return 0;
			}
		}
	}
	
	sub_i = 0;
	for (i = 0; i < count + C_count; i++) {
		if (i < temp) {
			result[i] = str[i];
			continue;
		}
		if (temp <= i and i < temp + C_count) {
			result[i] = strChange[sub_i];
			
			sub_i++;
			
			continue;
		}
		if (i >= temp + C_count) {
			int j = 0;
			j = S_count - C_count;
			result[i] = str[i+j];
			
		}
	}

	
	for (i = 0; i < 100; i++) {
		cout << result[i];
	}
	
	return 0;
};

int main() {
	char str[100] = { NULL, };
	char strSearch[100] = { NULL, };
	char strChange[100] = { NULL, };

	cout << "원본 문자열을 입력하세요: ";
	cin.getline(str, sizeof(str));
	cout << "변경 전 문자열을 입력하세요: ";
	cin.getline(strSearch, sizeof(strSearch));
	cout << "변경 후 문자열을 입력하세요: ";
	cin.getline(strChange, sizeof(strChange));
	cout <<  my_str(str, strSearch, strChange);
	return 0;
}