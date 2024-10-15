// 241015_172927.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 광물 캐기

/*
문제 설명
마인은 곡괭이로 광산에서 광석을 캐려고 합니다. 마인은 다이아몬드 곡괭이, 철 곡괭이, 돌 곡괭이를 각각 0개에서 5개까지 가지고 있으며, 곡괭이로 광물을 캘 때는 피로도가 소모됩니다.
각 곡괭이로 광물을 캘 때의 피로도는 아래 표와 같습니다.

      광물   |   다이아몬드   |    철   |    돌
곡갱이       |                |         |            
--------------------------------------------------
다이아몬드   |       1        |    1    |    1
--------------------------------------------------
    철       |       5        |    1    |    1
--------------------------------------------------
    돌       |       25       |    5    |    1

예를 들어, 철 곡괭이는 다이아몬드를 캘 때 피로도 5가 소모되며, 철과 돌을 캘때는 피로도가 1씩 소모됩니다. 각 곡괭이는 종류에 상관없이 광물 5개를 캔 후에는 더 이상 사용할 수 없습니다.

마인은 다음과 같은 규칙을 지키면서 최소한의 피로도로 광물을 캐려고 합니다.

사용할 수 있는 곡괭이중 아무거나 하나를 선택해 광물을 캡니다.
한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용합니다.
광물은 주어진 순서대로만 캘 수 있습니다.
광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캡니다.
즉, 곡괭이를 하나 선택해서 광물 5개를 연속으로 캐고, 다음 곡괭이를 선택해서 광물 5개를 연속으로 캐는 과정을 반복하며, 더 사용할 곡괭이가 없거나 광산에 있는 모든 광물을 캘 때까지 과정을 반복하면 됩니다.

마인이 갖고 있는 곡괭이의 개수를 나타내는 정수 배열 picks와 광물들의 순서를 나타내는 문자열 배열 minerals가 매개변수로 주어질 때, 마인이 작업을 끝내기까지 필요한 최소한의 피로도를 return 하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool Compare(const std::vector<int>& _Left, const std::vector<int>& _Right)
{
    if (_Left[1] == _Right[1] && _Left[0] == _Right[0])
    {
        return _Left[2] > _Right[2];
    }

    if (_Left[0] == _Right[0])
    {
        return _Left[1] > _Right[1];
    }

    return _Left[0] > _Right[0];
}

int solution(std::vector<int> picks, std::vector<std::string> minerals)
{
    int answer = 0;

    int DiaPick = picks[0];
    int IronPick = picks[1];
    int StonePick = picks[2];

    // 가지고 있는 곡갱이로 캘 수 있는 갯수
    int PossibleCount = (DiaPick + IronPick + StonePick) * 5;

    // 광물 갯수
    const size_t MineralCount = minerals.size();

    // 캘 수 있는 실제 갯수
    const size_t DigCount = MineralCount > PossibleCount ? PossibleCount : MineralCount;

    // 한 곡갱이로 캐야 하는 광물 종류 별 갯수
    std::vector<std::vector<int>> CountToType;
    CountToType.reserve(DigCount / 5);

    // (다이아 갯수, 철 갯수, 돌 갯수)
    std::vector<int> PushVector(3);

    // CountToType 구해서 Push
    for (size_t i = 0; i < DigCount; i++)
    {
        if (minerals[i] == "diamond")
        {
            ++PushVector[0];
        }
        else if (minerals[i] == "iron")
        {
            ++PushVector[1];
        }
        else
        {
            ++PushVector[2];
        }


        if (i % 5 == 4 || i == DigCount - 1)
        {
            CountToType.push_back(PushVector);
            PushVector[0] = 0;
            PushVector[1] = 0;
            PushVector[2] = 0;
        }
    }

    // 배열의 원소 갯수가 큰 순서대로 정렬
    sort(CountToType.begin(), CountToType.end(), Compare);

    for (const std::vector<int>& CurMinerals : CountToType)
    {
        // 가지고 있는 곡갱이를 대상으로 피로도 계산 후 answer +
        if (DiaPick > 0)
        {
            int Fatigue = CurMinerals[0] + CurMinerals[1] + CurMinerals[2];
            answer += Fatigue;

            --DiaPick;
            continue;
        }

        if (IronPick > 0)
        {
            int Fatigue = (CurMinerals[0] * 5) + CurMinerals[1] + CurMinerals[2];
            answer += Fatigue;

            --IronPick;
            continue;
        }

        if (StonePick > 0)
        {
            int Fatigue = (CurMinerals[0] * 25) + (CurMinerals[1] * 5) + CurMinerals[2];
            answer += Fatigue;

            --StonePick;
            continue;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ 1, 3, 2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" }) << std::endl;
    std::cout << solution({ 0, 1, 1 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" }) << std::endl;
    std::cout << solution({ 1, 1, 0 }, { "iron", "iron", "diamond", "iron", "stone", "diamond", "diamond", "diamond" }) << std::endl;
    std::cout << solution({ 1, 1, 0 }, { "iron", "iron", "iron", "iron", "iron", "diamond"}) << std::endl;
    std::cout << solution({ 1, 1, 0 }, { "stone", "stone", "iron", "stone", "diamond", "diamond", "diamond", "diamond", "diamond", "diamond" }) << std::endl;
}