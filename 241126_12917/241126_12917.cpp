// 241126_12917.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문자열 내림차순으로 배치하기

/*
문제설명
문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string solution(std::string s)
{
    std::sort(s.begin(), s.end(), std::greater<char>());

    return s;
}

int main()
{
    std::cout << solution("Zbcdefg") << std::endl;
}
