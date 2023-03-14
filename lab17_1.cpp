#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a, int N , int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(a+i);
        if( i+1 >= M and (i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *a,int N ,int M){
    for(int i = 0; i < N*M; i++){
        a[i] = (double)(rand()%101)/100;
    }
}

void findRowSum(const double *a,double *b,int N,int M){
    double sum = 0 ;
	int index = 0 ;
   for (int i = 0; i < M*N; i++){
	if ((i+1)%M == 0 and (i+1) >= M){
		sum += a[i];
		b[index]= sum;
		sum = 0;
		index++ ;
	}else {
		sum += a[i];
	}
   }
}

void findColSum(const double *a,double *b,int N,int M){
	double sum = 0 ;
	int index = 0 ;
	for (int i = 0; i < M; i++)
	{
		index = i ;
		for (int j = 0; j < N; j++)
		{
			sum += *(a+index);
			index += M ;	
		}
		b[i]=sum;
		sum = 0;
	}
}
