#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Test
{
public:
	int operator()(int value) const
	{
		if (value < 0)
			return 0;
		else
			return 1;
	}
};

int add(int a, int b)
{
	return a + b;
}

class Del
{
public:
	int operator()(int a, int b) const
	{
		return a - b;
	}
};

int main(int argc, char* argv[])
{
	cout << Test()(1) << endl;

	int (*funcAdd) (int, int);
	funcAdd = add;

	cout << (*funcAdd)(1, 2) << endl;

	map< string, function<int(int, int)>> myoper = {
		{"add", add},
		{"del", Del()}
	};

	cout << myoper["add"](3, 2) << endl;
	cout << myoper["del"](3, 2) << endl;

	return 0;
}