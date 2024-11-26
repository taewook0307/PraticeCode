// 241126_12903.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 가운데 글자 가져오기

/*
문제설명
단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요.
단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.
*/

#include <iostream>
#include <string>

std::string solution(std::string s)
{
    std::string answer = "";

    if (s.length() % 2 == 0)
    {
        int Half = s.length() / 2;
        
        answer = s.substr(Half - 1, 2);
    }
    else
    {
        int Half = s.length() / 2;
        answer = s[Half];
    }
    
    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
