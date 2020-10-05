#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
#include<math.h>
using namespace std;

int dinhThuc( int arr[20][20], int size) {
	int det = 0;
   		int submatrix[20][20];
   		int n = size;
   		if (n == 2)
   		return ((arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]));
   		else {
      		for (int x = 0; x < n; x++) {
         		int subi = 0;
         		for (int i = 1; i < n; i++) {
           		 	int subj = 0;
           			for (int j = 0; j < n; j++) {
               			if (j == x)
               			continue;
               			submatrix[subi][subj] = arr[i][j];
               			subj++;
            		}
            		subi++;
         		}
         		det = det + (pow(-1, x) * arr[0][x] * dinhThuc( submatrix, n - 1 ));
      		}
  	 		}	
	return det;
}
int random(int min, int max){
	return min + rand()%(max + 1 - min);
}


int main()
{
	FILE* f; char fn[100], link[]="H:\\Documents on H\\DA GTLT\\proj\\Files\\";
	printf("Create file or override if it existed (File name(*.inp): "); gets(fn);
	strcat(link,fn);
	strcpy(fn,link);
	if(!strchr(fn,'.')) strcat(fn,".inp");
	cout << fn <<endl;
	f = fopen(fn,"w+");
	srand((int)time(0));
	
	cout << "Nhap kich thuoc ma tran: ";
	int size;
	cin >> size;
	int arr[20][20],det ;
	
	do{ // check if det(matrix) != 0
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
//			cout << setw(4) << random(-50,50) << " ";
            	arr[i][j] = (double)random(-50,50);
        
			}
				cout << "\n";
		}
		
		det = dinhThuc(arr,size);
		cout << det << endl;
	}while(det==0);
	
	printf("%4d%4d\n",size,size);
	fprintf(f,"%4d%4d\n",size,size);
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			fprintf(f,"%4d",arr[i][j]);
			printf("%4d",arr[i][j]);
		}
			fprintf(f,"\n");
			cout << "\n";
	}
	
	fclose(f);
}
