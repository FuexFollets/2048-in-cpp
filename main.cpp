#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using g4x4 = std::vector<std::vector<int>>;

g4x4 initial{};

int r14() { return (rand() % 4); }

class G2048 {
  public:
    int score;

    g4x4 grid;

    G2048(g4x4 g = initial, int score = 0);

    void display(g4x4 g = initial);

    g4x4 rotate_g(int rotations, g4x4 g); // used for move
    g4x4 collapse(g4x4 g); // removes 0
    std::tuple<g4x4, int> combine(const g4x4 g);

    g4x4 add_r_numbers(g4x4 g);

    g4x4 move(int direction, g4x4);

  private:
    int mv_count{0}; // move count
};

G2048::G2048(g4x4 g, int score) {
  grid = g;
  score = score;
}

void G2048::display(const g4x4 g) {
  for (auto& row : g) {
    for (auto& val : row) {
      std::cout << val << ' ';
    }
  std::cout << '\n';
  }
}

g4x4 G2048::rotate_g(const int rotations, const g4x4 g) {
  static g4x4 r_grid{g};
  for (int i; i <= rotations; i++) {
    for (int x{0}; x < 4; x++) {
      for (int y{0}; y < 4; y++) {
        r_grid[x][y] = g[y][x];
      }
    }
    for (int r{0}; r != 4; r++) {
    r_grid[r] = g[4 - r];
    }   
  }
  return r_grid;
}


g4x4 G2048::collapse(const g4x4 g) {
  static g4x4 coll{initial};
  int rn{0}; int cn{0};

 for (auto& row : g) {
   cn = 0;
   for (auto& val : row) {
     if (val) {
       coll[rn][cn++] = val;
     }
   }
   rn++;
 }

  return coll;
}

std::tuple<g4x4, int> G2048::combine(const g4x4 g) {
  static g4x4 cmb{initial};
  int score_diff{0};

  int appn{0};

  int rn{0};
  for (auto& row : g) {
    appn = 0;
    for (int inst{0}; inst < 3; inst++) {
      if (row[inst] == row[inst + 1]) {
        cmb[rn][appn++] = row[inst] * 2;
        score_diff += row[inst] * 2;
      }
    }
    rn++;
  }
  return std::tuple<g4x4, int>{cmb, score_diff};
}

g4x4 G2048::move(int direction, g4x4 g) {

}

int main() {
  std::cout << "'\n'";
}