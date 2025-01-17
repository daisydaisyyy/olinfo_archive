/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>
using namespace std;
// constraints
#define MAXN 100000

// input data
int N, P, i;
int H[MAXN];

bool can_destroy(int i){
	if(i == 0)	return N==1 || H[i] > H[i+1];
	else if(i == N-1)	return H[i] > H[i-1];
	else {
		return  ((H[i] > H[i+1]) &&  (H[i] > H[i-1]));
	}
}

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input1.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &P));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &H[i]));

    // insert your code here
	vector<int> next;
	for(i=0;i<N; i++) {
		if(can_destroy(i)) {
			//cout << "can destroy " << i << endl;
			next.push_back(i);
		}
	}

	for(int p=0;p<P;p++) {
		vector<int> following;
		for(int n:next) {
			H[n] = 0; // set to 0 the destroyed houses 
			if(n > 0 && can_destroy(n-1)) {
				//cout << "destroyed " << n-1 << endl;
				following.push_back(n-1); // set the house as destroyed by next plane
			}
			if(n > 0 && can_destroy(n+1)) {
				//cout << "destroyed " << n+1 << endl;
				following.push_back(n+1);
			}
		}
		next = following;
	}
	
    // count houses destr
	int c = 0;
	for(i=0; i < N ; i++ )
	{
		if(H[i] == 0) c++;
	}

    printf("%d\n", c); // print the result
    return 0;
}
