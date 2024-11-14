﻿// 241114_42583.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 다리를 지나는 트럭

/*
문제설명
트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순으로 건너려 합니다.
모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다.
다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며, 다리는 weight 이하까지의 무게를 견딜 수 있습니다.
단, 다리에 완전히 오르지 않은 트럭의 무게는 무시합니다.

예를 들어, 트럭 2대가 올라갈 수 있고 무게를 10kg까지 견디는 다리가 있습니다. 무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건너야 합니다.

경과 시간	다리를 지난 트럭	다리를 건너는 트럭	대기 트럭
0           []	                []	                [7,4,5,6]
1~2	        []	                [7]	                [4,5,6]
3	        [7]	                [4]	                [5,6]
4	        [7]	                [4,5]	            [6]
5	        [7,4]	            [5]	                [6]
6~7	        [7,4,5]	            [6]	                []
8	        [7,4,5,6]	        []	                []

따라서, 모든 트럭이 다리를 지나려면 최소 8초가 걸립니다.

solution 함수의 매개변수로 다리에 올라갈 수 있는 트럭 수 bridge_length, 다리가 견딜 수 있는 무게 weight, 트럭 별 무게 truck_weights가 주어집니다.
이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

int solution(int bridge_length, int weight, std::vector<int> truck_weights)
{
    int Time = 1;

    size_t TruckCount = truck_weights.size();

    std::queue<std::pair<int, int>> Bridge;

    Bridge.push(std::make_pair(truck_weights[0], 1));

    size_t CrossCount = 0;
    size_t TruckIndex = 1;

    int OnBridgeWeight = truck_weights[0];

    while (CrossCount < TruckCount)
    {
        ++Time;

        if (false == Bridge.empty() && bridge_length == (Time - Bridge.front().second))
        {
            ++CrossCount;
            OnBridgeWeight -= Bridge.front().first;
            Bridge.pop();
        }

        if (TruckIndex != TruckCount)
        {
            if (weight >= OnBridgeWeight + truck_weights[TruckIndex])
            {
                Bridge.push(std::make_pair(truck_weights[TruckIndex], Time));
                OnBridgeWeight += truck_weights[TruckIndex];
                ++TruckIndex;
            }
        }
    }

    return Time;
}

int main()
{
    std::cout << solution(2, 10, { 7,4,5,6 }) << std::endl;
}
