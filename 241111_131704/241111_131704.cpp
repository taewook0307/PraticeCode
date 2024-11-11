// 241111_131704.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 택배상자

/*
문제설명
영재가 5개의 상자를 실어야 하며, 택배 기사님이 알려준 순서가 기존의 컨테이너 벨트에 네 번째, 세 번째, 첫 번째, 두 번째, 다섯 번째 놓인 택배상자 순서인 경우,
영재는 우선 첫 번째, 두 번째, 세 번째 상자를 보조 컨테이너 벨트에 보관합니다.
그 후 네 번째 상자를 트럭에 싣고 보조 컨테이너 벨트에서 세 번째 상자 빼서 트럭에싣습니다.
다음으로 첫 번째 상자를 실어야 하지만 보조 컨테이너 벨트에서는 두 번째 상자를, 기존의 컨테이너 벨트에는 다섯 번째 상자를 꺼낼 수 있기 때문에 더이상의 상자는 실을 수 없습니다.
따라서 트럭에는 2개의 상자만 실리게 됩니다.

택배 기사님이 원하는 상자 순서를 나타내는 정수 배열 order가 주어졌을 때, 영재가 몇 개의 상자를 실을 수 있는지 return 하는 solution 함수를 완성하세요.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

int solution(std::vector<int> order)
{
    int answer = 0;

    std::stack<int> SubContainer;

    int StartOrder = 1;

    for (int OrderNum : order)
    {
        while (StartOrder < OrderNum)
        {
            SubContainer.push(StartOrder);
            ++StartOrder;
        }

        if (StartOrder > OrderNum && false == SubContainer.empty() && OrderNum != SubContainer.top())
        {
            break;
        }

        if (StartOrder == OrderNum)
        {
            ++answer;
            ++StartOrder;
        }

        if (false == SubContainer.empty() && OrderNum == SubContainer.top())
        {
            SubContainer.pop();
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ 4, 3, 1, 2, 5 }) << std::endl;
    std::cout << solution({ 5, 4, 3, 2, 1 }) << std::endl;
}
