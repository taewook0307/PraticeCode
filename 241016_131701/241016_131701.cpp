// 241016_131701.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 연속 부분 수열 합의 개수

/*
문제 설명
철호는 수열을 가지고 놀기 좋아합니다. 어느 날 철호는 어떤 자연수로 이루어진 원형 수열의 연속하는 부분 수열의 합으로 만들 수 있는 수가 모두 몇 가지인지 알아보고 싶어졌습니다.
원형 수열이란 일반적인 수열에서 처음과 끝이 연결된 형태의 수열을 말합니다.
원형 수열은 처음과 끝이 연결되어 끊기는 부분이 없기 때문에 연속하는 부분 수열도 일반적인 수열보다 많아집니다.
원형 수열의 모든 원소 elements가 순서대로 주어질 때, 원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <set>

int solution(std::vector<int> elements)
{
    int answer = 0;

    std::vector<int> IncreaseVector;
    IncreaseVector.reserve(elements.size() * 2);
    
    for (int i = 0; i < 2; ++i)
    {
        for (int CurElement : elements)
        {
            IncreaseVector.emplace_back(CurElement);
        }
    }

    std::set<int> AllCombi;

    const size_t ElementCount = elements.size();

    for (size_t i = 0; i < ElementCount; ++i)
    {
        std::vector<int> Combination(ElementCount, elements[i]);

        int Index = 1;

        for (size_t j = i + 1; j < ElementCount + i; ++j)
        {
            for (size_t k = Index; k < ElementCount; ++k)
            {
                Combination[k] += IncreaseVector[j];
            }

            ++Index;
        }
        
        for (int CombiSum : Combination)
        {
            AllCombi.insert(CombiSum);
        }
    }

    answer = AllCombi.size();

    return answer;
}

int main()
{
    std::cout << solution({ 7,9,1,1,4 }) << std::endl;
}