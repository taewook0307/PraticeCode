// 241105_Making_A_Magic_Square.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 마방진 만들기

/*
문제 설명
주어진 행렬이 마방진으로 바꿀 때 드는 최소 비용을 구하세요
*/

#include <iostream>
#include <vector>

int formingMagicSquare(std::vector<std::vector<int>> s)
{
    const std::vector<std::vector<std::vector<int>>> Magic =
    {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };
    
    int minCost = INT_MAX;

    for (const std::vector<std::vector<int>>& Check : Magic)
    {
        int cost = 0;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cost += abs(s[i][j] - Check[i][j]);
            }
        }

        minCost = std::min(minCost, cost);
    }

    return minCost;
}

int main()
{
    std::cout << "Hello World!\n";
}
