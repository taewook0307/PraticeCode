// 240815_86051.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 없는 숫자 더하기

/*
문제 설명
0부터 9까지의 숫자 중 일부가 들어있는 정수 배열 numbers가 매개변수로 주어집니다.
numbers에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 더한 수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> numbers)
{
    //int answer = 0;

    //sort(numbers.begin(), numbers.end());

    //const int numbersSize = numbers.size();
    //int j = 0;

    //for (int i = 0; i < 10; ++i)
    //{
    //    if (i == numbers[j])
    //    {
    //        if (j != numbersSize - 1)
    //        {
    //            ++j;
    //        }
    //        continue;
    //    }
    //    else
    //    {
    //        answer += i;
    //    }
    //}

    //return answer;

    int answer = 45;

    for (int i = 0; i < numbers.size(); ++i)
    {
        answer -= numbers[i];
    }

    return answer;
}

void PrintResult(std::vector<int> numbers)
{
    int Result = solution(numbers);
    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> numbers0 = { 1,2,3,4,6,7,8,0 };
    PrintResult(numbers0);

    std::vector<int> numbers1 = { 5,8,4,0,6,7,9 };
    PrintResult(numbers1);
}
