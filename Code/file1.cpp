#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
using namespace std;
int random(int min, int max){
	return min + rand()%(max + 1 - min);
}
int main()
{
	FILE* f;
	f = fopen("H:\\Documents on H\\DA GTLT\\proj\\Files\\test.inp","w+");
	srand((int)time(0));
	int h=6,c=7;
	fprintf(f,"%4d%4d\n",h,c);
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
//			cout << setw(4) << random(-50,50) << " ";
			fprintf(f,"%4d",random(-50,50));
		}
//		cout << "\n";
			fprintf(f,"\n");
	}
	fclose(f);
}
