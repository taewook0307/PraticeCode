// 241122_12928.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 약수의 합

/*
문제설명
정수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 함수, solution을 완성해주세요.
*/

#include <iostream>

int solution(int n)
{
    if (n < 2)
    {
        return n;
    }

    int answer = 1 + n;

    int LoopCount = sqrt(n);

    for (int i = 2; i <= LoopCount; ++i)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                answer += i;
            }
            else
            {
                answer += i;
                answer += n / i;
            }
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(12) << std::endl;
    std::cout << solution(5) << std::endl;
}
