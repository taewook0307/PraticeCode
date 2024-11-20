// 241120_12899.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 124나라의 숫자

/*
문제설명
124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.

124 나라에는 자연수만 존재합니다.
124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.

10진법	124 나라
  1	       1
  2	       2
  3	       4
  4	       11
  5	       12
  6	       14
  7	       21
  8	       22
  9	       24
  10	   41

자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string solution(int n)
{
    std::string answer = "";

    while (n > 0)
    {
        int RemainValue = n % 3;

        if (0 == RemainValue)
        {
            answer += '4';
            n /= 3;
            --n;
        }
        else
        {
            answer += (RemainValue + '0');
            n /= 3;
        }
    }

    std::reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    std::cout << solution(3) << std::endl;
    std::cout << solution(4) << std::endl;
    std::cout << solution(11) << std::endl;
}
