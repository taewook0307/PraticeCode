// 241001_72411.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
#include <map>
#include <set>
#include <algorithm>

//struct OrderStandard
//{
//    bool operator() (const std::string& _Left, const std::string& _Right) const
//    {
//        if (_Left.size() == _Right.size())
//        {
//            return _Left < _Right;
//        }
//        else
//        {
//            return _Left.size() < _Right.size();
//        }
//    }
//};
//
//std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course)
//{
//    std::vector<std::string> answer;
//    answer.reserve(orders.size());
//
//    // 오름차순으로 정렬
//    for (std::string& Order : orders)
//    {
//        sort(Order.begin(), Order.end());
//    }
//
//    // 만들어진 코스와 카운트 수
//    std::map<std::string, int, OrderStandard> Course;
//
//    // 코스 만들기 - 1
//    //const int OrdersCount = static_cast<int>(orders.size());
//
//    //for (int i = 0; i < OrdersCount; ++i)
//    //{
//    //    std::string StandardOrder = orders[i];
//    //    const int StandardOrderSize = static_cast<int>(StandardOrder.size());
//
//    //    for (int j = i + 1; j < OrdersCount; ++j)
//    //    {
//    //        std::string CheckOrder = orders[j];
//
//    //        std::string MakeCourse = "";
//
//    //        for (char Menu : StandardOrder)
//    //        {
//    //            if (std::string::npos != CheckOrder.find(Menu))
//    //            {
//    //                // 기준 둘 다 가지고 있으면 MakeCourse에 추가
//    //                MakeCourse.push_back(Menu);
//    //            }
//
//    //            // 만들어진 코스 길이가 2이상이면 map에 추가
//    //            if (2 <= MakeCourse.size())
//    //            {
//    //                Course.insert(std::make_pair(MakeCourse, 0));
//    //            }
//    //        }
//    //    }
//    //}
//
//    // 코스 만들기 - 2
//    //for (int CourseCount : course)
//    //{
//    //    for (const std::string& Order : orders)
//    //    {
//    //        std::string MakeCourse = "";
//    //        const size_t MenuCount = Order.size();
//
//    //        if (CourseCount > Order.size())
//    //        {
//    //            continue;
//    //        }
//
//    //        for (int i = 0; i < MenuCount - CourseCount + 1; ++i)
//    //        {
//    //            MakeCourse = Order.substr(i, CourseCount - 1);
//
//    //            for (int j = i + MakeCourse.size(); j < MenuCount; ++j)
//    //            {
//    //                std::string PlusCourse = MakeCourse;
//    //                PlusCourse.push_back(Order[j]);
//
//    //                Course.insert(std::make_pair(PlusCourse, 0));
//    //            }
//    //        }
//    //    }
//    //}
//
//    // 코스 만들기 - 3
//    //int MaxCourseCount = course[course.size() - 1];
//    //std::vector<std::set<std::string>> AllCourse;
//    //AllCourse.resize(MaxCourseCount);
//
//    //for (const std::string& Order : orders)
//    //{
//    //    for (int i = 0; i < MaxCourseCount; ++i)
//    //    {
//    //        std::set<std::string> MakeCourse = AllCourse[i];
//
//    //        const size_t OrderSize = Order.size();
//
//    //        if (i > 0)
//    //        {
//    //            const std::set<std::string>& PrevSet = AllCourse[i - 1];
//
//    //            for (const std::string& CurCourse : PrevSet)
//    //            {
//    //                char LastChar = CurCourse[CurCourse.size() - 1];
//
//    //                for (char Menu : Order)
//    //                {
//    //                    if (Menu > LastChar)
//    //                    {
//    //                        std::string PlusCourse = CurCourse;
//    //                        PlusCourse.push_back(Menu);
//    //                        MakeCourse.insert(PlusCourse);
//    //                    }
//    //                }
//    //            }
//    //        }
//    //        else
//    //        {
//    //            for (size_t i = 0; i < OrderSize; i++)
//    //            {
//    //                std::string PlusCourse = Order.substr(i, 1);
//    //                MakeCourse.insert(PlusCourse);
//    //            }
//    //        }
//
//    //        AllCourse[i] = MakeCourse;
//    //    }
//    //}
//
//    //for (int CourseCount : course)
//    //{
//    //    std::set<std::string>& Courses = AllCourse[CourseCount - 1];
//
//    //    for (const std::string& CurCourse : Courses)
//    //    {
//    //        Course.insert(std::make_pair(CurCourse, 0));
//    //    }
//    //}
//
//    // 코스 만들기 - 4
//    std::string AllMenu = "";
//
//    for (const std::string& Order : orders)
//    {
//        for (char Menu : Order)
//        {
//            if (std::string::npos == AllMenu.find(Menu))
//            {
//                AllMenu += Menu;
//            }
//        }
//    }
//
//    sort(AllMenu.begin(), AllMenu.end());
//
//    int MaxCourseCount = course[course.size() - 1];
//    std::vector<std::set<std::string>> AllCourse;
//    AllCourse.resize(MaxCourseCount);
//
//    for (const std::string& Order : orders)
//    {
//        for (int i = 0; i < MaxCourseCount; ++i)
//        {
//            std::set<std::string> MakeCourse = AllCourse[i];
//
//            const size_t OrderSize = Order.size();
//
//            if (i > 0)
//            {
//                const std::set<std::string>& PrevSet = AllCourse[i - 1];
//
//                for (const std::string& CurCourse : PrevSet)
//                {
//                    char LastChar = CurCourse[CurCourse.size() - 1];
//
//                    for (char Menu : Order)
//                    {
//                        if (Menu > LastChar)
//                        {
//                            std::string PlusCourse = CurCourse;
//                            PlusCourse.push_back(Menu);
//                            MakeCourse.insert(PlusCourse);
//                        }
//                    }
//                }
//            }
//            else
//            {
//                for (size_t i = 0; i < OrderSize; i++)
//                {
//                    std::string PlusCourse = Order.substr(i, 1);
//                    MakeCourse.insert(PlusCourse);
//                }
//            }
//
//            AllCourse[i] = MakeCourse;
//        }
//    }
//
//    for (int CourseCount : course)
//    {
//        std::set<std::string>& Courses = AllCourse[CourseCount - 1];
//
//        for (const std::string& CurCourse : Courses)
//        {
//            Course.insert(std::make_pair(CurCourse, 0));
//        }
//    }
//
//    // 해당 코스요리를 포함하는 주문 수 계산
//    for (const std::string& Order : orders)
//    {
//        std::map<std::string, int>::iterator BeginIter = Course.begin();
//        std::map<std::string, int>::iterator EndIter = Course.end();
//
//        for (; BeginIter != EndIter; ++BeginIter)
//        {
//            bool IsOrder = true;
//
//            for (char Menu : BeginIter->first)
//            {
//                if (std::string::npos == Order.find(Menu))
//                {
//                    IsOrder = false;
//                }
//            }
//
//            if (true == IsOrder)
//            {
//                BeginIter->second += 1;
//            }
//        }
//    }
//
//    for (int CourseMenuCount : course)
//    {
//        std::map<std::string, int>::iterator BeginIter = Course.begin();
//        std::map<std::string, int>::iterator EndIter = Course.end();
//
//        int MaxCount = -1;
//        std::vector<std::string> PlusFactor;
//        PlusFactor.reserve(Course.size());
//
//        for (; BeginIter != EndIter; ++BeginIter)
//        {
//            if (CourseMenuCount == BeginIter->first.size()) 
//            {
//                if (MaxCount < BeginIter->second && 1 < BeginIter->second)
//                {
//                    PlusFactor.clear();
//                    MaxCount = BeginIter->second;
//                    PlusFactor.push_back(BeginIter->first);
//                }
//                else if (MaxCount == BeginIter->second)
//                {
//                    PlusFactor.push_back(BeginIter->first);
//                }
//                else
//                {
//                    continue;
//                }
//            }
//            else if (CourseMenuCount < BeginIter->first.size())
//            {
//                break;
//            }
//        }
//
//        for (const std::string& PlusCourse : PlusFactor)
//        {
//            answer.push_back(PlusCourse);
//        }
//    }
//
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}

