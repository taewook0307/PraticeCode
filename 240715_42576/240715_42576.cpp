// 240715_42576.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 완주하지 못한 선수

/*
문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다.
단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와
완주한 선수들의 이름이 담긴 배열 completion이 주어질 때,
완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

std::string solution(std::vector<std::string> participant, std::vector<std::string> completion)
{
    std::string answer = "";

    std::unordered_multiset<std::string> ParticipantSet;

    for (const std::string& ParticipantName : participant)
    {
        ParticipantSet.insert(ParticipantName);
    }

    for (const std::string& CompletionName : completion)
    {
        std::unordered_multiset<std::string>::iterator FindIter = ParticipantSet.find(CompletionName);

        if (ParticipantSet.end() == FindIter)
        {
            continue;
        }

        ParticipantSet.erase(FindIter);
    }

    answer = ParticipantSet.begin()->c_str();

    return answer;
}

void PrintResult(const std::vector<std::string>& participant, const std::vector<std::string>& completion)
{
    std::string Result = solution(participant, completion);
    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<std::string> Participant0 = { "leo", "kiki", "eden" };
    std::vector<std::string> Completion0 = { "eden", "kiki" };

    PrintResult(Participant0, Completion0);

    std::vector<std::string> Participant1 = { "leo", "kiki", "eden", "eden", "Kevin"};
    std::vector<std::string> Completion1 = { "eden", "kiki", "leo", "Kevin" };

    PrintResult(Participant1, Completion1);

    std::vector<std::string> Participant2 = { "leo", "kiki", "eden", "eden", "evan" };
    std::vector<std::string> Completion2 = { "Kevin", "eden", "kiki", "leo" };

    PrintResult(Participant2, Completion2);
}
