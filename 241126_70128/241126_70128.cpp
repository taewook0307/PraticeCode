// 241126_70128.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 내적

/*
문제설명
길이가 같은 두 1차원 정수 배열 a, b가 매개변수로 주어집니다. a와 b의 내적을 return 하도록 solution 함수를 완성해주세요.

이때, a와 b의 내적은 a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] 입니다. (n은 a, b의 길이)
*/

#include <iostream>
#include <vector>
#include <numeric>

int solution(std::vector<int> a, std::vector<int> b)
{
    //int answer = 0;

    //const size_t Count = a.size();

    //for (size_t i = 0; i < Count; ++i)
    //{
    //    answer += (a[i] * b[i]);
    //}

    //return answer;
    
    return std::inner_product(a.begin(), a.end(), b.begin(), 0);
}

int main()
{
    std::cout << "Hello World!\n";
}
