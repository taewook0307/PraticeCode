// 241112_154538.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 숫자 변환하기

/*
문제설명
자연수 x를 y로 변환하려고 합니다. 사용할 수 있는 연산은 다음과 같습니다.

x에 n을 더합니다
x에 2를 곱합니다.
x에 3을 곱합니다.

자연수 x, y, n이 매개변수로 주어질 때, x를 y로 변환하기 위해 필요한 최소 연산 횟수를 return하도록 solution 함수를 완성해주세요.
이때 x를 y로 만들 수 없다면 -1을 return 해주세요.
*/

#include <iostream>
#include <queue>

int solution(int x, int y, int n)
{
    std::queue<std::pair<int, int>> BFS;
    BFS.push(std::make_pair(y, 0));

    while (false == BFS.empty())
    {
        int CurNum = BFS.front().first;
        int Count = BFS.front().second;

        if (CurNum == x)
        {
            return Count;
        }

        BFS.pop();

        if (CurNum - n >= x)
        {
            BFS.push(std::make_pair(CurNum - n, Count + 1));
        }

        if (CurNum / 2 >= x && CurNum % 2 == 0)
        {
            BFS.push(std::make_pair(CurNum / 2, Count + 1));
        }

        if (CurNum / 3 >= x && CurNum % 3 == 0)
        {
            BFS.push(std::make_pair(CurNum / 3, Count + 1));
        }
    }

    return -1;
}

int main()
{
    std::cout << solution(10, 40, 5) << std::endl;
    std::cout << solution(10, 40, 30) << std::endl;
    std::cout << solution(2, 5, 4) << std::endl;
}
