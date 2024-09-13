// 240909_1844.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 게임 맵 최단 거리

/*
문제 설명
ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.

캐릭터가 움직일 때는 동, 서, 남, 북 방향으로 한 칸씩 이동하며, 게임 맵을 벗어난 길은 갈 수 없습니다.

게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요.
단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

제한사항
    - maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
        n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
    - maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
    - 처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.
*/

#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    Node(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    int X;
    int Y;
};

int solution(std::vector<std::vector<int> > maps)
{
    int answer = 0;

    const int RowCount = static_cast<int>(maps.size());
    const int ColumnCount = static_cast<int>(maps[0].size());

    // 인덱스에 더해질 값 : 왼쪽 오른쪽 위 아래
    int IndexX[4] = { -1, 1, 0, 0 };
    int IndexY[4] = { 0, 0, -1, 1 };

    std::vector<std::vector<bool>> Visit(RowCount, std::vector<bool>(ColumnCount, false));
    std::vector<std::vector<int>> Distance(RowCount, std::vector<int>(ColumnCount, 0));

    Node CurNode = Node();
    Visit[CurNode.X][CurNode.Y] = true;
    Distance[CurNode.X][CurNode.Y] = 1;

    // 탐색용 큐
    std::queue<Node> Search;
    // 초기값 push
    Search.push(CurNode);

    while (false == Search.empty())
    {
        CurNode = Search.front();
        Search.pop();

        // 목적지를 pop한 경우
        if (RowCount - 1 == CurNode.X && ColumnCount - 1 == CurNode.Y)
        {
            answer = Distance[CurNode.X][CurNode.Y];
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextNodeX = CurNode.X + IndexX[i];
            int NextNodeY = CurNode.Y + IndexY[i];

            // 맵 밖인지 확인
            if (0 > NextNodeX
                || 0 > NextNodeY
                || RowCount <= NextNodeX
                || ColumnCount <= NextNodeY)
            {
                continue;
            }

            // 벽인지 확인
            if (0 == maps[NextNodeX][NextNodeY])
            {
                continue;
            }

            // 이미 지나온 길인지 확인
            if (true == Visit[NextNodeX][NextNodeY])
            {
                continue;
            }

            // 다음에 갈 수 있는 노드들을 큐에 push
            Search.push(Node(NextNodeX, NextNodeY));
            Visit[NextNodeX][NextNodeY] = true;
            Distance[NextNodeX][NextNodeY] = Distance[CurNode.X][CurNode.Y] + 1;
        }
    }

    // 목적지에 도달하지 못했을 경우
    if (false == Visit[RowCount - 1][ColumnCount - 1])
    {
        return -1;
    }

    return answer;
}

//#include <queue>
//#include <map>
//
//bool IsOver(const std::pair<int, int>& _Check, int _MaxRow, int _MaxColumn)
//{
//    if (0 > _Check.first
//        || 0 > _Check.second
//        || _MaxRow <= _Check.first
//        || _MaxRow <= _Check.second)
//    {
//        return true;
//    }
//
//    return false;
//}
//
//int solution(std::vector<std::vector<int>> maps)
//{
//    int answer = 0;
//
//    const int RowCount = static_cast<int>(maps.size());
//    const int ColumnCount = static_cast<int>(maps[0].size());
//
//    // 이동 경로 노드 넘버링
//    int Number = 0;
//
//    std::map<std::pair<int, int>, int> MapData;
//
//    for (int i = 0; i < RowCount; ++i)
//    {
//        for (int j = 0; j < ColumnCount; ++j)
//        {
//            if (0 == maps[i][j])
//            {
//                continue;
//            }
//
//            std::pair<int, int> CurPair = std::make_pair(i, j);
//            MapData.insert(std::make_pair(CurPair, Number));
//            ++Number;
//        }
//    }
//
//    // 각 노드별 이동할 수 있는 노드 정보
//    std::map<int, std::vector<int>> Link;
//
//    for (std::pair<std::pair<int, int>, int> Node : MapData)
//    {
//        const int CurNodeNum = Node.second;
//
//        std::vector<int> LinkNodes;
//        LinkNodes.reserve(4);
//
//        const int IndexX = Node.first.first;
//        const int IndexY = Node.first.second;
//
//        std::pair<int, int> Left = std::make_pair(IndexX - 1, IndexY);
//        std::pair<int, int> Right = std::make_pair(IndexX + 1, IndexY);
//        std::pair<int, int> Up = std::make_pair(IndexX, IndexY - 1);
//        std::pair<int, int> Down = std::make_pair(IndexX, IndexY + 1);
//
//        if (false == IsOver(Left, RowCount, ColumnCount))
//        {
//            if (1 == maps[Left.first][Left.second])
//            {
//                LinkNodes.push_back(MapData[Left]);
//            }
//        }
//
//        if (false == IsOver(Right, RowCount, ColumnCount))
//        {
//            if (1 == maps[Right.first][Right.second])
//            {
//                LinkNodes.push_back(MapData[Right]);
//            }
//        }
//
//        if (false == IsOver(Up, RowCount, ColumnCount))
//        {
//            if (1 == maps[Up.first][Up.second])
//            {
//                LinkNodes.push_back(MapData[Up]);
//            }
//        }
//
//        if (false == IsOver(Down, RowCount, ColumnCount))
//        {
//            if (1 == maps[Down.first][Down.second])
//            {
//                LinkNodes.push_back(MapData[Down]);
//            }
//        }
//
//        Link.insert(std::make_pair(CurNodeNum, LinkNodes));
//    }
//
//    // 탐색 시작
//    const int MapCount = static_cast<int>(MapData.size());
//    std::vector<bool> Visit(MapCount, false);
//    std::vector<int> Distance(MapCount, 0);
//
//    int CurNode = 0;
//    int Destination = MapCount - 1;
//    Visit[0] = true;
//    Distance[0] = 1;
//
//    std::queue<int> Search;
//    Search.push(CurNode);
//
//    while (false == Search.empty())
//    {
//        CurNode = Search.front();
//        Search.pop();
//
//        if (Destination == CurNode)
//        {
//            answer = Distance[Destination];
//        }
//
//        std::vector<int> LinkNodes = Link[CurNode];
//        for (int NextNode : LinkNodes)
//        {
//            if (true == Visit[NextNode])
//            {
//                continue;
//            }
//
//            Search.push(NextNode);
//            Visit[NextNode] = true;
//            int PrevDistance = Distance[CurNode];
//            Distance[NextNode] = PrevDistance + 1;
//        }
//    }
//
//    if (false == Visit[Destination])
//    {
//        return -1;
//    }
//
//    return answer;
//}

int main()
{
    std::vector<std::vector<int>> maps0 = { { 1,0,1,1,1 }, { 1,0,1,0,1 }, { 1,0,1,1,1 }, { 1,1,1,0,1 }, { 0,0,0,0,1 } };

    std::cout << solution(maps0);
}
