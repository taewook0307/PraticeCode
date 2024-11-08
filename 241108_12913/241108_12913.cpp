// 241108_12913.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 땅따먹기

/*
문제설명
땅따먹기 게임을 하려고 합니다. 땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고, 모든 칸에는 점수가 쓰여 있습니다.
1행부터 땅을 밟으며 한 행씩 내려올 때, 각 행의 4칸 중 한 칸만 밟으면서 내려와야 합니다.
단, 땅따먹기 게임에는 한 행씩 내려올 때, 같은 열을 연속해서 밟을 수 없는 특수 규칙이 있습니다.

예를 들면,

| 1 | 2 | 3 | 5 |

| 5 | 6 | 7 | 8 |

| 4 | 3 | 2 | 1 |

로 땅이 주어졌다면, 1행에서 네번째 칸 (5)를 밟았으면, 2행의 네번째 칸 (8)은 밟을 수 없습니다.

마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 return하는 solution 함수를 완성해 주세요.

위 예의 경우, 1행의 네번째 칸 (5), 2행의 세번째 칸 (7), 3행의 첫번째 칸 (4) 땅을 밟아 16점이 최고점이 되므로 16을 return 하면 됩니다.
*/

#include <iostream>
#include <vector>

int solution(std::vector<std::vector<int> > land)
{
    int answer = 0;

    std::vector<std::vector<int>> DP(land.size(), std::vector<int>(land[0].size(), 0));

    for (int i = 0; i < 4; ++i)
    {
        DP[0][i] = land[0][i];
    }

    size_t RowCount = land.size();

    for (int i = 1; i < RowCount; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int MaxValue = -1;

            for (int k = 0; k < 4; ++k)
            {
                if (j == k)
                {
                    continue;
                }

                MaxValue = std::max(MaxValue, DP[i - 1][k] + land[i][j]);
            }

            DP[i][j] = MaxValue;
        }
    }

    answer = *std::max_element(DP[RowCount - 1].begin(), DP[RowCount - 1].end());

    return answer;
}

int main()
{
    std::cout << solution({ {1,2,3,5},{5,6,7,8},{4,3,2,1} }) << std::endl;
}
