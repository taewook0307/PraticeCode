// 241204_77485.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 행렬 테두리 회전하기

/*
문제설명
rows x columns 크기인 행렬이 있습니다.
행렬에는 1부터 rows x columns까지의 숫자가 한 줄씩 순서대로 적혀있습니다.
이 행렬에서 직사각형 모양의 범위를 여러 번 선택해, 테두리 부분에 있는 숫자들을 시계방향으로 회전시키려 합니다.
각 회전은 (x1, y1, x2, y2)인 정수 4개로 표현하며, 그 의미는 다음과 같습니다.

- x1 행 y1 열부터 x2 행 y2 열까지의 영역에 해당하는 직사각형에서 테두리에 있는 숫자들을 한 칸씩 시계방향으로 회전합니다.


-------------------------------------                                                       -------------------------------------
|  1  |  2  |  3  |  4  |  5  |  6  |                                                       |  1  |  2  |  3  |  4  |  5  |  6  |
-------------------------------------                                                       -------------------------------------
|  7  |  8  |  9  | 10  | 11  | 12  |                                                       |  7  | 14  |  8  |  9  | 11  | 12  |
-------------------------------------                                                       -------------------------------------
| 13  | 14  | 15  | 16  | 17  | 18  |                                                       | 13  | 20  | 15  | 10  | 17  | 18  |
-------------------------------------               query(2, 2, 5, 4) 적용 후               -------------------------------------
| 19  | 20  | 21  | 22  | 23  | 24  |                                                       | 19  | 26  | 21  | 16  | 23  | 24  |
-------------------------------------                                                       -------------------------------------
| 25  | 26  | 27  | 28  | 29  | 30  |                                                       | 25  | 27  | 28  | 22  | 29  | 30  |
-------------------------------------                                                       -------------------------------------
| 31  | 32  | 33  | 34  | 35  | 36  |                                                       | 31  | 32  | 33  | 34  | 35  | 36  |
-------------------------------------                                                       -------------------------------------

행렬의 세로 길이(행 개수) rows, 가로 길이(열 개수) columns, 그리고 회전들의 목록 queries가 주어질 때,
각 회전들을 배열에 적용한 뒤, 그 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <array>
#include <deque>

std::vector<int> solution(int rows, int columns, std::vector<std::vector<int>> queries)
{
    const size_t QueryCount = queries.size();
    std::vector<int> answer;
    answer.reserve(QueryCount);

    std::vector<std::vector<int>> Board(rows, std::vector<int>(columns, 0));

    int Num = 1;

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            Board[i][j] = Num;
            ++Num;
        }
    }

    std::array<int, 4> DirX = { 0, 1, 0, -1 };
    std::array<int, 4> DirY = { 1, 0, -1, 0 };

    for (const std::vector<int>& Query : queries)
    {
        std::deque<int> RollNums;

        int RangeStartX = Query[0] - 1;
        int RangeStartY = Query[1] - 1;
        int RangeEndX = Query[2] - 1;
        int RangeEndY = Query[3] - 1;

        RollNums.push_back(Board[RangeStartX][RangeStartY]);
        int DirIndex = 0;

        int NewX = RangeStartX;
        int NewY = RangeStartY;

        while (1)
        {
            NewX += DirX[DirIndex];
            NewY += DirY[DirIndex];

            if (DirIndex == 0 && NewY > RangeEndY
                || DirIndex == 1 && NewX > RangeEndX
                || DirIndex == 2 && NewY < RangeStartY
                || DirIndex == 3 && NewX < RangeStartX
                )
            {
                NewX -= DirX[DirIndex];
                NewY -= DirY[DirIndex];
                ++DirIndex;
                NewX += DirX[DirIndex];
                NewY += DirY[DirIndex];
            }

            if (NewX == RangeStartX && NewY == RangeStartY)
            {
                break;
            }

            RollNums.push_back(Board[NewX][NewY]);
        }

        int BackNum = RollNums.back();
        RollNums.pop_back();
        RollNums.push_front(BackNum);

        int MinValue = *std::min_element(RollNums.begin(), RollNums.end());

        answer.push_back(MinValue);

        if (answer.size() == QueryCount)
        {
            return answer;
        }

        Board[NewX][NewY] = RollNums.front();
        RollNums.pop_front();
        DirIndex = 0;

        while (1)
        {
            NewX += DirX[DirIndex];
            NewY += DirY[DirIndex];

            if (DirIndex == 0 && NewY > RangeEndY
                || DirIndex == 1 && NewX > RangeEndX
                || DirIndex == 2 && NewY < RangeStartY
                || DirIndex == 3 && NewX < RangeStartX
                )
            {
                NewX -= DirX[DirIndex];
                NewY -= DirY[DirIndex];
                ++DirIndex;
                NewX += DirX[DirIndex];
                NewY += DirY[DirIndex];
            }

            if (NewX == RangeStartX && NewY == RangeStartY)
            {
                break;
            }

            Board[NewX][NewY] = RollNums.front();
            RollNums.pop_front();
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
    std::vector<int> Result1 = solution(3, 3, { {1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3} });
    std::vector<int> Result2 = solution(100, 97, { {1,1,100,97} });

    int a = 0;
}
