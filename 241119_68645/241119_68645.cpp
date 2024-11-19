// 241119_68645.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 삼각 달팽이

/*
문제설명
정수 n이 매개변수로 주어집니다.
밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후,
첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return 하도록 solution 함수를 완성해주세요.

n = 4

      1
    2   9
  3   10  8
4   5   6   7

answer = {1, 2, 9, 3, 10, 8, 4, 5, 6, 7 }

n = 5
        1
      2  12
    3  13  11
  4  14  15  10
5   6   7   8   9

answer = { 1, 2, 12, 3, 13, 11, 4, 14, 15, 10, 5, 6, 7, 8, 9 }
*/

#include <iostream>
#include <vector>
#include <array>

int Sum(int _Num)
{
    if (_Num == 1)
    {
        return 1;
    }

    return Sum(_Num - 1) + _Num;
}

bool IsOver(int _X, int _Y, int _Condition)
{
    if (_X < 0)
    {
        return true;
    }
    if (_Y < 0)
    {
        return true;
    }
    if (_X >= _Condition)
    {
        return true;
    }
    if (_Y >= _Condition)
    {
        return true;
    }

    return false;
}

std::vector<int> solution(int n)
{
    int RecordValue = Sum(n);

    std::vector<int> answer;
    answer.reserve(RecordValue);

    std::vector<std::vector<int>> Record(n, std::vector<int>(n, 0));

    std::array<int, 3> DirX = { 0, 1, -1 };
    std::array<int, 3> DirY = { 1, 0, -1 };

    int DirIndex = 0;

    int CurRecord = 1;

    int X = 0;
    int Y = 0;

    while (CurRecord <= RecordValue)
    {
        Record[Y][X] = CurRecord;
        ++CurRecord;

        int NewX = X + DirX[DirIndex];
        int NewY = Y + DirY[DirIndex];

        if (false == IsOver(NewX, NewY, n) && 0 == Record[NewY][NewX])
        {
            
        }
        else
        {
            ++DirIndex;

            if (DirIndex == 3)
            {
                DirIndex = 0;
            }
        }

        X += DirX[DirIndex];
        Y += DirY[DirIndex];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (0 != Record[i][j])
            {
                answer.push_back(Record[i][j]);
            }
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result1 = solution(4);
    std::vector<int> Result2 = solution(5);
    std::vector<int> Result3 = solution(6);
}
