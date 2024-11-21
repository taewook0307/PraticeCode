// 241121_159993.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 미로 탈출

/*
문제설명
1 x 1 크기의 칸들로 이루어진 직사각형 격자 형태의 미로에서 탈출하려고 합니다.
각 칸은 통로 또는 벽으로 구성되어 있으며, 벽으로 된 칸은 지나갈 수 없고 통로로 된 칸으로만 이동할 수 있습니다.
통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데, 이 문은 레버를 당겨서만 열 수 있습니다.
레버 또한 통로들 중 한 칸에 있습니다. 따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여 레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 됩니다.
이때 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있습니다.
미로에서 한 칸을 이동하는데 1초가 걸린다고 할 때, 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 합니다.

미로를 나타낸 문자열 배열 maps가 매개변수로 주어질 때, 미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 완성해주세요. 만약, 탈출할 수 없다면 -1을 return 해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <queue>

int solution(std::vector<std::string> maps)
{
    const size_t Row = maps.size();
    const size_t Column = maps[0].size();

    std::array<int, 4> DirX = { -1, 1, 0, 0 };
    std::array<int, 4> DirY = { 0, 0, -1, 1 };

    std::vector<std::vector<int>> TimeLever(Row, std::vector<int>(Column, -1));
    std::vector<std::vector<bool>> IsVisitedLever(Row, std::vector<bool>(Column, false));
    std::vector<std::vector<int>> TimeEnd(Row, std::vector<int>(Column, -1));
    std::vector<std::vector<bool>> IsVisitedEnd(Row, std::vector<bool>(Column, false));

    std::queue<std::pair<int, int>> Node;

    std::pair<int, int> Start;
    std::pair<int, int> End;
    std::pair<int, int> Lever;

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Column; ++j)
        {
            if (maps[i][j] == 'X')
            {
                continue;
            }
            else if (maps[i][j] == 'O')
            {
                TimeLever[i][j] = 0;
                TimeEnd[i][j] = 0;
            }
            else if (maps[i][j] == 'S')
            {
                TimeLever[i][j] = 0;
                TimeEnd[i][j] = 0;
                Start = std::make_pair(i, j);
                IsVisitedLever[i][j] = true;
                Node.push(Start);
            }
            else if (maps[i][j] == 'E')
            {
                TimeLever[i][j] = 0;
                TimeEnd[i][j] = 0;
                End = std::make_pair(i, j);
            }
            else
            {
                TimeLever[i][j] = 0;
                TimeEnd[i][j] = 0;
                Lever = std::make_pair(i, j);
            }
        }
    }

    while (false == Node.empty())
    {
        std::pair<int, int> CurNode = Node.front();
        Node.pop();

        if (CurNode == Lever)
        {
            TimeEnd[CurNode.first][CurNode.second] = TimeLever[CurNode.first][CurNode.second];
            IsVisitedEnd[CurNode.first][CurNode.second] = true;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurNode.first + DirX[i];
            int NextY = CurNode.second + DirY[i];

            if (NextX < 0 || NextY < 0 || NextX >= Row || NextY >= Column)
            {
                continue;
            }

            if (false == IsVisitedLever[NextX][NextY] && -1 != TimeLever[NextX][NextY])
            {
                Node.push(std::make_pair(NextX, NextY));
                TimeLever[NextX][NextY] = TimeLever[CurNode.first][CurNode.second] + 1;
                IsVisitedLever[NextX][NextY] = true;
            }
        }
    }

    if (false == IsVisitedLever[Lever.first][Lever.second])
    {
        return -1;
    }

    while (false == Node.empty())
    {
        Node.pop();
    }

    Node.push(Lever);

    while (false == Node.empty())
    {
        std::pair<int, int> CurNode = Node.front();
        Node.pop();

        if (CurNode == End)
        {
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurNode.first + DirX[i];
            int NextY = CurNode.second + DirY[i];

            if (NextX < 0 || NextY < 0 || NextX >= Row || NextY >= Column)
            {
                continue;
            }

            if (false == IsVisitedEnd[NextX][NextY] && -1 == TimeEnd[NextX][NextY])
            {
                Node.push(std::make_pair(NextX, NextY));
                TimeEnd[NextX][NextY] = TimeEnd[CurNode.first][CurNode.second] + 1;
                IsVisitedEnd[NextX][NextY] = true;
            }
        }
    }

    if (false == IsVisitedEnd[End.first][End.second])
    {
        return -1;
    }

    return TimeEnd[End.first][End.second];
}

int main()
{
    std::cout << solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" }) << std::endl;
    std::cout << solution({ "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" }) << std::endl;
}
