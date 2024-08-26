// 240805_72410.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 신규 아이디 추천

/*
문제 설명
카카오에 입사한 신입 개발자 네오는 "카카오계정개발팀"에 배치되어, 카카오 서비스에 가입하는 유저들의 아이디를 생성하는 업무를 담당하게 되었습니다.
"네오"에게 주어진 첫 업무는 새로 가입하는 유저들이 카카오 아이디 규칙에 맞지 않는 아이디를 입력했을 때, 입력된 아이디와 유사하면서 규칙에 맞는 아이디를 추천해주는 프로그램을 개발하는 것입니다.
다음은 카카오 아이디의 규칙입니다.

    아이디의 길이는 3자 이상 15자 이하여야 합니다.
    아이디는 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 문자만 사용할 수 있습니다.
    단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.

"네오"는 다음과 같이 7단계의 순차적인 처리 과정을 통해 신규 유저가 입력한 아이디가 카카오 아이디 규칙에 맞는 지 검사하고 규칙에 맞지 않은 경우 규칙에 맞는 새로운 아이디를 추천해 주려고 합니다.
신규 유저가 입력한 아이디를 나타내는 new_id가 매개변수로 주어질 때, "네오"가 설계한 7단계의 처리 과정을 거친 후의 추천 아이디를 return 하도록 solution 함수를 완성해 주세요.

    1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
         만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

bool CheckAvailable(const char _Value)
{
    if ('a' <= _Value && 'z' >= _Value
        || '0' <= _Value && '9' >= _Value
        || '-' == _Value
        || '_' == _Value
        || '.' == _Value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string solution(std::string new_id) {
    std::string answer = "";
    std::deque<char> Change_Id;

    char PrevChar = NULL;

    const int new_idSize = new_id.size();

    for (int i = 0; i < new_idSize; ++i)
    {
        // 1단계
        new_id[i] = std::tolower(new_id[i]);
        
        //2단계
        if (false == CheckAvailable(new_id[i]))
        {
            continue;
        }

        //3단계
        if (NULL != PrevChar && '.' == PrevChar && '.' == new_id[i])
        {
            continue;
        }

        Change_Id.push_back(new_id[i]);
        PrevChar = new_id[i];
    }

    // 4단계
    while (false == Change_Id.empty() && '.' == Change_Id.front())
    {
        Change_Id.pop_front();
    }

    while (false == Change_Id.empty() && '.' == Change_Id.back())
    {
        Change_Id.pop_back();
    }

    // 5단계
    if (0 == Change_Id.size())
    {
        Change_Id.push_back('a');
    }

    // 6단계
    while (15 < Change_Id.size())
    {
        Change_Id.pop_back();
    }

    // 7단계
    while (3 > Change_Id.size())
    {
        char LastChar = Change_Id.back();

        Change_Id.push_back(LastChar);
    }

    // 4단계
    while (false == Change_Id.empty() && '.' == Change_Id.front())
    {
        Change_Id.pop_front();
    }

    while (false == Change_Id.empty() && '.' == Change_Id.back())
    {
        Change_Id.pop_back();
    }

    while (false == Change_Id.empty())
    {
        char CurChar = Change_Id.front();

        answer += CurChar;
        Change_Id.pop_front();
    }

    return answer;
}

void PrintResult(const std::string& new_id)
{
    std::string Result = solution(new_id);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::string New_ID_0 = "...405Ab#*&^(ECdf.";
    PrintResult(New_ID_0);

    std::string New_ID_1 = "abcdefghijklmn.p";
    PrintResult(New_ID_1);
}
