// 240923_87390.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// n^2 배열 자르기

/*
문제 설명
정수 n, left, right가 주어집니다. 다음 과정을 거쳐서 1차원 배열을 만들고자 합니다.

    1. n행 n열 크기의 비어있는 2차원 배열을 만듭니다.
    2. i = 1, 2, 3, ..., n에 대해서, 다음 과정을 반복합니다.
        - 1행 1열부터 i행 i열까지의 영역 내의 모든 빈 칸을 숫자 i로 채웁니다.
    3. 1행, 2행, ..., n행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만듭니다.
    4. 새로운 1차원 배열을 arr이라 할 때, arr[left], arr[left+1], ..., arr[right]만 남기고 나머지는 지웁니다.

정수 n, left, right가 매개변수로 주어집니다.
주어진 과정대로 만들어진 1차원 배열을 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>

//std::vector<int> solution(int n, long long left, long long right)
//{
//    long long Size = right - left + 1;
//    std::vector<int> answer;
//    answer.reserve(static_cast<size_t>(Size));
//    
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            int Index = n * i + j;
//
//            if (Index > right)
//            {
//                return answer;
//            }
//
//            if (Index < left)
//            {
//                continue;
//            }
//
//            int PushNum = i < j ? j + 1 : i + 1;
//            answer.push_back(PushNum);
//        }
//    }
//
//    return answer;
//}

std::vector<int> solution(int n, long long left, long long right)
{
    long long Size = right - left + 1;
    std::vector<int> answer;
    answer.reserve(static_cast<size_t>(Size));

    for (long long i = left; i <= right; ++i)
    {
        long long row = i / n;
        long long column = i % n;

        int IntRow = static_cast<int>(row);
        int IntColumn = static_cast<int>(column);

        int PushValue = IntRow < IntColumn ? IntColumn + 1 : IntRow + 1;

        answer.push_back(PushValue);
    }

    return answer;
}

void PrintVector(const std::vector<int>& _Vector)
{
    std::cout << "----------------------------------" << std::endl;
    for (int Num : _Vector)
    {
        printf_s("%d ", Num);
    }
    std::cout << std::endl << "----------------------------------" << std::endl;
}

int main()
{
    std::vector<int> Result0 = solution(3, 2, 5);
    PrintVector(Result0);

    std::vector<int> Result1 = solution(4, 7, 14);
    PrintVector(Result1);
}
