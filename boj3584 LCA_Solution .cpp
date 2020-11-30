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

//�ʱ�ȭ
void init() {
    memset(parent, 0, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    memset(chk, false, sizeof(chk));
    memset(whoroot, true, sizeof(whoroot));
    for (int i = 1; i <= n; i++)
        node[i].clear();
}

//�ٷ� ���� �ִ� �θ�� ����
void dfs(int cur, int d) {
    chk[cur] = true;
    depth[cur] = d; //����
    for (auto& next : node[cur]) {
        if (chk[next]) continue;
        parent[next][0] = cur; //next�� 1(2^0)��° �θ�� cur
        dfs(next, d + 1);
    }
}

void makeTree() {
    dfs(root, 0);

    //��� u(1~n)�� �θ� �����ϱ�
    // tmp :: here�� 2^(i-1)��° ����
        /*
            ��, ac[here][i] = ac[tmp][i-1]��
            here�� 2^i��° ������ tmp�� 2^(i-1)��° ������ 2^(i-1)��° ����� ���ٴ� �ǹ�
            ������� i = 3�϶�
            here�� 8��° ������ tmp(here�� 4��° ����)�� 4��° ����� ����.
            i =  4�϶� here�� 16��° ������ here�� 8��° ����(tmp)�� 8��°�� ����.
        */
    for (int k = 1; k < 20; k++) {
        for (int u = 1; u <= n; u++) {
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }
}

//�ּ� ���� ���� ã��
int LCA(int a, int b) {
    //�������� b�� �������ְ� ����
    if (depth[a] > depth[b]) swap(a, b);

    //���̰� �ٸ� ��ŭ �����ֱ�
    //b�� 2^i��° ������ a�� ���̺��� ũ�ų� ������ ������Ʈ
    // b�� �÷��� depth�� �����ش�.
            /*
                �̷����ϸ� ���� max_level�� 4���
                2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0������� ã�ư��ٵ�
                �ᱹ 1, 2, 3, 4, 5 ..., 31���� ��� ã�� ��İ� ��������.
                �������, i�� 4�϶��� 1�϶� �����ߴ� ġ��
                depth[a] <= depth[ac[b][4]]�� ����
                b = ac[b][4];�� �Ǿ� b�� b�� 16��° ������ ���� ���� ���̰�
                depth[a] <= depth[ac[b][1]]�� ����(���� b�� ó�� b�� 16��° ������ b�� �ٲ����.)
                b = ac[b][1];�� �Ǿ� b�� b�� 2��° ������ ���� �ȴ�.
                ��, b�� 16��° ������ 2��° ������ ���� ���̴� b�� 18��° ������ ���� �ȴ�.
                (�ϰ��� �ϴ� ���� 3��°, 7��°, 11��° �̷� ����鵵 ��� �� �� �ִٴ� �ǹ��̴�.)
            */

    for (int i = 20 - 1; i >= 0; i--) {
        if (depth[a] <= depth[parent[b][i]])
            b = parent[b][i];
    }

    //a�� b�� ���ٸ� -> �ּ� ���� ����
    if (a == b) return a;

    //������ ������ ������ ������Ʈ
    // a�� b�� �ٸ��ٸ� ���� ���̰� ������
        // ���̸� ��� �÷� ���� �ٸ� ����� ������ ������ ������ �ݺ��Ѵ�.
        // ��, ���� �ٸ� ���(2,3)�� ������ 1�� ���ٸ� lca = ac[2][0]�� ���� 2�� ������ 1���� �� �� �ְ�
        // ���������� ac[3][0] ���� 3�� ������ 1���� �˰ԵǸ� �˰����� ���̳���.

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
        cin >> n; //��� ����

        //����
        for (int i = 0; i < n - 1; i++) {
            int p, c;
            cin >> p >> c;
            node[c].push_back(p);
            node[p].push_back(c);
            whoroot[c] = false;
        }

        //��Ʈ ã��
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