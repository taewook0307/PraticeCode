// 241113_77885.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 2개 이하로 다른 비트

/*
문제설명
양의 정수 x에 대한 함수 f(x)를 다음과 같이 정의합니다.

x보다 크고 x와 비트가 1~2개 다른 수들 중에서 제일 작은 수
예를 들어,

f(2) = 3 입니다. 다음 표와 같이 2보다 큰 수들 중에서 비트가 다른 지점이 2개 이하이면서 제일 작은 수가 3이기 때문입니다.
수	비트	다른 비트의 개수
2	000...0010
3	000...0011	1
f(7) = 11 입니다. 다음 표와 같이 7보다 큰 수들 중에서 비트가 다른 지점이 2개 이하이면서 제일 작은 수가 11이기 때문입니다.

수	비트	다른 비트의 개수
7	000...0111
8	000...1000	4
9	000...1001	3
10	000...1010	3
11	000...1011	2

정수들이 담긴 배열 numbers가 매개변수로 주어집니다.
numbers의 모든 수들에 대하여 각 수의 f 값을 배열에 차례대로 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>

std::vector<long long> solution(std::vector<long long> numbers)
{
    std::vector<long long> answer;
    answer.reserve(numbers.size());

    for (long long Num : numbers)
    {
        if (Num % 2 == 0)
        {
            answer.push_back(Num + 1);
            continue;
        }

        long long Move = 0;

        while (1)
        {
            if ((Num & (1LL << Move)) == 0)
            {
                break;
            }

            ++Move;
        }

        if (Move != 0)
        {
            long long PrevBitNum = 1LL << (Move - 1);
            Num = Num + (1LL << Move) - PrevBitNum;
        }
        else
        {
            Num += (1LL << Move);
        }

        answer.push_back(Num);
    }

    return answer;
}

int main()
{
    std::vector<long long> Result = solution({2, 7});

    int a = 0;
}
