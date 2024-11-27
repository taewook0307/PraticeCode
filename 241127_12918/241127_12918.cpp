// 241127_12918.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문자열 다루기 기본

/*
문제설명
문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요.
예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.
*/

#include <iostream>
#include <string>

bool solution(std::string s)
{
    size_t Len = s.length();

    bool Flag = true;

    for (char C : s)
    {
        if (false == isdigit(C))
        {
            Flag = false;
            break;
        }
    }

    return (Len == 4 || Len == 6) && Flag;
}

int main()
{
    std::cout << "Hello World!\n";
}
