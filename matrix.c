#include <stdio.h>
#include <stdlib.h>

int main() {

    int m1[2][3] = {
        {0,0,0},
        {1,1,1},
    };

    int m2[3][2] = {
        {0,1},
        {0,1},
        {0,1}
    };

    // Mátrix transzponálás
    /*for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 2;j++) {
            m2[i][j] = m1[j][i];
        }
    }*/

    // Mátrix összeadás (csak akkor lehetséges ha a két mátrix dimenziói megegyeznek)
    /*for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 2;j++) {
            m2[i][j] = m2[i][j] + m2[i][j];
        }
    }*/

    int mRES[2][2];

    // Mátrix szorzás sor[n] elemet oszlop[n] elemel szorzunk és hozzáadjuk a következo sor[n+1] * oszlop[n+1] elemet majd összeadjuk
        
        int i = 0;
            for (int x = 0;x < 3;x++) {
                mRES[i][i] += m1[i][x] * m2[x][i];
                mRES[i][i+1] += m1[i][x] * m2[x][i+1];
            }

        i = 1;
            for (int x = 0;x < 3;x++) {
                mRES[i][i] += m1[i][x] * m2[x][i];
                mRES[i][i-1] += m1[i][x] * m2[x][i-1];
            }


    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++) {
            printf("%d ",mRES[i][j]);
        }
        puts("");
    }

    return 0;
}

/*
    [0,0,0] [0,1]
    [1,1,1] [0,1] = [0*0+0*0+0*0][0*1+0*1+0*1]  [0,0]
            [0,1]   [1*0+1*0+1*0][1*1+1*1+1*1]  [0,3]

*/