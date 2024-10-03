// 241003_12924.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 숫자의 표현

/*
문제 설명
Finn은 요즘 수학공부에 빠져 있습니다. 수학 공부를 하던 Finn은 자연수 n을 연속한 자연수들로 표현 하는 방법이 여러개라는 사실을 알게 되었습니다.
예를들어 15는 다음과 같이 4가지로 표현 할 수 있습니다.

1 + 2 + 3 + 4 + 5 = 15
4 + 5 + 6 = 15
7 + 8 = 15
15 = 15

자연수 n이 매개변수로 주어질 때, 연속된 자연수들로 n을 표현하는 방법의 수를 return하는 solution를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> Factor(int _Value)
{
    if (_Value <= 0)
    {
        return std::vector<int>(0);
    }

    std::vector<int> Result;
    Result.reserve(_Value / 2);

    int N = _Value;

    for (int i = 1; i < N; ++i)
    {
        if (0 == _Value % i)
        {
            N = _Value / i;

            Result.push_back(i);

            if (i != N)
            {
                Result.push_back(N);
            }
        }
    }

    return Result;
}

int solution(int n)
{
    int answer = 0;

    // 숫자의 약수의 갯수 중 홀수의 갯수 구하기
    std::vector<int> FactorN = Factor(n);

    answer = count_if(FactorN.begin(), FactorN.end(),
        [](int _Value)
        {
            return _Value % 2 != 0;
        }
    );

    // n이 홀수이면 본인 제외하고 2추가하기 때문에 굳이 빼주고 더해줄 필요 X

    return n == 1 ? 1 : answer;
}

int main()
{
    int Result0 = solution(1);

    int Result1 = solution(20);

    int Result3 = solution(1);

    int Result2 = solution(10);
}
