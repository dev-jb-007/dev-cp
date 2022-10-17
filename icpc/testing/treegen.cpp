#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  int n = rand(1, 10);
  cout << n << endl;
  vector<int>done{1},todo;
  for (int i = 2; i <= n;i++)
    todo.push_back(i);

  int size = n - 1;
  vector<pair<int, int>>edges;
  for (int i = 0; i < n - 1; ++i) {
    int p = done[rand(0,(int)done.size() - 1)];
    int q = rand(0,size - 1);
    int r = todo[q];
    swap(todo[q],todo[size - 1]);
    size--;
    edges.push_back({p,r});
    done.push_back(r);
  }
  for (auto &m : edges) {
    cout<<m.first<<" "<<m.second<<endl;
  }
  cout << endl;
}
