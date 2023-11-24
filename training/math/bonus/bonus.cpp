/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
long long N, i;
long long S[MAXN], P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    assert(1 == scanf("%lld", &N));
    for(i=0; i<N; i++) {
        assert(1 == scanf("%lld", &S[i]));
        assert(1 == scanf("%lld", &P[i]));
    }

	
	
    //
    long long int num=0,den=0,pos=0,c,a=0,d,b=0; //setta c e d
    //p punt max, S punt fatto
	//a/b>=c/d   a*d>b*c
	
	for(i=0;i<N;i++){
		num+=S[i];
		den+=P[i];
	}
	
	c=num-S[0];
	d=den-P[0];
	
	for(i=1;i<N;i++){
		a=num-S[i];
		b=den-P[i];
		if(a*d>c*b){
			c=a;
			d=b;
			pos=i;
		}
	}
    printf("%lld\n",pos); // print the result
    return 0;
}
