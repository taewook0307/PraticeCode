// 241114_42839.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 소수 찾기

/*
문제설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

bool IsPrime(int _Num)
{
    if (_Num < 2)
    {
        return false;
    }

    if (_Num < 4)
    {
        return true;
    }

    int LoopCount = std::sqrt(_Num);

    for (int i = 2; i <= LoopCount; ++i)
    {
        if (0 == _Num % i)
        {
            return false;
        }
    }

    return true;
}

int solution(std::string numbers)
{
    int answer = 0;

    size_t Len = numbers.length();

    std::unordered_set<int> MakeNumberSet;

    sort(numbers.begin(), numbers.end());

    do
    {
        for (size_t i = 1; i <= Len; ++i)
        {
            std::string PartString = numbers.substr(0, i);

            int MakeNum = std::stoi(PartString);

            if (true == IsPrime(MakeNum))
            {
                MakeNumberSet.insert(MakeNum);
            }
        }
    } while (true == std::next_permutation(numbers.begin(), numbers.end()));
    
    answer = static_cast<int>(MakeNumberSet.size());

    return answer;
}

int main()
{
    std::cout << solution("17") << std::endl;
}
