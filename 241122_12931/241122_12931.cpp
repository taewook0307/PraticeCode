// 241122_12931.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 자릿수 더하기

/*
문제설명
자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 solution 함수를 만들어 주세요.
예를들어 N = 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.
*/

#include <iostream>

int solution(int n)
{
    int answer = 0;

    while (n != 0)
    {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
