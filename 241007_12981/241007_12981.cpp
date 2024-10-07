// 241007_12981.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 영어 끝말잇기

/*
문제 설명
1부터 n까지 번호가 붙어있는 n명의 사람이 영어 끝말잇기를 하고 있습니다. 영어 끝말잇기는 다음과 같은 규칙으로 진행됩니다.

- 1번부터 번호 순서대로 한 사람씩 차례대로 단어를 말합니다.
- 마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작합니다.
- 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
- 이전에 등장했던 단어는 사용할 수 없습니다.
- 한 글자인 단어는 인정되지 않습니다.

다음은 3명이 끝말잇기를 하는 상황을 나타냅니다.

tank → kick → know → wheel → land → dream → mother → robot → tank

위 끝말잇기는 다음과 같이 진행됩니다.

1번 사람이 자신의 첫 번째 차례에 tank를 말합니다.
2번 사람이 자신의 첫 번째 차례에 kick을 말합니다.
3번 사람이 자신의 첫 번째 차례에 know를 말합니다.
1번 사람이 자신의 두 번째 차례에 wheel을 말합니다.
(계속 진행)
끝말잇기를 계속 진행해 나가다 보면, 3번 사람이 자신의 세 번째 차례에 말한 tank 라는 단어는 이전에 등장했던 단어이므로 탈락하게 됩니다.

사람의 수 n과 사람들이 순서대로 말한 단어 words 가 매개변수로 주어질 때, 가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

std::vector<int> solution(int n, std::vector<std::string> words)
{
    std::vector<int> answer(2);

    std::unordered_set <std::string> SetWords;
    std::string LastPushWord = "";

    int DropCount = -1;

    for (const std::string& CurWord : words)
    {
        // 한글자 확인
        if (CurWord.size() == 1)
        {
            DropCount = SetWords.size() + 1;
            break;
        }

        // 끝말 확인
        if (LastPushWord != "" && CurWord[0] != *LastPushWord.rbegin())
        {
            DropCount = SetWords.size() + 1;
            break;
        }

        std::pair<std::unordered_set<std::string>::iterator, bool> Push = SetWords.insert(CurWord);
        LastPushWord = CurWord;

        // 중복 문자 확인
        if (false == Push.second)
        {
            DropCount = SetWords.size() + 1;
            break;
        }
    }

    if (DropCount == -1)
    {
        return answer;
    }

    if (DropCount % n == 0)
    {
        answer[0] = n;
    }
    else
    {
        answer[0] = DropCount % n;
    }

    answer[1] = ceil(DropCount / static_cast<float>(n));

    return answer;
}

int main()
{
    std::vector<int> Result0 = solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });

    std::vector<int> Result1 = solution(5, { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" });

    std::vector<int> Result2 = solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });

    int a = 0;
}
