#include <iostream>

using namespace std;

int main()
{
	int A[12], sum;
	cout << "Enter 12 numbers in array: ";
	for (int i = 0; i < 12; i++) 
		cin >> A[i];   
	__asm
	{
		mov sum, 0
		lea esi, A
		mov ecx, 10
		lp:
			lodsd                     //������� LODSD ��������� ������� ����� �� ������ �� ������������� ������ 
			imuL eax              
			add sum, eax           
		loop lp
	}

	cout << "Sum of squares = " << sum << endl;      
	system("pause");
	return 0;
}

