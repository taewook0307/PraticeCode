// 250108_43163.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// https://school.programmers.co.kr/learn/courses/30/lessons/43163
// 단어 변환

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

int solution(std::string begin, std::string target, std::vector<std::string> words)
{
    int answer = 0;

    const size_t BeginLen = begin.length();
    const size_t WordCount = words.size();

    std::vector<bool> IsChanged(WordCount, false);
    std::unordered_map<std::string, int> ChangeCount;

    std::queue<std::string> BFS;
    BFS.push(begin);
    ChangeCount[begin] = 0;

    while (false == BFS.empty())
    {
        std::string CurString = BFS.front();
        BFS.pop();

        if (CurString == target)
        {
            break;
        }

        for (size_t i = 0; i < WordCount; ++i)
        {
            if (true == IsChanged[i])
            {
                continue;
            }

            int Count = 0;

            for (size_t j = 0; j < BeginLen; ++j)
            {
                if (words[i][j] != CurString[j])
                {
                    ++Count;
                }
            }

            if (Count == 1)
            {
                BFS.push(words[i]);
                IsChanged[i] = true;
                ChangeCount[words[i]] = ChangeCount[CurString] + 1;
            }
        }
    }

    answer = ChangeCount[target];

    return answer;
}

int main()
{
    std::cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << std::endl;
    std::cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << std::endl;
}
