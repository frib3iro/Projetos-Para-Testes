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
	int NumerosAcertados[tam] = {};
	int MeuJogo[tam] = {};
	int JogoMaquina[tam] = {};

	// Inicio da geração do jogo automático ou manual
	cout << "Digite [01] para gerar um jogo manual\n"
		<< "Digite [02] para gerar um jogo automático : ";

	cout << "\n\nQual sua resposta: ";
	
	int jogo;
	cin >> jogo;
	if(jogo == 1)
	{
		cout << "Digite os números do seu jogo:\n";
		gerarJogo(MeuJogo, tam);
		cout << "\nO seu jogo é:  ";
		exibir(MeuJogo, tam);
	}
	else if(jogo == 2)
	{
		gerarSorteio(MeuJogo, tam);
		cout << "\nO seu jogo é:  ";
		exibir(MeuJogo, tam);
	}

	// Mostra resultado da mega sena
	cout << "\n\nA Mega Sena é: ";
	gerarSorteio(JogoMaquina, tam);
	exibir(JogoMaquina, tam);

	// Inicio do gerarSorteio da mega sena
	gerarSorteio(JogoMaquina, tam);

	int acertos = 0;
	for(int i = 0; i < tam; i++)
	{
		for(int j = 0; j < tam; j++)
		{
			if(MeuJogo[i] == JogoMaquina[j])
			{
				NumerosAcertados[i] = MeuJogo[i];
				acertos++;
				break;
			}
			else
			{
				continue;
			}
		}
	}


	if(acertos == 0)
	{
		cout << "\n\nSinto muito, você não obteve nenhum acerto!\n";
	}
	else
	{
		if(acertos > 1)
		{
			cout << "\n\nVocê obteve " << acertos << " acertos!\n";
			exibir(NumerosAcertados, tam);
		}
		else
		{
			cout << "\n\nVocê obteve " << acertos << " acerto! ";
			exibir(NumerosAcertados, tam);
		}
	}

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
	cout << "\n--------------------------------";
}
