/* Solution of polygon by edomora97
 * Discard the squares cutted by a side of the polygon.
 * Check for the ones left if the square is inside or outside the polygon.
 * For a step it's required to find the center of a square, for using ints only
 * all the coordinates are doubled.
 *
 * Complexity O(N²F)
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXF 1000
#define MAXN 100

// input data
int F, i;
int X[MAXF];
int Y[MAXF];

struct segment_t {
  int x1, y1;
  int x2, y2;
  int a, b, c;  // ax + by = c

  segment_t() {}

  segment_t(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
    a = y1 - y2;
    b = x2 - x1;
    c = x2 * y1 - x1 * y2;
  }

  bool intersects(const segment_t& oth) const {
    // we want to solve Ax=b
    // where A = [a1 b1]
    //           [a2 b2]
    // and   b = [c1]
    //           [c2]
    // x=A^-1 * b
    // where A^-1 = 1/detA [ b2 -b1 ]
    //                     [ -a2 a1 ]
    // so x = [ b2c1-b1c2 ]
    //        [ a1c2-a2c1 ]
    int det = a * oth.b - b * oth.a;
    // det=0 <=> the segments are parallel
    if (det == 0) {
      // parallel segments are not a problem
      return false;
    }
    // those coordinates are multiplied by det
    int x = oth.b * c - b * oth.c;
    int y = a * oth.c - oth.a * c;
    return pointInSegment(x, y, det) && oth.pointInSegment(x, y, det);
  }

  // assuming the point is in the line, is it in the range of the segment?
  // x and y should be scaled by a factor of 1/det
  bool pointInSegment(int x, int y, int det) const {
    // express the line as:
    // x = x1 + (x2 - x1)t
    // y = y1 + (y2 - y1)t
    // then (x1,y1) is at t=0 and (x2,y2) is at t=1, (x,y) is in the segment
    // iff it has a 0<t<1.
    // t = (x-x1)/(x2-x1) = ax/bx = (y-y1)/(y2-y1) = ay/by
    // with the appropriate scaling due to 1/det
    int ax = x - det * x1, bx = det * (x2 - x1);
    int ay = y - det * y1, by = det * (y2 - y1);
    // make the denominators positive
    if (bx < 0) {
      bx = -bx;
      ax = -ax;
    }
    if (by < 0) {
      by = -by;
      ay = -ay;
    }
    // non-vertical lines
    if (bx != 0) {
      return 0 < ax && ax < bx;
    }
    // non-horizontal lines
    if (by != 0) {
      return 0 < ay && ay < by;
    }
    cerr << "Degenerate segment: (" << x1 / 2 << "," << y1 / 2 << ") -> ("
         << x2 / 2 << "," << y2 / 2 << ") " << a << "x+" << b << "y=" << c / 2
         << endl;
    assert(!"Degenerate segment");
  }
};

ostream& operator<<(ostream& o, const segment_t& s) {
  o << "(" << s.x1 / 2 << "," << s.y1 / 2 << ") -> (" << s.x2 / 2 << ","
    << s.y2 / 2 << ") ~ " << s.a << "x+" << s.b << "y=" << s.c / 2;
  return o;
}

int main() {
  assert(1 == scanf("%d", &F));
  for (i = 0; i < F; i++) {
    assert(2 == scanf("%d%d", &X[i], &Y[i]));
    X[i] *= 2;
    Y[i] *= 2;
  }

  vector<segment_t> segments(F);
  for (int i = 0; i < F; i++) {
    int j = (i + 1) % F;
    segments[i] = segment_t(X[i], Y[i], X[j], Y[j]);
  }
  int sol = 0;

  // dx and dy for all the 4 sides and 2 diagonals of a square
  int dx[][2] = {{0, 2}, {2, 2}, {0, 2}, {0, 0}, {0, 2}, {0, 2}};
  int dy[][2] = {{0, 0}, {0, 2}, {2, 2}, {0, 2}, {0, 2}, {2, 0}};
  for (int x = 0; x <= 2 * MAXN; x += 2) {
    for (int y = 0; y <= 2 * MAXN; y += 2) {
      // check every square:
      // - if a line goes inside the square it is discarded
      //   * a line goes inside if it intersects one of the 4 sides or one of
      //     the 2 diagonals
      //   * since touching segments do not intersect, the diagonals are
      //     required
      // - if not line intersects the square, check if its center is inside the
      //   polygon
      //   * consider vertical segment from the center to the top of the space
      //   * if it intersects an even number of sides it's outside of the
      //     polygon
      //   * starting from the center guarantees that it's not collinear with
      //     any side
      bool intersected = false;
      for (int k = 0; k < 6 && !intersected; k++) {
        segment_t s2(x + dx[k][0], y + dy[k][0], x + dx[k][1], y + dy[k][1]);
        for (const segment_t& s : segments) {
          if (s2.intersects(s)) {
            intersected = true;
            break;
          }
        }
      }
      if (intersected) continue;
      // since all the coordinates are doubled, the center is at (x+1,y+1)
      segment_t goUp(x + 1, y + 1, x + 1, 2 * MAXN + 1);
      int numIntersects = 0;
      for (const segment_t& s : segments) {
        if (goUp.intersects(s)) numIntersects++;
      }
      if (numIntersects % 2 == 1) {
        sol++;
      }
    }
  }

  printf("%d\n", sol);
  return 0;
}
