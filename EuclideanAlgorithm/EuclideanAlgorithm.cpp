// EuclideanAlgorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 유클리드 호제법
/*
유클리드 호제법이란 ?
2개의 자연수의 최대공약수를 구하는 방법

ex)
1071과 1029의 최대공약수 구하기

1071 % 1029 = 42
1029 % 42 = 21
42 % 21 = 0

최대공약수 = 21
*/

#include <iostream>

int Enclidean(int _Num1, int _Num2)
{
    int Dividend = _Num1 > _Num2 ? _Num1 : _Num2;
    int Divisor = _Num1 > _Num2 ? _Num2 : _Num1;

    while (true)
    {
        int RemainValue = Dividend % Divisor;

        if (0 == RemainValue)
        {
            return Divisor;
        }

        Dividend = Divisor;
        Divisor = RemainValue;
    }
}

int EnclideanRecursive(int _Num1, int _Num2)
{
    int Dividend = _Num1 > _Num2 ? _Num1 : _Num2;
    int Divisor = _Num1 > _Num2 ? _Num2 : _Num1;

    if (0 == Dividend % Divisor)
    {
        return _Num2;
    }
    else
    {
        return EnclideanRecursive(Divisor, Dividend % Divisor);
    }
}

int main()
{
    std::cout << Enclidean(1071, 1029) << std::endl;    // 21
    std::cout << Enclidean(48, 18) << std::endl;        // 6
    std::cout << Enclidean(56, 98) << std::endl;        // 14
    std::cout << Enclidean(101, 10) << std::endl;       // 1
    std::cout << Enclidean(100, 25) << std::endl;       // 25
    std::cout << Enclidean(81, 27) << std::endl;        // 27
    std::cout << Enclidean(7, 5) << std::endl;          // 1

    std::cout << std::endl << "Recursive ----------------" << std::endl;
    std::cout << EnclideanRecursive(1071, 1029) << std::endl;    // 21
    std::cout << EnclideanRecursive(48, 18) << std::endl;        // 6
    std::cout << EnclideanRecursive(56, 98) << std::endl;        // 14
    std::cout << EnclideanRecursive(101, 10) << std::endl;       // 1
    std::cout << EnclideanRecursive(100, 25) << std::endl;       // 25
    std::cout << EnclideanRecursive(81, 27) << std::endl;        // 27
    std::cout << EnclideanRecursive(7, 5) << std::endl;          // 1
}
