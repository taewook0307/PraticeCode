// 241125_12936.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 줄 서는 방법

/*
문제설명
n명의 사람이 일렬로 줄을 서고 있습니다. n명의 사람들에게는 각각 1번부터 n번까지 번호가 매겨져 있습니다.
n명이 사람을 줄을 서는 방법은 여러가지 방법이 있습니다. 예를 들어서 3명의 사람이 있다면 다음과 같이 6개의 방법이 있습니다.

[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 1, 2]
[3, 2, 1]

사람의 수 n과, 자연수 k가 주어질 때, 사람을 나열 하는 방법을 사전 순으로 나열 했을 때, k번째 방법을 return하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
//#include <algorithm>
//
//std::vector<int> solution(int n, long long k)
//{
//    std::vector<int> Lower;
//    Lower.reserve(n);
//
//    for (int i = 1; i <= n; ++i)
//    {
//        Lower.push_back(i);
//    }
//
//    int i = 1;
//
//    do
//    {
//        if (k == i++)
//        {
//            break;
//        }
//
//    } while (std::next_permutation(Lower.begin(), Lower.end()));
//
//    return Lower;
//}

std::vector<int> solution(int n, long long k)
{
    std::vector<long long> Factorial(n, 0);
    Factorial[0] = 1;
    Factorial[1] = 1;

    long long Result = 1;

    for (long long i = 2; i < n; ++i)
    {
        Factorial[i] = Result * i;
        Result *= i;
    }

    std::vector<int> answer;
    answer.reserve(n);

    std::set<int> InputData;

    int Value = 1;
    int Count = answer.size() + 1;

    while (1)
    {
        if (answer.size() == n)
        {
            break;
        }

        if (k > Factorial[n - Count])
        {
            ++Value;
            while (InputData.end() != InputData.find(Value))
            {
                ++Value;
            }
            k -= Factorial[n - Count];
        }
        else
        {
            answer.push_back(Value);
            InputData.insert(Value);
            Count = answer.size() + 1;
            Value = 1;
            while (InputData.end() != InputData.find(Value))
            {
                ++Value;
            }
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution(3, 5);
}
