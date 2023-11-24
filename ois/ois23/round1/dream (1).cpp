#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int reverse(int num)
{
    int rev = 0;
    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    return rev;
}

int main()
{
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int K, X;
    cin >> K >> X;

    long long int pal[K];

    long long int smallest = pow(10, X - 1);
    // cout << "S" << smallest << endl;
    long long int largest = pow(10, X) - 1;
    // cout << "L" << largest << endl;
    int k = 0;
    for (long long int i = smallest; i <= largest, k < K; i++)
    {
        if (i == reverse(i))
        {
            pal[k] = i;
            k++;
        }
    }

    long long int sum = 0;
    for (int i = 0; i < K; i++) {
        // cout << "P" << pal[i] << endl;
        sum += pal[i];
    }

    cout << sum % 666013;
    
    return 0;
}
