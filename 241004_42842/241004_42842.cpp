// 241004_42842.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 카펫

/*
문제 설명
Leo는 카펫을 사러 갔다가 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown,
노란색 격자의 수 yellow가 매개변수로 주어질 때
카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

- 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다
*/

#include <iostream>
#include <vector>

std::vector<int> solution(int brown, int yellow)
{
    //std::vector<int> answer;
    //answer.reserve(2);

    //for (int i = 1; i <= yellow; ++i)
    //{
    //    if (0 == yellow % i)
    //    {
    //        int Quotient = yellow / i;

    //        int OutlineCount = i * 2 + (Quotient + 2) * 2;

    //        if (OutlineCount == brown)
    //        {
    //            int RowCount = (i + 2) <= (Quotient + 2) ? (Quotient + 2) : (i + 2);
    //            int ColumnCount = (i + 2) <= (Quotient + 2) ? (i + 2) : (Quotient + 2);

    //            answer.push_back(RowCount);
    //            answer.push_back(ColumnCount);
    //            break;
    //        }
    //    }
    //}

    //return answer;
    
    // 다른 사람 풀이 -------------------------------------------------------------------------
    // 가로 길이 * 세로 길이 = Brown 갯수 + Yellow 갯수

    //      (가로 + 세로)의 갯수
    int len = brown / 2 + 2;

    // 가로 길이 최댓값
    int Wide = len - 3;
    // 세로 길이 최소값
    int Height = 3;

    while (Wide >= Height)
    {
        if (Wide * Height == (brown + yellow))
        {
            break;
        }

        --Wide;
        ++Height;
    }

    return std::vector<int>{Wide, Height};
}

int main()
{
    std::vector<int> Carpet0 = solution(10, 2);
    std::vector<int> Carpet1 = solution(8, 1);
    std::vector<int> Carpet2 = solution(24, 24);
}
