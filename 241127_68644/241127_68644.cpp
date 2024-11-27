// 241127_68644.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 두 개 뽑아서 더하기

/*
문제설명
정수 배열 numbers가 주어집니다.
numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <set>

std::vector<int> solution(std::vector<int> numbers)
{
    std::vector<int> answer;
    std::set<int> PlusValue;

    const size_t NumCount = numbers.size();

    for (size_t i = 0; i < NumCount - 1; ++i)
    {
        for (size_t j = i + 1; j < NumCount; ++j)
        {
            PlusValue.insert(numbers[i] + numbers[j]);
        }
    }

    answer.reserve(PlusValue.size());

    for (int Value : PlusValue)
    {
        answer.push_back(Value);
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
