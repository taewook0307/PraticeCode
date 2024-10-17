// 241017_12949.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 행렬의 곱셈

/*
문제 설명
2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2)
{
	const size_t Arr1Row = arr1.size();
	const size_t Arr1Column = arr1[0].size();
	const size_t Arr2Row = arr2.size();
	const size_t Arr2Column = arr2[0].size();

	std::vector<std::vector<int>> answer(Arr1Row, std::vector<int>(Arr2Column, 0));
	
	for (size_t i = 0; i < Arr1Row; ++i)
	{
		for (size_t j = 0; j < Arr2Column; ++j)
		{
			int Value = 0;

			std::vector<int> Plus = arr1[i];

			for (int k = 0; k < Arr1Column; ++k)
			{
				Value += (Plus[k] * arr2[k][j]);
			}

			answer[i][j] = Value;
		}
	}

	return answer;
}

int main()
{
	std::vector<std::vector<int>> Result0 = solution({ {1, 4}, {3, 2}, {4, 1} }, { {3, 3}, {3, 3} });
	std::vector<std::vector<int>> Result1 = solution({ {2, 3, 2}, {4, 2, 4}, {3, 1, 4} }, { {5, 4, 3}, {2, 4, 1}, {3, 1, 1} });

	int a = 0;
}
