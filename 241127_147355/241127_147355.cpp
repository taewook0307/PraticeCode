// 241127_147355.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 크기가 작은 부분 문자열

/*
문제설명
숫자로 이루어진 문자열 t와 p가 주어질 때, t에서 p와 길이가 같은 부분문자열 중에서,
이 부분문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수를 return하는 함수 solution을 완성하세요.

예를 들어, t="3141592"이고 p="271" 인 경우, t의 길이가 3인 부분 문자열은 314, 141, 415, 159, 592입니다.
이 문자열이 나타내는 수 중 271보다 작거나 같은 수는 141, 159 2개 입니다.
*/

#include <iostream>
#include <string>

int solution(std::string t, std::string p)
{
    int answer = 0;

    const size_t tLen = t.length();
    const size_t pLen = p.length();

    for (size_t i = 0; i <= tLen - pLen; ++i)
    {
        std::string CheckString = t.substr(i, pLen);

        if (CheckString <= p)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution("3141592", "271") << std::endl;
    std::cout << solution("500220839878", "7") << std::endl;
    std::cout << solution("10203", "15") << std::endl;
}
