// 241127_68935.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 3진법 뒤집기

/*
문제설명
자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int solution(int n)
{
    int answer = 0;

    std::vector<int> ThreeBinary;
    ThreeBinary.reserve(n / 3);

    while (n != 0)
    {
        ThreeBinary.push_back(n % 3);
        n /= 3;
    }

    std::reverse(ThreeBinary.begin(), ThreeBinary.end());

    size_t LoopCount = ThreeBinary.size();

    for (size_t i = 0; i < LoopCount; ++i)
    {
        answer += std::pow(3, i) * ThreeBinary[i];
    }

    return answer;
}

int main()
{
    std::cout << solution(45) << std::endl;
    std::cout << solution(125) << std::endl;
}
