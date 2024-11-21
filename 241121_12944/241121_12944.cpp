// 241121_12944.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 평균 구하기

/*
문제설명
정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.
*/

#include <iostream>
#include <vector>
#include <numeric>

double solution(std::vector<int> arr)
{
    double answer = 0;

    double Sum = std::accumulate(arr.begin(), arr.end(), 0.0f);

    answer = Sum / arr.size();

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
