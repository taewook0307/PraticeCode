// 250108_1844.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// https://school.programmers.co.kr/learn/courses/30/lessons/1844
// 게임 맵 최단 거리

#include <vector>
#include <queue>
#include <array>
#include <iostream>

// 평균시간 : 0.1 ~ 0.2초
int solution(std::vector<std::vector<int>> maps)
{
    int answer = 0;

    const size_t Row = maps.size();
    const size_t Column = maps[0].size();

    std::array<int, 4> DirX = { -1, 1, 0, 0 };
    std::array<int, 4> DirY = { 0, 0, -1, 1 };

    std::vector<std::vector<int>> Pay(Row, std::vector<int>(Column, 0));
    std::vector<std::vector<bool>> IsVisited(Row, std::vector<bool>(Column, false));
    std::queue<std::pair<int, int>> BFS;

    BFS.push(std::make_pair(0, 0));
    IsVisited[0][0] = true;
    Pay[0][0] = 1;

    while (false == BFS.empty())
    {
        std::pair<int, int> CurNode = BFS.front();
        BFS.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NewX = CurNode.first + DirX[i];
            int NewY = CurNode.second + DirY[i];

            if (NewX < 0 || NewY < 0 || NewX >= Row || NewY >= Column)
            {
                continue;
            }

            if (0 == maps[NewX][NewY])
            {
                continue;
            }

            if (true == IsVisited[NewX][NewY])
            {
                continue;
            }

            IsVisited[NewX][NewY] = true;
            Pay[NewX][NewY] = Pay[CurNode.first][CurNode.second] + 1;
            BFS.push(std::make_pair(NewX, NewY));
        }
    }

    if (true == IsVisited[Row - 1][Column - 1])
    {
        answer = Pay[Row - 1][Column - 1];
    }
    else
    {
        answer = -1;
    }

    return answer;
}

int main()
{
    std::cout << solution({ {1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1} }) << std::endl;
    std::cout << solution({ {1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,0}, {0,0,0,0,1} }) << std::endl;
}
