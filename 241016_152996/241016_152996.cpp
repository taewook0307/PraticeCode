// 241016_152996.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 시소 짝꿍

/*
문제 설명
어느 공원 놀이터에는 시소가 하나 설치되어 있습니다. 이 시소는 중심으로부터 2(m), 3(m), 4(m) 거리의 지점에 좌석이 하나씩 있습니다.
이 시소를 두 명이 마주 보고 탄다고 할 때, 시소가 평형인 상태에서 각각에 의해 시소에 걸리는 토크의 크기가 서로 상쇄되어 완전한 균형을 이룰 수 있다면 그 두 사람을 시소 짝꿍이라고 합니다.
즉, 탑승한 사람의 무게와 시소 축과 좌석 간의 거리의 곱이 양쪽 다 같다면 시소 짝꿍이라고 할 수 있습니다.
사람들의 몸무게 목록 weights이 주어질 때, 시소 짝꿍이 몇 쌍 존재하는지 구하여 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

//long long solution(std::vector<int> weights)
//{
//    long long answer = 0;
//
//    sort(weights.begin(), weights.end());
//
//    const size_t People = weights.size();
//
//    for (size_t i = 0; i < People; ++i)
//    {
//        for (size_t j = i + 1; j < People; ++j)
//        {
//            if (weights[i] == weights[j])
//            {
//                ++answer;
//                continue;
//            }
//
//            int HeavyPerson = weights[i] < weights[j] ? weights[j] : weights[i];
//            int LightPerson = weights[i] < weights[j] ? weights[i] : weights[j];
//
//            if (HeavyPerson * 2 == LightPerson * 3
//                || HeavyPerson * 2 == LightPerson * 4
//                || HeavyPerson * 3 == LightPerson * 4)
//            {
//                ++answer;
//            }
//        }
//    }
//
//    return answer;
//}

long long solution(std::vector<int> weights)
{
    long long answer = 0;

    std::vector<long long> arr(2001, 0);

    // 몸무게 갯수 구하기
    for (const auto v : weights)
    {
        arr[v]++;
    }

    // 100부터 1000까지 확인
    for (int i = 100; i <= 1000; ++i)
    {
        // 갯수가 0 이면 Continue
        if (arr[i] == 0)
        {
            continue;
        }

        // 서로 같은 쌍의 갯수 더하기
        answer += arr[i] * (arr[i] - 1) / 2;

        // 1 : 2 비율의 갯수 더하기
        answer += arr[i] * arr[2 * i];

        // 2 : 3 비율의 갯수 더하기
        if ((i * 3) % 2 == 0)
        {
            answer += arr[i] * arr[i * 3 / 2];
        }

        // 3 : 4 비율의 갯수 더하기
        if ((i * 4) % 3 == 0)
        {
            answer += arr[i] * arr[i * 4 / 3];
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ 100,180,360,100,270 }) << std::endl;
}
