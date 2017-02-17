#include <bits/stdc++.h>

#define ff first
#define mp make_pair
#define ss second
#define pb push_back


using namespace std;
typedef long long LL;

bool isValid(int x, int y, int N);

int bfsPath(pair<int, int> source, pair<int, int> dest, int size, int* const dx, int* const dy, int n)
{

    int N = size;
    queue<pair<pair<int, int>, int> > KnightQue;
    map<pair<int, int>, bool> visited;

    KnightQue.push(mp(source, 0));

    while (!KnightQue.empty()) {

        pair<pair<int, int>, int> temp = KnightQue.front();
        KnightQue.pop();
        if (temp.ff.ff == dest.ff && temp.ff.ss == dest.ss)
            return temp.ss;
        int x = temp.ff.ff;
        int y = temp.ff.ss;
        int dis = temp.ss + 1;

        if (visited.count(mp(x, y)))
            continue;
        visited[mp(x, y)] = true;

        for (int i = 0; i < 8; ++i) {

            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (isValid(x1, y1, N))
                KnightQue.push(mp(mp(x1, y1), dis));
        }
    }

    return -1;
}

bool isValid(int x, int y, int N)
{
    if (x <= 0 || y <= 0 || x > N || y > N)
        return false;
    return true;
}

void knightL(int N, int x1, int y1, int x2, int y2)
{

    pair<int, int> source;
    source.ff = x1;
    source.ss = y1;

    pair<int, int> dest;
    dest.ff = x2;
    dest.ss = y2;

    int size = N;

    int i = 0, j = 0;

    for (i = 1; i < N; i++) {
        for (j = 1; j < N; j++) {

            int dx[8] = { j, j, -j, -j, i, i, -i, -i };
            int dy[8] = { -i, i, i, -i, j, -j, j, -j };

            int ans = bfsPath(source, dest, size, dx, dy, N);
            cout << ans << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    knightL(n,1, 1, n, n);
    return 0;
}
