// 241003_12945.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 피보나치 수

/*
문제 설명
피보나치 수는 F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2) 가 적용되는 수 입니다.

예를들어

F(2) = F(0) + F(1) = 0 + 1 = 1
F(3) = F(1) + F(2) = 1 + 1 = 2
F(4) = F(2) + F(3) = 1 + 2 = 3
F(5) = F(3) + F(4) = 2 + 3 = 5
와 같이 이어집니다.

2 이상의 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수, solution을 완성해 주세요.
*/

#include <iostream>
#include <vector>

std::vector<int> FibonacciValue;

int Fibonacci(int _Num)
{
    if (0 == _Num)
    {
        if (FibonacciValue.size() == 0)
        {
            FibonacciValue.push_back(0);
        }
        return 0;
    }

    if (1 == _Num)
    {
        if (FibonacciValue.size() == 1)
        {
            FibonacciValue.push_back(1);
        }
        return 1;
    }

    if (FibonacciValue.size() >= _Num + 1)
    {
        return FibonacciValue[_Num];
    }

    int Result = Fibonacci(_Num - 2) + Fibonacci(_Num - 1);
    FibonacciValue.resize(_Num + 1);
    FibonacciValue[_Num] = Result % 1234567;

    return FibonacciValue[_Num];
}

int solution(int n)
{
    int FibonacciN = Fibonacci(n);

    return FibonacciN % 1234567;
}

int main()
{
    int Num = solution(20);
}
