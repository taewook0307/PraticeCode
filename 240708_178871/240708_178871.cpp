// 240708_178871.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 달리기 경주

/*
문제 설명
얀에서는 매년 달리기 경주가 열립니다.
해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다.
예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때,
해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다.
즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.

선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 players와
해설진이 부른 이름을 담은 문자열 배열 callings가
매개변수로 주어질 때, 경주가 끝났을 때 선수들의 이름을
1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 무조건 시간초과되는 풀이 ------------------------------------------------------------------------------------------------
//std::vector<std::string> solution(std::vector<std::string> players, std::vector<std::string> callings) {
//    std::vector<std::string> answer;
//
//    const int playersSize = players.size();
//    answer.reserve(playersSize);
//
//    for (std::string CallPlayer : callings)
//    {
//        int Index = find(players.begin(), players.end(), CallPlayer) - players.begin();
//
//        std::string Temp = players[Index];
//        players[Index] = players[Index - 1];
//        players[Index - 1] = Temp;
//    }
//
//    for (std::string player : players)
//    {
//        answer.push_back(player);
//    }
//
//    return answer;
//}
//--------------------------------------------------------------------------------------------------------------------------

std::vector<std::string> solution(std::vector<std::string> players, std::vector<std::string> callings)
{
    std::vector<std::string> answer;

    

    return answer;
}

void PrintResult(std::vector<std::string> players, std::vector<std::string> callings)
{
    std::vector<std::string> Result = solution(players, callings);

    const int Size = Result.size();

    for (int i = 0; i < Size; ++i)
    {
        std::cout << i << " : " << Result[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> players = { "mumu", "soe", "poe", "kai", "mine" };
    std::vector<std::string> callings = { "kai", "kai", "mine", "mine" };

    PrintResult(players, callings);
}