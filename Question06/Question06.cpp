// Question06.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string isValid(std::string s)
{
    std::map<char, int> CharCount;

    for (char C : s)
    {
        if (CharCount.find(C) != CharCount.end())
        {
            ++CharCount[C];
        }
        else
        {
            CharCount.insert(std::make_pair(C, 1));
        }
    }

    std::vector<int> Count(s.size() + 1, 0);

    for (const std::pair<char, int>& Pair : CharCount)
    {
        ++Count[Pair.second];
    }

    int MaxCount = std::max_element(Count.begin(), Count.end()) - Count.begin();
    int DifferenceCount = 0;

    for (const std::pair<char, int>& Pair : CharCount)
    {
        if (Pair.second != MaxCount)
        {
            if (Pair.second - MaxCount <= 1)
            {
                ++DifferenceCount;
            }
            else
            {
                DifferenceCount += abs(Pair.second - MaxCount);
            }
        }
    }

    if (DifferenceCount <= 1)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    std::cout << isValid("ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd");
}

// aabbccd  Yes
// aabbcd   No