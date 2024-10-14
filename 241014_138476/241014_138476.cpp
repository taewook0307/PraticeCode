// 241014_138476.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 귤 고르기

/*
문제 설명
경화는 과수원에서 귤을 수확했습니다. 경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매하려고 합니다.
그런데 수확한 귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화하고 싶습니다.

예를 들어, 경화가 수확한 귤 8개의 크기가 [1, 3, 2, 5, 4, 5, 2, 3] 이라고 합시다.
경화가 귤 6개를 판매하고 싶다면, 크기가 1, 4인 귤을 제외한 여섯 개의 귤을 상자에 담으면, 귤의 크기의 종류가 2, 3, 5로 총 3가지가 되며 이때가 서로 다른 종류가 최소일 때입니다.

경화가 한 상자에 담으려는 귤의 개수 k와 귤의 크기를 담은 배열 tangerine이 매개변수로 주어집니다.
경화가 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

bool Compare(const std::pair<int, int>& _Left, const std::pair<int, int>& _Right)
{
    if (_Left.second == _Right.second)
    {
        return _Left.first < _Right.first;
    }

    return _Left.second > _Right.second;
}

int solution(int k, std::vector<int> tangerine)
{
    int answer = 0;

    // 크기 별로 가지수를 map에 저장
    std::map<int, int> CountToSize;

    for (int CurSize : tangerine)
    {
        if (CountToSize.find(CurSize) != CountToSize.end())
        {
            ++CountToSize[CurSize];
        }
        else
        {
            CountToSize.insert(std::make_pair(CurSize, 1));
        }
    }

    // 가짓 수가 많은 순서대로 정렬시키기 위해 vector 이용
    std::vector<std::pair<int, int>> CountToSizeVector;
    CountToSizeVector.reserve(CountToSize.size());

    for (const std::pair<int, int>& CurPair : CountToSize)
    {
        CountToSizeVector.push_back(CurPair);
    }

    sort(CountToSizeVector.begin(), CountToSizeVector.end(), Compare);

    // 가짓수가 많은 것부터 담는 갯수 추가
    int Count = 0;

    for (const std::pair<int, int>& CurSize : CountToSizeVector)
    {
        if (k <= Count)
        {
            break;
        }

        Count += CurSize.second;
        ++answer;
    }

    return answer;
}

int main()
{
    std::cout << solution(6, { 1, 3, 2, 5, 4, 5, 2, 3 }) << std::endl;
    std::cout << solution(4, { 1, 3, 2, 5, 4, 5, 2, 3 }) << std::endl;
    std::cout << solution(2, { 1, 1, 1, 1, 2, 2, 2, 3 }) << std::endl;
    std::cout << solution(5, {1, 1, 2, 2, 3, 3}) << std::endl;
}
