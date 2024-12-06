// 241206_12905.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 가장 큰 정사각형 찾기

/*
문제설명
1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다.
표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요.
(단, 정사각형이란 축에 평행한 정사각형을 말합니다.)

ex)

0111
1111
1111
0010            정답 : 9

*/

#include <iostream>
#include <vector>

int solution(std::vector<std::vector<int>> board)
{
    int answer = 0;

    const size_t Row = board.size();
    const size_t Column = board[0].size();

    std::vector<std::vector<int>> Width(Row, std::vector<int>(Column, 0));

    for (size_t i = 0; i < Row; ++i)
    {
        Width[i][0] = board[i][0];

        answer = std::max(Width[i][0], answer);
    }

    for (size_t i = 0; i < Column; ++i)
    {
        Width[0][i] = board[0][i];

        answer = std::max(Width[0][i], answer);
    }

    for (size_t i = 1; i < Row; ++i)
    {
        for (size_t j = 1; j < Column; ++j)
        {
            if (1 == board[i][j])
            {
                int UpTileValue = Width[i][j - 1];
                int CrossTileValue = Width[i - 1][j - 1];
                int LeftTileValue = Width[i - 1][j];

                int MinValue = std::min(std::min(UpTileValue, CrossTileValue), LeftTileValue);

                Width[i][j] = MinValue + 1;

                answer = std::max(Width[i][j], answer);
            }
            else
            {
                Width[i][j] = 0;
            }
        }
    }

    answer *= answer;

    return answer;
}

int main()
{
    std::cout << solution({ { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 0, 0, 1, 0 } }) << std::endl;
    std::cout << solution({ { 0, 0, 1, 1 }, { 1, 1, 1, 1 } }) << std::endl;
    std::cout << solution({ { 1, 1, 1, 1 }, { 1, 1, 1, 1 } }) << std::endl;
    std::cout << solution({ { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }) << std::endl;
    std::cout << solution({ { 0, 1, 0, 1 }, { 1, 0, 1, 0 } }) << std::endl;
    std::cout << solution({ { 1, 0 }, { 0, 0 } }) << std::endl;
}
