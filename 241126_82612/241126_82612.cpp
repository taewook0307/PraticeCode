// 241126_82612.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 부족한 금액 계산하기

/*
문제설명
새로 생긴 놀이기구는 인기가 매우 많아 줄이 끊이질 않습니다.
이 놀이기구의 원래 이용료는 price원 인데, 놀이기구를 N 번 째 이용한다면 원래 이용료의 N배를 받기로 하였습니다. 
즉, 처음 이용료가 100이었다면 2번째에는 200, 3번째에는 300으로 요금이 인상됩니다.
놀이기구를 count번 타게 되면 현재 자신이 가지고 있는 금액에서 얼마가 모자라는지를 return 하도록 solution 함수를 완성하세요.
단, 금액이 부족하지 않으면 0을 return 하세요.
*/

#include <iostream>

long long solution(int price, int money, int count)
{
    long long answer = 0;

    long long Fee = 0;

    for (int i = 1; i <= count; ++i)
    {
        Fee += price * i;
    }

    answer = static_cast<long long>(money) - Fee;

    return answer > 0 ? 0 : -answer;
}

// 가우스 공식 이용하면 코드 줄이기 가능

int main()
{
    std::cout << solution(3, 20, 4) << std::endl;
}
