// 241026_Simple_Array_Sum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <numeric>

int simpleArraySum(std::vector<int> ar)
{
    return std::accumulate(ar.begin(), ar.end(), 0);
}

int main()
{
    std::cout << "Hello World!\n";
}
