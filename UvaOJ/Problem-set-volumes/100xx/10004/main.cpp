#include <iostream>
using namespace std;

#define CHECKED 2
#define QUEUED 1
#define UNCHECKED 0

#define NOCOLOR 0
#define RED 1
#define BLUE 2

struct node {
    int status;
    int color;
} a [200];

int nodes;
bool matrix[200][200];

void reset() {
  for (int i = 0; i < 200; i++ ) {
    a[i].status = UNCHECKED;
    a[i].color = NOCOLOR;
  }
  for (int i=0; i<200; i++) {
    for (int j=0; j<200; j++) {
      matrix[i][j] = false;
    }
  }
}

int nextNode() {
    for ( int i=0; i<nodes; i++) {
        if (a[i].status == QUEUED) {
          return i;
        }
    }
    return -1;
}

int main () {
  ios_base::sync_with_stdio (false);
  while (cin >> nodes) {
    if (nodes == 0)
      break;

    bool isColorable = true;

    reset();

    int edges;
    cin >> edges;

    int x, y;
    for (int i=0; i<edges; i++) {
        cin >> x >> y;
        matrix[x][y] = true;
    }

    a[0].color = RED;
    a[0].status = QUEUED;

    int index = nextNode();

    while (index != -1) {

      if (a[index].color == RED) {
          for (int i=0; i < nodes; i++) {
              if (matrix[index][i] == true) {
                if (a[i].color == RED) {
                  isColorable = false;
                }
                else {
                  a[i].color = BLUE;
                }
                if (a[i].status == UNCHECKED) {
                  a[i].status = QUEUED;
                }
              }
          }
      }

      else {
        for (int i=0; i<nodes; i++) {
          if ( matrix [index] [i] == true ) {
            if (a[i].color == BLUE) {
              isColorable = false;
            }
            else {
              a[i].color = RED;
            }
            if (a[i].status == UNCHECKED) {
              a[i].status = QUEUED;
            }
          }
        }

      }

      a[index].status = CHECKED;
      index = nextNode();

    }

    if ( isColorable ) {
      cout << "BICOLORABLE." << endl;
    }
    else {
      cout << "NOT BICOLORABLE." << endl;
    }
  }

  return 0;
}
