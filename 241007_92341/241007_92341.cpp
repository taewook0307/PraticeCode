// 241007_92341.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 주차 요금 계산

/*
문제 설명
주차장의 요금표와 차량이 들어오고(입차) 나간(출차) 기록이 주어졌을 때, 차량별로 주차 요금을 계산하려고 합니다. 아래는 하나의 예시를 나타냅니다.

요금표
기본 시간(분) | 기본 요금(원) | 단위 시간(분) | 단위 요금(원)
     180      |     5000      |      10       |     600

입/출차 기록
시각(시:분)	    차량 번호	내역
05:34	        5961	    입차
06:00	        0000	    입차
06:34	        0000	    출차
07:59	        5961	    출차
07:59	        0148	    입차
18:59	        0000	    입차
19:09	        0148	    출차
22:59	        5961	    입차
23:00	        5961	    출차

자동차별 주차 요금
차량 번호	    누적 주차 시간(분)	    주차 요금(원)
0000	        34 + 300 = 334	        5000 + ⌈(334 - 180) / 10⌉ x 600 = 14600
0148	        670	                    5000 +⌈(670 - 180) / 10⌉x 600 = 34400
5961	        145 + 1 = 146	        5000

- 어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다.
- 0000번 차량은 18:59에 입차된 이후, 출차된 내역이 없습니다. 따라서, 23:59에 출차된 것으로 간주합니다.
- 00:00부터 23:59까지의 입/출차 내역을 바탕으로 차량별 누적 주차 시간을 계산하여 요금을 일괄로 정산합니다.
- 누적 주차 시간이 기본 시간이하라면, 기본 요금을 청구합니다.
- 누적 주차 시간이 기본 시간을 초과하면, 기본 요금에 더해서, 초과한 시간에 대해서 단위 시간 마다 단위 요금을 청구합니다.
- 초과한 시간이 단위 시간으로 나누어 떨어지지 않으면, 올림합니다.
- ⌈a⌉ : a보다 작지 않은 최소의 정수를 의미합니다. 즉, 올림을 의미합니다.

주차 요금을 나타내는 정수 배열 fees,
자동차의 입/출차 내역을 나타내는 문자열 배열 records가 매개변수로 주어집니다.
차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아서 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class CalculateFee
{
public:
    CalculateFee(int _BaseTime, int _BasePay, int _OverStandardTime, int _OverPay)
        : BaseTime(_BaseTime), BasePay(_BasePay), OverStandardTime(_OverStandardTime), OverPay(_OverPay)
    {

    }

    int GetFee(int _Time)
    {
        if (_Time <= BaseTime)
        {
            return BasePay;
        }

        float Over = _Time - BaseTime;
        int AddPay = ceil(Over / OverStandardTime) * OverPay;
        
        return BasePay + AddPay;
    }

private:
    int BaseTime;
    int BasePay;
    int OverStandardTime;
    int OverPay;
};

struct Time
{
    Time(std::string& _Time)
    {
        Seconds = stoi(_Time.substr(0, 2)) * 60 + stoi(_Time.substr(3, 2));
    }

    int Seconds = 0;
};

bool Compare(std::string& _Left, std::string& _Right)
{
    std::string LeftCarNum = _Left.substr(6, 4);
    std::string RightCarNum = _Right.substr(6, 4);

    if (LeftCarNum == RightCarNum)
    {
        return _Left < _Right;
    }

    return LeftCarNum < RightCarNum;
}

std::vector<int> solution(std::vector<int> fees, std::vector<std::string> records)
{
    std::vector<int> answer;

    CalculateFee ParkingFeeCalculator = CalculateFee(fees[0], fees[1], fees[2], fees[3]);

    size_t RecordCount = records.size();
    
    if (RecordCount == 1)
    {
        std::string EndTime = "23:59";
        Time OutTime = Time(EndTime);

        std::string PrevTimeString = records[0].substr(0, 5);
        Time PrevTime = Time(PrevTimeString);

        int ParkingTime = (OutTime.Seconds - PrevTime.Seconds);

        answer.push_back(ParkingFeeCalculator.GetFee(ParkingTime));

        return answer;
    }

    sort(records.begin(), records.end(), Compare);
    
    std::string PrevTimeString = records[0].substr(0, 5);
    Time PrevTime = Time(PrevTimeString);
    std::string PrevCarNum = records[0].substr(6, 4);
    bool IsIn = records[0].back() == 'N' ? true : false;

    int ParkingTime = 0;;

    for (size_t i = 1; i < RecordCount; ++i)
    {
        std::string CarNum = records[i].substr(6, 4);

        if (i == RecordCount - 1)
        {
            bool CurIn = records[i].back() == 'N' ? true : false;

            if (true == CurIn)
            {
                std::string EndTime = "23:59";
                Time OutTime = Time(EndTime);

                std::string CurTimeString = records[i].substr(0, 5);
                Time CurTime = Time(CurTimeString);

                ParkingTime += (OutTime.Seconds - CurTime.Seconds);

                answer.push_back(ParkingFeeCalculator.GetFee(ParkingTime));
            }
            else
            {
                std::string OutTimeString = records[i].substr(0, 5);
                Time OutTime = Time(OutTimeString);

                ParkingTime += (OutTime.Seconds - PrevTime.Seconds);

                answer.push_back(ParkingFeeCalculator.GetFee(ParkingTime));
            }
        }
        else if (CarNum != PrevCarNum)
        {
            // 23:59분까지 있을경우
            if (true == IsIn)
            {
                std::string EndTime = "23:59";
                Time OutTime = Time(EndTime);

                ParkingTime += (OutTime.Seconds - PrevTime.Seconds);

                answer.push_back(ParkingFeeCalculator.GetFee(ParkingTime));
                ParkingTime = 0;
                PrevCarNum = CarNum;

                std::string CurInTimeString = records[i].substr(0, 5);
                PrevTime = Time(CurInTimeString);

                IsIn = records[i].back() == 'N' ? true : false;
            }
            // 그 전 차량의 주차비 계산 후 push
            else
            {
                answer.push_back(ParkingFeeCalculator.GetFee(ParkingTime));
                ParkingTime = 0;
                PrevCarNum = CarNum;

                std::string CurTimeString = records[i].substr(0, 5);
                PrevTime = Time(CurTimeString);
                IsIn = records[i].back() == 'N' ? true : false;
            }
        }
        else
        {
            bool CurIn = records[i].back() == 'N' ? true : false;

            // 입차 후 출차
            if (true == IsIn && false == CurIn)
            {
                std::string OutTimeString = records[i].substr(0, 5);
                Time OutTime = Time(OutTimeString);

                ParkingTime += (OutTime.Seconds - PrevTime.Seconds);

                PrevTime = OutTime;
                IsIn = CurIn;
            }
            // 한번 출차한 차가 재입차
            else if (false == IsIn && true == CurIn)
            {
                std::string InTimeString = records[i].substr(0, 5);
                Time InTime = Time(InTimeString);

                IsIn = CurIn;
                PrevTime = InTime;
            }
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Fees0 = { 180, 5000, 10, 600 };
    std::vector<std::string> Records0 = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    std::vector<int> Result0 = solution(Fees0, Records0);

    std::vector<int> Fees1 = { 120, 0, 60, 591 };
    std::vector<std::string> Records1 = { "16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN" };
    std::vector<int> Result1 = solution(Fees1, Records1);

    std::vector<int> Fees2 = { 1, 461, 1, 10 };
    std::vector<std::string> Records2 = { "00:00 1234 IN" };
    std::vector<int> Result2 = solution(Fees2, Records2);

    int a = 0;
}
