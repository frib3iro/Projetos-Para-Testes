#include <iomanip>
#include <iostream> 
#include <random> 
using namespace std;

int main()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 15);

	cout << "preenchendo cada elemento do vetor\n";
	int mega[6];
	for(int i = 0; i < 6; i++)
		mega[i] = dist(mt);
	cout << endl;

	cout << "Mostrando cada elemento do vetor 01\n";
	for(int v : mega)
		cout << internal << setw(2) << setfill('0') << v << " ";
	cout << endl;

	cout << "Mostrando cada elemento do vetor 02\n";
	for(int i = 0; i < 6; i++)
		cout << internal << setw(2) << setfill('0') << mega[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}