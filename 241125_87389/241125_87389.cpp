// 241125_87389.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 나머지가 1이 되는 수 찾기

/*
문제설명
자연수 n이 매개변수로 주어집니다. n을 x로 나눈 나머지가 1이 되도록 하는 가장 작은 자연수 x를 return 하도록 solution 함수를 완성해주세요.
답이 항상 존재함은 증명될 수 있습니다.
*/

#include <iostream>

int solution(int n)
{
    int answer = 3;

    int LowN = n - 1;

    for (int i = 3; i <= LowN; ++i)
    {
        if (LowN % i == 0)
        {
            answer = i;
            break;
        }
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
