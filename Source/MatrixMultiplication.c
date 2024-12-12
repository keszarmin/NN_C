#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int m=3,n=4;
	
	int m1[3][4] = {
		{1,1,1,1},
		{2,2,2,2},
		{3,3,3,3}
	};

    int m2[4][3] = {
		{1,2,3},
		{1,2,3},
		{1,2,3},
		{1,2,3}
	};
	
	int mRES[3][3];
    
	int i=n,
	    d=m,
		item;
		
		
		
	for (d-1 >= 0;d--;) {
		item = m;
		for (item-1 >= 0;item--;) {
			i = n;
			for (i-1 >= 0;i--;) {
				mRES[d][item] += m1[d][i] * m2[i][item];
				printf("%d * %d\n",m1[d][i],m2[i][item]);
			}
		}
		printf("\n");
	}
	
	for (int x = 0;x < 3;x++) {
		for (int y =0;y<3;y++) {
			printf("%d ",mRES[x][y]);
		}
		printf("\n");
	}
	
    return 0;

}
