#include <stdio.h>
#include <stdlib.h>
#include <time.h>
				   
char pairs[2][5] = {{'K', 't', 'u', 'e', 'v'},
					   {'p', 'a', 'l', 'Y', 'j'}}; 
				   
char kalem[5]={'k', 'a', 'l', 'e', 'm'};

char production[5][5]={{'K', 't', 'u', 'e', 'v'},
					   {'p', 'a', 'l', 'Y', 'j'},
    				   {'K', 'a', 'l', 'e', 'm'},
					   {'K', 't', 'u', 'e', 'v'},
					   {'p', 'a', 'l', 'Y', 'j'}};
					   
char mutation[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int i = 0;
int j = 0;
int k = 0;

int select1, select2, cross;

int fitness[5]={0,0,0,0,0};

int randomsayi(){
	select1 = rand() % 5 + 0;
	select2 = rand() % 5 + 0;
	
	while(select2 == select1){
		select2 = rand() % 5 + 0;
	}
}

int main() {
	
	srand(time(NULL));
	
	while((fitness[0]<5)&&(fitness[1]<5)&&(fitness[2]<5)&&(fitness[3]<5)&&(fitness[4]<5)){
		
		int prob1, prob2, cross, loop1, loop2, loop3, loop4, loop5, loop6, loop7, mutate1, mutate2;
		int pair1_fitness = 0;
		int pair2_fitness = 0;
		
		for(i=0; i<5; i++){
			
			randomsayi();
			cross = rand() % 5 + 1;
			for(loop1=0; loop1<5; loop1++){
				fitness[loop1] = 0;
			}
			
			for(j=0; j<cross; j++){
				prob1 = rand() % 100 + 1;
				mutate1 = rand() % 26 + 0;
				if(prob1>40){
					production[i][j] = pairs[0][j];
			    }
			    else{
			    	production[i][j] = mutation[mutate1];
				}
				
			}
			for(k=cross; k<5; k++){
				prob2 = rand() % 100 + 1;
				mutate2 = rand() % 26 + 0;
				if(prob2>10){
				production[i][k] = pairs[1][k];
				}
				else{
				production[i][j] = mutation[mutate2];
				}
				
			}
		}
		
		for(loop2=0; loop2<5; loop2++){
			for(loop3=0; loop3<5; loop3++){
				if(production[loop2][loop3]==kalem[loop3]){
					fitness[loop2]++;
				}
			}
		}
	
	
		for(loop7=0; loop7<5; loop7++){
			printf("%c", production[loop7][0]);
			printf("%c", production[loop7][1]);
			printf("%c", production[loop7][2]);
			printf("%c", production[loop7][3]);
			printf("%c %d\n", production[loop7][4], fitness[loop7]);
	}
		for(loop6=0; loop6<5; loop6++){
			pairs[0][loop6]=production[0][loop6];	
		}
	
		pair1_fitness = fitness[0];
		
		for(loop5=1; loop5<5; loop5++){
			if((pair1_fitness >= pair2_fitness)&&(fitness[loop5]>=pair2_fitness)){
				pair2_fitness = pair1_fitness;
				pair1_fitness = fitness[loop5];
				for(loop6=0; loop6<5; loop6++){
				pairs[1][loop6]=pairs[0][loop6];
				
				}
				for(loop6=0; loop6<5; loop6++){
				pairs[0][loop6]=production[loop5][loop6];
				}
			}
			else if((fitness[loop5]>=pair1_fitness)&&(pair1_fitness <= pair2_fitness)){
				pair1_fitness = fitness[loop5];
				for(loop6=0; loop6<5; loop6++){
				pairs[0][loop6]=production[loop5][loop6];
				}
				}
		}
		
		for(loop7=0; loop7<2; loop7++){
			printf("%c", pairs[loop7][0]);
			printf("%c", pairs[loop7][1]);
			printf("%c", pairs[loop7][2]);
			printf("%c", pairs[loop7][3]);
			printf("%c\n", pairs[loop7][4]);
	}

}
	return 0;
}
