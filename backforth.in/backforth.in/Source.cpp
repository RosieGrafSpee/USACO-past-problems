#include <vector>
#include <fstream>
#include <set>

using namespace std;

int main()
{
	ifstream input("backforth.in");
	ofstream output("backforth.out");

	multiset<int> first, second; int var;
	for (int i = 0; i < 10; i++)
	{
		input >> var;
		first.insert(var);
	}

	for (int i = 0; i < 10; i++)
	{
		input >> var;
		second.insert(var);
	}

	for ()
}