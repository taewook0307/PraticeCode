﻿// 241204_67257.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 수식 최대화

/*
문제설명
IT 벤처 회사를 운영하고 있는 라이언은 매년 사내 해커톤 대회를 개최하여 우승자에게 상금을 지급하고 있습니다.
이번 대회에서는 우승자에게 지급되는 상금을 이전 대회와는 다르게 다음과 같은 방식으로 결정하려고 합니다.
해커톤 대회에 참가하는 모든 참가자들에게는 숫자들과 3가지의 연산문자(+, -, *) 만으로 이루어진 연산 수식이 전달되며,
참가자의 미션은 전달받은 수식에 포함된 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 가장 큰 숫자를 제출하는 것입니다.
단, 연산자의 우선순위를 새로 정의할 때, 같은 순위의 연산자는 없어야 합니다.
즉, + > - > * 또는 - > * > + 등과 같이 연산자 우선순위를 정의할 수 있으나
+,* > - 또는 * > +,-처럼 2개 이상의 연산자가 동일한 순위를 가지도록 연산자 우선순위를 정의할 수는 없습니다.
수식에 포함된 연산자가 2개라면 정의할 수 있는 연산자 우선순위 조합은 2! = 2가지이며, 연산자가 3개라면 3! = 6가지 조합이 가능합니다.
만약 계산된 결과가 음수라면 해당 숫자의 절댓값으로 변환하여 제출하며 제출한 숫자가 가장 큰 참가자를 우승자로 선정하며, 우승자가 제출한 숫자를 우승상금으로 지급하게 됩니다.

예를 들어, 참가자 중 네오가 아래와 같은 수식을 전달받았다고 가정합니다.

"100-200*300-500+20"

일반적으로 수학 및 전산학에서 약속된 연산자 우선순위에 따르면 더하기와 빼기는 서로 동등하며 곱하기는 더하기, 빼기에 비해 우선순위가 높아 * > +,- 로 우선순위가 정의되어 있습니다.
대회 규칙에 따라 + > - > * 또는 - > * > + 등과 같이 연산자 우선순위를 정의할 수 있으나
+,* > - 또는 * > +,- 처럼 2개 이상의 연산자가 동일한 순위를 가지도록 연산자 우선순위를 정의할 수는 없습니다.
수식에 연산자가 3개 주어졌으므로 가능한 연산자 우선순위 조합은 3! = 6가지이며, 그 중 + > - > * 로 연산자 우선순위를 정한다면 결괏값은 22,000원이 됩니다.
반면에 * > + > - 로 연산자 우선순위를 정한다면 수식의 결괏값은 -60,420 이지만, 규칙에 따라 우승 시 상금은 절댓값인 60,420원이 됩니다.

참가자에게 주어진 연산 수식이 담긴 문자열 expression이 매개변수로 주어질 때, 우승 시 받을 수 있는 가장 큰 상금 금액을 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

long long Calculate(long long _A, long long _B, char _Op)
{
    switch (_Op)
    {
    case '+':
        return _A + _B;
    case '-':
        return _A - _B;
    case '*':
        return _A * _B;
    default:
        return 0;
    }
}

long long solution(std::string expression)
{
    long long answer = 0;

    std::vector<std::vector<char>> AllPriority
        = { {'+', '-', '*'}, {'+', '*', '-'},
           {'-', '+', '*'}, {'-', '*', '+'},
           {'*', '+', '-'}, {'*', '-', '+'}
    };

    std::vector<long long> Nums;
    std::vector<char> Operators;

    const size_t ExLen = expression.length();

    std::string NumString = "";

    for (size_t i = 0; i < ExLen; ++i)
    {
        if ('0' <= expression[i] && '9' >= expression[i])
        {
            NumString += expression[i];
        }
        else
        {
            long long PushValue = std::stoll(NumString);
            Nums.push_back(PushValue);
            NumString = "";
            Operators.push_back(expression[i]);
        }

        if (i == ExLen - 1)
        {
            long long PushValue = std::stoll(NumString);
            Nums.push_back(PushValue);
        }
    }

    for (const std::vector<char>& CurPriority : AllPriority)
    {
        std::vector<long long> CopyNums = Nums;
        std::vector<char> CopyOperators = Operators;

        while (1)
        {
            std::vector<char>::iterator FindIter = std::find(CopyOperators.begin(), CopyOperators.end(), CurPriority[0]);
            if (CopyOperators.end() == FindIter)
            {
                break;
            }

            size_t Index = FindIter - CopyOperators.begin();

            CopyNums[Index] = Calculate(CopyNums[Index], CopyNums[Index + 1], *FindIter);

            CopyOperators.erase(FindIter);
            CopyNums.erase(CopyNums.begin() + Index + 1);
        }

        while (1)
        {
            std::vector<char>::iterator FindIter = std::find(CopyOperators.begin(), CopyOperators.end(), CurPriority[1]);
            if (CopyOperators.end() == FindIter)
            {
                break;
            }

            size_t Index = FindIter - CopyOperators.begin();

            CopyNums[Index] = Calculate(CopyNums[Index], CopyNums[Index + 1], *FindIter);

            CopyOperators.erase(FindIter);
            CopyNums.erase(CopyNums.begin() + Index + 1);
        }

        while (1)
        {
            std::vector<char>::iterator FindIter = std::find(CopyOperators.begin(), CopyOperators.end(), CurPriority[2]);
            if (CopyOperators.end() == FindIter)
            {
                break;
            }

            size_t Index = FindIter - CopyOperators.begin();

            CopyNums[Index] = Calculate(CopyNums[Index], CopyNums[Index + 1], *FindIter);

            CopyOperators.erase(FindIter);
            CopyNums.erase(CopyNums.begin() + Index + 1);
        }

        answer = std::max(answer, std::abs(CopyNums[0]));
        std::cout << "answer = " << answer << std::endl;
    }

    return answer;
}

int main()
{
    std::cout << solution("100-200*300-500+20") << std::endl;
}
