// 241017_76502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 괄호 회전하기

/*
문제 설명
다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

    (), [], {} 는 모두 올바른 괄호 문자열입니다.
    만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
    만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.

대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다.
이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <stack>

int solution(std::string s)
{
    int answer = 0;

    const size_t RollCount = s.size();
    std::stack<char> Check;

    for (size_t i = 0; i < RollCount; ++i)
    {
        size_t Index = i;
        for (size_t j = 0; j < RollCount; ++j)
        {
            if (true == Check.empty())
            {
                Check.push(s[Index]);
            }
            else
            {
                char PushChar = s[Index];
                char InChar = Check.top();

                if (PushChar - InChar == 2 || PushChar - InChar == 1)
                {
                    Check.pop();
                }
                else
                {
                    Check.push(PushChar);
                }
            }

            if (Index + 1 == RollCount)
            {
                Index = 0;
            }
            else
            {
                ++Index;
            }
        }

        if (0 == Check.size())
        {
            ++answer;
        }
        else
        {
            while (Check.empty() != true)
            {
                Check.pop();
            }
        }
    }

    return answer;
}

int main()
{
    std::cout << solution("[](){}") << std::endl;
    std::cout << solution("}]()[{") << std::endl;
    std::cout << solution("[)(]") << std::endl;
    std::cout << solution("}}}") << std::endl;
}
