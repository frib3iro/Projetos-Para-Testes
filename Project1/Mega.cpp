#include <iomanip>
#include <vector>
#include <iostream> 
#include <random> 
#include <algorithm> 
using namespace std;

const int tam = 6;
int random();
void gerarSorteio(vector<int> &sorteio);
void gerarJogo(vector<int> &jogo);
void exibir(vector<int> &jogo);

int main()
{
	// Cria??o dos vetores "jogo" e "acertos" para armazenar os jogos
	//int jogo[TamVet] = {};
	//int sorteio[TamVet] = {};
	//int acerto[TamVet] = {};

	vector<int> jogo;
	vector<int> sorteio;
	vector<int> acerto;

	// Bloco de resposta para cria??o do jogo
	cout << "Digite [1] para gerar um jogo manual:\n"
		 << "Digite [2] para gerar um jogo autom?tico:\n\n";
	cout << "Digite sua resposta: ";
	int resposta;
	cin >> resposta;
	if(resposta == 1)
	{
		gerarJogo(jogo);
	}
	else if(resposta == 2)
	{
		gerarSorteio(jogo);
	}

	// Mostrando o jogo criado
	cout << "\nO jogo escolhido foi:\n";
	exibir(jogo);

	// Bloco para gera??o do gerarSorteio 
	cout << "\n\nIniciando o sorteio...\n\n";
	int dezenas = 0;
	while(true)
	{
		gerarSorteio(sorteio);
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

void gerarSorteio(vector<int> &sorteio)
{
	int num = random();
	int i = 0;
	while(i < sorteio.size())
	{
		if(sorteio[i] == num)
		{
			num = random();
			i = 0;
			continue;
		}
		else if(sorteio[i] == 0)
		{
			sorteio[i] = num;
			i = 0;
			num = random();
		}
		else
		{
			i++;
		}
	}
	sort(sorteio.begin(), sorteio.end());
}

void gerarJogo(vector<int> &jogo)
{
	for(int i = 0; i < jogo.size(); i++)
	{
		cout << "\nDigite o " << i + 1 << "? n?mero: ";
		int num;
		cin >> num;
		jogo[i] = num;
	}
	sort(jogo.begin(), jogo.end());
}

void exibir(vector<int> &jogo)
{
	for(int i = 0; i < jogo.size(); i++)
		cout << internal << setw(2) << setfill('0') << jogo[i] << " ";
	
}
