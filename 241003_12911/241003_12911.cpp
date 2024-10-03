// 241003_12911.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 다음 큰 숫자

/*
문제 설명
자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.

    조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
    조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
    조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.

예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.

자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

int solution(int n)
{
    int answer = n;

    int FindLastOne = -1;
    for (int i = 1; i < n; i = i << 1)
    {
        if (i == (n & i))
        {
            FindLastOne = i;
            break;
        }
    }

    answer += FindLastOne;

    int AnswerNorN = answer ^ n;
    
    std::bitset<32> Bit(AnswerNorN);
    std::string BitString = Bit.to_string();

    int Count = count(BitString.begin(), BitString.end(), '1');
    Count -= 2;

    if (0 == Count)
    {
        return answer;
    }

    int PlusValue = 0;

    for (int i = 0; i < Count; ++i)
    {
        PlusValue += pow(2, i);
    }
    
    answer += PlusValue;

    return answer;
}

int main()
{
    int Result0 = solution(78);
    int Result1 = solution(15);
}
