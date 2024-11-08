// 241108_42584.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 주식가격

/*
문제설명
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
*/

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> solution(std::vector<int> prices)
{
    size_t PriceCount = prices.size();
    std::vector<int> answer(PriceCount, 0);

    std::stack<int> Time;
    Time.push(0);

    for (size_t i = 0; i < PriceCount; ++i)
    {
        while (false == Time.empty() && prices[Time.top()] > prices[i])
        {
            int Index = Time.top();
            Time.pop();
            answer[Index] = i - Index;
        }

        Time.push(i);
    }

    while (false == Time.empty())
    {
        int Index = Time.top();
        Time.pop();

        answer[Index] = PriceCount - 1 - Index;
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution({ 1, 2, 3, 2, 3 });

    int a = 0;
}
