#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define EULER_NUMBER 2.71828

double sigmoid(double n) {
    return (1 / (1 + pow(EULER_NUMBER, -n)));
}

double derivate_sigmoid(double n) {
    return n * (1.0 - n);
}

int main(void) {
    
    int in[4][2] = {
        {0,1},
        {1,0},
        {1,0},
        {1,1}
    };

    int res[4] = {1,1,0,0};

    double hidden_layer[2] = {0,0};
    double hidden_layer_in_w[2][2] = {{0.5,0.5},{0.5,0.5}};
    double hidden_layer_out_w[2] = {0.5,0.5};
 
    for (int ep = 0;ep < 10000;ep++)
    {
        for (int i = 0;i < 4;i++) {
            
            for (int j = 0;j <2;j++) {
                for (int k = 0;k < 2;k++) {
                    hidden_layer[j] += in[i][j]*hidden_layer_in_w[i][j];
                }
                hidden_layer[j] = sigmoid(hidden_layer[j]);
            }

            double out = 0;

            for (int j = 0;j < 2;j++) {
                out += hidden_layer[j] * hidden_layer_out_w[j];
            }
            out = sigmoid(out);

            double error = res[i] - out;

            for (int j = 0;j < 2;j++) {
                hidden_layer_out_w[j] = error * hidden_layer[j] * 0.5 * derivate_sigmoid(out);
            }

            for (int j = 0;j < 2;j++) {
                for (int k = 0;k < 2;k++) {
                    hidden_layer_in_w[k][j] = derivate_sigmoid(hidden_layer_in_w[k][j]) * error * 0.5;
                }
            }

            
        }
    }

    printf("%f %f\n",hidden_layer[0],hidden_layer[1]);

    return 0;
}