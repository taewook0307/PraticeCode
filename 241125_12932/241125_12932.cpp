// 241125_12932.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 자연수 뒤집어 배열로 만들기

/*
문제설명
자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
*/

#include <iostream>
#include <vector>

std::vector<int> solution(long long n)
{
    std::vector<int> answer;
    answer.reserve(11);

    while (n != 0)
    {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
