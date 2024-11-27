// 241127_12921.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 소수 찾기

/*
문제설명
1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.

소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
(1은 소수가 아닙니다.)
*/

#include <iostream>
//#include <cmath>
//
//bool IsPrimeNum(int _Num)
//{
//    if (_Num < 2)
//    {
//        return false;
//    }
//
//    if (_Num < 4)
//    {
//        return true;
//    }
//
//    int LoopCount = std::sqrt(_Num);
//
//    for (int i = 2; i <= LoopCount; ++i)
//    {
//        if (_Num % i == 0)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int solution(int n)
//{
//    int answer = 0;
//
//    for (int i = 2; i <= n; ++i)
//    {
//        if (true == IsPrimeNum(i))
//        {
//            ++answer;
//        }
//    }
//
//    return answer;
//}

#include <vector>
#include <algorithm>

int solution(int n)
{
    std::vector<bool> IsPrime(n + 1, true);
    IsPrime[0] = false;
    IsPrime[1] = false;

    int CheckNum = 2;

    while (CheckNum != n)
    {
        if (false == IsPrime[CheckNum])
        {
            ++CheckNum;
            continue;
        }

        int Mul = 2;
        int Start = CheckNum * Mul;

        while (Start <= n)
        {
            IsPrime[Start] = false;
            ++Mul;
            Start = CheckNum * Mul;
        }

        ++CheckNum;
    }

    return std::count(IsPrime.begin(), IsPrime.end(), true);
}

int main()
{
    std::cout << solution(10) << std::endl;
}