//std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course)
//{
//    std::vector<std::string> answer;
//    answer.reserve(orders.size());
//
//    const size_t CourseSize = course.size();
//
//    // 주문이 들어온 메뉴 확인
//    std::set<std::string> OrderedAllMenu;
//
//    for (const std::string& Order : orders)
//    {
//        const size_t MenuCount = Order.size();
//
//        for (size_t i = 0; i < MenuCount; i++)
//        {
//            std::string CurMenu = Order.substr(i, 1);
//            OrderedAllMenu.insert(CurMenu);
//        }
//    }
//
//    // 메뉴로 만들 수 있는 모든 조합 만들기
//    int MaxCourseCount = course[course.size() - 1];
//    std::vector<std::set<std::string>> AllCourse;
//    AllCourse.resize(MaxCourseCount);
//    AllCourse[0] = OrderedAllMenu;
//
//    for (const std::string& Order : orders)
//    {
//        for (int i = 1; i < MaxCourseCount; ++i)
//        {
//            std::set<std::string> MakeCourse = AllCourse[i];
//            const std::set<std::string>& PrevSet = AllCourse[i - 1];
//
//            const size_t OrderSize = Order.size();
//
//            for (const std::string& CurCourse : PrevSet)
//            {
//                char LastChar = CurCourse[CurCourse.size() - 1];
//
//                for (char Menu : Order)
//                {
//                    if (Menu > LastChar)
//                    {
//                        std::string PlusCourse = CurCourse;
//                        PlusCourse.push_back(Menu);
//                        MakeCourse.insert(PlusCourse);
//                    }
//                }
//            }
//
//            AllCourse[i] = MakeCourse;
//        }
//    }
//
//    std::map<std::string, int, OrderStandard> Course;
//
//    // 만들어진 조합 중 2개 이상 포함되는 주문 내용은 Course에 추가
//    for (int CourseCount : course)
//    {
//        std::set<std::string> CountAllCourse = AllCourse[CourseCount - 1];
//        
//        std::set<std::string>::iterator BeginIter = CountAllCourse.begin();
//        std::set<std::string>::iterator EndIter = CountAllCourse.end();
//
//        for (; BeginIter != EndIter; ++BeginIter)
//        {
//            int Count = 0;
//
//            for (const std::string& Order : orders)
//            {
//                bool IsOrder = true;
//
//                for (char Menu : *BeginIter)
//                {
//                    if (std::string::npos == Order.find(Menu))
//                    {
//                        IsOrder = false;
//                    }
//                }
//
//                if (true == IsOrder)
//                {
//                    ++Count;
//                }
//            }
//
//            if (Count > 1)
//            {
//                Course.insert(std::make_pair(*BeginIter, Count));
//            }
//        }
//    }
//
//    // 해당 조합 중 가장 많은 Course 요리 추가
//    for (int CourseMenuCount : course)
//    {
//        std::map<std::string, int>::iterator BeginIter = Course.begin();
//        std::map<std::string, int>::iterator EndIter = Course.end();
//
//        int MaxCount = -1;
//        std::vector<std::string> PlusFactor;
//        PlusFactor.reserve(Course.size());
//
//        for (; BeginIter != EndIter; ++BeginIter)
//        {
//            if (CourseMenuCount == BeginIter->first.size())
//            {
//                if (MaxCount < BeginIter->second && 1 < BeginIter->second)
//                {
//                    PlusFactor.clear();
//                    MaxCount = BeginIter->second;
//                    PlusFactor.push_back(BeginIter->first);
//                }
//                else if (MaxCount == BeginIter->second)
//                {
//                    PlusFactor.push_back(BeginIter->first);
//                }
//                else
//                {
//                    continue;
//                }
//            }
//            else if (CourseMenuCount < BeginIter->first.size())
//            {
//                break;
//            }
//        }
//
//        for (const std::string& PlusCourse : PlusFactor)
//        {
//            answer.push_back(PlusCourse);
//        }
//    }
//
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}

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

    std::set<char> OverlapMenu;
    std::set<std::string> OverlapMenuString;

    const size_t OrderCount = orders.size();

    // 주문서 중 한 번이라도 겹치는 메뉴 확인
    for (size_t i = 0; i < OrderCount - 1; ++i)
    {
        std::string StandardOrder = orders[i];

        for (size_t j = i + 1; j < OrderCount; ++j)
        {
            std::string CheckOrder = orders[j];

            for (char Menu : CheckOrder)
            {
                if (std::string::npos != StandardOrder.find(Menu))
                {
                    OverlapMenu.insert(Menu);
                    OverlapMenuString.insert(std::string(1, Menu));
                }
            }
        }
    }

    // 한 번이라도 겹친 메뉴들로 만들 수 있는 모든 조합 제조
    int MaxCourseCount = course[course.size() - 1];
    std::vector<std::set<std::string>> AllCourse;
    AllCourse.resize(MaxCourseCount);
    AllCourse[0] = OverlapMenuString;

    for (int i = 1; i < MaxCourseCount; ++i)
    {
        std::set<std::string> MakeCourse = AllCourse[i];
        const std::set<std::string>& PrevSet = AllCourse[i - 1];

        for (const std::string& CurCourse : PrevSet)
        {
            char LastChar = CurCourse[CurCourse.size() - 1];

            for (char Menu : OverlapMenu)
            {
                if (Menu > LastChar)
                {
                    std::string PlusCourse = CurCourse;
                    PlusCourse.push_back(Menu);
                    MakeCourse.insert(PlusCourse);
                }
            }
        }

        AllCourse[i] = MakeCourse;
    }

    // 만들어진 조합 중 2개 이상 포함되는 주문 내용은 Course에 추가
    std::map<std::string, int, OrderStandard> Course;

    for (int CourseCount : course)
    {
        std::set<std::string> CountAllCourse = AllCourse[CourseCount - 1];

        std::set<std::string>::iterator BeginIter = CountAllCourse.begin();
        std::set<std::string>::iterator EndIter = CountAllCourse.end();

        int MaxCount = -1;

        for (; BeginIter != EndIter; ++BeginIter)
        {
            int Count = 0;

            for (const std::string& Order : orders)
            {
                bool IsOrder = true;

                for (char Menu : *BeginIter)
                {
                    if (std::string::npos == Order.find(Menu))
                    {
                        IsOrder = false;
                        break;
                    }
                }

                if (true == IsOrder)
                {
                    ++Count;
                }
            }

            if (Count > 1)
            {
                // 이미 들어간 문자 중 최대 크기의 문자보다 큰 경우만 insert
                if (Count >= MaxCount)
                {
                    Course.insert(std::make_pair(*BeginIter, Count));
                    MaxCount = Count;
                }                
            }
        }
    }

    // 해당 조합 중 가장 많은 Course 요리 추가
    for (int CourseMenuCount : course)
    {
        std::map<std::string, int>::iterator BeginIter = Course.begin();
        std::map<std::string, int>::iterator EndIter = Course.end();

        int MaxCount = -1;
        std::vector<std::string> PlusFactor;
        PlusFactor.reserve(Course.size());

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

    // 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    std::vector<std::string> Orders0 = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    std::vector<int> Course0 = { 2,3,4 };
    std::vector<std::string> Result0 = solution(Orders0, Course0);

    std::vector<std::string> Orders1 = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    std::vector<int> Course1 = { 2,3,5 };
    std::vector<std::string> Result1 = solution(Orders1, Course1);

    std::vector<std::string> Orders2 = { "XYZ", "XWY", "WXA" };
    std::vector<int> Course2 = { 2,3,4 };
    std::vector<std::string> Result2 = solution(Orders2, Course2);

    std::vector<std::string> Orders3 = { "ABCD", "ABCD", "ABCD" };
    std::vector<int> Course3 = { 2,3,4 };
    std::vector<std::string> Result3 = solution(Orders3, Course3);

    int a = 0;
}
