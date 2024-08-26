// 240826_176963.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 추억점수

/*
문제 설명
사진들을 보며 추억에 젖어 있던 루는 사진별로 추억 점수를 매길려고 합니다.
사진 속에 나오는 인물의 그리움 점수를 모두 합산한 값이 해당 사진의 추억 점수가 됩니다.

예를 들어 사진 속 인물의 이름이 ["may", "kein", "kain"]이고 각 인물의 그리움 점수가 [5점, 10점, 1점]일 때 해당 사진의 추억 점수는 16(5 + 10 + 1)점이 됩니다.
다른 사진 속 인물의 이름이 ["kali", "mari", "don", "tony"]이고 ["kali", "mari", "don"]의 그리움 점수가 각각 [11점, 1점, 55점]]이고,
"tony"는 그리움 점수가 없을 때, 이 사진의 추억 점수는 3명의 그리움 점수를 합한 67(11 + 1 + 55)점입니다.

그리워하는 사람의 이름을 담은 문자열 배열 name,
각 사람별 그리움 점수를 담은 정수 배열 yearning,
각 사진에 찍힌 인물의 이름을 담은 이차원 문자열 배열 photo가 매개변수로 주어질 때,
사진들의 추억 점수를 photo에 주어진 순서대로 배열에 담아 return하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> name, std::vector<int> yearning, std::vector<std::vector<std::string>> photo)
{
    const int photoCount = static_cast<int>(photo.size());

    std::vector<int> answer;
    answer.reserve(photoCount);

    // 사람과 점수 Mapping
    std::unordered_map<std::string, int> ScoreMap;
    
    const int nameCount = static_cast<int>(name.size());

    for (int i = 0; i < nameCount; ++i)
    {
        ScoreMap.insert(std::make_pair(name[i], yearning[i]));
    }

    // 사진별 점수 구하기
    for (const std::vector<std::string>& CurPhoto : photo)
    {
        int Score = 0;
        const int CurPhotoPeople = static_cast<int>(CurPhoto.size());

        for (int i = 0; i < CurPhotoPeople; ++i)
        {
            int PersonScore = ScoreMap[CurPhoto[i]];

            Score += PersonScore;
        }

        answer.push_back(Score);
    }

    return answer;
}

void PrintResult(const std::vector<std::string>& name, const std::vector<int>& yearning, const std::vector<std::vector<std::string>>& photo)
{
    std::vector<int> Result = solution(name, yearning, photo);

    std::cout << "Result : ";

    for (int Score : Result)
    {
        std::cout << Score << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> name0 = { "may", "kein", "kain", "radi" };
    std::vector<int> yearning0 = { 5, 10, 1, 3 };
    std::vector<std::vector<std::string>> photo0 = { { "may", "kein", "kain", "radi" }, { "may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" } };

    PrintResult(name0, yearning0, photo0);
}
