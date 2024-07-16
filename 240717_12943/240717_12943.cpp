// 240717_12943.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 콜라츠 추측

/*
문제 설명
1937년 Collatz란 사람에 의해 제기된 이 추측은, 주어진 수가 1이 될 때까지 다음 작업을 반복하면,
모든 수를 1로 만들 수 있다는 추측입니다.
작업은 다음과 같습니다.

1-1. 입력된 수가 짝수라면 2로 나눕니다.
1-2. 입력된 수가 홀수라면 3을 곱하고 1을 더합니다.
2. 결과로 나온 수에 같은 작업을 1이 될 때까지 반복합니다.

예를 들어, 주어진 수가 6이라면 6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1 이 되어 총 8번 만에 1이 됩니다.
위 작업을 몇 번이나 반복해야 하는지 반환하는 함수, solution을 완성해 주세요.
단, 주어진 수가 1인 경우에는 0을, 작업을 500번 반복할 때까지 1이 되지 않는다면 –1을 반환해 주세요.
*/

#include <iostream>

int solution(int num) {
    int answer = 0;

    long long InputNum = static_cast<long long>(num);

    if (1 == InputNum)
    {
        return 0;
    }

    while (1 != InputNum)
    {
        ++answer;

        if (0 == InputNum % 2)
        {
            InputNum /= 2;
        }
        else
        {
            InputNum *= 3;
            InputNum += 1;
        }

        if (answer >= 500)
        {
            return -1;
        }
    }

    return answer;
}

void PrintResult(int num)
{
    int Result = solution(num);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    PrintResult(6);
    PrintResult(16);
    PrintResult(1);
    PrintResult(626331);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
