// 241125_12954.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// x만큼 간격이 있는 n개의 숫자

/*
문제설명
함수 solution은 정수 x와 자연수 n을 입력 받아, x부터 시작해 x씩 증가하는 숫자를 n개 지니는 리스트를 리턴해야 합니다.
다음 제한 조건을 보고, 조건을 만족하는 함수, solution을 완성해주세요.
*/

#include <iostream>
#include <vector>

std::vector<long long> solution(int x, int n)
{
    std::vector<long long> answer;
    answer.reserve(n);

    for (int i = x; ; i += x)
    {
        answer.push_back(i);

        if (answer.size() == n)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    std::vector<long long> Result = solution(2, 5);
    std::vector<long long> Result1 = solution(4, 3);
}
