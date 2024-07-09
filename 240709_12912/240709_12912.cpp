// 240709_12912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 두 정수 사이의 합

/*
문제 설명
두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 리턴하는 함수, solution을 완성하세요.
예를 들어 a = 3, b = 5인 경우, 3 + 4 + 5 = 12이므로 12를 리턴합니다.
*/

#include <iostream>
#include <string>
#include <vector>

long long solution(int a, int b) {
    long long answer = 0;

    if (a == b)
    {
        return a;
    }

    long long BigValue = a < b ? (long long)b : (long long)a;
    long long SmallValue = a < b ? (long long)a : (long long)b;

    long long PlusOneToBigger = BigValue * (BigValue + 1) / 2;
    long long PlusOneToSmall = SmallValue * (SmallValue + 1) / 2;

    answer = PlusOneToBigger - PlusOneToSmall + SmallValue;

    return answer;
}

void PrintResult(int a, int b)
{
    long long Result = solution(a, b);
    std::cout << Result << std::endl;
}

int main()
{
    PrintResult(3, 5);
    PrintResult(3, 3);
    PrintResult(5, 3);

    PrintResult(-3, 0);
}