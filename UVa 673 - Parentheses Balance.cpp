#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n , f;
	string x;
	cin >> n;
	f = getchar();
	while (n--)
	{
		string x;
		getline(cin, x);
		if (x.empty())
		{
			cout << "Yes" << endl;
			continue;
		}
		stack<char> p;
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == '(' && x[i] == '[')
				p.push(x[i]);
			else if (!p.empty() &&p.top() == '(' && x[i] == ')')
				p.pop();
			else if (!p.empty() && p.top() == '[' && x[i] == ']')
				p.pop();
			else
				p.push(x[i]);
		}
		if (p.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

