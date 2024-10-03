// 241002_72411.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 메뉴 리뉴얼

/*
문제 설명
각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders,
"스카피"가 추가하고 싶어하는 코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때,
"스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.
(각 손님은 단품메뉴를 2개 이상 주문해야 하며, 각 단품메뉴는 A ~ Z의 알파벳 대문자로 표기합니다.)

단, 코스요리 메뉴는 최소 2가지 이상의 단품메뉴로 구성하려고 합니다.
또한, 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함하기로 했습니다.

제한 사항
 - orders 배열의 크기는 2 이상 20 이하
 - orders 배열의 각 원소는 크기가 2 이상 10 이하
 - course 배열의 크기는 1 이상 10 이하
 - 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬

ex)
1번 손님 A, B, C, D, E
2번 손님 A, C
3번 손님 C, D, E
4번 손님 A, C, D, E
5번 손님 B, C, F, G
6번 손님 A, C, D, E, H

코스 종류
요리 2개 코스 A, C
요리 3개 코스 C, D, E
요리 4개 코스 B, C, F, G
요리 4개 코스 A, C, D, E
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Course
{
public:
    Course(const std::string& _Value)
        : Order(_Value)
    {

    }

    std::set<std::string> MakeCourse(int _Count)
    {
        std::set<std::string> ReturnSet;

        if (_Count == 1)
        {
            for (char Menu : Order)
            {
                ReturnSet.insert(std::string(1, Menu));
            }

            return ReturnSet;
        }

        std::set<std::string> PrevSet = MakeCourse(_Count - 1);

        for (const std::string& Course : PrevSet)
        {
            char LastMenu = Course[Course.size() - 1];

            for (char Menu : Order)
            {
                std::string PlusCourse = Course;
                if (LastMenu < Menu)
                {
                    PlusCourse += Menu;
                    ReturnSet.insert(PlusCourse);
                }
            }
        }

        return ReturnSet;
    }

private:
    std::string Order = "";
};

struct OrderStandard
{
    bool operator() (const std::string& _Left, const std::string& _Right) const
    {
        if (_Left.size() == _Right.size())
        {
            return _Left < _Right;
        }
        else
        {
            return _Left.size() < _Right.size();
        }
    }
};

std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course)
{
    std::vector<std::string> answer;
    answer.reserve(orders.size());

    // 만든 조합과 조합을 가지고 있는 개수
    std::map<std::string, int, OrderStandard> CourseCount;

    for (std::string& Order : orders)
    {
        sort(Order.begin(), Order.end());
    }

    for (int Count : course)
    {
        // 현재 오더로 조합 만들기
        for (const std::string& Order : orders)
        {
            Course CurOrderCourse = Course(Order);
            std::set<std::string> CurOrderSet = CurOrderCourse.MakeCourse(Count);

            for (const std::string& MakeCourse : CurOrderSet)
            {
                if (CourseCount.end() != CourseCount.find(MakeCourse))
                {
                    CourseCount[MakeCourse] += 1;
                }
                else
                {
                    CourseCount.insert(std::make_pair(MakeCourse, 1));
                }
            }
        }
    }

    std::map<std::string, int>::iterator BeginIter = CourseCount.begin();
    std::map<std::string, int>::iterator EndIter = CourseCount.end();

    for (; BeginIter != EndIter;)
    {
        if (BeginIter->second == 1)
        {
            BeginIter = CourseCount.erase(BeginIter);
        }
        else
        {
            ++BeginIter;
        }
    }

    for (int CourseMenuCount : course)
    {
        std::map<std::string, int>::iterator BeginIter = CourseCount.begin();
        std::map<std::string, int>::iterator EndIter = CourseCount.end();

        int MaxCount = -1;
        std::vector<std::string> PlusFactor;
        PlusFactor.reserve(CourseCount.size());

        for (; BeginIter != EndIter; ++BeginIter)
        {
            if (CourseMenuCount == BeginIter->first.size())
            {
                if (MaxCount < BeginIter->second && 1 < BeginIter->second)
                {
                    PlusFactor.clear();
                    MaxCount = BeginIter->second;
                    PlusFactor.push_back(BeginIter->first);
                }
                else if (MaxCount == BeginIter->second)
                {
                    PlusFactor.push_back(BeginIter->first);
                }
                else
                {
                    continue;
                }
            }
            else if (CourseMenuCount < BeginIter->first.size())
            {
                break;
            }
        }

        for (const std::string& PlusCourse : PlusFactor)
        {
            answer.push_back(PlusCourse);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    std::vector<std::string> Orders3 = { "ABCD", "ABCD", "ABCD" };
    std::vector<int> Course3 = { 2,3,4 };
    std::vector<std::string> Result3 = solution(Orders3, Course3);

    std::vector<std::string> Orders0 = { "ABCFG", "AC", "EDC", "ACDE", "BCFG", "ACDEH" };
    std::vector<int> Course0 = { 2,3,4 };
    std::vector<std::string> Result0 = solution(Orders0, Course0);

    std::vector<std::string> Orders1 = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    std::vector<int> Course1 = { 2,3,5 };
    std::vector<std::string> Result1 = solution(Orders1, Course1);

    std::vector<std::string> Orders2 = { "XYZ", "XWY", "WXA" };
    std::vector<int> Course2 = { 2,3,4 };
    std::vector<std::string> Result2 = solution(Orders2, Course2);

    int a = 0;
}
