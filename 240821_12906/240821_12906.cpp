// 240821_12906.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 같은 숫자는 싫어

/*
문제 설명
배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.
이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.
단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.

예를 들면,
    arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
    arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.

배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

//std::vector<int> solution(std::vector<int> arr)
//{
//    std::vector<int> answer;
//    answer.reserve(arr.size());
//
//    for (int Num : arr)
//    {
//        if (false == answer.empty())
//        {
//            int PrevNum = answer.back();
//
//            if (Num != PrevNum)
//            {
//                answer.push_back(Num);
//            }
//        }
//        else
//        {
//            answer.push_back(Num);
//        }
//    }
//
//    return answer;
//}

std::vector<int> solution(std::vector<int> arr)
{
    std::vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    answer.reserve(arr.size());

    answer = arr;

    return answer;
}

void PrintResult(const std::vector<int>& arr)
{
    std::vector<int> Result = solution(arr);

    std::cout << "Result : { ";

    for (int Num : Result)
    {
        std::cout << Num << " ";
    }

    std::cout << "}" << std::endl;
}

int main()
{
    std::vector<int> arr0 = { 1, 1, 3, 3, 0, 1, 1 };
    PrintResult(arr0);

    std::vector<int> arr1 = { 4, 4, 4, 3, 3 };
    PrintResult(arr1);
}
