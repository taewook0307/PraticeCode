// 241105_92335.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// k진수에서 소수 개수 구하기

/*
문제 설명
양의 정수 n이 주어집니다. 이 숫자를 k진수로 바꿨을 때, 변환된 수 안에 아래 조건에 맞는 소수(Prime number)가 몇 개인지 알아보려 합니다.

- 0P0처럼 소수 양쪽에 0이 있는 경우
- P0처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우
- 0P처럼 소수 왼쪽에만 0이 있고 오른쪽에는 아무것도 없는 경우
- P처럼 소수 양쪽에 아무것도 없는 경우
- 단, P는 각 자릿수에 0을 포함하지 않는 소수입니다.

예를 들어, 101은 P가 될 수 없습니다.

예를 들어, 437674을 3진수로 바꾸면 211020101011입니다.
여기서 찾을 수 있는 조건에 맞는 소수는 왼쪽부터 순서대로 211, 2, 11이 있으며, 총 3개입니다.
(211, 2, 11을 k진법으로 보았을 때가 아닌, 10진법으로 보았을 때 소수여야 한다는 점에 주의합니다.)
211은 P0 형태에서 찾을 수 있으며, 2는 0P0에서, 11은 0P에서 찾을 수 있습니다.

정수 n과 k가 매개변수로 주어집니다. n을 k진수로 바꿨을 때, 변환된 수 안에서 찾을 수 있는 위 조건에 맞는 소수의 개수를 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool IsPrime(long _Num)
{
    if (_Num == 0 || _Num == 1)
    {
        return false;
    }
    if (_Num == 2)
    {
        return true;
    }

    int LoopCount = sqrt(_Num);

    for (long i = 2; i <= LoopCount; ++i)
    {
        if (_Num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    std::string Change = "";

    while (1)
    {
        if (n <= k)
        {
            Change += '0' + n;
            break;
        }

        int RemainValue = n % k;

        Change += '0' + RemainValue;

        n /= k;
    }

    std::reverse(Change.begin(), Change.end());

    const size_t CheckCount = Change.size();

    long CheckNum = 0;

    for (size_t i = 0; i < CheckCount; ++i)
    {
        long PlusNum = Change[i] - '0';

        if (i == CheckCount - 1)
        {
            CheckNum *= 10;
            CheckNum += PlusNum;
        }

        if (PlusNum == 0 || i == CheckCount - 1)
        {
            if (true == IsPrime(CheckNum))
            {
                ++answer;
            }

            CheckNum = 0;
        }

        CheckNum *= 10;
        CheckNum += PlusNum;
    }

    return answer;
}

int main()
{
    std::cout << solution(110011, 10) << std::endl;
}
