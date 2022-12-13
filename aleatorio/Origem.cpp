#include <iomanip>
#include <iostream> 
#include <random> 
using namespace std;

const int TamVet = 6;
int random();

int main()
{
	cout << "preenchendo cada elemento do vetor\n";

	int vet[TamVet] = {};
	int num = random();
	int i = 0;

	while(i < TamVet)
	{
		if(vet[i] == num)
		{
			num = random();
			i = 0;
			continue;
		}
		else if(vet[i] == 0)
		{
			vet[i] = num;
			i = 0;
			num = random();
		}
		else
		{
			i++;
		}
	}

	int aux = 0;
	for(int i = 0; i < TamVet; i++)
	{
		if(vet[i] < vet[i + 1])
		{
			aux = vet[i];
			vet[i] = vet[i + 1];
			vet[i + 1] = aux;
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

int random()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 60);
	return dist(mt);
}
