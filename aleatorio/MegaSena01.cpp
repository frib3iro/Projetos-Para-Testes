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
	// Criação dos vetores "jogo" e "acertos" para armazenar os jogos
	int jogo[tam] = {};
	int sorteio[tam] = {};
	int acerto[tam] = {};

	// Bloco de resposta para criação do jogo
	cout << "Digite [1] para gerar um jogo manual:\n"
		<< "Digite [2] para gerar um jogo automático:\n\n";
	cout << "Digite sua resposta: ";
	int resposta;
	cin >> resposta;
	if(resposta == 1)
	{
		gerarJogo(jogo, tam);
	}
	else if(resposta == 2)
	{
		gerarSorteio(jogo, tam);
	}

	// Mostrando o jogo criado
	cout << "\nO jogo escolhido foi:\n";
	exibir(jogo, tam);

	// Bloco para geração do Sorteio 
	cout << "\n\nIniciando o sorteio...\n\n";
	int dezenas = 0;
	while(true)
	{
		gerarSorteio(sorteio, tam);
		for(int i = 0; i < tam; i++)
		{
			if(jogo[i] == sorteio[i])
			{
				acerto[i] = jogo[i];
				dezenas++;
			}
		}

	}

	// fim do programa
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

void gerarJogo(int vet[], int tam)
{
	for(int i = 0; i < tam; i++)
	{
		cout << "\nDigite o " << i + 1 << "º número: ";
		int num;
		cin >> num;
		vet[i] = num;
	}
	BubbleSort(vet, tam);
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
		cout << internal << setw(2) << setfill('0') << vet[i] << " ";

}
