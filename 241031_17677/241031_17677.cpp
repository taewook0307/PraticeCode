// 241031_17677.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [1차] 뉴스 클러스터링

/*
문제 설명
여러 언론사에서 쏟아지는 뉴스, 특히 속보성 뉴스를 보면 비슷비슷한 제목의 기사가 많아 정작 필요한 기사를 찾기가 어렵다.
Daum 뉴스의 개발 업무를 맡게 된 신입사원 튜브는 사용자들이 편리하게 다양한 뉴스를 찾아볼 수 있도록 문제점을 개선하는 업무를 맡게 되었다.

개발의 방향을 잡기 위해 튜브는 우선 최근 화제가 되고 있는 "카카오 신입 개발자 공채" 관련 기사를 검색해보았다.

카카오 첫 공채..'블라인드' 방식 채용
카카오, 합병 후 첫 공채.. 블라인드 전형으로 개발자 채용
카카오, 블라인드 전형으로 신입 개발자 공채
카카오 공채, 신입 개발자 코딩 능력만 본다
카카오, 신입 공채.. "코딩 실력만 본다"
카카오 "코딩 능력만으로 2018 신입 개발자 뽑는다"

기사의 제목을 기준으로 "블라인드 전형"에 주목하는 기사와 "코딩 테스트"에 주목하는 기사로 나뉘는 걸 발견했다.
튜브는 이들을 각각 묶어서 보여주면 카카오 공채 관련 기사를 찾아보는 사용자에게 유용할 듯싶었다.

유사한 기사를 묶는 기준을 정하기 위해서 논문과 자료를 조사하던 튜브는 "자카드 유사도"라는 방법을 찾아냈다.

자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나로 알려져 있다.
두 집합 A, B 사이의 자카드 유사도 J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.

예를 들어 집합 A = {1, 2, 3}, 집합 B = {2, 3, 4}라고 할 때, 교집합 A ∩ B = {2, 3}, 합집합 A ∪ B = {1, 2, 3, 4}이 되므로,
집합 A, B 사이의 자카드 유사도 J(A, B) = 2/4 = 0.5가 된다. 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int solution(std::string str1, std::string str2)
{
    int answer = 65536;

    const size_t Str1Size = str1.size();
    const size_t Str2Size = str2.size();

    if (Str1Size == 0 && Str2Size == 0)
    {
        return answer;
    }

    std::unordered_map<std::string, int> Str1Combi;
    std::unordered_map<std::string, int> Str2Combi;

    std::unordered_set<std::string> Intersection;
    std::unordered_set<std::string> Union;

    for (size_t i = 0; i < Str1Size - 1; ++i)
    {
        std::string CutString = str1.substr(i, 2);

        if (false == isalpha(CutString[0]) || false == isalpha(CutString[1]))
        {
            continue;
        }

        int Check = islower(CutString[0]);

        CutString[0] = std::tolower(CutString[0]);
        CutString[1] = std::tolower(CutString[1]);

        ++Str1Combi[CutString];
        Union.insert(CutString);
    }
    for (size_t i = 0; i < Str2Size - 1; ++i)
    {
        std::string CutString = str2.substr(i, 2);

        if (false == isalpha(CutString[0]) || false == isalpha(CutString[1]))
        {
            continue;
        }

        CutString[0] = std::tolower(CutString[0]);
        CutString[1] = std::tolower(CutString[1]);

        ++Str2Combi[CutString];
        Union.insert(CutString);

        if (Str1Combi.find(CutString) != Str1Combi.end())
        {
            Intersection.insert(CutString);
        }
    }

    int IntersectonCount = Intersection.size();
    int UnionCount = Union.size();

    if (IntersectonCount == 0 && UnionCount == 0)
    {
        IntersectonCount = 1;
        UnionCount = 1;
    }
    else
    {
        for (const std::string& IntersectionValue : Intersection)
        {
            if (Str1Combi.find(IntersectionValue) != Str1Combi.end()
                && Str2Combi.find(IntersectionValue) != Str2Combi.end())
            {
                int Value = std::min(Str1Combi[IntersectionValue], Str2Combi[IntersectionValue]);
                IntersectonCount += (Value - 1);
            }
        }

        for (const std::string& UnionValue : Union)
        {
            int Value = std::max(Str1Combi[UnionValue], Str2Combi[UnionValue]);
            UnionCount += (Value - 1);
        }
    }

    answer *= IntersectonCount;

    answer /= UnionCount;

    return answer;
}

int main()
{
    std::cout << solution("aaabbcccccccc", "aaaabbcccc") << std::endl;      // 40329
    std::cout << solution("AAbbaa_AAbb", "BBB") << std::endl;      // 16384
}
