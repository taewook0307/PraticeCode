// 241004_42885.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 구명보트

/*
문제 설명
무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다.
구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만
1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때,
모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());

    size_t StartIndex = 0;
    size_t LastIndex = people.size() - 1;

    while (StartIndex <= LastIndex)
    {
        // 다른 이들은 다 보트에 타고 1명만 남은 경우
        if (StartIndex == LastIndex)
        {
            ++answer;
            break;
        }

        // 남은 사람 중 가장 가벼운 사람의 Index
        int Little = people[StartIndex];
        // 남은 사람 중 가장 무거운 사람의 Index
        int Max = people[LastIndex];

        // 가장 가벼운 이와 가장 무거운 이가 같이 탈 수 있는 경우
        if (Max + Little <= limit)
        {
            ++answer;
            ++StartIndex;
            --LastIndex;
        }
        // 같이 못 탈 경우
        else
        {
            ++answer;
            --LastIndex;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ 70, 50, 80, 50 }, 100) << std::endl;
    std::cout << solution({ 70, 80, 50 }, 100) << std::endl;
}
