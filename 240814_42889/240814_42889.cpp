// 240814_42889.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 실패율

/*
문제 설명
슈퍼 게임 개발자 오렐리는 큰 고민에 빠졌다.
그녀가 만든 프랜즈 오천성이 대성공을 거뒀지만, 요즘 신규 사용자의 수가 급감한 것이다.
원인은 신규 사용자와 기존 사용자 사이에 스테이지 차이가 너무 큰 것이 문제였다.

이 문제를 어떻게 할까 고민 한 그녀는 동적으로 게임 시간을 늘려서 난이도를 조절하기로 했다.
역시 슈퍼 개발자라 대부분의 로직은 쉽게 구현했지만, 실패율을 구하는 부분에서 위기에 빠지고 말았다.
오렐리를 위해 실패율을 구하는 코드를 완성하라.

실패율은 다음과 같이 정의한다.

    스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

전체 스테이지의 개수 N,
게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때,
실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
//#include <map>

bool Compare(const std::pair<float, int>& _LeftPair, const std::pair<float, int>& _RightPair)
{
    if (_LeftPair.first == _RightPair.first)
    {
        return _LeftPair.second < _RightPair.second;
    }

    return _LeftPair.first > _RightPair.first;
}

std::vector<int> solution(int N, std::vector<int> stages) {
    std::vector<int> answer;
    answer.reserve(N);

    // 실패횟수
    std::vector<int> FailureCount(N);

    for (int StopStage : stages)
    {
        if (N < StopStage)
        {
            continue;
        }

        ++FailureCount[StopStage - 1];
    }

    int UserCount = stages.size();
    //// 실패율과 스테이지 번호 저장용 multimap
    //std::multimap<float, int, std::greater<>> FailureRate;

    //for (int i = 0; i < N; ++i)
    //{
    //    if (UserCount < 0)
    //    {
    //        break;
    //    }

    //    // 실패율
    //    float Failure = static_cast<float>(FailureCount[i]) / static_cast<float>(UserCount);
    //    // 계산된 실패율과 stage 번호 insert
    //    FailureRate.insert(std::make_pair(Failure, i + 1));
    //    // 전체 유저 수에서 실패한 인원수 빼기
    //    UserCount -= FailureCount[i];
    //}

    std::vector<std::pair<float, int>> FailureRate;
    FailureRate.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        if (UserCount < 0)
        {
            break;
        }

        if (UserCount == 0)
        {
            FailureRate.push_back(std::make_pair(0.0f, i + 1));
            continue;
        }

        // 실패율
        float Failure = static_cast<float>(FailureCount[i]) / static_cast<float>(UserCount);

        // 계산된 실패율과 stage 번호 push
        FailureRate.push_back(std::make_pair(Failure, i + 1));

        // 전체 유저 수에서 실패한 인원수 빼기
        UserCount -= FailureCount[i];
    }

    sort(FailureRate.begin(), FailureRate.end(), Compare);

    for (std::pair<float, int> CurIter : FailureRate)
    {
        answer.push_back(CurIter.second);
    }

    return answer;
}

void PrintResult(int N, std::vector<int> stages)
{
    std::vector<int> Result = solution(N, stages);

    int i = 0;
    for (int Num : Result)
    {
        std::cout << Num << " ";
    }
    std::cout << std::endl << "---------------------------------------------" << std::endl;
}

int main()
{
    std::vector<int> stages0 = { 2, 1, 2, 6, 2, 4, 3, 3 };
    PrintResult(5, stages0);

    std::vector<int> stages1 = { 4,4,4,4,4 };
    PrintResult(4, stages1);
}
