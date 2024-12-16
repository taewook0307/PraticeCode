// 241216_81302.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 거리두기 확인하기

/*
문제설명
개발자를 희망하는 죠르디가 카카오에 면접을 보러 왔습니다.

코로나 바이러스 감염 예방을 위해 응시자들은 거리를 둬서 대기를 해야하는데 개발 직군 면접인 만큼 아래와 같은 규칙으로 대기실에 거리를 두고 앉도록 안내하고 있습니다.

1. 대기실은 5개이며, 각 대기실은 5x5 크기입니다.
2. 거리두기를 위하여 응시자들 끼리는 맨해튼 거리1가 2 이하로 앉지 말아 주세요.
3. 단 응시자가 앉아있는 자리 사이가 파티션으로 막혀 있을 경우에는 허용합니다.

ex)
거리두기 지킨 예

PX          PXP
XP

거리두기 안 지킨 예

PX          P0P
0P


5개의 대기실을 본 죠르디는 각 대기실에서 응시자들이 거리두기를 잘 기키고 있는지 알고 싶어졌습니다.
자리에 앉아있는 응시자들의 정보와 대기실 구조를 대기실별로 담은 2차원 문자열 배열 places가 매개변수로 주어집니다.
각 대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 배열에 담아 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//std::vector<int> solution(std::vector<std::vector<std::string>> places)
//{
//    const size_t RoomCount = places.size();
//    const size_t Row = places[0].size();
//    const size_t Column = places[0][0].length();
//
//    std::vector<int> answer;
//    answer.reserve(places.size());
//
//    for (size_t Room = 0; Room < RoomCount; ++Room)
//    {
//        std::vector<std::string>& CheckRoom = places[Room];
//        bool IsCorrect = true;
//
//        for (size_t i = 0; i < Row - 1; ++i)
//        {
//            for (size_t j = 0; j < Column - 1; ++j)
//            {
//                char Seat = CheckRoom[i][j];
//                char LeftSeat = CheckRoom[i + 1][j];
//                char DownSeat = CheckRoom[i][j + 1];
//                char CrossSeat = CheckRoom[i + 1][j + 1];
//
//                switch (Seat)
//                {
//                case 'P':
//                {
//                    if (LeftSeat == 'P')
//                    {
//                        IsCorrect = false;
//                        break;
//                    }
//
//                    if (DownSeat == 'P')
//                    {
//                        IsCorrect = false;
//                        break;
//                    }
//
//                    if (CrossSeat == 'P' && (LeftSeat != 'X' || DownSeat != 'X'))
//                    {
//                        IsCorrect = false;
//                        break;
//                    }
//
//                    if (i < Row - 2 && j < Column - 2)
//                    {
//                        char TwoLeftSeat = CheckRoom[i + 2][j];
//                        char TwoDownSeat = CheckRoom[i][j + 2];
//
//                        if (TwoLeftSeat == 'P' && LeftSeat != 'X'
//                            || TwoDownSeat == 'P' && DownSeat != 'X')
//                        {
//                            IsCorrect = false;
//                            break;
//                        }
//                    }
//
//                    break;
//                }
//                case 'O':
//                {
//                    if (LeftSeat == 'P' && DownSeat == 'P'
//                        || LeftSeat == 'P' && CrossSeat == 'P'
//                        || DownSeat == 'P' && CrossSeat == 'P')
//                    {
//                        IsCorrect = false;
//                        break;
//                    }
//                    break;
//                }
//                case 'X':
//                {
//                    if (LeftSeat == 'P' && DownSeat == 'P' && CrossSeat != 'X')
//                    {
//                        IsCorrect = false;
//                        break;
//                    }
//                    break;
//                }
//                default:
//                    break;
//                }
//            }
//
//            if (IsCorrect == false)
//            {
//                break;
//            }
//        }
//
//        answer.push_back(true == IsCorrect ? 1 : 0);
//    }
//
//    return answer;
//}

int CalDistance(const std::pair<int, int>& _Left, const std::pair<int, int>& _Right)
{
    int Result = abs(_Left.first - _Right.first) + abs(_Left.second - _Right.second);

    return Result;
}

std::vector<int> solution(std::vector<std::vector<std::string>> places)
{
    const int RoomCount = static_cast<int>(places.size());
    const int Row = static_cast<int>(places[0].size());
    const int Column = static_cast<int>(places[0][0].length());

    std::vector<int> answer;
    answer.reserve(RoomCount);

    for (const std::vector<std::string>& CheckRoom : places)
    {
        bool IsCorrect = true;
        std::vector<std::pair<int, int>> Seats;

        for (int i = 0; i < Row; ++i)
        {
            for (int j = 0; j < Column; ++j)
            {
                if (CheckRoom[i][j] == 'P')
                {
                    Seats.push_back(std::make_pair(i, j));
                }
            }
        }

        int PersonCount = static_cast<int>(Seats.size());

        if (0 == PersonCount)
        {
            answer.push_back(1);
            continue;
        }

        for (int i = 0; i < PersonCount - 1; ++i)
        {
            for (int j = i + 1; j < PersonCount; ++j)
            {
                int Distance = CalDistance(Seats[i], Seats[j]);

                switch (Distance)
                {
                case 1:
                {
                    IsCorrect = false;
                    break;
                }
                case 2:
                {
                    int DifX = Seats[j].first - Seats[i].first;
                    int DifY = Seats[j].second - Seats[i].second;

                    if (DifX != 0 && DifY != 0)
                    {
                        if (DifY < 0)
                        {
                            if (CheckRoom[Seats[i].first][Seats[i].second - 1] == 'X' && CheckRoom[Seats[i].first + 1][Seats[i].second] == 'X')
                            {
                                continue;
                            }
                        }
                        else
                        {
                            if (CheckRoom[Seats[i].first + 1][Seats[i].second] == 'X' && CheckRoom[Seats[i].first][Seats[i].second + 1] == 'X')
                            {
                                continue;
                            }
                        }

                        IsCorrect = false;
                        break;
                    }
                    else if (DifX == 0)
                    {
                        int CheckX = Seats[i].first;
                        int CheckY = Seats[i].second + 1;

                        if (CheckRoom[CheckX][CheckY] != 'X')
                        {
                            IsCorrect = false;
                            break;
                        }
                    }
                    else if (DifY == 0)
                    {
                        int CheckX = Seats[i].first + 1;
                        int CheckY = Seats[i].second;

                        if (CheckRoom[CheckX][CheckY] != 'X')
                        {
                            IsCorrect = false;
                            break;
                        }
                    }
                    
                    break;
                }
                default:
                    break;
                }

                if (false == IsCorrect)
                {
                    break;
                }
            }

            if (false == IsCorrect)
            {
                break;
            }
        }

        answer.push_back(true == IsCorrect ? 1 : 0);
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution(                         // 1 0 1 1 1
        {
            {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
            {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
            {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
            {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
            {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        }
    );

    std::vector<int> Result1 = solution(                        // 0 0 1 1 1
        {
            {"XP0PX", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
            {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
            {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
            {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
            {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        }
    );

    std::vector<int> Result2 = solution(                        // 0
        {
            {"OOPOO", "OPOOO", "OOOOO", "OOOOO", "OOOOO"}
        }
    );

    std::vector<int> Result3 = solution(                        //  0 1 0
        {
            {"PPPPP", "XXXXX", "PPPPP", "XXXXX", "PPPPP"},
            {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"},
            {"POXPX", "XPXOX", "OXPXP", "PXOXP", "XXXOX"}
        }
    );

    int a = 0;
}
