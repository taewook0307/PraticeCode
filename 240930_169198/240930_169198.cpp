// 240930_169198.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 당구 연습

/*
문제 설명
"원쿠션"(당구에서 공을 쳐서 벽에 맞히는 걸 쿠션이라고 부르고, 벽에 한 번 맞힌 후 공에 맞히면 원쿠션이라고 부릅니다) 연습
당구공의 위치가 담긴 리스트
리스트에 담긴 각 위치에 순서대로 공을 놓아가며 "원쿠션" 연습을 시행


당구대의 가로 길이 m, 세로 길이 n과
머쓱이가 쳐야 하는 공이 놓인 위치 좌표를 나타내는 두 정수 startX, startY,
그리고 매 회마다 목표로 해야하는 공들의 위치 좌표를 나타내는 정수 쌍들이 들어있는 2차원 정수배열 balls가 주어집니다.
"원쿠션" 연습을 위해 머쓱이가 공을 적어도 벽에 한 번은 맞춘 후 목표 공에 맞힌다고 할 때,
각 회마다 머쓱이가 친 공이 굴러간 거리의 최솟값의 제곱을 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

단, 친 공이 벽에 부딪힐 때 진행 방향은 항상 입사각과 반사각이 동일하며,
만약 꼭짓점에 부딪힐 경우 진입 방향의 반대방향으로 공이 진행됩니다. 공의 크기는 무시하며,
두 공의 좌표가 정확히 일치하는 경우에만 두 공이 서로 맞았다고 판단합니다.

공이 목표 공에 맞기 전에 멈추는 경우는 없으며,
목표 공에 맞으면 바로 멈춘다고 가정합니다
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Location
{
    Location(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    int DistanceSqure(const Location& _Other)
    {
        int a = _Other.X - X;
        int b = _Other.Y - Y;

        int DistanceSqure = pow(a, 2) + pow(b, 2);

        return DistanceSqure;
    }

    int X;
    int Y;
};

std::vector<int> solution(int m, int n, int startX, int startY, std::vector<std::vector<int>> balls)
{
    std::vector<int> answer;
    answer.reserve(balls.size());

    Location Start(startX, startY);

    static std::vector<Location> CheckList =
    {
        // 왼쪽
        Location(-Start.X, Start.Y),
        // 오른쪽
        Location(Start.X + 2 *(m - Start.X), Start.Y),
        // 위쪽
        Location(Start.X, Start.Y + 2 * (n - Start.Y)),
        // 아래쪽
        Location(Start.X, -Start.Y)
    };

    for (const std::vector<int>& CurBall : balls)
    {
        Location Destination(CurBall[0], CurBall[1]);

        int MinDistance = -1;

        for (int i = 0; i < 4; ++i)
        {
            Location CheckLocation = CheckList[i];
            int Distance = CheckLocation.DistanceSqure(Destination);

            // X좌표가 같을경우
            if (Destination.X == Start.X)
            {
                // 위쪽
                if (i == 2 && Start.Y < Destination.Y)
                {
                    continue;
                }
                // 아래쪽
                if (i == 3 && Start.Y > Destination.Y)
                {
                    continue;
                }
            }

            // Y좌표가 같을경우
            if (Destination.Y == Start.Y)
            {
                // 왼쪽
                if (i == 0 && Start.X > Destination.X)
                {
                    continue;
                }
                // 오른쪽
                if (i == 1 && Start.X < Destination.X)
                {
                    continue;
                }
            }

            if (MinDistance < 0)
            {
                MinDistance = Distance;
            }
            else
            {
                MinDistance = std::min<int>(MinDistance, Distance);
            }
        }

        answer.push_back(MinDistance);
    }

    return answer;
}

int main()
{
    std::vector<std::vector<int>> balls0 = { {7, 7}, {2, 7}, {7, 3} };
    std::vector<int> Result0 = solution(10, 10, 3, 7, balls0);

    int a = 0;
}
