// 241119_178870.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 연속된 부분 수열의 합

/*
문제 설명
비내림차순으로 정렬된 수열이 주어질 때, 다음 조건을 만족하는 부분 수열을 찾으려고 합니다.

- 기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열이어야 합니다.
- 부분 수열의 합은 k입니다.
- 합이 k인 부분 수열이 여러 개인 경우 길이가 짧은 수열을 찾습니다.
- 길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에 나오는 수열을 찾습니다.

수열을 나타내는 정수 배열 sequence와 부분 수열의 합을 나타내는 정수 k가 매개변수로 주어질 때,
위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return 하는 solution 함수를 완성해주세요.
이때 수열의 인덱스는 0부터 시작합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>

std::vector<int> solution(std::vector<int> sequence, int k)
{
    const size_t NumCount = sequence.size();

    std::vector<int> answer(2, -1);
    std::deque<std::pair<int, int>> Part;

    int Index = 0;
    int Sum = 0;
    int PartCount = INT_MAX;

    while (Index < NumCount)
    {
        if (Sum <= k)
        {
            Part.push_back(std::make_pair(sequence[Index], Index));
            Sum += sequence[Index];
            ++Index;

            if (Sum == k && PartCount > Part.size())
            {
                answer[0] = Part.front().second;
                answer[1] = Part.back().second;
                PartCount = Part.size();
            }
        }
        else
        {
            Sum -= Part.front().first;
            Part.pop_front();

            if (Sum == k && PartCount > Part.size())
            {
                answer[0] = Part.front().second;
                answer[1] = Part.back().second;
                PartCount = Part.size();
            }
        }
    }

    while (false == Part.empty())
    {
        if (Sum == k && PartCount > Part.size())
        {
            answer[0] = Part.front().second;
            answer[1] = Part.back().second;
            PartCount = Part.size();
        }

        Sum -= Part.front().first;
        Part.pop_front();
    }

    return answer;
}

int main()
{
    std::vector<int> Result0 = solution({ 1, 2, 3, 4, 5 }, 7);
    std::vector<int> Result1 = solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);
    std::vector<int> Result2 = solution({ 2, 2, 2, 2, 2 }, 6);
}
