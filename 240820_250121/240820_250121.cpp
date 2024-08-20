// 240820_250121.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 데이터 분석

/*
문제 설명
AI 엔지니어인 현식이는 데이터를 분석하는 작업을 진행하고 있습니다.
데이터는 ["코드 번호(code)", "제조일(date)", "최대 수량(maximum)", "현재 수량(remain)"]으로 구성되어 있으며
현식이는 이 데이터들 중 조건을 만족하는 데이터만 뽑아서 정렬하려 합니다.

예를 들어 다음과 같이 데이터가 주어진다면
    data = [[1, 20300104, 100, 80], [2, 20300804, 847, 37], [3, 20300401, 10, 8]]

이 데이터는 다음 표처럼 나타낼 수 있습니다.

    code	  date	        maximum	        remain
      1	    20300104	      100	          80
      2	    20300804	      847	          37
      3	    20300401	      10	          8

주어진 데이터 중 "제조일이 20300501 이전인 물건들을 현재 수량이 적은 순서"로 정렬해야 한다면 조건에 맞게 가공된 데이터는 다음과 같습니다.
    data = [[3,20300401,10,8],[1,20300104,100,80]]

정렬한 데이터들이 담긴 이차원 정수 리스트 data와
어떤 정보를 기준으로 데이터를 뽑아낼지를 의미하는 문자열 ext,
뽑아낼 정보의 기준값을 나타내는 정수 val_ext,
정보를 정렬할 기준이 되는 문자열 sort_by가 주어집니다.

data에서 ext 값이 val_ext보다 작은 데이터만 뽑은 후,
sort_by에 해당하는 값을 기준으로 오름차순으로 정렬하여 return 하도록 solution 함수를 완성해 주세요.
단, 조건을 만족하는 데이터는 항상 한 개 이상 존재합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

int ReturnIndex(const std::string& _DataName)
{
    if ("code" == _DataName)
    {
        return 0;
    }
    else if ("date" == _DataName)
    {
        return 1;
    }
    else if ("maximum" == _DataName)
    {
        return 2;
    }
    else if ("remain" == _DataName)
    {
        return 3;
    }
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> data, std::string ext, int val_ext, std::string sort_by)
{
    std::vector<std::vector<int>> answer;
    const int DataCount = static_cast<int>(data.size());
    answer.reserve(DataCount);

    std::multimap<int, std::vector<int>> answerMap;

    int CompareCondition = ReturnIndex(ext);
    int SortCondition = ReturnIndex(sort_by);

    // 조건에 부합하는 Data 뽑기
    for (std::vector<int> CurData : data)
    {
        if (val_ext > CurData[CompareCondition])
        {
            answerMap.insert(std::make_pair(CurData[SortCondition], CurData));
        }
    }

    // 뽑은 Data 담기
    std::multimap<int, std::vector<int>>::iterator BeginIter = answerMap.begin();
    std::multimap<int, std::vector<int>>::iterator EndIter = answerMap.end();

    for (; BeginIter != EndIter; ++BeginIter)
    {
        answer.push_back(BeginIter->second);
    }

    return answer;
}

void PrintResult(std::vector<std::vector<int>> data, std::string ext, int val_ext, std::string sort_by)
{
    std::vector<std::vector<int>> answer = solution(data, ext, val_ext, sort_by);

    for (std::vector<int> CurData : answer)
    {
        printf_s("{ %d, %d, %d, %d }\n", CurData[0], CurData[1], CurData[2], CurData[3]);
    }
}

int main()
{
    std::vector<std::vector<int>> data0 = { { 1, 20300104, 100, 80 }, { 2, 20300804, 847, 37 }, { 3, 20300401, 10, 8 } };
    std::string ext0 = "date";
    int val_ext0 = 20300501;
    std::string sort_by0 = "remain";

    PrintResult(data0, ext0, val_ext0, sort_by0);
}
