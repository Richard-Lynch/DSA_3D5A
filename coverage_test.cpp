#include <stdio.h>
#include <math.h>

int main(){

    int output[1000];
    bool dupe = false;

    for(int i = 'A'-60; i<='E'-60; i++){
        for(int j = i; j<='E'-60; j++){
            int output1 = i*j;
            int output2 = pow(j, i);
            int output3 = pow(i, j);
            int output4 = output2%'F';
            int output5 = output2%'A';
            int output6 = output3%'F';
            int output7 = output3%'A';

            for(int k = 'A'-60; k <='F'-60; k++ ){
                if(output[k] == output4){
                    printf("%c, %c : duplicate \n", i+60, j+60);
                    dupe = true;
                    }
                }
            output[i] = output4;
            printf("%c, %c : %i \n", i+60, j+60, output4);
        }
    }
    if(dupe){
        printf("there was a duplicate\n");
    }
    

    return 0;
}