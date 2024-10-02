// 241002_12951.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// JadenCase 문자열 만들기

/*
문제 설명
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.
단, 첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다.

문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

*/

#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string s)
{
    std::string answer = "";

    //char PrevChar = NULL;

    //for (char CurChar : s)
    //{
    //    if (NULL == PrevChar || ' ' == PrevChar)
    //    {
    //        if ('a' <= CurChar && 'z' >= CurChar)
    //        {
    //            char ChangeChar = CurChar - 32;
    //            answer += ChangeChar;
    //            PrevChar = CurChar;
    //        }
    //        else
    //        {
    //            answer += CurChar;
    //            PrevChar = CurChar;
    //        }
    //    }
    //    else
    //    {
    //        if ('A' <= CurChar && 'Z' >= CurChar)
    //        {
    //            char ChangeChar = CurChar + 32;
    //            answer += ChangeChar;
    //            PrevChar = CurChar;
    //        }
    //        else
    //        {
    //            answer += CurChar;
    //            PrevChar = CurChar;
    //        }
    //    }
    //}

    answer += std::toupper(s[0]);

    const int StringSize = s.size();

    for (size_t i = 1; i < StringSize; ++i)
    {
        char TopChar = answer[i - 1];

        if (TopChar == ' ')
        {
            answer += std::toupper(s[i]);
        }
        else
        {
            answer += std::tolower(s[i]);
        }
    }

    return answer;
}

int main()
{
    std::string Result0 = solution("3people unFollowed me");
    std::string Result1 = solution("for the last week");
}
