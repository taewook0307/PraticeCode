// 241007_12914.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 멀리 뛰기

/*
문제 설명
효진이는 멀리 뛰기를 연습하고 있습니다. 효진이는 한번에 1칸, 또는 2칸을 뛸 수 있습니다.

칸이 총 4개 있을 때, 효진이는
    (1칸, 1칸, 1칸, 1칸)
    (1칸, 2칸, 1칸)
    (1칸, 1칸, 2칸)
    (2칸, 1칸, 1칸)
    (2칸, 2칸)
의 5가지 방법으로 맨 끝 칸에 도달할 수 있습니다.

멀리뛰기에 사용될 칸의 수 n이 주어질 때, 효진이가 끝에 도달하는 방법이 몇 가지인지 알아내,
여기에 1234567를 나눈 나머지를 리턴하는 함수, solution을 완성하세요.
예를 들어 4가 입력된다면, 5를 return하면 됩니다.
*/

#include <iostream>
#include <vector>

void MakeCombi(int n, std::vector<long long>& _Vector)
{
    size_t VectorSize = _Vector.size();

    for (size_t i = VectorSize; i <= n; ++i)
    {
        long long PushValue = (_Vector[i - 1] + _Vector[i - 2]) % 1234567;
        _Vector.push_back(PushValue);
    }
}

long long solution(int n)
{
    long long answer = 1;

    std::vector<long long> Combi;
    Combi.reserve(n);

    // 1칸 이동
    Combi.push_back(1);
    // 2칸 이동
    Combi.push_back(2);

    MakeCombi(n, Combi);

    answer = Combi[n - 1];

    return answer;
}

int main()
{
    std::cout << solution(2000) << std::endl;
    std::cout << solution(3) << std::endl;
}