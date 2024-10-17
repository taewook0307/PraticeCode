// 241017_131127.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 할인 행사

/*
문제 설명
XYZ 마트는 일정한 금액을 지불하면 10일 동안 회원 자격을 부여합니다. XYZ 마트에서는 회원을 대상으로 매일 한 가지 제품을 할인하는 행사를 합니다.
할인하는 제품은 하루에 하나씩만 구매할 수 있습니다. 알뜰한 정현이는 자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치할 경우에 맞춰서 회원가입을 하려 합니다.

예를 들어, 정현이가 원하는 제품이 바나나 3개, 사과 2개, 쌀 2개, 돼지고기 2개, 냄비 1개이며,
XYZ 마트에서 14일간 회원을 대상으로 할인하는 제품이 날짜 순서대로 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나인 경우에 대해 알아봅시다.
첫째 날부터 열흘 간에는 냄비가 할인하지 않기 때문에 첫째 날에는 회원가입을 하지 않습니다.
둘째 날부터 열흘 간에는 바나나를 원하는 만큼 할인구매할 수 없기 때문에 둘째 날에도 회원가입을 하지 않습니다.
셋째 날, 넷째 날, 다섯째 날부터 각각 열흘은 원하는 제품과 수량이 일치하기 때문에 셋 중 하루에 회원가입을 하려 합니다.

정현이가 원하는 제품을 나타내는 문자열 배열 want와 정현이가 원하는 제품의 수량을 나타내는 정수 배열 number, XYZ 마트에서 할인하는 제품을 나타내는 문자열 배열 discount가 주어졌을 때,
회원등록시 정현이가 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수를 return 하는 solution 함수를 완성하시오.
가능한 날이 없으면 0을 return 합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<std::string> want, std::vector<int> number, std::vector<std::string> discount)
{
    int answer = 0;

    const size_t DiscountDays = discount.size();

    if (10 == DiscountDays)
    {
        std::vector<int> GetItem(want.size(), 0);
        const size_t CheckSize = want.size();

        for (int j = 0; j < CheckSize; ++j)
        {
            int FindIndex = find(want.begin(), want.end(), discount[j]) - want.begin();

            if (FindIndex < CheckSize)
            {
                ++GetItem[FindIndex];
            }
            else
            {
                return 0;
            }

            for (size_t k = 0; k < CheckSize; ++k)
            {
                if (number[k] > GetItem[k])
                {
                    return 0;
                }
            }
        }

        return 1;
    }

    for (size_t i = 0; i <= DiscountDays - 10; ++i)
    {
        std::vector<int> GetItem(want.size(), 0);
        const size_t CheckSize = want.size();
        
        size_t StartIndex = i;
        size_t EndIndex = i + 10;
        bool Flag = true;
        
        for (int j = StartIndex; j < EndIndex; ++j)
        {
            int FindIndex = find(want.begin(), want.end(), discount[j]) - want.begin();

            if (FindIndex < CheckSize)
            {
                ++GetItem[FindIndex];
            }
            else
            {
                Flag = false;
                break;
            }
        }

        if (false == Flag)
        {
            continue;
        }

        for (size_t k = 0; k < CheckSize; ++k)
        {
            if (number[k] > GetItem[k])
            {
                Flag = false;
                break;
            }
        }

        if (true == Flag)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" }) << std::endl;
    std::cout << solution({ "apple" }, { 10 }, { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" }) << std::endl;
}
