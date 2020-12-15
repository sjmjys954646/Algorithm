#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int parent[10002][20];
int depth[10002], root, n;
vector<int> node[10002];
bool chk[10002], whoroot[10002];

//초기화
void init() {
    memset(parent, 0, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    memset(chk, false, sizeof(chk));
    memset(whoroot, true, sizeof(whoroot));
    for (int i = 1; i <= n; i++)
        node[i].clear();
}

//바로 위에 있는 부모와 연결
void dfs(int cur, int d) {
    chk[cur] = true;
    depth[cur] = d; //깊이
    for (auto& next : node[cur]) {
        if (chk[next]) continue;
        parent[next][0] = cur; //next의 1(2^0)번째 부모는 cur
        dfs(next, d + 1);
    }
}

void makeTree() {
    dfs(root, 0);

    //노드 u(1~n)의 부모를 연결하기
    // tmp :: here의 2^(i-1)번째 조상
        /*
            즉, ac[here][i] = ac[tmp][i-1]은
            here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
            예를들어 i = 3일때
            here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
            i =  4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
        */
    for (int k = 1; k < 20; k++) {
        for (int u = 1; u <= n; u++) {
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }
}

//최소 공통 조상 찾기
int LCA(int a, int b) {
    //깊은쪽을 b로 설정해주고 시작
    if (depth[a] > depth[b]) swap(a, b);

    //깊이가 다른 만큼 맞춰주기
    //b의 2^i번째 조상이 a의 깊이보다 크거나 같으면 업데이트
    // b를 올려서 depth를 맞춰준다.
            /*
                이렇게하면 만약 max_level이 4라면
                2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0방식으로 찾아갈텐데
                결국 1, 2, 3, 4, 5 ..., 31까지 모두 찾는 방식과 같아진다.
                예를들어, i가 4일때와 1일때 만족했다 치면
                depth[a] <= depth[ac[b][4]]에 의해
                b = ac[b][4];가 되어 b는 b의 16번째 조상을 보고 있을 것이고
                depth[a] <= depth[ac[b][1]]에 의해(현재 b는 처음 b의 16번째 조상인 b로 바뀌었다.)
                b = ac[b][1];이 되어 b는 b의 2번째 조상을 보게 된다.
                즉, b의 16번째 조상의 2번째 조상을 보는 것이니 b의 18번째 조상을 보게 된다.
                (하고자 하는 말은 3번째, 7번째, 11번째 이런 조상들도 모두 볼 수 있다는 의미이다.)
            */

    for (int i = 20 - 1; i >= 0; i--) {
        if (depth[a] <= depth[parent[b][i]])
            b = parent[b][i];
    }

    //a와 b가 같다면 -> 최소 공통 조상
    if (a == b) return a;

    //조상이 같아질 때까지 업데이트
    // a와 b가 다르다면 현재 깊이가 같으니
        // 깊이를 계속 올려 서로 다른 노드의 조상이 같아질 때까지 반복한다.
        // 즉, 서로 다른 노드(2,3)의 조상이 1로 같다면 lca = ac[2][0]에 의해 2의 조상이 1임을 알 수 있고
        // 마찬가지로 ac[3][0] 또한 3의 조상이 1임을 알게되며 알고리즘이 끝이난다.

    for (int i = 20 - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; 
    cin >> t;
    while (t--) {
        init();
        cin >> n; //노드 개수

        //간선
        for (int i = 0; i < n - 1; i++) {
            int p, c;
            cin >> p >> c;
            node[c].push_back(p);
            node[p].push_back(c);
            whoroot[c] = false;
        }

        //루트 찾기
        for (int i = 1; i <= n; i++)
            if (whoroot[i]) {
                root = i;
                break;
            }

        makeTree();

        //target
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

    return 0;
}