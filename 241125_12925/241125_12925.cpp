// 241125_12925.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문자열을 정수로 바꾸기

/*
문제설명
문자열 s를 숫자로 변환한 결과를 반환하는 함수, solution을 완성하세요.
*/

#include <iostream>
#include <string>

int solution(std::string s)
{
    return std::stoi(s);
}

int main()
{
    std::cout << solution("-1234");
}
