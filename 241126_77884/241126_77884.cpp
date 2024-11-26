// 241126_77884.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 약수의 개수 더하기

/*
문제설명
두 정수 left와 right가 매개변수로 주어집니다.
left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <cmath>

int CountDivisor(int _Num)
{
    if (_Num <= 2)
    {
        return _Num;
    }

    int Count = 0;

    int LoopCount = std::sqrt(_Num);

    for (int i = 1; i <= LoopCount; ++i)
    {
        if (_Num % i == 0)
        {
            if (_Num / i == i)
            {
                Count += 1;
                continue;
            }

            Count += 2;
        }
    }

    return Count;
}

int solution(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; ++i)
    {
        if (CountDivisor(i) % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(13, 17) << std::endl;
    std::cout << solution(24, 27) << std::endl;
}
