// Question01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'beautifulPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 */

int beautifulPairs(vector<int> A, vector<int> B)
{
    int MaxAValue = *max_element(A.begin(), A.end());
    int MaxBValue = *max_element(B.begin(), B.end());

    int MaxValue = MaxAValue > MaxBValue ? MaxAValue : MaxBValue;
    int LittleValue = MaxAValue > MaxBValue ? MaxBValue : MaxAValue;

    std::vector<int> ACount(MaxValue + 1, 0);
    std::multimap<int, int> AIndex;

    std::vector<int> BCount(MaxValue + 1, 0);
    std::multimap<int, int> BIndex;

    int Index = 0;

    for (int NumA : A)
    {
        ++ACount[NumA];
        AIndex.insert(std::make_pair(NumA, Index));
        ++Index;
    }

    Index = 0;
    for (int NumB : B)
    {
        ++BCount[NumB];
        BIndex.insert(std::make_pair(NumB, Index));
        ++Index;
    }

    int Result = 0;

    for (size_t i = 0; i < MaxValue + 1; ++i)
    {
        Result += (ACount[i] * BCount[i]);
    }

    return Result;
}

int main()
{
    int result = beautifulPairs({ 3, 5, 7, 11, 5, 8 }, { 5, 7, 11, 10, 5, 8 });

    cout << result << "\n";
    return 0;
}
