// 241025_Question01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int pageCount(int n, int p)
{
    int FrontPage = 0;

    int FrontDifference = p - 1;

    int DivideFrontDifference = FrontDifference / 2;
    int RemainFrontDifference = FrontDifference % 2;

    if (RemainFrontDifference != 0)
    {
        FrontPage = DivideFrontDifference + 1;
    }
    else
    {
        FrontPage = DivideFrontDifference;
    }
    
    int BackPage = 0;

    int BackDifference = n % 2 == 0 ? n - p + 1 : n - p;

    int DivideBackDifference = BackDifference / 2;

    BackPage = DivideBackDifference;

    return BackPage < FrontPage ? BackPage : FrontPage;
}

int main()
{
    std::cout << pageCount(7, 3) << std::endl;
    std::cout << pageCount(5, 3) << std::endl;
    std::cout << pageCount(5, 4) << std::endl;
    std::cout << pageCount(6, 2) << std::endl;
}



/*

1 ----- 1
2 ----- 2
3 ----- 2
4 ----- 3
5 ----- 3
6 ----- 4
7 ----- 4

7 ----- 0
6 ----- 0
5 ----- 1
4 ----- 1
3 ----- 2
2 ----- 2
1 ----- 3

*/