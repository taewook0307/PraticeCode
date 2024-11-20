// 241120_86971.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 전력망을 둘로 나누기

/*
문제설명
n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다.
당신은 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다.
이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.

송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어집니다.
전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때,
두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int solution(int n, std::vector<std::vector<int>> wires)
{
    int answer = INT_MAX;

    std::sort(wires.begin(), wires.end());

    const size_t Count = wires.size();
    size_t RemoveIndex = 0;

    while (RemoveIndex != Count)
    {
        std::vector<std::vector<int>> CheckWires;
        CheckWires.reserve(Count - 1);

        for (int i = 0; i < Count; ++i)
        {
            if (i == RemoveIndex)
            {
                continue;
            }

            CheckWires.push_back(wires[i]);
        }

        std::vector<bool> IsVisit(n + 1, false);
        std::queue<int> Node;

        IsVisit[CheckWires[0][0]] = true;
        Node.push(CheckWires[0][0]);

        while (false == Node.empty())
        {
            int Begin = Node.front();
            Node.pop();

            for (const std::vector<int>& CurNode : CheckWires)
            {
                int CurNodeBegin = CurNode[0];
                int CurNodeEnd = CurNode[1];

                if (CurNodeBegin > Begin)
                {
                    break;
                }

                if (CurNodeBegin == Begin && false == IsVisit[CurNodeEnd])
                {
                    Node.push(CurNodeEnd);
                    IsVisit[CurNodeEnd] = true;
                }

                if (CurNodeEnd == Begin && false == IsVisit[CurNodeBegin])
                {
                    Node.push(CurNodeBegin);
                    IsVisit[CurNodeBegin] = true;
                }
            }
        }

        int NetOneCount = 0;
        int NetTwoCount = 0;

        for (int i = 1; i < n + 1; ++i)
        {
            if (IsVisit[i] == true)
            {
                ++NetOneCount;
            }
            else
            {
                ++NetTwoCount;
            }
        }

        int Difference = abs(NetOneCount - NetTwoCount);

        answer = std::min(Difference, answer);

        ++RemoveIndex;
    }

    return answer;
}

int main()
{
    std::cout << solution(9, { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} }) << std::endl;
    std::cout << solution(4, { {1,2},{2,3},{3,4} }) << std::endl;
    std::cout << solution(7, { {1,2},{2,7},{3,7},{3,4},{4,5},{6,7} }) << std::endl;
}