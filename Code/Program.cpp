#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
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
			for (int j = i; j < n; j++) { // duyet tim hang khac hang i co so o cot i khac 0
				if (arrGhep[j][i] != 0 && j != i && i != n - 1) {
					double mul = (arrGhep[i][i] - 1) / arrGhep[j][i];; //he so nhan vao hang j,k de tru di ra duoc arr[i][i]=1

					for (int k = 0; k < 2 * n; k++) {
						arrGhep[i][k] -= mul * arrGhep[j][k];
					}
					for (int k = 0; k < n; k++) { // bien doi cac so con lai o cot i thanh 0
						if (k != i) {
							double temp = arrGhep[k][i];
							for (int t = 0; t < 2 * n; t++) {
								arrGhep[k][t] -= temp * arrGhep[i][t];
							}
						}
					}
					break;
				}
				if (i == n - 1) { // bien doi hang cuoi cot cuoi ma tran dau vao
					double mul = 1 / arrGhep[n - 1][n - 1];
					for (int k = 0; k < 2 * n; k++) arrGhep[n - 1][k] *= mul;
					for (int k = 0; k < n; k++) { // bien doi cac so con lai o cot n-1 thanh 0
						if (k != i) {
							double temp = arrGhep[k][i];
							for (int t = 0; t < 2 * n; t++) {
								arrGhep[k][t] -= temp * arrGhep[i][t];
							}
						}
					}
				}

			}
	}
		cout << "\nMa tran sau khi qua bien doi Gauss-Jordan:\n";
		for(int i=0;i<n;i++){ 
				for(int j=0;j<2*n;j++){
					printf("%6.2f",arrGhep[i][j]);
				}
				cout << "\n";	
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

