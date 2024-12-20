﻿// 241126_12910.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 나누어 떨어지는 숫자 배열

/*
문제설명
array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> arr, int divisor)
{
    std::vector<int> answer;
    answer.reserve(arr.size());

    for (int Num : arr)
    {
        if (Num % divisor == 0)
        {
            answer.push_back(Num);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        std::sort(answer.begin(), answer.end());
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
