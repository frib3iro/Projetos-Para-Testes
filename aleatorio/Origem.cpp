#include <iomanip>
#include <iostream> 
#include <random> 
using namespace std;

const int TamVet = 6;
int random();
void Mega(int[], int);
void BubbleSort(int[], int);
void MostrarJogo(int[], int);

int main()
{
	cout << "Criando um jogo da Mega Sena...\n\n";
	int vet[TamVet] = {};
	
	Mega(vet, TamVet);
	BubbleSort(vet, TamVet);
	MostrarJogo(vet, TamVet);

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

void Mega(int vet[], int TamVet)
{
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
}

void BubbleSort(int vet[], int TamVet)
{
	for(int i = 0; i < TamVet; ++i)
	{
		for(int j = i + 1; j < TamVet; ++j)
		{
			int aux = 0;
			if(vet[i] > vet[j])
			{
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
}

void MostrarJogo(int vet[], int TamVet)
{
	for(int i = 0; i < TamVet; i++)
	{
		cout << internal << setw(2) << setfill('0') << vet[i] << " ";
	}
	cout << endl << endl;
}
