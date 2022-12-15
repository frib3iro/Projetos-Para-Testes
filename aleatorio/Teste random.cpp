#include <iomanip>
#include <iostream> 
#include <random> 
using namespace std;

const int tam = 6;
int random();
void gerarSorteio(int[], int);
void gerarJogo(int[], int);
void BubbleSort(int[], int);
void exibir(int[], int);

int main()
{
	int MeuJogo[tam] = {};
	int JogoMaquina[tam] = {};

	gerarSorteio(MeuJogo, tam);
	cout << "\nO seu jogo é:  ";
	exibir(MeuJogo, tam);
	cout << "\n--------------------------------" << endl;

	// Mostra resultado da mega sena
	cout << "\nA Mega Sena é: ";
	gerarSorteio(JogoMaquina, tam);
	exibir(JogoMaquina, tam);
	cout << "\n--------------------------------" << endl;

	cout << endl;
	 
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

void gerarSorteio(int vet[], int tam)
{
	int num = random();
	int i = 0;
	while(i < tam)
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
	BubbleSort(vet, tam);
}

void gerarJogo(int MeuJogo[], int tam)
{
	for(int i = 0; i < tam; i++)
	{
		cout << "\nDigite o " << i + 1 << "º número: ";
		int num;
		cin >> num;
		MeuJogo[i] = num;
	}
	BubbleSort(MeuJogo, tam);
}

void BubbleSort(int vet[], int tam)
{
	int aux;
	for(int i = 0; i < tam; ++i)
	{
		for(int j = i + 1; j < tam; ++j)
		{
			if(vet[i] > vet[j])
			{
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
}

void exibir(int vet[], int tam)
{
	for(int i = 0; i < tam; i++)
	{
		cout << internal << setw(2) << setfill('0') << vet[i] << " ";
	}
}
