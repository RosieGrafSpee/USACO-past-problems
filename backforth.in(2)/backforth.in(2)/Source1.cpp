#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ifstream input("backforth.in");
	ofstream output("backforth.out");
	multiset<int> barn[2];

	int in;
	for (int i = 0; i < 20; i++)
	{
		input >> in;
		barn[i / 10].insert(in);
	}

	int tank[2] = { 0, 0 };
	for (int i = 0; i < 5; i++)
	{
		for (multiset<int>::iterator j = barn[i % 2].begin(); j != barn[i % 2].end(); j++)
		{
			barn[(i + 1) % 2].insert(*j);
			tank[(i + 1) % 2] += *j; tank[i % 2] -= *j;
			barn[i % 2].erase(j);
		}
	}
}