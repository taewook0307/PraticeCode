// 240813_12934.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 정수 제곱근 판별

/*
문제 설명
임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하려 합니다.
n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수를 완성하세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

long long solution(long long n) {
    long long answer = 0;

    double RootN = sqrt(static_cast<double>(n));
    long long ChangeRootN = static_cast<long long>(RootN);

    if (RootN == ChangeRootN)
    {
        answer = (ChangeRootN + 1) * (ChangeRootN + 1);
    }
    else
    {
        answer = -1;
    }

    return answer;
}

void PrintResult(long long n)
{
    long long Result = solution(n);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    PrintResult(121);
    PrintResult(3);
}
