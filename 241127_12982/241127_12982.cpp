// 241127_12982.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 예산

/*
문제설명
S사에서는 각 부서에 필요한 물품을 지원해 주기 위해 부서별로 물품을 구매하는데 필요한 금액을 조사했습니다.
그러나, 전체 예산이 정해져 있기 때문에 모든 부서의 물품을 구매해 줄 수는 없습니다.
그래서 최대한 많은 부서의 물품을 구매해 줄 수 있도록 하려고 합니다.

물품을 구매해 줄 때는 각 부서가 신청한 금액만큼을 모두 지원해 줘야 합니다.
예를 들어 1,000원을 신청한 부서에는 정확히 1,000원을 지원해야 하며, 1,000원보다 적은 금액을 지원해 줄 수는 없습니다.

부서별로 신청한 금액이 들어있는 배열 d와 예산 budget이 매개변수로 주어질 때, 최대 몇 개의 부서에 물품을 지원할 수 있는지 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> d, int budget)
{
    int answer = 0;

    const size_t DepartmentCount = d.size();

    std::sort(d.begin(), d.end());

    int Fee = 0;

    for (int i = 0; i < DepartmentCount; ++i)
    {
        Fee += d[i];

        if (Fee <= budget)
        {
            ++answer;
        }
        else
        {
            break;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ 1,3,2,5,4 }, 9) << std::endl;
}
