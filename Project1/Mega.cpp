#include <iomanip>
#include <iostream> 
#include <random> 
using namespace std;

int aleatorio();

int main()
{
	

	cout << "preenchendo cada elemento do vetor\n";
	int mega[6];
	for(int i = 0; i < 6; i++)
		mega[i] = aleatorio();
	cout << endl;

	cout << "preenchendo cada elemento do vetor02\n";
	int vet[6];
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(vet[i] == aleatorio())
			{
				break;
			}
			else
			{
				vet[i] = aleatorio();
			}
		}
	}
		
	cout << endl;

	cout << "Mostrando cada elemento do vetor 01\n";
	for(int v : mega)
		cout << internal << setw(2) << setfill('0') << v << " ";
	cout << endl << endl;

	cout << "Mostrando cada elemento do vetor 02\n";
	for(int i = 0; i < 6; i++)
		cout << internal << setw(2) << setfill('0') << mega[i] << " ";
	cout << endl << endl;

	system("pause");
	return 0;
}

int aleatorio()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 60);
	return dist(mt);
}
