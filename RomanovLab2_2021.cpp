

#include <iostream>

int main()
{
    

	unsigned int numbers[12] = { 4,51,6,7,8,40,50,55,60,65,70,80 };
	const unsigned int a = 34;
	int x = 0 ;
	for (int i = 0; i <= 11; i++) {
		int c = numbers[i];
		numbers[i] = numbers[i] & a;
		numbers[i] = numbers[i] ^ a;
		
		if (numbers[i] == 0) {
			std::cout << i << " - " << c << "\n";
			x++;
		}


	}
	std::cout << x << "\n";
	system("pause");
	return 0;
	
}
