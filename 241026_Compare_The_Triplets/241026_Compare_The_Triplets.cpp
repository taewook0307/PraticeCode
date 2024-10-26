// 241026_Compare_The_Triplets.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<int> compareTriplets(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> Result(2, 0);

    const size_t Count = a.size();

	for (size_t i = 0; i < Count; ++i)
	{
		if (a[i] > b[i])
		{
			++Result[0];
		}
		else if (a[i] < b[i])
		{
			++Result[1];
		}
		else
		{
			continue;
		}
	}

	return Result;
}

int main()
{
    std::cout << "Hello World!\n";
}
