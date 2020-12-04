#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
#include<tgmath.h>
using namespace std;



int main()
{
	FILE* f; char fn[100], link[]="H:\\Documents on H\\DA GTLT\\proj\\Files\\";
	printf("File name(*.inp): "); gets(fn);
	strcat(link,fn);
	strcpy(fn,link);
	if(!strchr(fn,'.')) strcat(fn,".inp");
	cout << fn <<endl;
	f = fopen(fn,"r");
	if(f== NULL)
	cout << "File error!";
	else
	{
		int n,m;
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&m);
		int arr[n][n];
		double arrGhep[n][2*n];
		
		cout << "Ma tran doc tu file tren:\n";
		printf("%6d%6d\n",n,n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fscanf(f,"%d",&arr[i][j]);
				cout << setw(6) << arr[i][j];
			}
			cout << "\n";	
		}
		system("pause");
		//ghep ma tran voi ma tran don vi
		for(int i = 0; i< n; i++){ 
			for(int j = 0; j< 2*n; j++)
				if(j>=n){
					if(j==(n+i)) arrGhep[i][j]=1;
					else arrGhep[i][j]=0;
				}
				else arrGhep[i][j] = arr[i][j];
		}	
	
		cout << "\nMa tran sau khi ghep:\n";
		for(int i=0;i<n;i++){ //in ra lai ma tran vua ghep
				for(int j=0;j<2*n;j++){
					cout << setw(6) << arrGhep[i][j];
				}
				cout << "\n";	
			}
			system("pause");
			
			
		// Gauss-Jordan
		for (int i = 0; i < n; i++) {
			if (arrGhep[i][i] == 0) { // kiem tra = 0
				if (i == (n - 1)) {
					cout << "Ma tran suy bien!" << endl;
					return 0;
				}
				for (int j = i + 1; j < n; j++) { // duyet tim hang duoi hang i co so o cot i khac 0
					if (arrGhep[j][i] != 0) {
						for (int k = 0; k < 2 * n; k++) { // hoan doi 2 hang cho nhau
							arrGhep[i][k] += arrGhep[j][k];
							arrGhep[j][k] = arrGhep[i][k] - arrGhep[j][k];
							arrGhep[i][k] -= arrGhep[j][k];
						}
						break;
					}
					if (j == (n - 1)) { // neu duyet tim den hang cuoi ma cac phan tu van bang khong
						cout << "Ma tran suy bien!" << endl;
						return 0;
					}
				}
			}

			double mul = 1 / arrGhep[i][i]; // bien doi arrGhep[i][i] = 1
			for (int k = 0; k < 2 * n; k++) arrGhep[i][k] *= mul;

			if (arrGhep[i][i] == 1) {
				for (int k = i + 1; k < n; k++) { // bien doi cac so con lai nam duoi hang i tren cot i thanh 0
					if (arrGhep[k][i] != 0) {
						double temp = arrGhep[k][i];
						for (int t = 0; t < 2 * n; t++) {
							arrGhep[k][t] -= temp * arrGhep[i][t];
						}
					}
				}
			}


			for (int j = i - 1; j >= 0; j--) { //cuoi cung la bien doi phan tam giac phia tren thanh 0
				if (arrGhep[j][i] == 0) continue;
				else {
					double temp = arrGhep[j][i];
					for (int t = 0; t < 2 * n; t++) {
						arrGhep[j][t] -= temp * arrGhep[i][t];
					}		
				}
			}
		}

		cout << "\nMa tran sau khi qua bien doi Gauss-Jordan:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				printf("%6.2f", arrGhep[i][j]);
			}
			cout << "\n";
		}
		system("pause");
		cout << "\nMa tran nghich dao:\n";
		for (int i = 0; i < n; i++) {
			for (int j = n; j < 2 * n; j++) {
				printf("%6.2f", arrGhep[i][j]);
			}
			cout << "\n";
		}

		double check[n][n] = { 0 };
		cout << " Kiem tra:\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					check[i][j]+= arr[i][k] * arrGhep[k][j + n];
				}
				cout << roundf(check[i][j] * 100) / 100 << " " ;
			}
			cout << endl;
		}
	}
	
	
		
	fclose(f);
}

/* 
x x x x
x x x x
x x x x
x x x x
--->
1 x x x
x x x x
x x x x
x x x x
--->
x x x x
x x x x
x x x x
x x x x
--->
1 x x x
0 x x x
0 x x x
0 x x x
--->
1 x x x
0 1 x x
0 x x x
0 x x x
--->
1 0 x x
0 1 x x
0 0 x x
0 0 x x
--->
.
.
.
--->
1 0 0 x
0 1 0 x
0 0 1 x
0 0 0 1
--->
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
*/

