// 241126_12947.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 하샤드 수

/*
문제설명
양의 정수 x가 하샤드 수이려면 x의 자릿수의 합으로 x가 나누어져야 합니다.
예를 들어 18의 자릿수 합은 1+8=9이고, 18은 9로 나누어 떨어지므로 18은 하샤드 수입니다.
자연수 x를 입력받아 x가 하샤드 수인지 아닌지 검사하는 함수, solution을 완성해주세요.
*/

#include <iostream>

bool solution(int x)
{
    int CopyX = x;

    int Sum = 0;

    while (CopyX != 0)
    {
        Sum += CopyX % 10;
        CopyX /= 10;
    }

    return (x % Sum) == 0;
}

int main()
{
    std::cout << solution(10) << std::endl;
}
