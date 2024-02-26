//
//  main.cpp
//  11725
//
//  Created by Jun Hyeok Kim on 2/26/24.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vect[100001];
int res[100001];
bool visited[100001] = {false,};

void dfs(int start) {
    visited[start] = true;
    
    for (int i=0; i<vect[start].size(); i++) {
        int next = vect[start][i];
        if (!visited[next]) {
            res[next] = start;
            dfs(next);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int y,x;
        cin >> y >> x;
        vect[y].push_back(x);
        vect[x].push_back(y);
    }
    
    dfs(1);
    
    for (int i=2; i<=n; i++) {
        cout << res[i] << "\n";
    }
    
    return 0;
}
