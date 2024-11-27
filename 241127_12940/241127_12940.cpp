// 241127_12940.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 최대공약수와 최소공배수

/*
문제설명
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요.
배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다.
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 유클리드 호제법을 이용한 더 간단한 함수 코드
//int Euclidean(int a, int b)
//{
//    return b ? Euclidean(b, a % b) : a;
//}

int GCD(int _Num1, int _Num2)
{
    if (_Num2 > _Num1)
    {
        std::swap(_Num1, _Num2);
    }

    if (_Num1 % _Num2 == 0)
    {
        return _Num2;
    }

    return GCD(_Num2, _Num1 % _Num2);
}

int LCM(int _Num1, int _Num2, int _GCD)
{
    return _Num1 * _Num2 / _GCD;
}

std::vector<int> solution(int n, int m)
{
    std::vector<int> answer;
    answer.reserve(2);

    answer.push_back(GCD(n, m));
    answer.push_back(LCM(n, m, answer[0]));

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
