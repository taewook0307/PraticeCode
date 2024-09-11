// 240911_340198.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [PCCE 기출문제] 10번/공원

/*
문제 설명
지민이는 다양한 크기의 정사각형 모양 돗자리를 가지고 공원에 소풍을 나왔습니다.
공원에는 이미 돗자리를 깔고 여가를 즐기는 사람들이 많아 지민이가 깔 수 있는 가장 큰 돗자리가 어떤 건지 확인하려 합니다.
지민이가 가진 돗자리들의 한 변의 길이들이 담긴 정수 리스트 mats, 현재 공원의 자리 배치도를 의미하는 2차원 문자열 리스트 park가 주어질 때
지민이가 깔 수 있는 가장 큰 돗자리의 한 변 길이를 return 하도록 solution 함수를 완성해 주세요.
아무런 돗자리도 깔 수 없는 경우 -1을 return합니다
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool IsMatSetting(const std::vector<std::vector<std::string>>& _Park, int _MatSize, int _StartXIndex, int _StartYIndex)
{
    for (int i = _StartXIndex; i < _StartXIndex + _MatSize; ++i)
    {
        for (int j = _StartYIndex; j < _StartYIndex + _MatSize; ++j)
        {
            if ("-1" != _Park[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int solution(std::vector<int> mats, std::vector<std::vector<std::string>> park)
{
    int answer = -1;

    const int RowCount = static_cast<int>(park.size());
    const int ColumnCount = static_cast<int>(park[0].size());

    // 매트 사이즈가 큰 순서대로 정렬
    sort(mats.begin(), mats.end(), std::greater<int>());

    for (int MatSize : mats)
    {
        // 각 인덱스를 시작점으로 돗자리를 펼 수 있는지 확인
        for (int i = 0; i <= RowCount - MatSize; ++i)
        {
            for (int j = 0; j <= ColumnCount - MatSize; ++j)
            {
                bool IsSetting = IsMatSetting(park, MatSize, i, j);

                // 펼 수 있을경우에는 해당 사이즈 리턴
                if (true == IsSetting)
                {
                    return MatSize;
                }
            }
        }
    }

    // 아니면 -1 리턴
    return answer;
}

int main()
{
    std::vector<int> mats0 = { 5,3,2 };
    std::vector<std::vector<std::string>> park0 =
    { 
        {"-1", "-1", "-1"},
        {"-1", "-1", "-1"},
        {"-1", "-1", "-1"}
    };
    std::cout << solution(mats0, park0) << std::endl;
}
