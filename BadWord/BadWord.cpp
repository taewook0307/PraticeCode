// BadWord.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 욕 거르기

// 욕설 input이 들어옴
// 1. input 개수
// 2. 욕이 들어옴
//
// 씨발
// 개새끼
// 씨발련
//
// 만약 욕설 리스트에 해당 욕이 없다면 저장함.
// 근데 여기서 욕설 리스트에 있는 욕설을 포함하는 욕설을 출력해야함.
//
// 씨발    <- 리스트에 없으므로 리스트에 저장
// 개새끼 <- 리스트에 없으므로 리스트에 저장
// 씨발련 <- 욕설 리스트에 저장된 씨발을 포함하는 욕설이므로 출력
//
// 체크된 욕설을 출력되는 프로그램을 짜시오.

#include <iostream>
#include <string>
#include <vector>

void Filter(const std::vector<std::string>& _Input)
{
    std::vector<std::string> FilterList;
    FilterList.reserve(_Input.size());

    for (const std::string& CheckWord : _Input)
    {
        const int FilterListSize = FilterList.size();

        if (FilterListSize == 0)
        {
            FilterList.push_back(CheckWord);
            continue;
        }

        for (int i = 0; i < FilterListSize; ++i)
        {
            if (std::string::npos == CheckWord.find(FilterList[i]))
            {
                if (i == FilterListSize - 1)
                {
                    FilterList.push_back(CheckWord);
                }
            }
            else
            {
                std::cout << CheckWord << std::endl;
                break;
            }
        }
    }
}

int main()
{
    std::vector<std::string> Input = { "abcd", "abcde", "sdkfkkoxcc", "dkfuds", "kdgugs", "dkfdu", "dsf", "dkjfgusdgg", "dkdkfdufd", "kkoxcc" };

    Filter(Input);

    std::cout << std::endl << "Input2" << std::endl;

    std::vector<std::string> Input2 =
    {
    "ecv", "pzy", "vi", "mj", "jg", "dxd", "lr", "imo", "iz", "dnz", "gy", "os", "nif",
    "yh", "guc", "dd", "vt", "huh", "vxw", "hmx", "ob", "bo", "yc", "ek", "bvi", "mn",
    "sb", "qs", "jr", "yp", "rd", "xse", "gzd", "ngg", "ns", "su", "gu", "vn", "pw",
    "wek", "xi", "hyb", "yn", "uy", "dj", "sn", "vw", "nf", "ig", "hv"
    };

    Filter(Input2);
}
