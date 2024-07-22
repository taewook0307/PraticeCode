// 240722_1845.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 폰켓몬

/*
문제 설명
당신은 폰켓몬을 잡기 위한 오랜 여행 끝에, 홍 박사님의 연구실에 도착했습니다.
홍 박사님은 당신에게 자신의 연구실에 있는 총 N 마리의 폰켓몬 중에서 N/2마리를 가져가도 좋다고 했습니다.

당신은 최대한 다양한 종류의 폰켓몬을 가지길 원하기 때문에, 최대한 많은 종류의 폰켓몬을 포함해서 N/2마리를 선택하려 합니다.
N마리 폰켓몬의 종류 번호가 담긴 배열 nums가 매개변수로 주어질 때,
N/2마리의 폰켓몬을 선택하는 방법 중,
가장 많은 종류의 폰켓몬을 선택하는 방법을 찾아,
그때의 폰켓몬 종류 번호의 개수를 return 하도록 solution 함수를 완성해주세요
*/

#include <iostream>
#include <vector>
#include <set>

int solution(std::vector<int> nums)
{
    int answer = 0;

    int GetCount = nums.size() / 2;

    std::set<int> MonsterType;

    for (int CurNum : nums)
    {
        MonsterType.insert(CurNum);
    }

    int MonsterTypeCount = static_cast<int>(MonsterType.size());

    answer = MonsterTypeCount < GetCount ? MonsterTypeCount : GetCount;

    return answer;
}

void PrintResult(std::vector<int> nums)
{
    int Result = solution(nums);
    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> nums0 = { 3,1,2,3 };
    PrintResult(nums0);
}
