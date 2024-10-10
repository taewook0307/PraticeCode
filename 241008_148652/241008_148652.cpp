// 241008_148652.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 유사 칸토어 비트열

/*
문제 설명
수학에서 칸토어 집합은 0과 1 사이의 실수로 이루어진 집합으로, [0, 1]부터 시작하여 각 구간을 3등분하여 가운데 구간을 반복적으로 제외하는 방식으로 만들어집니다.

남아는 칸토어 집합을 조금 변형하여 유사 칸토어 비트열을 만들었습니다. 유사 칸토어 비트열은 다음과 같이 정의됩니다.

- 0 번째 유사 칸토어 비트열은 "1" 입니다.
- n(1 ≤ n) 번째 유사 칸토어 비트열은 n - 1 번째 유사 칸토어 비트열에서의 1을 11011로 치환하고 0을 00000로 치환하여 만듭니다.

남아는 n 번째 유사 칸토어 비트열에서 특정 구간 내의 1의 개수가 몇 개인지 궁금해졌습니다.
n과 1의 개수가 몇 개인지 알고 싶은 구간을 나타내는 l, r이 주어졌을 때 그 구간 내의 1의 개수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>

//int solution(int n, long long l, long long r)
//{
//    int answer = 0;
//
//    std::vector<std::vector<int>> OneIndex;
//
//    OneIndex.push_back(std::vector<int>(1, 0));
//
//    for (int i = 1; i <= n; ++i)
//    {
//        std::vector<int>& PrevVector = OneIndex[i - 1];
//        const size_t PrevVectorSize = PrevVector.size();
//
//        std::vector<int> PushVector;
//        PushVector.reserve(PrevVectorSize * 4);
//
//        for (size_t i = 0; i < PrevVectorSize; ++i)
//        {
//            if (i > r)
//            {
//                break;
//            }
//
//            int FirstIndex = 5 * PrevVector[i];
//            if (FirstIndex > r)
//            {
//                break;
//            }
//            PushVector.push_back(FirstIndex);
//
//            int SecondIndex = 5 * PrevVector[i] + 1;
//            if (SecondIndex > r)
//            {
//                break;
//            }
//            PushVector.push_back(SecondIndex);
//
//            int ThirdIndex = 5 * PrevVector[i] + 3;
//            if (ThirdIndex > r)
//            {
//                break;
//            }
//            PushVector.push_back(ThirdIndex);
//
//            int LastIndex = 5 * PrevVector[i] + 4;
//            if (LastIndex > r)
//            {
//                break;
//            }
//            PushVector.push_back(LastIndex);
//        }
//
//        OneIndex.push_back(PushVector);
//    }
//    
//    std::vector<int>& NVector = OneIndex[n];
//    size_t NVectorSize = NVector.size();
//
//    for (size_t i = 0; i < NVectorSize; ++i)
//    {
//        if (l - 1 <= NVector[i] && r - 1 >= NVector[i])
//        {
//            ++answer;
//        }
//    }
//
//    return answer;
//}

/*
전의 1의 인덱스 : a
전의 0의 인덱스 : b

구할 1의 인덱스 : 5 * a + 0, 5 * a + 1, 5 * a + 3, 5 * 0 + 4

구할 0의 인덱스 : 5 * a + 2, 5 * b + 0, 5 * b + 1, 5 * b + 2, 5 * b + 3, 5 * b + 4

전체 길이 : 5 ^ n

n = 1
1 : 0, 1, 3, 4
0 : 2
1개

n = 2
1 : 0, 1, 3, 4, 5, 6, 8, 9, 15, 16, 18, 19, 20, 21, 23, 24
0 : 2, 7, 10, 11, 12, 13, 14, 17, 22

0 : 10 ~ 14

14 = (5 * 2) + 4

n = 3
0 : 50 ~ 74

74 = ((5 * 2) + 4) * 5 + 4

n = 4
0 : 250 ~ 374

n = 5
0 : 1250 ~ 1874
*/

/*

n = 1
1

n = 2
1 1 0 1 1

n = 3
4 4 0 4 4

n = 4
16 16 0 16 16

n = 5
64 64 0 64 64
*/

int solution(int n, long long l, long long r)
{
    int answer = 0;
    
    for (long long i = l; i <= r; ++i)
    {
        bool Flag = true;

        // 현재 인덱스를 5로 나눴을 때 3이면 가운데 부분
        if (i % 5 == 3)
        {
            continue;
        }

        long long Area = i;

        while (1)
        {
            // 5, 10 등 5의 배수는 5로 나눈 몫이 해당 구역 ex) 5번 인덱스는 5 / 5 = 1 => 1번구역
            if (Area % 5 == 0)
            {
                Area = Area / 5;
            }
            // 그 외 숫자는 5로 나눈 몫에 1을 더한 수가 해당 구역 ex) 4번 인덱스는 4 / 5 = 0, 0 + 1 => 1번구역
            else
            {
                Area = (Area / 5) + 1;
            }

            // 현재 인덱스가 있는 구역이 0이 연속되는 3번 구역일 경우 현재 인덱스의 값은 0
            if (Area % 5 == 3)
            {
                Flag = 0;
                break;
            }
            // 현제 인덱스 구역이 5보다 작고 위의 조건 중 맞는게 없는 경우 현재 인덱스 값은 1
            else if (Area <= 5)
            {
                Flag = 1;
                break;
            }
        }

        if (true == Flag)
        {
            ++answer;
        }
    }

    return answer;
}

// 1 ~ 5 6 ~10 11~15 16~20 21~25
// 11011 11011 00000 11011 11011

int main()
{
    std::cout << solution(2, 4, 17) << std::endl;           // 8
    std::cout << solution(3, 30, 118) << std::endl;         // 39
    std::cout << solution(3, 1, 125) << std::endl;          // 64
    std::cout << solution(3, 27, 68) << std::endl;          // 15
    std::cout << solution(4, 30, 118) << std::endl;         // 64
    std::cout << solution(4, 27, 68) << std::endl;          // 15
}

// 1101111011000001101111011 1101111011000001101111011 0000000000000000000000000 1101111011000001101111011 1101111011000001101111011