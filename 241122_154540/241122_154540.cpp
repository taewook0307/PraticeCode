// 241122_154540.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 무인도 여행

/*
문제설명
메리는 여름을 맞아 무인도로 여행을 가기 위해 지도를 보고 있습니다.
지도에는 바다와 무인도들에 대한 정보가 표시돼 있습니다.
지도는 1 x 1크기의 사각형들로 이루어진 직사각형 격자 형태이며, 격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀있습니다.
지도의 'X'는 바다를 나타내며, 숫자는 무인도를 나타냅니다. 이때, 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룹니다.
지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다.
어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 합니다.

지도를 나타내는 문자열 배열 maps가 매개변수로 주어질 때, 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return 하는 solution 함수를 완성해주세요.
만약 지낼 수 있는 무인도가 없다면 -1을 배열에 담아 return 해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stack>
#include <algorithm>

std::vector<int> solution(std::vector<std::string> maps)
{
    std::vector<int> answer;

    const size_t Row = maps.size();
    const size_t Column = maps[0].length();

    std::array<int, 4> DirX = {-1, 1, 0, 0};
    std::array<int, 4> DirY = {0, 0, -1, 1};

    std::vector<std::vector<bool>> Check(Row, std::vector<bool>(Column, false));

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Column; ++j)
        {
            if ('X' == maps[i][j])
            {
                Check[i][j] = true;
            }
        }
    }

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Column; ++j)
        {
            if (true == Check[i][j])
            {
                continue;
            }

            std::pair<int, int> Start = std::make_pair(i, j);

            std::vector<std::vector<bool>> IsVisited(Row, std::vector<bool>(Column, false));
            std::stack<std::pair<int, int>> Node;
            Node.push(Start);
            IsVisited[Start.first][Start.second] = true;
            int Day = 0;

            while (false == Node.empty())
            {
                std::pair<int, int> CurNode = Node.top();

                bool Flag = false;

                for (int i = 0; i < 4; ++i)
                {
                    int NewX = CurNode.first + DirX[i];
                    int NewY = CurNode.second + DirY[i];

                    if (NewX < 0 || NewY < 0 || NewX >= Row || NewY >= Column)
                    {
                        continue;
                    }

                    if (false == IsVisited[NewX][NewY] && 'X' != maps[NewX][NewY])
                    {
                        Node.push(std::make_pair(NewX, NewY));
                        IsVisited[NewX][NewY] = true;
                        Flag = true;
                        break;
                    }
                }

                if (Flag == false)
                {
                    Node.pop();
                    Day += maps[CurNode.first][CurNode.second] - '0';
                    Check[CurNode.first][CurNode.second] = true;

                    if (CurNode == Start)
                    {
                        answer.push_back(Day);
                    }
                }
            }
        }
    }

    if (true == answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        std::sort(answer.begin(), answer.end());
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution({ "X591X","X1X5X","X231X", "1XXX1" });
    std::vector<int> Result1 = solution({ "X591X", "11X5X", "X231X", "1XXX1" });
    
    int a = 0;
}
