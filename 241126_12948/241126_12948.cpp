// 241126_12948.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 핸드폰 번호 가리기

/*
문제설명
프로그래머스 모바일은 개인정보 보호를 위해 고지서를 보낼 때 고객들의 전화번호의 일부를 가립니다.
전화번호가 문자열 phone_number로 주어졌을 때, 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 리턴하는 함수, solution을 완성해주세요.
*/

#include <iostream>
#include <string>

std::string solution(std::string phone_number)
{
    const size_t NumberLength = phone_number.length();

    if (NumberLength == 4)
    {
        return phone_number;
    }

    std::string BackNumber = phone_number.substr(NumberLength - 4);
    std::string answer = "";

    for (size_t i = 0; i < NumberLength - 4; ++i)
    {
        answer += '*';
    }

    answer += BackNumber;

    return answer;
}

int main()
{
    std::cout << solution("01033334444") << std::endl;
    std::cout << solution("027778888") << std::endl;
}
