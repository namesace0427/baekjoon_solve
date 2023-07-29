#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int INF = 987654321;
int N, M;
int result;
int graph[MAX][MAX];
vector<pair<int, int>> house, chicken;
bool visited[13];

int distance(pair<int, int> a, pair<int, int> b)
{
        return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int idx, int selected)
{
        if (selected == M)
        {
                 int tempResult = 0;
                 for (int i = 0; i < house.size(); i++)
                 {
                         int dist = INF;
                         for (int j = 0; j < chicken.size(); j++)
                                 if (visited[j])
                                          dist = min(dist, distance(house[i], chicken[j]));
                         tempResult += dist;
                 }
                 result = min(result, tempResult);
                 return;
        }

        if (idx == chicken.size())
                 return;

        visited[idx] = true;
        DFS(idx + 1, selected + 1);
        visited[idx] = false;
        DFS(idx + 1, selected);
}

 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> N >> M;
        for(int i=0; i<N; i++)
                 for (int j = 0; j < N; j++)
                 {
                         cin >> graph[i][j];
                         if (graph[i][j] == 1)
                                 house.push_back({ i, j });
                         else if (graph[i][j] == 2)
                                 chicken.push_back({ i, j });
                 }

        result = INF;
        DFS(0, 0);
        cout << result << "\n";
        return 0;
}
