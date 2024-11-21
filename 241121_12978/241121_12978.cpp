// 241121_12978.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 배달

/*
문제설명
N개의 마을로 이루어진 나라가 있습니다. 이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있습니다.
각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데, 서로 다른 마을 간에 이동할 때는 이 도로를 지나야 합니다.
도로를 지날 때 걸리는 시간은 도로별로 다릅니다. 현재 1번 마을에 있는 음식점에서 각 마을로 음식 배달을 하려고 합니다.
각 마을로부터 음식 주문을 받으려고 하는데, N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다.

마을의 개수 N, 각 마을을 연결하는 도로의 정보 road, 음식 배달이 가능한 시간 K가 매개변수로 주어질 때,
음식 주문을 받을 수 있는 마을의 개수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <queue>

int solution(int N, std::vector<std::vector<int>> road, int K)
{
    int answer = 0;

    std::vector<bool> IsVisited(N + 1, false);
    std::vector<int> Distance(N + 1, 0);

    std::queue<int> Node;
    Node.push(1);
    IsVisited[1] = true;

    while (false == Node.empty())
    {
        int Begin = Node.front();
        Node.pop();

        for (const std::vector<int>& CurRoad : road)
        {
            int RoadStart = CurRoad[0];
            int RoadEnd = CurRoad[1];
            int RoadDistance = CurRoad[2];

            if (RoadStart == Begin)
            {
                if (false == IsVisited[RoadEnd])
                {
                    Node.push(RoadEnd);
                    Distance[RoadEnd] = RoadDistance + Distance[Begin];
                    IsVisited[RoadEnd] = true;
                }
                else
                {
                    int NewDistance = RoadDistance + Distance[Begin];

                    if (NewDistance < Distance[RoadEnd])
                    {
                        Node.push(RoadEnd);
                        Distance[RoadEnd] = NewDistance;
                    }
                }
            }

            if (RoadEnd == Begin)
            {
                if (false == IsVisited[RoadStart])
                {
                    Node.push(RoadStart);
                    Distance[RoadStart] = RoadDistance + Distance[Begin];
                    IsVisited[RoadStart] = true;
                }
                else
                {
                    int NewDistance = RoadDistance + Distance[Begin];

                    if (NewDistance < Distance[RoadStart])
                    {
                        Node.push(RoadStart);
                        Distance[RoadStart] = NewDistance;
                    }
                }
            }
        }
    }

    for (int i = 1; i < N + 1; ++i)
    {
        if (Distance[i] <= K)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3) << std::endl;              // 4
    std::cout << solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4) << std::endl;      // 4
}
