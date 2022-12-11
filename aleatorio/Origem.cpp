#include <iomanip>
#include <iostream> 
#include <random> 
using namespace std;

int aleatorio();

int main()
{
	cout << "preenchendo cada elemento do vetor\n";
	int vet[6] = {};
	for(int i = 0; i < 6; i++)
	{
		int num = aleatorio();
		for(int j = 0; j < 6; j++)
		{
			if(vet[i] == num)
			{
				break;
			}
			else
			{
				vet[i] = num;
				break;
			}
		}
	}

	cout << endl;

	cout << "Mostrando cada elemento do vetor\n";
	for(int v : vet)
		cout << internal << setw(2) << setfill('0') << v << " ";
	cout << endl << endl;

	system("pause");
	return 0;
}

int aleatorio()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 6);
	return dist(mt);
}
