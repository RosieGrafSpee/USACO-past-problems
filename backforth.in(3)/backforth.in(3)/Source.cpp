#include <fstream>
#include <vector>
#include <set>

using namespace std;

multiset<int> barn[2];
int tank[2] = { 1000, 1000 };

set<int> results;

void count(int day = 0)
{
	if (day >= 4)
	{
		results.insert(tank[0]);
		return;
	}

	multiset<int> copy = barn[day % 2];

	for (multiset<int>::iterator j = copy.begin(); j != copy.end(); j++)
	{
		int i = *j;

		barn[(day + 1) % 2].insert(i);
		tank[(day + 1) % 2] += i; tank[day % 2] -= i;
		barn[day % 2].erase(barn[day % 2].find(i));
		count(day + 1);

		barn[(day + 1) % 2].erase(barn[(day + 1) % 2].find(i));
		barn[day % 2].insert(i);
		tank[(day + 1) % 2] -= i; tank[day % 2] += i;
	}
}

int main()
{
	ifstream input("backforth.in");
	ofstream output("backforth.out");

	int in;
	for (int i = 0; i < 20; i++)
	{
		input >> in;
		barn[i / 10].insert(in);
	}

	count();

	output << results.size();
}