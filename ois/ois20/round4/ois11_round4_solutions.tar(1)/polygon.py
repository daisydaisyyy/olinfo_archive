#!/usr/bin/env pypy3
MAXN = 100

class Segment:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.a = y1 - y2
        self.b = x2 - x1
        self.c = x2 * y1 - x1 * y2

    def intersects(self, oth):
        det = self.a * oth.b - self.b * oth.a
        if det == 0:
            return False
        x = (oth.b * self.c - self.b * oth.c) / det
        y = (self.a * oth.c - oth.a * self.c) / det
        return self.pointInSegment(x, y) and oth.pointInSegment(x, y)

    def pointInSegment(self, x, y):
        ax, bx = x - self.x1, self.x2 - self.x1
        ay, by = y - self.y1, self.y2 - self.y1
        if bx < 0:
            ax, bx = -ax, -bx
        if by < 0:
            ay, by = -ay, -by
        if bx != 0:
            return 0 < ax < bx
        if by != 0:
            return 0 < ay < by
        assert False

# input data
F = int(input().strip())
X = []
Y = []
for _ in range(F):
    x, y = map(int, input().split())
    X += [x]
    Y += [y]

segments = []
for i in range(F):
    j = (i+1) % F
    segments += [Segment(X[i], Y[i], X[j], Y[j])]

sol = 0
dx = [[0,1], [1,1], [0,1], [0,0], [0,1], [0,1]]
dy = [[0,0], [0,1], [1,1], [0,1], [0,1], [1,0]]
for x in range(MAXN+1):
    for y in range(MAXN+1):
        inters = False
        for ((dx1, dx2), (dy1, dy2)) in zip(dx, dy):
            s2 = Segment(x+dx1, y+dy1, x+dx2, y+dy2)
            for s in segments:
                if s2.intersects(s):
                    inters = True
                    break
            if inters:
                break
        if inters:
            continue
        goUp = Segment(x+0.5, y+0.5, x+0.5, MAXN+1)
        numInters = 0
        for s in segments:
            if goUp.intersects(s):
                numInters += 1
        if numInters % 2 == 1:
            sol += 1
print(sol)
