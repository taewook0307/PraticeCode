// 241023_Mini_Max_Sum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
5개의 양의 정수가 주어졌을 때, 4개를 더하여 구할 수 있는 최솟값 최댓값을 구하시오
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void miniMaxSum(std::vector<int> arr)
{
    size_t MaxValue = *std::max_element(arr.begin(), arr.end());
    size_t MinValue = *std::min_element(arr.begin(), arr.end());

    //size_t Sum = accumulate(arr.begin(), arr.end(), 0);
    size_t Sum = 0;

    for (int Num : arr)
    {
        Sum += static_cast<size_t>(Num);
    }

    size_t MinSum = Sum - MaxValue;
    size_t MaxSum = Sum - MinValue;

    std::cout << MinSum << " " << MaxSum;
}

int main()
{
    std::vector<int> arr = { 256741038, 623958417, 467905213, 714532089, 938071625 };
    miniMaxSum(arr);

    return 0;
}
