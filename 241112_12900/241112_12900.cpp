// 241112_12900.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 2 x n 타일링

/*
가로 길이가 2이고 세로의 길이가 1인 직사각형모양의 타일이 있습니다.
이 직사각형 타일을 이용하여 세로의 길이가 2이고 가로의 길이가 n인 바닥을 가득 채우려고 합니다.
타일을 채울 때는 다음과 같이 2가지 방법이 있습니다.

타일을 가로로 배치 하는 경우
타일을 세로로 배치 하는 경우

직사각형의 가로의 길이 n이 매개변수로 주어질 때, 이 직사각형을 채우는 방법의 수를 return 하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <algorithm>

int solution(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    int n1 = 1;
    int n2 = 2;

    for (int i = 3; i <= n; ++i)
    {
        n1 += n2;
        n1 %= 1000000007;
        std::swap(n1, n2);
    }

    return n2;
}

int main()
{
    std::cout << solution(4) << std::endl;
}
