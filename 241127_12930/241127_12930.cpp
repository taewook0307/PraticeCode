// 241127_12930.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 이상한 문자 만들기

/*
문제설명
문자열 s는 한 개 이상의 단어로 구성되어 있습니다.
각 단어는 하나 이상의 공백문자로 구분되어 있습니다.
각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.
*/

#include <iostream>
#include <string>

std::string solution(std::string s)
{
    std::string answer = "";

    const size_t Len = s.length();
    int Index = 0;

    for (size_t i = 0; i < Len; ++i)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            Index = 0;
            continue;
        }

        if (Index % 2 == 0)
        {
            answer += std::toupper(s[i]);
        }
        else
        {
            answer += std::tolower(s[i]);
        }
        ++Index;
    }

    return answer;
}

int main()
{
    std::cout << solution("try hello world") << std::endl;
}