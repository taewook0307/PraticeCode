// 241025_Question05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

int journeyToMoon(int n, std::vector<std::vector<int>> astronaut)
{
    std::vector<std::set<int>> AllGroup;

    for (const std::vector<int>& CurAstronaut : astronaut)
    {
        int MemberOne = CurAstronaut[0];
        int MemberTwo = CurAstronaut[1];

        bool Flag = false;

        size_t AllGroupSize = AllGroup.size();

        for (size_t i = 0; i < AllGroupSize; ++i)
        {
            std::set<int>* CurGroup = &AllGroup[i];
            
            if (CurGroup->find(MemberOne) != CurGroup->end()
                || CurGroup->find(MemberTwo) != CurGroup->end())
            {
                CurGroup->insert(MemberOne);
                CurGroup->insert(MemberTwo);
                Flag = true;
                break;
            }
        }

        if (Flag == false)
        {
            std::set<int> NewGroup;
            NewGroup.insert(MemberOne);
            NewGroup.insert(MemberTwo);
            AllGroup.push_back(NewGroup);
        }
    }

    size_t AllGroupSize = AllGroup.size();
    for (size_t i = 0; i < AllGroupSize - 1; ++i)
    {
        for (size_t i = i + 1; i < AllGroupSize; ++i)
        {
            
        }
    }
}

int main()
{
    std::cout << journeyToMoon(10, { {0, 2}, {1, 8}, {1, 4}, {2, 8}, {2, 6}, {3, 5}, {6, 9} }) << std::endl;
}