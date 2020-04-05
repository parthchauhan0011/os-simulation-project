#include <iostream> 
using namespace std; 

int main() 
{ 
	int n=5,m=4,i,j,k;  
	int allocate[5][4] = { { 0, 1, 0, 2 },{ 1, 0, 0, 0 }, { 1, 3, 5, 4 }, { 0, 6, 3, 2 }, { 0, 0, 1, 4 } }; 
	int maxi[5][4] = { { 0, 0, 1, 2 },{ 1, 7, 5, 0 }, { 2, 3, 5, 6 },{ 0, 6, 5, 2 }, { 0, 6, 5, 6 } }; 
	int available[4] = { 1, 5, 2, 0 }; 
	int f[n], res[n], ok = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = maxi[i][j] - allocate[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > available[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					res[ok++] = i; 
					for (y = 0; y < m; y++) 
						available[y] += allocate[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 
	cout << "Safe Sequence is \n\n"; 
	for (i = 0; i < n - 1; i++) 
		cout << "Process" << res[i] << "->"; 
	cout << "Process" << res[n-1] <<endl; 
	return (0); 
} 


