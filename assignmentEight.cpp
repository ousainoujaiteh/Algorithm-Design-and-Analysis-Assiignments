#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

// creating a structure to store peanuts, catfood and the M/N
struct Room
{
	int peanut;
	int catFood;
	float rate;
};

// sorting rooms according to rate

bool compare(Room a, Room b)
{
	return a.rate > b.rate;
}

int main()
{
	int m, n;
	double sum;
	vector<float> storage;
	vector<Room> rooms;

	Room strinfo; // variable for structure
	cin >> m >> n;
	while (m != -1 && n != -1) //check whether m and n are -1
	{
		rooms.clear();
		// cout << setprecision(3);

		sum = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> strinfo.peanut >> strinfo.catFood;

			cout << setprecision(3);
			strinfo.rate = (float)strinfo.peanut / strinfo.catFood;
			rooms.push_back(strinfo);
		}

		// sorting based on rate

		sort(rooms.begin(), rooms.end(), compare);

		// calculating the maximum amount of peanuts

		for (int i = 0; i < rooms.size(); i++)
		{
			if (m <= rooms[i].catFood)
			{
				sum += m * rooms[i].rate;
				// storage.push_back(sum);
				break;
			}
			else
			{
				sum += rooms[i].peanut;
				m -= rooms[i].catFood;
			}
		}
		storage.push_back(sum);

		cin >> m >> n;
	}

	for (int i = 0; i < storage.size(); i++)
		cout << fixed << setprecision(3) << storage[i] << "\n"; // printing the decimal values answer with fixed size

	return 0;
}
