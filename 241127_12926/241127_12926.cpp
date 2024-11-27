// 241127_12926.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 시저 암호

/*
문제설명
문제 설명
어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 합니다.
예를 들어 "AB"는 1만큼 밀면 "BC"가 되고, 3만큼 밀면 "DE"가 됩니다. "z"는 1만큼 밀면 "a"가 됩니다.
문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수, solution을 완성해 보세요.
*/

#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string s, int n)
{
    std::string answer = "";

    for (char C : s)
    {
        if (C == ' ')
        {
            answer += ' ';
            continue;
        }

        bool IsUpper = C >= 'A' && C <= 'Z';

        char MoveC = C;

        for (int i = 0; i < n; ++i)
        {
            ++MoveC;

            if (true == IsUpper && MoveC > 'Z')
            {
                MoveC = 'A';
            }
            else if (false == IsUpper && MoveC > 'z')
            {
                MoveC = 'a';
            }
        }

        answer += MoveC;
    }

    return answer;
}

int main()
{
    std::cout << solution("a B z", 25) << std::endl;
}
