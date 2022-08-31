#include <stdio.h>
#include <stdlib.h>
void queenChecks(int board[8][8] , int i , int j){
        for(int e =0 ; e<8;e++) {
			board[i][e]=1;
			board[e][j]=1;
		}
		for(int k=0;k<8;k++) {
			if((j-k+i)<8 && (j-k+i)>=0) {
				board[k][j-k+i]=1;
			}
			if(j+k-i<8 && (j+k-i)>=0 ) {
				board[k][j+k-i]=1;
			}
		}
		board[i][j]=8;
}
void printBoard(int board[8][8]){
for(int i =0 ; i<8 ; i++){
    for(int j =0 ; j<8 ; j++){
        printf("%i ",board[i][j]);
    }
    printf("\n");
}
}
void nqueens(){
    int solved=0;
	int x;
	while(solved==0) {
		solved = 1;
	int board[8][8] ;
	for(int i=0;i<8;i++) {
		for(int j=0; j<8 ; j++) {
			solved = 0;
			if(board[i][j]==0) {
				solved = 1;
				while(1) {
				x =rand()%8;
				if(board[i][x]==0) {
				queenChecks(board,i,x);
				break;
				}
			}
				break;
			}
			}
		if(solved==0)
			break;
	}
	if(solved==1) {
	printBoard(board);
	printf("\n1's represent empty squares , 8's represent queens\n\n");
	printf("Press Any key to generate a new board combination......");
	getch();
	system("cls");
	solved=0;
	}
    for(int m =0 ;m<8 ; m++){
        for(int l=0;l<8;l++){
            board[m][l]=0;
        }
	}
	}
	}
int main()
{
    nqueens();
    return 0;
}
