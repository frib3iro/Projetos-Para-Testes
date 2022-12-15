#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
	vector<int> a;
	vector<int> b;
	int tam = a.size();


	a.push_back(10);
	a.push_back(7);
	a.push_back(5);
	a.push_back(2);

	cout << "\nTamanho do vector a: " << a.size() << endl;

	cout << "\nVector a: ";

	sort(a.begin(), a.end());

	for(int v : a)
	{
		cout << internal << setw(2) << setfill('0') << v << " ";
	}
	cout << "\n\n";

	system("pause");
	return 0;
}