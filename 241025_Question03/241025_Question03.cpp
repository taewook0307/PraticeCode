// 241025_Question03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int lilysHomework(std::vector<int> arr)
{
    int AscendingCount = 0;
    const size_t ArrSize = arr.size();

    std::vector<int> CopyVector = arr;

    std::vector<int>::iterator SortedLocation = CopyVector.begin();
    int SortedIndex = -1;

    while(1)
    {
        if (SortedLocation == CopyVector.end())
        {
            break;
        }

        int MinIndex = std::min_element(SortedLocation, CopyVector.end()) - CopyVector.begin();
        
        if ((MinIndex - SortedIndex) == 1)
        {
            SortedIndex = MinIndex;
            ++SortedLocation;
            continue;
        }

        if (SortedIndex + 1 == ArrSize)
        {
            break;
        }

        std::swap(CopyVector[SortedIndex + 1], CopyVector[MinIndex]);
        ++AscendingCount;
        ++SortedIndex;
        ++SortedLocation;
    }

    int DecendingCount = 0;

    std::vector<int>::iterator DecendingSortedLocation = arr.begin();
    int DecendingSortedIndex = -1;

    while (1)
    {
        if (DecendingSortedLocation == arr.end())
        {
            break;
        }

        int MaxIndex = std::max_element(DecendingSortedLocation, arr.end()) - arr.begin();

        if ((MaxIndex - DecendingSortedIndex) == 1)
        {
            DecendingSortedIndex = MaxIndex;
            ++DecendingSortedLocation;
            continue;
        }

        if (DecendingSortedIndex + 1 == ArrSize)
        {
            break;
        }

        std::swap(arr[DecendingSortedIndex + 1], arr[MaxIndex]);
        ++DecendingCount;
        ++DecendingSortedIndex;
        ++DecendingSortedLocation;
    }

    return DecendingCount > AscendingCount ? AscendingCount : DecendingCount;
}

int main()
{
    std::cout << lilysHomework({ 3, 4, 2, 5, 1 }) << std::endl;
    std::cout << lilysHomework({ 7, 15, 12, 3 }) << std::endl;
    std::cout << lilysHomework({ 2, 5, 3, 1 }) << std::endl;
    std::cout << lilysHomework({ 1, 2, 3, 4 }) << std::endl;
}
