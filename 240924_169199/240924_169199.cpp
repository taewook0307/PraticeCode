// 240924_169199.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 리코쳇 로봇

/*
문제 설명
리코쳇 로봇이라는 보드게임이 있습니다.

이 보드게임은 격자모양 게임판 위에서 말을 움직이는 게임으로, 시작 위치에서 출발한 뒤 목표 위치에 정확하게 멈추기 위해 최소 몇 번의 이동이 필요한지 말하는 게임입니다.

이 게임에서 말의 이동은 현재 위치에서 상, 하, 좌, 우 중 한 방향으로
게임판 위의 장애물이나 게임판 가장자리까지 부딪힐 때까지 미끄러져 움직이는 것을 한 번의 이동으로 정의합니다.

("."은 빈 공간을, "R"은 로봇의 처음 위치를, "D"는 장애물의 위치를, "G"는 목표지점을 나타냅니다.)

게임판의 상태를 나타내는 문자열 배열 board가 주어졌을 때,
말이 목표위치에 도달하는데 최소 몇 번 이동해야 하는지 return 하는 solution함수를 완성해주세요.
만약 목표위치에 도달할 수 없다면 -1을 return 해주세요.
*/

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>

struct Index
{
    Index(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    Index(const Index& _Other)
        : X(_Other.X), Y(_Other.Y)
    {

    }

    bool operator==(const Index& _Other)
    {
        return this->X == _Other.X && this->Y == _Other.Y;
    }

    bool operator!=(const Index& _Other)
    {
        return this->X != _Other.X || this->Y != _Other.Y;
    }

    int X;
    int Y;
};

bool IsOver(int _X, int _Y, int _Row, int _Column)
{
    if (_X < 0)
    {
        return true;
    }
    if (_Y < 0)
    {
        return true;
    }
    if (_X >= _Row)
    {
        return true;
    }
    if (_Y >= _Column)
    {
        return true;
    }

    return false;
}

int solution(std::vector<std::string> board)
{
    int RowCount = static_cast<int>(board.size());
    int ColumnCount = static_cast<int>(board[0].size());

    std::vector<std::vector<bool>> IsVisit(RowCount, std::vector<bool>(ColumnCount, false));
    std::vector<std::vector<int>> Distance(RowCount, std::vector<int>(ColumnCount, 0));

    Index CurLocation;
    Index Destination;

    // 초기값 세팅
    for (int i = 0; i < RowCount; ++i)
    {
        for (int j = 0; j < ColumnCount; ++j)
        {
            Index CurIndex(i, j);

            // 장애물
            if ('D' == board[i][j])
            {
                Distance[i][j] = -1;
            }
            // 시작점
            else if ('R' == board[i][j])
            {
                CurLocation.X = i;
                CurLocation.Y = j;
                IsVisit[CurLocation.X][CurLocation.Y] = true;
            }
            // 도착점
            else if ('G' == board[i][j])
            {
                Destination.X = i;
                Destination.Y = j;
            }
            // 그 외
            else
            {
                continue;
            }
        }
    }

    // 시작점 Queue에 세팅
    std::queue<Index> Search;
    Search.push(CurLocation);

    // 탐색 시작
    while (true != Search.empty())
    {
        CurLocation.X = Search.front().X;
        CurLocation.Y = Search.front().Y;
        
        // 큐에 제일 윗 부분이 목적지에 경우
        if (CurLocation == Destination)
        {
            return Distance[Destination.X][Destination.Y];
        }

        Search.pop();
        
        std::array<int, 4> PlusX = { -1, 1, 0, 0 };
        std::array<int, 4> PlusY = { 0, 0, -1, 1 };

        Index MoveIndex(CurLocation);

        for (int i = 0; i < 4; ++i)
        {
            // 첫번째 이동
            MoveIndex.X = CurLocation.X + PlusX[i];
            MoveIndex.Y = CurLocation.Y + PlusY[i];

            // 이동한 후 확인 후 계속 이동
            while (false == IsOver(MoveIndex.X, MoveIndex.Y, RowCount, ColumnCount))
            {
                if ('D' == board[MoveIndex.X][MoveIndex.Y])
                {
                    break;
                }

                MoveIndex.X += PlusX[i];
                MoveIndex.Y += PlusY[i];
            }

            // 범위 초과 후 이전 값으로 이동
            MoveIndex.X -= PlusX[i];
            MoveIndex.Y -= PlusY[i];

            // 방문기록 확인
            if (MoveIndex != CurLocation && false == IsVisit[MoveIndex.X][MoveIndex.Y])
            {
                Search.push(MoveIndex);
                Distance[MoveIndex.X][MoveIndex.Y] = Distance[CurLocation.X][CurLocation.Y] + 1;
                IsVisit[MoveIndex.X][MoveIndex.Y] = true;
            }
        }
    }

    // 도착하지 못했을 경우
    if (false == IsVisit[Destination.X][Destination.Y])
    {
        return -1;
    }
}

int main()
{
    std::vector<std::string> board0 = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." };
    int Result0 = solution(board0);

    std::cout << "Result0 : " << Result0 << std::endl;

    std::vector<std::string> board1 = { ".D.R", "....", ".G..", "...D" };
    int Result1 = solution(board1);

    std::cout << "Result0 : " << Result1 << std::endl;
}
