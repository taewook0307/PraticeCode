// 241121_42840.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 모의고사

/*
문제설명
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> answers)
{
    std::vector<int> answer;

    std::vector<std::vector<int>> People = { {1, 2, 3, 4, 5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };
    std::vector<int> Score(3, 0);

    const size_t AnswerCount = answers.size();

    int Person0Index = 0;
    int Person1Index = 0;
    int Person2Index = 0;

    for (int i = 0; i < AnswerCount; ++i)
    {
        if (answers[i] == People[0][Person0Index])
        {
            ++Score[0];
        }

        if (answers[i] == People[1][Person1Index])
        {
            ++Score[1];
        }

        if (answers[i] == People[2][Person2Index])
        {
            ++Score[2];
        }

        ++Person0Index;
        ++Person1Index;
        ++Person2Index;

        if (Person0Index == 5)
        {
            Person0Index = 0;
        }

        if (Person1Index == 8)
        {
            Person1Index = 0;
        }

        if (Person2Index == 10)
        {
            Person2Index = 0;
        }
    }

    int MaxScore = *std::max_element(Score.begin(), Score.end());

    for (int i = 0; i < 3; ++i)
    {
        if (Score[i] == MaxScore)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
