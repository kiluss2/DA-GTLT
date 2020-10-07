#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
#include<math.h>
using namespace std;


int random(int min, int max){
	return min + rand()%(max + 1 - min);
}


int main()
{
	cout << " .-------.\n |  Hi   |\n '-------'\n      ^      {\\_/}\n"
			<< "      '----- (O.o)\n             (> <)\n";
			
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
	int arr[20][20];
	double a[size][size], det = 1; 
	
	
	do{ // check if det(matrix) != 0
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
            	arr[i][j] = (double)random(-50,50);
        		a[i][j] = arr[i][j]; // gan sang ma tran double
			}
		}
	
		
		for(int i = 0; i < size; i++){
			if(a[i][i] == 0){ // kiem tra lieu phan tu nam tren duong cheo co bang 0
				int j;
				for(j = i + 1; j< size ; j++ ){ // neu bang 0 thi duyet xuong tim phan tu cung cot o hang khac khac 0
					if(arr[j][i]!=0){ 
						for(int k = 0;k < size ; k++){ // hoan doi 2 hang cho nhau
							a[i][k] += a[j][k];
							a[j][k] = a[i][k]- a[j][k];
							a[i][k] -= a[j][k];
						}
						break;
					}
				}	
			}
			for(int j = i + 1; j < size; j++){ // bien doi cac phan tu duoi duong cheo thanh 0
				if(a[i][i] == 0) break; // dinh  thuc = 0
				else{
					double mul = a[j][i]/a[i][i];
					for(int k = 0; k< size ; k++){
						a[j][k] -= a[i][k]*mul;
					}
				}
			}
			det *= a[i][i];
		} 
		cout <<"Dinh Thuc = " << det << endl;
	}while(det == 0);
	
	printf("%4d%4d\n",size,size); // kich thuoc matran
	fprintf(f,"%4d%4d\n",size,size);
	
	for(int i=0;i<size;i++){ // in ma tran tao duoc
		for(int j=0;j<size;j++){
			fprintf(f,"%4d",arr[i][j]);
			printf("%4d",arr[i][j]);
		}
			fprintf(f,"\n");
			cout << "\n";
	}
	
	
	system("pause");
	
	cout << "Ma tran sau khi bien doi gauss:\n";
	for(int i=0;i<size;i++){ // ma tran double sau khi bi bien doi
		for(int j=0;j<size;j++){
			printf("%8.2f",a[i][j]);
		}
			cout << "\n";
	}
	
	fclose(f);
}
