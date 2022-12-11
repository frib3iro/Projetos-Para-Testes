#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	int zipCode = 9;
	cout << internal << setw(2) << setfill('0') << zipCode << endl;

	return 0;
}