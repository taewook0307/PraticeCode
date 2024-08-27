// 240827_42862.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 체육복

/*
문제 설명
점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다.
다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다.
학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.
예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다.
체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.

전체 학생의 수 n,
체육복을 도난당한 학생들의 번호가 담긴 배열 lost,
여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때,
체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>

int solution(int n, std::vector<int> lost, std::vector<int> reserve)
{
    int answer = 0;

    std::vector<int> Clothes(n, 1);

    // 잃어버린 학생들 체육복 수 계산
    for (const int LostStudent : lost)
    {
        --Clothes[LostStudent - 1];
    }

    // 여분을 가진 학생들 체육복 수 계산
    for (const int ReserveStudent : reserve)
    {
        ++Clothes[ReserveStudent - 1];
    }

    // 전체 학생 중 체육복이 없는 이 확인
    for (int i = 0; i < n; ++i)
    {
        if (0 == Clothes[i])
        {
            int PrevNum = i - 1;
            int BackNum = i + 1;

            if (PrevNum >= 0)
            {
                if (2 == Clothes[PrevNum])
                {
                    Clothes[PrevNum] = 1;
                    Clothes[i] = 1;
                }
            }

            if (n > BackNum)
            {
                if (2 == Clothes[BackNum] && 0 == Clothes[i])
                {
                    Clothes[BackNum] = 1;
                    Clothes[i] = 1;
                }
            }
        }
    }

    for (const int Result : Clothes)
    {
        if (0 < Result)
        {
            ++answer;
        }
    }

    return answer;
}

void PrintResult(int n, const std::vector<int>& lost, const std::vector<int>& reserve)
{
    int Result = solution(n, lost, reserve);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> lost0 = { 2, 4 };
    std::vector<int> reserve0 = { 1, 3, 5 };
    PrintResult(5, lost0, reserve0);

    std::vector<int> lost1 = { 2, 5 };
    std::vector<int> reserve1 = { 3 };
    PrintResult(5, lost1, reserve1);

    std::vector<int> lost2 = { 1 };
    std::vector<int> reserve2 = { 3 };
    PrintResult(3, lost2, reserve2);
}
