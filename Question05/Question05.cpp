// Question05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <set>

struct Location
{
    Location(int _X, int _Y)
        : X(_X), Y(_Y)
    {

    }

    void operator+=(const Location& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
    }

    bool operator==(const Location& _Other)
    {
        return X == _Other.X && Y == _Other.Y;
    }

    int X = -1;
    int Y = -1;
};

int queensAttack(int n, int k, int r_q, int c_q, std::vector<std::vector<int>> obstacles)
{
    int Result = 0;

    Location QueenLoc = Location(r_q, c_q);

    std::vector<int> PlusX = {-1, 1, 0, 0, -1, 1, -1, 1};
    std::vector<int> PlusY = {0, 0, 1, -1, 1, 1, -1, -1};

    for (size_t i = 0; i < 8; ++i)
    {
        Location PlusLocation = Location(PlusX[i], PlusY[i]);
        Location MoveQueen = QueenLoc;

        while(1)
        {
            MoveQueen += PlusLocation;
            bool flag = true;

            if (MoveQueen.X <= 0 || MoveQueen.Y <= 0
                || MoveQueen.X > n || MoveQueen.Y > n)
            {
                flag = false;
                break;
            }

            for (const std::vector<int>& Obstacle : obstacles)
            {
                Location ObstacleLoc = Location(Obstacle[0], Obstacle[1]);
                if (ObstacleLoc == MoveQueen)
                {
                    flag = false;
                    break;
                }
            }

            if (true == flag)
            {
                ++Result;
            }
            else
            {
                break;
            }
        }
    }

    return Result;
}


int main()
{
    std::cout << queensAttack(5, 3, 4, 3, { {5, 5}, {4, 2}, {2, 3} }) << std::endl;
}
