// 241218_62048.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 멀쩡한 사각형

/*
문제설명
가로 길이가 Wcm, 세로 길이가 Hcm인 직사각형 종이가 있습니다.
종이에는 가로, 세로 방향과 평행하게 격자 형태로 선이 그어져 있으며, 모든 격자칸은 1cm x 1cm 크기입니다.
이 종이를 격자 선을 따라 1cm × 1cm의 정사각형으로 잘라 사용할 예정이었는데, 누군가가 이 종이를 대각선 꼭지점 2개를 잇는 방향으로 잘라 놓았습니다.
그러므로 현재 직사각형 종이는 크기가 같은 직각삼각형 2개로 나누어진 상태입니다.
새로운 종이를 구할 수 없는 상태이기 때문에, 이 종이에서 원래 종이의 가로, 세로 방향과 평행하게 1cm × 1cm로 잘라 사용할 수 있는 만큼만 사용하기로 하였습니다.
가로의 길이 W와 세로의 길이 H가 주어질 때, 사용할 수 있는 정사각형의 개수를 구하는 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <algorithm>

long long GCD(long long _Num1, long long _Num2)
{
    if (_Num1 % _Num2 == 0)
    {
        return _Num2;
    }

    return GCD(_Num2, _Num1 % _Num2);
}

long long solution(int w, int h)
{
    long long longW = static_cast<long long>(w);
    long long longH = static_cast<long long>(h);

    long long answer = longW * longH;

    long long GCDWH = longW > longH ? GCD(longW, longH) : GCD(longH, longW);

    long long longWW = longW / GCDWH;
    long long longHH = longH / GCDWH;

    long long PartCut = (longWW * longHH) - (longWW - 1) * (longHH - 1);
    long long AllCut = PartCut * GCDWH;

    answer -= AllCut;

    return answer;
}

int main()
{
    std::cout << solution(8, 12) << std::endl;
}
