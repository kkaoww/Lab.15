#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double t[][N]){
    for(int i = 0; i < N; i++){
    cout << "Row " << i + 1 << ": ";
        for(int j = 0; j < N; j++){
         cin >> t[i][j] ;
        }
    }
}

void findLocalMax(const double t[][N], bool k[][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
        {
			if ((i > 0 && i <= N - 2) && (j > 0 && j <= N - 2))
			{
				if ((t[i][j] >= t[i - 1][j]) && (t[i][j] >= t[i][j - 1]) && (t[i][j] >= t[i][j + 1]) && (t[i][j] >= t[i + 1][j]))
				{
					k[i][j] = 1;
				}
				else k[i][j] = 0;
			}
			else k[i][j] = 0;
		}
	}
}

void showMatrix(const bool t[][N]){
 for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; j++){
    cout << t[i][j] << " " ;
      }
  cout << endl;
  }
}

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}
