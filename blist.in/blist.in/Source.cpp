#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream input("blist.in");
	ofstream output("blist.out");

	int n;
	input >> n;

	vector<int> start, finish, buckets;
	for (int i = 0; i < n; i++)
	{
		start.push_back(0);
		finish.push_back(0);
		buckets.push_back(0);

		input >> start[i] >> finish[i] >> buckets[i];
	}

	int loc[1001] = {}; 
	for (int i = 0; i < n; i++)
	{
		for (int j = start[i]; j <= finish[i]; j++) // <? <=?
		{
			loc[j] += buckets[i];
		}
	}

	int max = 0;
	for (int i = 0; i < 1001; i++)
	{
		max = max > loc[i] ? max : loc[i];
	}

	output << max;
}