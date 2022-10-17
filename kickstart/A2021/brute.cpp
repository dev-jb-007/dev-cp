#include <iostream>
#include <set>

#define int long long

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int T;
  std::cin >> T;

  for(int t = 1; t <= T; t++) {
    std::cout << "Case #" << t << ": ";

    int r, c;
    std::cin >> r >> c;

    int a[r][c];
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        std::cin >> a[i][j];
      }
    }

    std::set<std::pair<int, std::pair<int, int> > > best;

    int ans = 0;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(i) {
          if(a[i-1][j]+1 < a[i][j])
            best.insert({-a[i-1][j], {i-1, j}});
          if(a[i][j]+1 < a[i-1][j])
            best.insert({-a[i][j], {i, j}});
        }
        if(j) {
          if(a[i][j-1]+1 < a[i][j])
            best.insert({-a[i][j-1], {i, j-1}});
          if(a[i][j]+1 < a[i][j-1])
            best.insert({-a[i][j], {i, j}});
        }
      }
    }

    while(!best.empty()) {
      auto u = *best.begin();
      best.erase(best.begin());
      int x = u.second.first, y = u.second.second;
      int max = 0;
      for(int j = 0; j < 4; j++) {
        int nx = x + dx[j], ny = y + dy[j];
        if(nx >= 0 && ny >= 0 && nx < r && ny < c)
          max = std::max(a[nx][ny], max);
      }

      ans += max-1-a[x][y];
      a[x][y] = max-1;
      for(int j = 0; j < 4; j++) {
        int nx = x + dx[j], ny = y + dy[j];
        if(nx >= 0 && ny >= 0 && nx < r && ny < c) {
          if(a[nx][ny]+1 < a[x][y]) {
            best.insert({-a[nx][ny], {nx, ny}});
          }
        }
      }
    }
    std::cout << ans;
    
    std::cout << std::endl;
  }

  return 0;
}

