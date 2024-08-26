// 240724_12901.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 2016년

/*
문제 설명
2016년 1월 1일은 금요일입니다.

2016년 a월 b일은 무슨 요일일까요?
두 수 a ,b를 입력받아
2016년 a월 b일이 무슨 요일인지 리턴하는 함수,
solution을 완성하세요.

요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT 입니다.
*/

#include <iostream>
#include <string>
#include <vector>

std::string solution(int a, int b)
{
    std::string answer = "";

    std::vector<std::string> Week = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    std::vector<int> Days = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int CalculateDays = 0;

    for (int i = 0; i < a - 1; ++i)
    {
        CalculateDays += Days[i];
    }

    CalculateDays += b;

    int RemainDay = CalculateDays % 7;

    answer = Week[RemainDay];

    return answer;
}

void PrintResult(int a, int b)
{
    std::string Result = solution(a, b);
    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    PrintResult(5, 24);
}
