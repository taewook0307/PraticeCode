// 240730_159994.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 카드 뭉치

/*
문제 설명
코니는 영어 단어가 적힌 카드 뭉치 두 개를 선물로 받았습니다. 코니는 다음과 같은 규칙으로 카드에 적힌 단어들을 사용해 원하는 순서의 단어 배열을 만들 수 있는지 알고 싶습니다.

    - 원하는 카드 뭉치에서 카드를 순서대로 한 장씩 사용합니다.
    - 한 번 사용한 카드는 다시 사용할 수 없습니다.
    - 카드를 사용하지 않고 다음 카드로 넘어갈 수 없습니다.
    - 기존에 주어진 카드 뭉치의 단어 순서는 바꿀 수 없습니다.

예를 들어 첫 번째 카드 뭉치에 순서대로 ["i", "drink", "water"], 두 번째 카드 뭉치에 순서대로 ["want", "to"]가 적혀있을 때
["i", "want", "to", "drink", "water"] 순서의 단어 배열을 만들려고 한다면
첫 번째 카드 뭉치에서 "i"를 사용한 후 두 번째 카드 뭉치에서 "want"와 "to"를 사용하고
첫 번째 카드뭉치에 "drink"와 "water"를 차례대로 사용하면 원하는 순서의 단어 배열을 만들 수 있습니다.

문자열로 이루어진 배열 cards1,
cards2와 원하는 단어 배열 goal이 매개변수로 주어질 때,
cards1과 cards2에 적힌 단어들로 goal를 만들 있다면 "Yes"를,
만들 수 없다면 "No"를 return하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>

#include <queue>

std::string solution(std::vector<std::string> cards1, std::vector<std::string> cards2, std::vector<std::string> goal)
{
    std::string answer = "Yes";

    std::queue<std::string> Cards1Queue;
    std::queue<std::string> Cards2Queue;

    for (const std::string& CurString : cards1)
    {
        Cards1Queue.push(CurString);
    }

    for (const std::string& CurString : cards2)
    {
        Cards2Queue.push(CurString);
    }

    const int GoalCount = goal.size();

    for (int i = 0; i < GoalCount; ++i)
    {
        if (false == Cards1Queue.empty()
            && Cards1Queue.front() == goal[i])
        {
            Cards1Queue.pop();
        }
        else if (false == Cards2Queue.empty()
            && Cards2Queue.front() == goal[i])
        {
            Cards2Queue.pop();
        }
        else
        {
            answer = "No";
            break;
        }
    }
    
    return answer;
}

void PrintResult(const std::vector<std::string>& cards1, const std::vector<std::string>& cards2, const std::vector<std::string>& goal)
{
    std::string Result = solution(cards1, cards2, goal);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<std::string> EX1Cards1 = { "i", "drink", "water" };
    std::vector<std::string> EX1Cards2 = { "want", "to" };
    std::vector<std::string> EX1Goal = { "i", "want", "to", "drink", "water" };

    PrintResult(EX1Cards1, EX1Cards2, EX1Goal);

    std::vector<std::string> EX2Cards1 = { "i", "water", "drink" };
    std::vector<std::string> EX2Cards2 = { "want", "to" };
    std::vector<std::string> EX2Goal = { "i", "want", "to", "drink", "water" };

    PrintResult(EX2Cards1, EX2Cards2, EX2Goal);
}
