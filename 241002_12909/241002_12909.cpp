// 241002_12909.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 올바른 괄호

/*
문제 설명
괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다.

예를 들어
"()()" 또는 "(())()" 는 올바른 괄호입니다.
")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.

'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때,
문자열 s가 올바른 괄호이면 true를 return 하고,
올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.

*/

#include <iostream>
#include<string>
#include <stack>

bool solution(std::string s)
{
    bool answer = true;

    std::stack<char> StringStack;

    for (char CurChar : s)
    {
        if ('(' == CurChar)
        {
            StringStack.push(CurChar);
        }
        else if(')' == CurChar)
        {
            if (false == StringStack.empty())
            {
                char TopChar = StringStack.top();

                if (TopChar == '(')
                {
                    StringStack.pop();
                }
                else
                {
                    StringStack.push(CurChar);
                }
            }
            else
            {
                StringStack.push(CurChar);
            }   
        }
    }

    answer = StringStack.empty();

    std::cout << answer << std::endl;

    return answer;
}

int main()
{
    solution("()()");
    solution("(())()");
}
