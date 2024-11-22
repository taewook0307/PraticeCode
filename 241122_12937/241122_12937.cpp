// 241122_12937.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 짝수와 홀수

/*
문제설명
정수 num이 짝수일 경우 "Even"을 반환하고 홀수인 경우 "Odd"를 반환하는 함수, solution을 완성해주세요.
*/

#include <iostream>
#include <string>

std::string solution(int num)
{
    return num % 2 == 0 ? "Even" : "Odd";
}

//std::string solution(int num)
//{
//    return num & 1 ? "Even" : "Odd";
//}

int main()
{
    std::cout << "Hello World!\n";
}
