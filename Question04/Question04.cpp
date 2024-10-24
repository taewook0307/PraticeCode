// Question04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<int> circularArrayRotation(std::vector<int> a, int k, std::vector<int> queries)
{
    const size_t VectorSize = a.size();

    int StartIndex = k;

    StartIndex %= VectorSize;

    StartIndex = VectorSize - StartIndex;

    std::vector<int> Result;
    Result.reserve(queries.size());

    for (int QueryIndex : queries)
    {
        int Index = StartIndex + QueryIndex;
        if (Index >= VectorSize)
        {
            Index -= VectorSize;
        }

        Result.push_back(a[Index]);
    }

    return Result;
}

int main()
{
    std::vector<int> Result = circularArrayRotation({ 1, 2, 3 },
        2,
        {0, 1, 2}
    );
}

/*
회전횟수 % 벡터size->시작 인덱스

01234
12345


VectorSize 작은 회전 -> VectorSize - 회전횟수

VectorSize 큰 회전 -> 회전횟수 -= vectorSize

1번 회전 -> 4번 인덱스
2번 회전 -> 3번 인덱스
3번 회전 -> 2번 인덱스
4번 회전 -> 1번 인덱스
5번 회전 -> 0번 인덱스
6번 회전 -> 4번 인덱스
7번 회전 -> 3번 인덱스
zzzzzzz
*/