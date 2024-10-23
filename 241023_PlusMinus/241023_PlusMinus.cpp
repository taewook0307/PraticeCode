// 241023_PlusMinus.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
주어진 숫자 배열에서 양수, 음수, 0의 비율을 차례대로 출력하시오
출력된 숫자는 6자리까지
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//string ltrim(const string&);
//string rtrim(const string&);
//vector<string> split(const string&);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr)
{
    const size_t NumCount = arr.size();

    size_t ZeroCount = 0;
    size_t MinusCount = 0;
    size_t PlusCount = 0;

    for (int Num : arr)
    {
        if (Num < 0)
        {
            ++MinusCount;
        }
        else if (Num > 0)
        {
            ++PlusCount;
        }
        else
        {
            ++ZeroCount;
        }
    }

    float ZeroPercent = ZeroCount / static_cast<float>(NumCount);
    float MinusPercent = MinusCount / static_cast<float>(NumCount);
    float PlusPercent = PlusCount / static_cast<float>(NumCount);

    cout << fixed;
    cout.precision(6);
    cout << PlusPercent << endl << MinusPercent << endl << ZeroPercent << endl;
}

int main()
{
    std::vector<int> arr = { 1, 2, 3, -1, -2, -3, 0, 0 };

    plusMinus(arr);

    return 0;
}
//
//string ltrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );
//
//    return s;
//}
//
//vector<string> split(const string& str) {
//    vector<string> tokens;
//
//    string::size_type start = 0;
//    string::size_type end = 0;
//
//    while ((end = str.find(" ", start)) != string::npos) {
//        tokens.push_back(str.substr(start, end - start));
//
//        start = end + 1;
//    }
//
//    tokens.push_back(str.substr(start));
//
//    return tokens;
//}