// 240806_92334.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 신고 결과 받기

/*
문제 설명
신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.

각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
    신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
    한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
    유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.

이용자의 ID가 담긴 문자열 배열 id_list,
각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report,
정지 기준이 되는 신고 횟수 k가 매개변수로 주어질 때,
각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> id_list, std::vector<std::string> report, int k)
{
    const int id_listCount = id_list.size();
    std::vector<int> answer(id_listCount);

    // 플레이어와 인덱스 맵핑
    std::unordered_map<std::string, int> IdMap;

    for (int i = 0; i < id_listCount; ++i)
    {
        IdMap.insert(std::make_pair(id_list[i], i));
    }

    // report 중복 내용 제거 다른 방법
    //std::sort(report.begin(), report.end());
    //report.erase(std::unique(report.begin(), report.end()), report.end());

    // report 중복 내용 제거
    std::set<std::string> ReportSet;
    for (const std::string& ReportContent : report)
    {
        ReportSet.insert(ReportContent);
    }

    // 신고된 횟수
    std::vector<int> ReportCount(id_listCount);

    // 정지당한 플레이어
    std::set<std::string> BannedPlayer;

    // report 내용
    std::unordered_multimap<std::string, std::string> Report;

    for (const std::string& ReportList : ReportSet)
    {
        size_t BlankIndex = ReportList.find(' ');

        // 신고자와 피신고인으로 구별
        std::string Reporter = ReportList.substr(0, BlankIndex);
        std::string ReportedPlayer = ReportList.substr(BlankIndex + 1, ReportList.size() - BlankIndex);

        Report.insert(std::make_pair(ReportedPlayer, Reporter));

        int Index = IdMap[ReportedPlayer];
        ++ReportCount[Index];

        if (k <= ReportCount[Index])
        {
            BannedPlayer.insert(ReportedPlayer);
        }
    }

    std::unordered_multimap<std::string, std::string>::iterator StartIter = Report.begin();
    std::unordered_multimap<std::string, std::string>::iterator EndIter = Report.end();

    for (; StartIter != EndIter; ++StartIter)
    {
        if (BannedPlayer.end() != BannedPlayer.find(StartIter->first))
        {
            int Index = IdMap[StartIter->second];

            ++answer[Index];
        }
    }
    
    return answer;
}

void PrintResult(const std::vector<std::string>& id_list, const std::vector<std::string>& report, int k)
{
    std::vector<int> Result = solution(id_list, report, k);

    const int ResultSize = Result.size();

    std::cout << "Result : [ ";

    for (int i = 0; i < ResultSize; ++i)
    {
        if (i < ResultSize - 1)
        {
            std::cout << Result[i] << ", ";
        }
        else
        {
            std::cout << Result[i] << " ]";
        }
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> id_list_ex1 = { "muzi", "frodo", "apeach", "neo" };
    std::vector<std::string> report_ex1 = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi", "muzi frodo", "muzi frodo" };

    PrintResult(id_list_ex1, report_ex1, 2);
}
