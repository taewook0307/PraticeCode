// 240902_258712.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 가장 많이 받은 선물

/*
문제 설명
선물을 직접 전하기 힘들 때 카카오톡 선물하기 기능을 이용해 축하 선물을 보낼 수 있습니다.
당신의 친구들이 이번 달까지 선물을 주고받은 기록을 바탕으로 다음 달에 누가 선물을 많이 받을지 예측하려고 합니다.

두 사람이 선물을 주고받은 기록이 있다면, 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받습니다.
예를 들어 A가 B에게 선물을 5번 줬고, B가 A에게 선물을 3번 줬다면 다음 달엔 A가 B에게 선물을 하나 받습니다.

두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면, 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나 받습니다.
선물 지수는 이번 달까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값입니다.
예를 들어 A가 친구들에게 준 선물이 3개고 받은 선물이 10개라면 A의 선물 지수는 -7입니다.
B가 친구들에게 준 선물이 3개고 받은 선물이 2개라면 B의 선물 지수는 1입니다.
만약 A와 B가 선물을 주고받은 적이 없거나 정확히 같은 수로 선물을 주고받았다면, 다음 달엔 B가 A에게 선물을 하나 받습니다.

만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고받지 않습니다.
위에서 설명한 규칙대로 다음 달에 선물을 주고받을 때, 당신은 선물을 가장 많이 받을 친구가 받을 선물의 수를 알고 싶습니다.

친구들의 이름을 담은 1차원 문자열 배열 friends
이번 달까지 친구들이 주고받은 선물 기록을 담은 1차원 문자열 배열 gifts가 매개변수로 주어집니다.
이때, 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수를 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

class GiftScore
{
public:
    GiftScore()
    {

    }

    void Gift()
    {
        ++GiftCount;
    }

    void Receive()
    {
        ++ReceiveCount;
    }

    int GetGiftScore() const
    {
        return GiftCount - ReceiveCount;
    }

private:
    int GiftCount = 0;
    int ReceiveCount = 0;
};

int solution(std::vector<std::string> friends, std::vector<std::string> gifts)
{
    int answer = 0;

    const int FriendCount = static_cast<int>(friends.size());

    // 선물 지수 계산을 위한 Map
    std::map<std::string, GiftScore> GiftScoreCalculation;

    // 각 친구들 index Mapping
    std::map<std::string, int> FriendIndex;
    std::map<int, std::string> IndexToFriend;

    for (int i = 0; i < FriendCount; ++i)
    {
        FriendIndex.insert(std::make_pair(friends[i], i));
        IndexToFriend.insert(std::make_pair(i, friends[i]));
        GiftScoreCalculation.insert(std::make_pair(friends[i], GiftScore()));
    }

    // 선물보낸 개수를 위한 2차원 vector
    std::vector<std::vector<int>> GiftsCount(FriendCount, std::vector<int>(FriendCount, 0));

    for (const std::string& GiftLog : gifts)
    {
        size_t Index = GiftLog.find_first_of(' ');
        std::string Gifter = GiftLog.substr(0, Index);
        std::string Receiver = GiftLog.substr(Index + 1, GiftLog.size() - Index);

        ++GiftsCount[FriendIndex[Gifter]][FriendIndex[Receiver]];

        GiftScoreCalculation[Gifter].Gift();
        GiftScoreCalculation[Receiver].Receive();
    }

    // 다음달 받을 선물 개수용 vector
    std::vector<int> NextGiftCount(FriendCount, 0);

    for (int i = 0; i < FriendCount; ++i)
    {
        for (int j = 0; j < FriendCount; ++j)
        {
            if (i == j)
            {
                continue;
            }

            // 선물을 더 많이 준 경우
            if (GiftsCount[j][i] < GiftsCount[i][j])
            {
                ++NextGiftCount[i];
            }
            // 선물을 준 경우가 같을경우
            else if(GiftsCount[j][i] == GiftsCount[i][j])
            {
                std::string Gifter = IndexToFriend[i];
                std::string Receiver = IndexToFriend[j];

                int GifterScore = GiftScoreCalculation[Gifter].GetGiftScore();
                int ReceiverScore = GiftScoreCalculation[Receiver].GetGiftScore();

                // 선물지수가 높으면
                if (GifterScore > ReceiverScore)
                {
                    ++NextGiftCount[i];
                }
            }
        }
    }

    // 결과
    for (int Num : NextGiftCount)
    {
        answer = answer < Num ? Num : answer;
    }

    return answer;
}

void PrintResult(const std::vector<std::string>& friends, const std::vector<std::string> gifts)
{
    int Result = solution(friends, gifts);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<std::string> friends0 = { "muzi", "ryan", "frodo", "neo" };
    std::vector<std::string> gifts0 = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

    PrintResult(friends0, gifts0);

    std::vector<std::string> friends1 = { "joy", "brad", "alessandro", "conan", "david" };
    std::vector<std::string> gifts1 = { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" };

    PrintResult(friends1, gifts1);

    std::vector<std::string> friends2 = { "a", "b", "c" };
    std::vector<std::string> gifts2 = { "a b", "b a", "c a", "a c", "a c", "c a" };

    PrintResult(friends2, gifts2);
}
