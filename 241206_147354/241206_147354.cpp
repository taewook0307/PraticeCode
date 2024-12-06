// 241206_147354.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 테이블 해시 함수

/*
문제설명
완호가 관리하는 어떤 데이터베이스의 한 테이블은 모두 정수 타입인 컬럼들로 이루어져 있습니다.
테이블은 2차원 행렬로 표현할 수 있으며 열은 컬럼을 나타내고, 행은 튜플을 나타냅니다.
첫 번째 컬럼은 기본키로서 모든 튜플에 대해 그 값이 중복되지 않도록 보장됩니다. 완호는 이 테이블에 대한 해시 함수를 다음과 같이 정의하였습니다.

    1. 해시 함수는 col, row_begin, row_end을 입력으로 받습니다.
    2. 테이블의 튜플을 col번째 컬럼의 값을 기준으로 오름차순 정렬을 하되, 만약 그 값이 동일하면 기본키인 첫 번째 컬럼의 값을 기준으로 내림차순 정렬합니다.
    3. 정렬된 데이터에서 S_i를 i 번째 행의 튜플에 대해 각 컬럼의 값을 i 로 나눈 나머지들의 합으로 정의합니다.
    4. row_begin ≤ i ≤ row_end 인 모든 S_i를 누적하여 bitwise XOR 한 값을 해시 값으로서 반환합니다.

테이블의 데이터 data와 해시 함수에 대한 입력 col, row_begin, row_end이 주어졌을 때 테이블의 해시 값을 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = -1;

    std::sort(data.begin(), data.end(),
        [col](const std::vector<int>& _Left, const std::vector<int>& _Right)
        {
            if (_Left[col - 1] == _Right[col - 1])
            {
                return _Left[0] > _Right[0];
            }

            return _Left[col - 1] < _Right[col - 1];
        }
    );

    for (int i = row_begin - 1; i < row_end; ++i)
    {
        int S_i = 0;

        const std::vector<int>& Tuple = data[i];
        const size_t DataCount = Tuple.size();

        for (size_t j = 0; j < DataCount; ++j)
        {
            S_i += Tuple[j] % (i + 1);
        }

        if (answer == -1)
        {
            answer = S_i;
        }
        else
        {
            answer = answer ^ S_i;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ {2,2,6},{1,5,10},{4,2,9},{3,8,3} }, 2, 2, 3) << std::endl;
}
