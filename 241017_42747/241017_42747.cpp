// 241017_42747.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// H-Index

/*
문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> citations)
{
    const size_t CitationCount = citations.size();
    const size_t HalfIndex = CitationCount % 2 == 0 ? CitationCount / 2 - 1 : CitationCount / 2;
    sort(citations.begin(), citations.end());

    int ConditionValue = citations[HalfIndex];
    int RightCount = RightCount = std::count_if(citations.begin(), citations.end(),
        [=](int _Element)
        {
            return _Element >= ConditionValue;
        }
    );
    int LeftCount = CitationCount - RightCount;
    
    while (1)
    {
        if (ConditionValue >= LeftCount && ConditionValue <= RightCount)
        {
            return ConditionValue;
        }

        if (RightCount > ConditionValue)
        {
            ++ConditionValue;

            RightCount = std::count_if(citations.begin(), citations.end(),
                [=](int _Element)
                {
                    return _Element >= ConditionValue;
                }
            );
            LeftCount = CitationCount - RightCount;
        }
        else if (LeftCount < ConditionValue)
        {
            --ConditionValue;

            RightCount = std::count_if(citations.begin(), citations.end(),
                [=](int _Element)
                {
                    return _Element >= ConditionValue;
                }
            );
            LeftCount = CitationCount - RightCount;
        }
    }
}

int main()
{
    std::cout << solution({ 2, 0, 6, 1, 5 }) << std::endl;
    std::cout << solution({ 3, 0, 6, 2, 1, 5 }) << std::endl;
}
