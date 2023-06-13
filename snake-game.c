#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
int main(){
	int N,M,Y,i,j,k,x,y,kalanyem;
	// N ve M oyun tahtas�n�n uzunlu�u
	//x y y�lan�n ba��n�n koordinatlar�
	//i j k for de�i�kenleri
	char yon;
	int hamle=0,Flag=0,a=1,puan=0,b=0,Flag2=0;// flag2=oyun tahtas�n�n d���na ��kt� m� ? Flag while da fazla i�lem yapmamak i�in vs
	printf("satir ve sutun sayisin girin");
	scanf("%d %d",&N,&M);
	printf("yem sayisini girin");
	scanf("%d",&Y);
	int matris[N][M];
	srand(time(NULL));
    int snake[3][Y+1];// y�lan�n ba��n�n ve kuyru�unun kordinatlar�n� tutuyorum
    for(i=0;i<3;i++){
    	for(j=0;j<Y+1;j++){
    		snake[i][j]=-1;
		}
	}
	while(Y>=N*M){
		printf("Yem sayisini yanlis girdin");
		scanf("%d",&Y);
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			matris[i][j]=-1;
		}
	}
	for(i=0;i<Y;i++){// yemleri rastgele da��t�yorum
		x=rand()%(N-1);
	    y=rand()%(M-1);
		    while(matris[x][y]==0){
		        x=rand()%(N-1);
		        y=rand()%(M-1);
		}
		matris[x][y]=0;
    }
    while(Flag==0){// y�lan�n ba�lang�� noktas�n� rastgele �ekilde at�yorum
    	x=rand()%(N-1);
		y=rand()%(M-1);
		if(matris[x][y]==-1){
			Flag=1;
			snake[0][a-1]=a;
			snake[1][a-1]=x;
			snake[2][a-1]=y;
		}
	}
	Flag=0;
	k=0;
    for(i=0;i<N;i++){// oyun tahtas�n� ilk kez bast�r�yorum
    	printf("\n");
    	for(j=0;j<M;j++){
			    if(snake[1][k]==i && snake[2][k]==j){//e�er oyun tahtas�ndaki mevcut koordinatlara uygun bir y�lan matrisinin sat�r� varsa o bas�l�r
				    Flag=1;
			    }
    		if(Flag==1){
    			printf("|%2d|",snake[0][k]);
			}
    		else if(matris[i][j]==-1){
    			printf("|%2c|",' ');
			}
			else{
				printf("|%2d|",matris[i][j]);
			}
			Flag=0;
		}
	}
	while(Flag2==0 && puan<Y){
		printf("\nyon giriniz\n(l,r,u,d)");
		scanf(" %c",&yon);
		if(yon=='u'){
			x--;
		}
		else if(yon=='d'){
			x++;
		}
		else if(yon=='l'){
			y--;
		}
		else{
			y++;
		}
		for(i=1;i<a;i++){
			if(snake[1][i]==x && snake[2][i]==y){
				Flag2=1;
				printf("kuyruguna �arptin!");
			}
		}
		hamle++;
	if(x>=0 && y>=0){
		if(x<N && y<M){
			if(matris[x][y]==0){
				matris[x][y]=-1;
				puan++;
				a++;
				snake[0][a-1]=a;
				for(i=a-1;i>0;i--){
					snake[1][i]=snake[1][i-1];
					snake[2][i]=snake[2][i-1];
				}
				snake[1][0]=x;
				snake[2][0]=y;
			}
			else{
				for(i=a-1;i>0;i--){
					snake[1][i]=snake[1][i-1];
					snake[2][i]=snake[2][i-1];
				}
			    snake[1][0]=x;
		        snake[2][0]=y;
			}
		}
		else{
			Flag2=1;
		}
	}
	else{
		Flag2=1;
	}	
	Flag=0;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			k=0;
			while(k<Y+1 && Flag==0){
				if(snake[1][k]==i && snake[2][k]==j){
					Flag=1;
				}
				else{
					k++;
				}
			}
			if(Flag==1){
				printf("|%2d|",snake[0][k]);
			}
			else if(matris[i][j]==-1){
				printf("|%2c|",' ');
			}
			else{
				printf("|%2d|",matris[i][j]);
			}
			Flag=0;	
		}
	}
	printf("\n puaniniz:%d\n",puan);
	printf("\n toplam hamle sayisi:%d\n",hamle);
}
	if(Flag2==1){
		printf("kaybettiniz\n");
	}
	else{
		printf("tebrikler kazandiniz");
	}
	kalanyem=Y-puan;
	printf("\n puaniniz:%d\n",puan);
	puan++;
	printf("\n toplam hamle sayisi:%d\n",hamle);
	printf("\nKalan yem say�isi:%d\n",kalanyem);
	printf("Yilanin buyuklugu:%d",puan);
	
	
	
	return 0;
}
