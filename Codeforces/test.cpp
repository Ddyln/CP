#include <bits/stdc++.h>
using namespace std;

struct DP {
    int val, id, take, turn;
    bool operator < (DP b) {
        return val < b.val;
    }
};

signed main() {
    priority_queue <int, vector <int>, greater <int>> pq;
    pq.push(1);
    pq.push(2);
    cout << pq.top();
    return 0;
}