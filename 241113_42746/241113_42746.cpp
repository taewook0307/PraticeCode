// 241113_42746.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 가장 큰 수

/*
문제설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool Compare(const std::string& _Left, const std::string& _Right)
{
    return _Left + _Right > _Right + _Left;
}

std::string solution(std::vector<int> numbers)
{
    std::string answer = "";

    std::vector<std::string> StringNumbers;

    for (int Num : numbers)
    {
        std::string StringNum = std::to_string(Num);
        StringNumbers.push_back(StringNum);
    }

    std::sort(StringNumbers.begin(), StringNumbers.end(), Compare);

    if (StringNumbers[0] == "0")
    {
        return "0";
    }

    for (const std::string& Num : StringNumbers)
    {
        answer += Num;
    }

    return answer;
}

int main()
{
    std::cout << solution({ 12, 121 }) << std::endl;
    std::cout << solution({ 21, 212 }) << std::endl;
    std::cout << solution({ 0, 0, 0 }) << std::endl;
}
