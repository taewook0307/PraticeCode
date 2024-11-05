// 241105_154539.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 뒤에 있는 큰 수 찾기

/*
문제 설명
정수로 이루어진 배열 numbers가 있습니다.
배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.
정수 배열 numbers가 매개변수로 주어질 때, 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요.
단, 뒷 큰수가 존재하지 않는 원소는 -1을 담습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::vector<int> solution(std::vector<int> numbers)
{
    const size_t NumberCount = numbers.size();
    std::vector<int> answer(NumberCount, -1);
    std::stack<int, std::vector<int>> stack;

    for (int i = 0; i < NumberCount; ++i)
    {
        while (false == stack.empty())
        {
            if (numbers[stack.top()] >= numbers[i])
            {
                break;
            }
            else
            {
                answer[stack.top()] = numbers[i];
                stack.pop();
            }
        }
        stack.push(i);
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution({ 2, 3, 3, 5 });
    std::vector<int> Result0 = solution({ 9, 1, 5, 3, 6, 2 });

    int a = 0;
}
