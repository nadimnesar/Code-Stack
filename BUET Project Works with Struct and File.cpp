#include <stdio.h>
#include <stdlib.h>

struct data{
    int a;
    double b;
};

int main(){
    FILE *item = fopen("item.txt", "r");
    FILE *heavy = fopen("heavy.txt", "w");
    FILE *light = fopen("light.txt", "w");

    int t, i, j;
    fscanf(item, "%d", &t);
    struct data arr[t+1];
    double sum = 0;
    for(i = 0; i < t; i++){
        int x;
        double y;
        fscanf(item,"%d %lf", &x, &y);
        arr[i].a = x;
        arr[i].b = y;
        sum += y;
    }
    double avg = (double)(sum/t);

    struct data arrheavy[t+1];
    struct data arrlight[t+1];
    int k = 0, l = 0;
    for(i = 0; i < t; i++){
        if(arr[i].b >= avg){
            arrheavy[k].a = arr[i].a;
            arrheavy[k].b = arr[i].b;
            k++;
        }
        else{
            arrlight[l].a = arr[i].a;
            arrlight[l].b = arr[i].b;
            l++;
        }
    }

    double swap1;
    int swap2;
    for (i = 0; i < k; i++){
        for (j = i+1; j < k; j++){
            if (arrheavy[i].b < arrheavy[j].b){
                swap1 = arrheavy[i].b;
                swap2 = arrheavy[i].a;
                arrheavy[i].b = arrheavy[j].b;
                arrheavy[j].b = swap1;
                arrheavy[i].a = arrheavy[j].a;
                arrheavy[j].a = swap2;
            }
        }
    }
    for (i = 0; i < l; i++){
        for (j = i+1; j < l; j++){
            if (arrlight[i].b > arrlight[j].b){
                swap1 = arrlight[i].b;
                swap2 = arrlight[i].a;
                arrlight[i].b = arrlight[j].b;
                arrlight[j].b = swap1;
                arrlight[i].a = arrlight[j].a;
                arrlight[j].a = swap2;
            }
        }
    }
    for (i = 0; i < k; i++){
        fprintf(heavy, "%d %.1lf\n", arrheavy[i].a, arrheavy[i].b);
    }
    for (i = 0; i < l; i++){
        fprintf(light, "%d %.1lf\n", arrlight[i].a, arrlight[i].b);
    }
}
