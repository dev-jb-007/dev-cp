#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  int n = rand(1, 10);
  cout << n << " ";

  int m = rand(n - 1, (n * (n - 1)) / 2);
  cout << m << endl;

  vector<int> done{1}, todo;
  for (int i = 2; i <= n; i++)
    todo.push_back(i);

  int size = n - 1;
  map<pair<int, int>,int> edges;
  for (int i = 0; i < n - 1; ++i) {
    int p = done[rand(0, (int)done.size() - 1)];
    int q = rand(0, size - 1);
    int r = todo[q];
    swap(todo[q], todo[size - 1]);
    size--;
    edges[{p,r}] = 1;
    done.push_back(r);
  }
  for (int i = n - 1; i < m;i++) {
    while (true) {
      int p = rand(0,done.size() - 1);
      int q = rand(0,done.size() - 1);
      if (p == q)
        continue;
      if (edges.count({done[p],done[q]}) || edges.count({done[q],done[p]}))
        continue;
      edges[{done[p],done[q]}] = 1;
      break;
    }
  }

  for (auto &m : edges) {
    cout<< m.first.first<<" "<<m.first.second<<endl;
  }
  cout << endl;
}
