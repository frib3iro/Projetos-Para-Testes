#include <iomanip>
#include <vector>
#include <iostream> 
#include <random> 
#include <algorithm> 
using namespace std;

void imprime(vector<int>& vet);

int random();
void gerarSorteio(vector<int> &vet);
void gerarJogo(vector<int> &vet);
void exibir(vector<int> &vet);

int main()
{
	vector<int> vet = { 3,5,1,4,2 };
	sort(vet.begin(), vet.end());

	imprime(vet);

	cout << "\n\n";
	system("pause");
	return 0;
}

void imprime(vector<int> &vet)
{
	for(int i = 0; i < vet.size(); i++)
	{
		cout << vet[i] << " ";
	}
}
