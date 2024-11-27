// 241127_142086.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 가장 가까운 같은 글자

/*
문제설명
문자열 s가 주어졌을 때, s의 각 위치마다 자신보다 앞에 나왔으면서, 자신과 가장 가까운 곳에 있는 같은 글자가 어디 있는지 알고 싶습니다.
예를 들어, s="banana"라고 할 때,  각 글자들을 왼쪽부터 오른쪽으로 읽어 나가면서 다음과 같이 진행할 수 있습니다.

    - b는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
    - a는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
    - n은 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
    - a는 자신보다 두 칸 앞에 a가 있습니다. 이는 2로 표현합니다.
    - n도 자신보다 두 칸 앞에 n이 있습니다. 이는 2로 표현합니다.
    - a는 자신보다 두 칸, 네 칸 앞에 a가 있습니다. 이 중 가까운 것은 두 칸 앞이고, 이는 2로 표현합니다.

따라서 최종 결과물은 [-1, -1, -1, 2, 2, 2]가 됩니다.

문자열 s이 주어질 때, 위와 같이 정의된 연산을 수행하는 함수 solution을 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::string s)
{
    const size_t SLen = s.length();

    std::vector<int> answer;
    answer.reserve(SLen);

    std::map<char, int> Char;

    for (size_t i = 0; i < SLen; ++i)
    {
        if (Char.end() != Char.find(s[i]))
        {
            answer.push_back(i - Char[s[i]]);
            Char[s[i]] = i;
        }
        else
        {
            answer.push_back(-1);
            Char.insert(std::make_pair(s[i], i));
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution("banana");
    std::vector<int> Result1 = solution("foobar");
}
