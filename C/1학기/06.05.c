#include <stdio.h>
void ShowData(const int *ptr)		//����Ʈ���� ptr�� �̿��ؼ� ptr�� ����Ű�� ������ ����� ���� ������ �� ���� 
{
	int * rptr = ptr;				//�����ͺ��� rptr = ptr�� �ԷµǼ� rptr�� ptr�� ���� ����
	printf("%d \n", *rptr);			//��½� rptr = ptr = num = 10
	*rptr = 20;						//��½� rptr = ptr = num = 20(const int *ptr ���ǹ��ϰ� ��.)
}
int main()
{
	int num = 10;
	int * ptr = &num;	//*ptr���� &num���� ����.
	ShowData(ptr);		//ptr�� ShowData�Լ��� �Է�.
	printf("%d", *ptr);	//�ٲ� ���� ���̱����� �߰���.
	return 0;
}