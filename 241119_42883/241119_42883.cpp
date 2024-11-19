// 241119_42883.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 큰 수 만들기

/*
문제설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.
number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.
*/

#include <iostream>
#include <string>

std::string solution(std::string number, int k)
{
    std::string answer = "";
    int i = 0;

    for (int i = 0; i < number.size() - 1; ++i)
    {
        if (number[i] < number[i + 1])
        {
            number.erase(number.begin() + i);
            --k;
            i = -1;
        }

        if (k <= 0)
        {
            break;
        }
    }

    if (k > 0)
    {
        for (int i = k; i > 0; --i)
        {
            number.erase(number.size() - 1);
        }
    }

    answer = number;
    return answer;
}

int main()
{
    std::cout << solution("1924", 2) << std::endl;
    std::cout << solution("1231234", 3) << std::endl;
    std::cout << solution("4177252841", 4) << std::endl;
    std::cout << solution("56789", 4) << std::endl;
    std::cout << solution("1111", 2) << std::endl;
    std::cout << solution("3879781299", 2) << std::endl;
    std::cout << solution("928857", 3) << std::endl;
    std::cout << solution("99991", 3) << std::endl;
    std::cout << solution("10001", 3) << std::endl;
}
