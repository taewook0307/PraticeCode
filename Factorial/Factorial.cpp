// Factorial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Factorial(int _Value)
{
	if (_Value == 1)
	{
		return 1;
	}

	return _Value * Factorial(_Value - 1);
}

int main()
{
	int Factorial1 = Factorial(1);
	int Factorial2 = Factorial(2);
	int Factorial3 = Factorial(3);
	int Factorial4 = Factorial(4);
	int Factorial5 = Factorial(5);
	int Factorial6 = Factorial(6);
	int Factorial7 = Factorial(7);
}
