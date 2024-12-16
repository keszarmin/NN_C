#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int *W_SUM(int end,int *w,int *x) {
    int *res = calloc(end,sizeof(int));
    
    while (end > 0)
    {
        res[end] += w[end] * x[end];
        end--;
    }   

    return res;
    free(res);
}

int signum(float x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int *OUTPUT(int len,int *net) {
    float *net_norm = calloc(len,sizeof(float));
    int *res = calloc(len,sizeof(int));
    for (int i =0;i<len;i++) net_norm[i] = net[i]/10;
    for (int i =0;i<len;i++) res[i] = signum(net_norm[i]);
    free(net_norm);
    return res;
    free(res);
}

int main() {
    int x[5] = {
        5,6,6,5,3
    };
    int w[5] = {
        1,2,2,1,2
    };

    int *net = W_SUM(5,w,x);
    int *out = OUTPUT(5,net);

    for (int i =0;i<5;i++) printf("%d ",out[i]);

}