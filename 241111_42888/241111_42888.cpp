// 241111_42888.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 오픈채팅방

/*
문제설명
채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때,
모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.

채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메시지가 출력된다.

"Muzi님이 들어왔습니다."
"Prodo님이 들어왔습니다."

채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.

"Muzi님이 들어왔습니다."
"Prodo님이 들어왔습니다."
"Muzi님이 나갔습니다."

Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."
"Prodo님이 들어왔습니다."
"Prodo님이 나갔습니다."
"Prodo님이 들어왔습니다."

채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다.
이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."
"Ryan님이 들어왔습니다."
"Prodo님이 나갔습니다."
"Prodo님이 들어왔습니다."
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

std::vector<std::string> solution(std::vector<std::string> record)
{
    std::vector<std::string> answer;

    std::map<std::string, std::string> NickNames;
    std::queue<std::pair<char, std::string>> Records;

    for (const std::string& CurRecord : record)
    {
        char Action = CurRecord[0];

        int IdStart = CurRecord.find_first_of(' ');
        int IdEnd = CurRecord.find_last_of(' ');

        std::string id = CurRecord.substr(IdStart + 1, IdEnd - IdStart - 1);
        std::string NickName = CurRecord.substr(IdEnd + 1);

        if (Action == 'E' || Action == 'C')
        {
            NickNames[id] = NickName;
        }
        Records.push(std::make_pair(Action, id));
    }

    answer.reserve(Records.size());

    while (false == Records.empty())
    {
        std::pair<char, std::string> PushRecord = Records.front();
        Records.pop();

        char Action = PushRecord.first;

        switch (Action)
        {
        case 'E':
        {
            std::string PushValue = NickNames[PushRecord.second] + "님이 들어왔습니다.";
            answer.push_back(PushValue);
            break;
        }
        case 'L':
        {
            std::string PushValue = NickNames[PushRecord.second] + "님이 나갔습니다.";
            answer.push_back(PushValue);
            break;
        }
        default:
            break;
        }
    }

    return answer;
}

int main()
{
    std::vector<std::string> Result = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}
