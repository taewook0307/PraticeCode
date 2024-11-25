// 241125_12933.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 정수 내림차순으로 배치하기

/*
문제설명
함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

long long solution(long long n)
{
    long long answer = 0;

    std::vector<long long> Num;

    while (n != 0)
    {
        Num.push_back(n % 10);
        n /= 10;
    }

    std::sort(Num.begin(), Num.end(), std::greater<long long>());

    for (long long Plus : Num)
    {
        answer *= 10;
        answer += Plus;
    }

    return answer;
}

// string 정렬 이용도 가능

int main()
{
    std::cout << "Hello World!\n";
}
