#include <iostream> 
using namespace std;

void selecao(int[], int);
const int tam = 10;
int main()
{
	int vet[tam] = { 3,6,7,4,10,5,8,2,1,9 };
	selecao(vet, tam);

	for(int v : vet)
		cout << v << " ";

	cout << endl << endl;


	system("pause");
	return 0;
}

void selecao(int vet[], int tam)
{
	int aux;
	for(int i = 0; i < tam; i++)
	{
		for(int j = i + 1; j < tam; j++)
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
