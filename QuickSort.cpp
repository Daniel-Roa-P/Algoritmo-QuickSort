#include <iostream>
#include <stdlib.h>   
#include <time.h>

using namespace std;

int *a;
int n, aux;
struct timespec Inicio={0,0}, Final={0,0};

intercambio(int *a, int i, int j){
	
	aux=a[i];
	a[i]=a[j];
	a[j]=aux;
	
}

ordenRapido(int *a, int izquierda, int derecha){

	int i, j; int v;
  	
	if(derecha > izquierda){
		
		v= a[derecha];
		i = izquierda -1;
		j= derecha;
		
        for(;;){
			
			while (a[++i]<v);
            while (a[--j] >v);
            if(i>=j){
				
				break;
            
        	}
			intercambio(a,i,j);
        }
            
       intercambio(a, i, derecha);
       ordenRapido(a, izquierda, i-1);
       ordenRapido(a, i+1,derecha);
       
     }
}

int main() {
	
	while(true){
	
		cout<<"Ingrese N: ";
		cin>>n;
	
		a=new int [n];
	
		int j=n;
	
			for(int i=0 ; i<n; i++){
		
				a[i]=j;
				j--;
		
			}
		
		for(int i=0 ; i<n; i++){
		
				cout<<a[i]<<", ";
		
			}
	
		clock_gettime(CLOCK_MONOTONIC, &Inicio);
    
    	ordenRapido(a,0,n-1);
    
    	clock_gettime(CLOCK_MONOTONIC, &Final);
		
		cout<<endl;
		
		printf(" El tiempo que ha tardado es: %.5f nanosegundos.\n",
       		((double)Final.tv_nsec) - 
       		((double)Inicio.tv_nsec));
		
		cout<<endl;
		
		for(int i=0 ; i<n; i++){
		
				cout<<a[i]<<", ";
		
			}
	
		delete a;
		
		Inicio={0,0};
		Final={0,0};
		
		cout<<endl;
	}
}
