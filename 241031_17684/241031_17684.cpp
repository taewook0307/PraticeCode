// 241031_17684.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [3차] 압축

/*
문제 설명
신입사원 어피치는 카카오톡으로 전송되는 메시지를 압축하여 전송 효율을 높이는 업무를 맡게 되었다. 메시지를 압축하더라도 전달되는 정보가 바뀌어서는 안 되므로, 압축 전의 정보를 완벽하게 복원 가능한 무손실 압축 알고리즘을 구현하기로 했다.

어피치는 여러 압축 알고리즘 중에서 성능이 좋고 구현이 간단한 LZW(Lempel–Ziv–Welch) 압축을 구현하기로 했다. LZW 압축은 1983년 발표된 알고리즘으로, 이미지 파일 포맷인 GIF 등 다양한 응용에서 사용되었다.

LZW 압축은 다음 과정을 거친다.

    1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
    3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
    4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
    5. 단계 2로 돌아간다.

압축 알고리즘이 영문 대문자만 처리한다고 할 때, 사전은 다음과 같이 초기화된다. 사전의 색인 번호는 정수값으로 주어지며, 1부터 시작한다고 하자.

A B C D ... X  Y  Z
1 2 3 4 ... 24 25 26

예를 들어 입력으로 KAKAO가 들어온다고 하자.

1. 현재 사전에는 KAKAO의 첫 글자 K는 등록되어 있으나, 두 번째 글자까지인 KA는 없으므로, 첫 글자 K에 해당하는 색인 번호 11을 출력하고, 다음 글자인 A를 포함한 KA를 사전에 27 번째로 등록한다.
2. 두 번째 글자 A는 사전에 있으나, 세 번째 글자까지인 AK는 사전에 없으므로, A의 색인 번호 1을 출력하고, AK를 사전에 28 번째로 등록한다.
3. 세 번째 글자에서 시작하는 KA가 사전에 있으므로, KA에 해당하는 색인 번호 27을 출력하고, 다음 글자 O를 포함한 KAO를 29 번째로 등록한다.
4. 마지막으로 처리되지 않은 글자 O에 해당하는 색인 번호 15를 출력한다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::string msg)
{
    std::vector<int> answer;

    std::map<std::string, int> Dict;

    int Index = 1;

    std::string CurString = "A";

    for (int i = 1; i < 27; ++i)
    {
        Dict.insert(std::make_pair(CurString, i));
        CurString[0] += 1;
        ++Index;
    }

    const int InputCount = static_cast<int>(msg.size());

    for (int i = 0; i < InputCount;)
    {
        int LoopIndex = i;
        bool Flag = false;
        std::string CurString = msg.substr(i, 1);

        if (i == InputCount - 1)
        {
            answer.push_back(Dict[CurString]);
            break;
        }

        for (int j = i + 1; j < InputCount; ++j)
        {
            CurString += msg[j];

            if (Dict.find(CurString) != Dict.end())
            {
                if (j == InputCount - 1)
                {
                    answer.push_back(Dict[CurString]);
                    Flag = true;
                    break;
                }

                continue;
            }

            Dict.insert(std::make_pair(CurString, Index));
            ++Index;
            CurString.pop_back();

            answer.push_back(Dict[CurString]);
            LoopIndex = j;
            break;
        }

        i = LoopIndex;

        if (true == Flag)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution("KAKAO");
    std::vector<int> Result1 = solution("TOBEORNOTTOBEORTOBEORNOT");         // 20,15,2,5,15,18,14,15,20,27,29,31,36,30,32,34
    std::vector<int> Result2 = solution("ABABABABABABABAB");                 // 1,2,27,29,28,31,30
    std::vector<int> Result3 = solution("TOBEORNOTTOBEORTOBEORNOT");         // 20,8,1,20,27,29,9,19,33,31,30,28,20,33,14,15,39,19,41,43,36,9,39,46,38,47,34,19,36,52,45,40,42,35,38,48,62,54,51,61,53,55,66,57,44,59,64,32,49,60,29,52,76,37,32,71,43,70,47,75,73,80,43,79,56,72,84,61,86,68,81,90,69,92,72,85,63,96,89,87,91,83,101,94,103,65,97,106,99,108,50,74,111,77,66,98,81,70,93,118,117,88,33,122,116,58,127,62,127,78,114,123,100,133,95,112,105,104,132,145,87,134,130,129,137,131,82,79,148,151,150,144,153,159,102,135,121,156,159,125,75,162,113,158,124,109,126,149,67,142,146,166,155,158,174,171,140,119,128,175,120,138,152,161,174,181,139,154,141,187,143,176,165,172,167,191,164,182,194,184,136,170,193,147,86

    int a = 0;
}
