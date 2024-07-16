// 240716_132267.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

// �ݶ� ����

/*
���� ����
�� �� a���� �������ָ� �ݶ� b���� �ִ� ��Ʈ�� ���� ��,
�� �� n���� �������ָ� �� ���� ���� �� �ִ��� ����ϴ� �����Դϴ�.
���� �ݶ� ������ ����������, ���� ���� �� ���� a�� �̸��̸�, �߰������� �� ���� ���� �� �����ϴ�.

�ݶ� �ޱ� ���� ��Ʈ�� �־�� �ϴ� �� �� a,
�� �� a���� ������ �ָ� ��Ʈ�� �ִ� �ݶ� �� �� b,
����̰� ������ �ִ� �� ���� ���� n�� �Ű������� �־����ϴ�.
����̰� ���� �� �ִ� �ݶ��� �� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.
*/

#include <iostream>
#include <string>
#include <vector>

int solution(int a, int b, int n) {
    int answer = 0;

    int AllCokeCount = n;
    int NeedCokeCount = a;

    while (AllCokeCount >= NeedCokeCount)
    {
        int RemainCount = AllCokeCount % NeedCokeCount;
        AllCokeCount /= NeedCokeCount;

        answer += (AllCokeCount * b);

        AllCokeCount *= b;

        AllCokeCount += RemainCount;
    }

    return answer;
}

void PrintResult(int a, int b, int n)
{
    int Result = solution(a, b, n);

    std::cout << "Coke Count : " << Result << std::endl;
}

int main()
{
    PrintResult(2, 1, 20);
    PrintResult(3, 1, 20);
    PrintResult(4, 2, 20);
}