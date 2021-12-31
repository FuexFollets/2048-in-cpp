#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using g4x4 = std::vector<std::vector<int>>; // 2D vector

int n_count{0};

g4x4 initial{};

int r14() { return (rand() % 4); }


class G2048 {
  public:
    int score;

    g4x4 grid;

    G2048(g4x4 g = initial, int score = 0);

    void display(g4x4 g = initial);

    bool is_f(g4x4 g);
    void rotate_g(const int rotations, g4x4 g); // used for move
    void collapse(g4x4 g); // removes 0
    int combine(g4x4 g);
    void set_r_numbers(g4x4 g);
    int move(int direction);

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

bool G2048::is_f(g4x4 g) {
  int bl{0};
  for (auto& row : g) {
    for (auto& val : row) {
      if (val) {
        bl++;
      }
    }
  }
  return (bl == 16);
}

void G2048::rotate_g(const int rotations, g4x4 g) {
  g4x4 r_grid{g};
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
  g = r_grid;
}


void G2048::collapse(g4x4 g) {
  g4x4 coll{initial};
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
  g = coll;
}

int G2048::combine(g4x4 g) {
  g4x4 cmb{initial};
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
  g = cmb;
  return score_diff;
}

void G2048::set_r_numbers(g4x4 g) {
  int r{0}; int x{0};
  std::vector<int> blanks[16]; int bn;
  for (auto& row : g) {
    x = 0;
    for (auto& v : row) {
      if (!v) {
        blanks[bn] = {r, x};
      }
      x++;
    }
    r++;
  }
  auto& space{blanks[rand() % bn]};
  g[space[0]][space[1]] = ((rand() % 11) / 9) * 2;
}

// 0 left, 1 down, 2 right, 3 up 
int G2048::move(int direction) {
  auto& g{this->grid};
  rotate_g(direction, g);
  collapse(g);
  auto s = combine(g);
  rotate_g((4 - direction) % 4, g);
  set_r_numbers(g);
  return s;
}

/*
class M_node {
  public:
    M_node(int m, float p) { 
      n_count++;
      move = m; prob = p; }

    ~M_node() { n_count--; }

    float prob;
    int move;
    G_node* br[2];
};
*/

G2048 n_move(int direction, g4x4 g, int sc) {
  static G2048 grid{G2048(g, sc)};
  grid.move(direction);

  return grid;
}

class G_node {
  public:
    G_node(G2048 g, float p) { 
      n_count++;
      n_grid = g; prob = p;
    }

    ~G_node() { n_count--; }

    float prob;
    G2048 n_grid;
    G_node* br[8];

    void add_ns() {
      int node_n{0}; 
      for   
      
    }
};


int main() {
  std::cout << "'\n'";
}