// 241125_17683.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [3차] 방금그곡

/*
문제설명
라디오를 자주 듣는 네오는 라디오에서 방금 나왔던 음악이 무슨 음악인지 궁금해질 때가 많다.
그럴 때 네오는 다음 포털의 '방금그곡' 서비스를 이용하곤 한다. 방금그곡에서는 TV, 라디오 등에서 나온 음악에 관해 제목 등의 정보를 제공하는 서비스이다.

네오는 자신이 기억한 멜로디를 가지고 방금그곡을 이용해 음악을 찾는다.
그런데 라디오 방송에서는 한 음악을 반복해서 재생할 때도 있어서 네오가 기억하고 있는 멜로디는 음악 끝부분과 처음 부분이 이어서 재생된 멜로디일 수도 있다.
반대로, 한 음악을 중간에 끊을 경우 원본 음악에는 네오가 기억한 멜로디가 들어있다 해도 그 곡이 네오가 들은 곡이 아닐 수도 있다.
그렇기 때문에 네오는 기억한 멜로디를 재생 시간과 제공된 악보를 직접 보면서 비교하려고 한다. 다음과 같은 가정을 할 때 네오가 찾으려는 음악의 제목을 구하여라.

- 방금그곡 서비스에서는 음악 제목, 재생이 시작되고 끝난 시각, 악보를 제공한다.
- 네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
- 각 음은 1분에 1개씩 재생된다. 음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다.
  음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
- 음악이 00:00를 넘겨서까지 재생되는 일은 없다.
- 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
- 조건이 일치하는 음악이 없을 때에는 “(None)”을 반환한다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

std::map<std::string, char> MappingPitch;

class MusicInfo
{
public:
    MusicInfo()
    {

    }

    MusicInfo(const std::string& _Info)
    {
        std::vector<std::string> CurMusicInfos(4, "");
        std::string Temp = "";
        std::stringstream CurSS(_Info);
        int Index = 0;

        while (std::getline(CurSS, Temp, ','))
        {
            CurMusicInfos[Index] = Temp;
            ++Index;
        }

        StartTime = CurMusicInfos[0];
        EndTime = CurMusicInfos[1];
        MusicName = CurMusicInfos[2];
        Melody = CurMusicInfos[3];

        std::string ChangeM = "";
        std::string PrevPitch = "";
        const size_t MeloodyLength = Melody.length();

        for (size_t i = 0; i < MeloodyLength; ++i)
        {
            if ('#' != Melody[i])
            {
                ChangeM += PrevPitch;
                PrevPitch = Melody[i];

                if (i == MeloodyLength - 1)
                {
                    ChangeM += PrevPitch;
                }
            }
            else
            {
                PrevPitch += Melody[i];
                ChangeM += MappingPitch[PrevPitch];
                PrevPitch = "";
            }
        }

        Melody = ChangeM;

        CalculatePlayTime();
        MakePlayMelody();
    }

    std::string GetStartTime() const
    {
        return StartTime;
    }

    std::string GetPlayMelody() const
    {
        return PlayMelody;
    }

    int GetPlayTime() const
    {
        return PlayTime;
    }

    std::string GetMusicName() const
    {
        return MusicName;
    }

private:
    void CalculatePlayTime()
    {
        int StartHour = std::stoi(StartTime.substr(0, 2));
        int EndHour = std::stoi(EndTime.substr(0, 2));

        int StartSecond = std::stoi(StartTime.substr(3, 2));
        int EndSecond = std::stoi(EndTime.substr(3, 2));

        if (EndSecond < StartSecond)
        {
            EndHour -= 1;
            EndSecond += 60;
        }

        PlayTime = (EndSecond - StartSecond) + 60 * (EndHour - StartHour);
    }

    void MakePlayMelody()
    {
        int Index = 0;

        while (PlayMelody.length() != PlayTime)
        {
            PlayMelody += Melody[Index];
            ++Index;

            if (Index == Melody.length())
            {
                Index = 0;
            }
        }
    }

private:
    std::string StartTime = "";
    std::string EndTime = "";
    std::string MusicName = "";
    std::string Melody = "";

    int PlayTime = 0;
    std::string PlayMelody = "";
};

std::string solution(std::string m, std::vector<std::string> musicinfos)
{
    std::string answer = "";

    MappingPitch.insert(std::make_pair("A#", 'H'));
    MappingPitch.insert(std::make_pair("C#", 'I'));
    MappingPitch.insert(std::make_pair("D#", 'J'));
    MappingPitch.insert(std::make_pair("F#", 'K'));
    MappingPitch.insert(std::make_pair("G#", 'L'));

    std::string ChangeM = "";
    std::string PrevPitch = "";
    const size_t mLength = m.length();

    for (size_t i = 0; i < mLength; ++i)
    {
        if ('#' != m[i])
        {
            ChangeM += PrevPitch;
            PrevPitch = m[i];

            if (i == mLength - 1)
            {
                ChangeM += PrevPitch;
            }
        }
        else
        {
            PrevPitch += m[i];
            ChangeM += MappingPitch[PrevPitch];
            PrevPitch = "";
        }
    }

    MusicInfo AnswerMI;

    for (const std::string& CurMusicInfo : musicinfos)
    {
        MusicInfo CurMI = MusicInfo(CurMusicInfo);

        std::string CurPlayMelody = CurMI.GetPlayMelody();

        size_t FindIndex = CurPlayMelody.find(ChangeM);

        if (FindIndex == std::string::npos)
        {
            continue;
        }

        if (answer == "")
        {
            AnswerMI = CurMI;
            answer = CurMI.GetMusicName();
        }
        else
        {
            if (AnswerMI.GetPlayTime() < CurMI.GetPlayTime())
            {
                AnswerMI = CurMI;
                answer = CurMI.GetMusicName();
            }
            else if (AnswerMI.GetPlayTime() == CurMI.GetPlayTime())
            {
                if (AnswerMI.GetStartTime() > CurMI.GetStartTime())
                {
                    AnswerMI = CurMI;
                    answer = CurMI.GetMusicName();
                }
            }
        }
    }

    if (answer == "")
    {
        answer = "(None)";
    }

    return answer;
}

int main()
{
    std::cout << solution("ABCDEFG", { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" }) << std::endl;
    std::cout << solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" }) << std::endl;
    std::cout << solution("ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" }) << std::endl;
    std::cout << solution("A#", { "13:00,13:02,HAPPY,B#A#"}) << std::endl;
    std::cout << solution("A#D#", { "13:00,13:12,FOO,D#A#", "14:00,14:16,BUSY,D#A#"}) << std::endl;
}
