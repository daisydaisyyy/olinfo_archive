// @check-accepted: task

#include <iostream>

using namespace std;

int digit_sum(int x)
{

	int res = 0;
	while (x > 0)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	int d, n;
	cin >> d >> n;

	long long int s = d;
	for (int i = 2; i <= n; i++)
		s = s * 2 + digit_sum(i);

	cout << s << '\n';
	return 0;
}
