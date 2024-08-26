// 240819_172928.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 공원산책

/*
문제 설명
지나다니는 길을 'O', 장애물을 'X'로 나타낸 직사각형 격자 모양의 공원에서 로봇 강아지가 산책을 하려합니다.
산책은 로봇 강아지에 미리 입력된 명령에 따라 진행하며, 명령은 다음과 같은 형식으로 주어집니다.

["방향 거리", "방향 거리" … ]
예를 들어 "E 5"는 로봇 강아지가 현재 위치에서 동쪽으로 5칸 이동했다는 의미입니다.
로봇 강아지는 명령을 수행하기 전에 다음 두 가지를 먼저 확인합니다.

    주어진 방향으로 이동할 때 공원을 벗어나는지 확인합니다.
    주어진 방향으로 이동 중 장애물을 만나는지 확인합니다.

위 두 가지중 어느 하나라도 해당된다면, 로봇 강아지는 해당 명령을 무시하고 다음 명령을 수행합니다.
공원의 가로 길이가 W, 세로 길이가 H라고 할 때,
공원의 좌측 상단의 좌표는 (0, 0),
우측 하단의 좌표는 (H - 1, W - 1) 입니다.

공원을 나타내는 문자열 배열 park,
로봇 강아지가 수행할 명령이 담긴 문자열 배열 routes가 매개변수로 주어질 때,
로봇 강아지가 모든 명령을 수행 후 놓인 위치를 [세로 방향 좌표, 가로 방향 좌표] 순으로
배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Index
{
public:
    //Index()
    //    : X(0), Y(0)
    //{

    //}

    //Index(int _X, int _Y)
    //    : X(_X), Y(_Y)
    //{

    //}

    Index(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    bool Compare(const Index& _CompareValue)
    {
        return X == _CompareValue.X && Y == _CompareValue.Y;
    }

    Index operator+(const Index& _PlusValue) const
    {
        return Index(X + _PlusValue.X, Y + _PlusValue.Y);
    }

public:
    int X = 0;
    int Y = 0;
};

bool IsOver(const Index& _CheckIndex, const int MaxX, const int MaxY)
{
    if (0 > _CheckIndex.X)
    {
        return true;
    }
    if (0 > _CheckIndex.Y)
    {
        return true;
    }
    if (MaxX <= _CheckIndex.X)
    {
        return true;
    }
    if (MaxY <= _CheckIndex.Y)
    {
        return true;
    }

    return false;
}

std::vector<int> solution(std::vector<std::string> park, std::vector<std::string> routes)
{
    std::vector<int> answer(2);

    const int ParkRow = static_cast<int>(park.size());
    const int ParkColumn = static_cast<int>(park[0].size());

    Index CurLocation;
    std::vector<std::vector<bool>> Park(ParkRow, std::vector<bool>(ParkColumn, true));

    // MapData
    for (int i = 0; i < ParkRow; ++i)
    {
        std::string RowParkData = park[i];

        for (int j = 0; j < ParkColumn; ++j)
        {
            if ('O' == RowParkData[j])
            {
                continue;
            }
            else if ('X' == RowParkData[j])
            {
                Park[i][j] = false;
            }
            else
            {
                CurLocation = Index(i, j);
            }
        }
    }

    // MoveData
    for (std::string Move : routes)
    {
        std::stringstream ss(Move);
        char MoveDir;
        int MoveCount;

        ss >> MoveDir >> MoveCount;

        bool IsIgnore = false;

        switch (MoveDir)
        {
        case 'E':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(0, i);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(0, MoveCount);
            }
            break;
        }
        case 'W':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(0, -i);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(0, -MoveCount);
            }
            break;
        }
        case 'N':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(-i, 0);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(-MoveCount, 0);
            }
            break;
        }
        case 'S':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(i, 0);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(MoveCount, 0);
            }
            break;
        }
        default:
            break;
        }
    }

    answer[0] = CurLocation.X;
    answer[1] = CurLocation.Y;

    return answer;
}

void PrintResult(std::vector<std::string> park, std::vector<std::string> routes)
{
    std::vector<int> answer = solution(park, routes);

    std::cout << "도착 세로지점 : " << answer[0] << ", 도착 가로지점 : " << answer[1] << std::endl;
}

int main()
{
    std::vector<std::string> park0 = { "SOO","OOO","OOO" };
    std::vector<std::string> routes0 = { "E 2","S 2","W 1" };

    PrintResult(park0, routes0);

//------------------------------------------------------------------------------
    std::vector<std::string> park1 = { "SOO","OXX","OOO" };
    std::vector<std::string> routes1 = { "E 2","S 2","W 1" };

    PrintResult(park1, routes1);

//------------------------------------------------------------------------------
    std::vector<std::string> park2 = { "OSO","OOO","OXO","OOO" };
    std::vector<std::string> routes2 = { "E 2","S 3","W 1" };

    PrintResult(park2, routes2);
}
