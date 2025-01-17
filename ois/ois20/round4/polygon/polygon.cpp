/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXF 1000
#define MAXN 100

// input data
int F, i;
int X[MAXF];
int Y[MAXF];

// discard the segments cutted by the polygon 

struct segment {
	int x1, y1, x2, y2;
	int a,b,c; // ax + by = c 
};

create_segment(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2){
	a = y2 - y1; 
	b = x1 - x2; 
	c = x1*x2 + y1*y2;
}

bool intersect(const create_segment& oth) const {
	//trova il determinante 
	det = a * oth.b - b * oth.a 
	if(det == 0) return false; // paralleli 
	x = oth.b * c - b * oth.c; 
	y = a * oth.c - oth.a * c; 
	return pointIn(x,y,det) && pointIn(x,y,det);
}


bool pointIn(x,y,det) {


}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &F));
    for(i=0; i<F; i++)
        assert(2 == scanf("%d%d", &X[i], &Y[i]));

    // insert your code here
	

    printf("%d\n", 42); // print the result
    return 0;
}
