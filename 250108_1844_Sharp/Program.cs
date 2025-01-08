// https://school.programmers.co.kr/learn/courses/30/lessons/1844
// 게임 맵 최단 거리

namespace _250108_1844_Sharp
{
    using System;

    class Solution
    {
        // 평균 시간 2 ~ 3초
        static public int solution(int[,] maps)
        {
            int answer = 0;

            int Row = maps.GetLength(0);
            int Column = maps.GetLength(1);

            int[] DirX = { -1, 1, 0, 0 };
            int[] DirY = { 0, 0, - 1, 1 };

            List<List<int>> Pay = new List<List<int>>();

            for (int i = 0; i < Row; i++)
            {
                Pay.Add(new List<int>(new int[Column]));
            }

            List<List<bool>> IsVisited = new List<List<bool>>();

            for (int i = 0; i < Row; i++)
            {
                IsVisited.Add(new List<bool>(new bool[Column]));
            }

            Queue<KeyValuePair<int, int>> BFS = new Queue<KeyValuePair<int, int>>();

            BFS.Enqueue(new KeyValuePair<int, int>(0, 0));
            Pay[0][0] = 1;
            IsVisited[0][0] = true;

            while (true == BFS.Any())
            {
                KeyValuePair<int, int> CurNode = BFS.Dequeue();

                for(int i = 0; i < 4; ++i)
                {
                    int NewX = CurNode.Key + DirX[i];
                    int NewY = CurNode.Value + DirY[i];

                    if(NewX < 0
                        || NewY < 0
                        || NewX == Row
                        || NewY == Column
                        || IsVisited[NewX][NewY] == true
                        || maps[NewX, NewY] == 0)
                    {
                        continue;
                    }

                    IsVisited[NewX][NewY] = true;
                    Pay[NewX][NewY] = Pay[CurNode.Key][CurNode.Value] + 1;
                    BFS.Enqueue(new KeyValuePair<int, int>(NewX, NewY));
                }
            }

            if(true == IsVisited[Row - 1][Column - 1])
            {
                answer = Pay[Row - 1][Column - 1];
            }
            else
            {
                answer = -1;
            }

            return answer;
        }

        // 평균 시간 : 1 ~ 1.5초
        //static public int solution(int[,] maps)
        //{
        //    int Row = maps.GetLength(0);
        //    int Column = maps.GetLength(1);

        //    int[] DirX = { -1, 1, 0, 0 };
        //    int[] DirY = { 0, 0, -1, 1 };

        //    int[,] Pay = new int[Row, Column];
        //    bool[,] IsVisited = new bool[Row, Column];

        //    Queue<KeyValuePair<int, int>> BFS = new Queue<KeyValuePair<int, int>>();

        //    BFS.Enqueue(new KeyValuePair<int, int>(0, 0));
        //    Pay[0, 0] = 1;
        //    IsVisited[0, 0] = true;

        //    while (0 < BFS.Count)
        //    {
        //        KeyValuePair<int, int> CurNode = BFS.Dequeue();

        //        if (CurNode.Key == Row - 1 && CurNode.Value == Column - 1)
        //        {
        //            return Pay[CurNode.Key, CurNode.Value];
        //        }

        //        for (int i = 0; i < 4; ++i)
        //        {
        //            int NewX = CurNode.Key + DirX[i];
        //            int NewY = CurNode.Value + DirY[i];

        //            if (NewX < 0 || NewY < 0 || NewX == Row || NewY == Column
        //                || IsVisited[NewX, NewY] || maps[NewX, NewY] == 0)
        //            {
        //                continue;
        //            }

        //            IsVisited[NewX, NewY] = true;
        //            Pay[NewX, NewY] = Pay[CurNode.Key, CurNode.Value] + 1;
        //            BFS.Enqueue(new KeyValuePair<int, int>(NewX, NewY));
        //        }
        //    }

        //    return -1;
        //}

        static void Main(string[] args)
        {
            int[,] ints = { { 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 } };
            Console.WriteLine(solution(ints));

            int[,] ints1 = { { 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 0 }, { 0, 0, 0, 0, 1 } };
            Console.WriteLine(solution(ints1));
        }
    }
}
