// 240627.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// k번째 수

/*
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면

array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
2에서 나온 배열의 3번째 숫자는 5입니다.

배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때,
commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> Command : commands)
    {
        vector<int> SliceArray;

        const int Start = Command[0] - 1;
        const int End = Command[1] - 1;
        const int AnswerNum = Command[2] - 1;

        int NewCapacity = End - Start + 1;
        SliceArray.reserve(NewCapacity);

        for (int i = Start; i <= End; ++i)
        {
            SliceArray.push_back(array[i]);
        }

        sort(SliceArray.begin(), SliceArray.end());

        const int AnswerValue = SliceArray[AnswerNum];

        answer.push_back(AnswerValue);
    }

    return answer;
}

int main()
{
    std::vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };

    std::vector<std::vector<int>> Commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };

    std::vector<int> answer;

    answer.resize(Commands.size());

    answer = solution(array, Commands);

    for (int Check : answer)
    {
        std::cout << "answer Value : " << Check << std::endl;
    }
}