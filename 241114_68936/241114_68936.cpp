// 241114_68936.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 쿼드 압축 후 개수 세기

/*
문제설명
0과 1로 이루어진 2n x 2n 크기의 2차원 정수 배열 arr이 있습니다. 당신은 이 arr을 쿼드 트리와 같은 방식으로 압축하고자 합니다. 구체적인 방식은 다음과 같습니다.

    당신이 압축하고자 하는 특정 영역을 S라고 정의합니다.
    만약 S 내부에 있는 모든 수가 같은 값이라면, S를 해당 수 하나로 압축시킵니다.
    그렇지 않다면, S를 정확히 4개의 균일한 정사각형 영역(입출력 예를 참고해주시기 바랍니다.)으로 쪼갠 뒤, 각 정사각형 영역에 대해 같은 방식의 압축을 시도합니다.

arr이 매개변수로 주어집니다. 위와 같은 방식으로 arr을 압축했을 때, 배열에 최종적으로 남는 0의 개수와 1의 개수를 배열에 담아서 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>

bool IsSame(const std::vector<std::vector<int>>& _CheckVector, int _StartX, int _EndX, int _StartY, int _EndY)
{
    int Check = _CheckVector[_StartX][_StartY];

    for (int i = _StartX; i < _EndX; ++i)
    {
        for (int j = _StartY; j < _EndY; ++j)
        {
            if (Check != _CheckVector[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void SetCheckTrue(std::vector<std::vector<bool>>& _ChangeVector, int _StartX, int _EndX, int _StartY, int _EndY)
{
    for (int i = _StartX; i < _EndX; ++i)
    {
        for (int j = _StartY; j < _EndY; ++j)
        {
            _ChangeVector[i][j] = true;
        }
    }
}

std::vector<int> solution(std::vector<std::vector<int>> arr)
{
    std::vector<int> answer(2, 0);

    size_t Row = arr.size();
    size_t Column = arr[0].size();

    size_t CheckRange = Row;

    std::vector<std::vector<bool>> IsCompression(Row, std::vector<bool>(Column, false));

    while (CheckRange != 0)
    {
        for (int i = 0; i < Row; i += CheckRange)
        {
            for (int j = 0; j < Column; j += CheckRange)
            {
                if (IsCompression[i][j] == true)
                {
                    continue;
                }

                if (true == IsSame(arr, i, i + CheckRange, j, j + CheckRange))
                {
                    SetCheckTrue(IsCompression, i, i + CheckRange, j, j + CheckRange);
                    if (arr[i][j] == 0)
                    {
                        ++answer[0];
                    }
                    else
                    {
                        ++answer[1];
                    }
                }
            }
        }

        CheckRange /= 2;
    }

    return answer;
}

int main()
{
    std::vector<int> Result0 = solution({ {1,1,0,0}, {1,0,0,0}, {1,0,0,1}, {1,1,1,1} });
    std::vector<int> Result1 = solution({ {1,1,1,1,1,1,1,1}, {0,1,1,1,1,1,1,1}, {0,0,0,0,1,1,1,1}, {0,1,0,0,1,1,1,1},
                                         {0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,0,1}, {0,0,0,0,1,0,0,1}, {0,0,0,0,1,1,1,1} });

    std::vector<int> Result2 = solution({ {0, 0}, {0, 0} });
}
