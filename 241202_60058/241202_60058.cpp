﻿// 241202_60058.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 괄호 변환

/*
문제설명
'(' 와 ')' 로만 이루어진 문자열이 있을 경우, '(' 의 개수와 ')' 의 개수가 같다면 이를 균형잡힌 괄호 문자열이라고 부릅니다.
그리고 여기에 '('와 ')'의 괄호의 짝도 모두 맞을 경우에는 이를 올바른 괄호 문자열이라고 부릅니다.
예를 들어, "(()))("와 같은 문자열은 "균형잡힌 괄호 문자열" 이지만 "올바른 괄호 문자열"은 아닙니다.
반면에 "(())()"와 같은 문자열은 "균형잡힌 괄호 문자열" 이면서 동시에 "올바른 괄호 문자열" 입니다.

'(' 와 ')' 로만 이루어진 문자열 w가 "균형잡힌 괄호 문자열" 이라면 다음과 같은 과정을 통해 "올바른 괄호 문자열"로 변환할 수 있습니다.

1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
  4-3. ')'를 다시 붙입니다.
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
  4-5. 생성된 문자열을 반환합니다.

"균형잡힌 괄호 문자열" p가 매개변수로 주어질 때, 주어진 알고리즘을 수행해 "올바른 괄호 문자열"로 변환한 결과를 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <stack>

bool IsCorrect(std::string _Value)
{
    std::stack<char> RemainValue;

    for (char C : _Value)
    {
        if (true == RemainValue.empty())
        {
            RemainValue.push(C);
            continue;
        }

        if (')' == C && '(' == RemainValue.top())
        {
            RemainValue.pop();
        }
        else
        {
            RemainValue.push(C);
        }
    }

    return RemainValue.empty();
}

std::string solution(std::string p)
{
    if (p == "")
    {
        return p;
    }

    std::string Result = "";

    std::string U = "";
    std::string V = "";

    int OpenCount = 0;
    int CloseCount = 0;

    for (char C : p)
    {
        U += C;

        if (C == '(')
        {
            ++OpenCount;
        }
        else
        {
            ++CloseCount;
        }

        if (OpenCount == CloseCount)
        {
            break;
        }
    }

    V = p.substr(U.length());

    if (true == IsCorrect(U))
    {
        Result += U;
        Result += solution(V);
        return Result;
    }

    Result += '(';
    Result += solution(V);
    Result += ')';

    std::string PushString = "";

    size_t ULength = U.length();
    for (size_t i = 1; i < ULength - 1; ++i)
    {
        if (U[i] == '(')
        {
            PushString += ')';
        }
        else
        {
            PushString += '(';
        }
    }

    Result += PushString;
    return Result;
}

int main()
{
    std::cout << solution("(()())()") << std::endl;
    std::cout << solution(")(") << std::endl;
    std::cout << solution("()))((()") << std::endl;
}
