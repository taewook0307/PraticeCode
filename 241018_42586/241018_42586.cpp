// 241018_42586.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 기능개발

/*
문제 설명
프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.

또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때
각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

//std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds)
//{
//    std::vector<int> answer;
//    answer.reserve(progresses.size());
//
//    const size_t ProgressCount = progresses.size();
//
//    std::queue<int> DistributionDay;
//
//    for (size_t i = 0; i < ProgressCount; ++i)
//    {
//        DistributionDay.push(std::ceil((100 - progresses[i]) / static_cast<float>(speeds[i])));
//    }
//
//    int Count = 1;
//    int Condition = DistributionDay.front();
//    DistributionDay.pop();
//
//    while(1)
//    {
//        if(DistributionDay.empty() == true)
//        {
//            if (Count != 0)
//            {
//                answer.push_back(Count);
//            }
//            break;
//        }
//
//        int CurValue = DistributionDay.front();
//        DistributionDay.pop();
//
//        if (CurValue <= Condition)
//        {
//            ++Count;
//        }
//        else
//        {
//            answer.push_back(Count);
//            Count = 1;
//            Condition = CurValue;
//        }
//    }
//
//    return answer;
//}

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;
    answer.reserve(progresses.size());

    const size_t ProgressCount = progresses.size();

    answer.push_back(1);
    int Max_Day = std::ceil((100 - progresses[0]) / static_cast<float>(speeds[0]));

    for (size_t i = 1; i < ProgressCount; ++i)
    {
        int Cur_Day = std::ceil((100 - progresses[i]) / static_cast<float>(speeds[i]));

        if (Cur_Day <= Max_Day)
        {
            ++answer.back();
        }
        else
        {
            Max_Day = Cur_Day;
            answer.push_back(1);
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result0 = solution({ 93, 30, 55 }, { 1, 30, 5 });
    std::vector<int> Result1 = solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });
}
