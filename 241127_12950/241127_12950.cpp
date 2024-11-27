// 241127_12950.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 행렬의 덧셈

/*
문제설명
행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다.
2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2)
{
    const size_t Row = arr1.size();
    const size_t Column = arr1[0].size();

    std::vector<std::vector<int>> answer(Row, std::vector<int>(Column, 0));

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Column; ++j)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
