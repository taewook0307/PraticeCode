// 241002_70129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 이진 변환 반복하기

/*
문제 설명
0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.

    - x의 모든 0을 제거합니다.
    - x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.

예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.

0과 1로 이루어진 문자열 s가 매개변수로 주어집니다.
s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때,
이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>

std::vector<int> solution(std::string s)
{
    std::vector<int> answer;
    answer.reserve(2);

    std::string ChangeString = s;
    int Count = 0;
    int RemoveCount = 0;

    while (ChangeString != "1")
    {
        std::string RemoveString = "";

        for (char CurChar : ChangeString)
        {
            if ('0' == CurChar)
            {
                ++RemoveCount;
            }
            else
            {
                RemoveString += '1';
            }
        }

        size_t Length = RemoveString.size();

        std::deque<char> BinaryLength;

        while (0 != Length)
        {
            if (0 == Length % 2)
            {
                BinaryLength.push_back('0');
            }
            else
            {
                BinaryLength.push_back('1');
            }
            Length /= 2;
        }

        std::string BinaryLengthString = "";

        while(false == BinaryLength.empty())
        {
            BinaryLengthString += BinaryLength.back();
            BinaryLength.pop_back();
        }

        while (BinaryLengthString[0] == '0')
        {
            BinaryLengthString.erase(BinaryLengthString.begin());
        }

        ChangeString = BinaryLengthString;
        ++Count;
    }

    answer.push_back(Count);
    answer.push_back(RemoveCount);

    return answer;
}

int main()
{
    std::vector<int> Result0 = solution("110010101001");
    std::vector<int> Result1 = solution("01110");
    std::vector<int> Result2 = solution("1111111");
}
