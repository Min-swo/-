#include <deque>
#include <iostream>
using namespace std;

#define MAX 100001

int N, K;
deque<pair<int, int>> q;
int visited[MAX];

bool isSafe(int a, int b) {
    if (a < 0 || a >= MAX || visited[a] <= b) {
        return false;
    }

    return true;
}

int bfs(int start, int end) {
    q.push_back({start, 0});

    while (!q.empty()) {
        pair<int, int> curPair = q.front();
        int cur = curPair.first;
        int count = curPair.second;
        q.erase(q.begin());

        if (cur == end) {
            return count;
        }

        if (isSafe(cur * 2, count)) {
            visited[cur * 2] = count;
            q.push_front({cur * 2, count});
        }
        if (isSafe(cur + 1, count + 1)) {
            visited[cur + 1] = count + 1;
            q.push_back({cur + 1, count + 1});
        }
        if (isSafe(cur - 1, count + 1)) {
            visited[cur - 1] = count + 1;
            q.push_back({cur - 1, count + 1});
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < MAX; i++) {
        visited[i] = MAX;
    }

    cin >> N >> K;

    cout << bfs(N, K) << "\n";

    return 0;
}