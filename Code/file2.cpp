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
		int arr[n][n], arrGhep[n][2*n];
		printf("%4d%4d\n",n,n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fscanf(f,"%d",&arr[i][j]);
				cout << setw(4) << arr[i][j];
			}
			cout << "\n";	
		}
		//ghep ma tran voi ma tran don vi
		for(int i = 0; i< n; i++){ 
			for(int j = 0; j< 2*n; j++)
				if(j>=n){
					if(j==(n+i)) arrGhep[i][j]=1;
					else arrGhep[i][j]=0;
				}
				else arrGhep[i][j] = arr[i][j];
		}	
	
		for(int i=0;i<n;i++){ //in ra lai ma tran vua ghep
				for(int j=0;j<2*n;j++){
					cout << setw(4) << arrGhep[i][j];
				}
				cout << "\n";	
			}
		
		for(int i = 0; i < n; i++){
			
		}	
	}
	
		
	fclose(f);
}


