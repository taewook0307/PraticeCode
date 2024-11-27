// 241127_12969.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 직사각형 별찍기

/*
문제설명
이 문제에는 표준 입력으로 두 개의 정수 n과 m이 주어집니다.
별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.
*/

#include <iostream>

int main(void)
{
    int a;
    int b;

    std::cin >> a >> b;

    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}
