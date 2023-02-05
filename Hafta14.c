#include <stdio.h>
#include <stdlib.h>

int degree(int A[5][5], int v, int n){
    int result = 0;
    int i;
    for(i = 0; i < n; i++){
        result += A[v][i];
    }
    return result;
}

int edges(int A[5][5], int n){
    int i, j, counter = 0;
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            counter += A[i][j];
        }
    }
    return counter;
}

int main()
{
    int i;
    int n = 5;
    int sum_degree = 0;
    int A[5][5] = {{0, 1, 1, 1, 0},
                    {1 , 0, 0, 1, 0},
                    {1, 0, 0, 1, 1},
                    {1, 1, 1, 0, 1},
                    {0, 0, 1, 1, 0}};
    
    for(i = 0; i < 5; i++){
        sum_degree += degree(A, i, 5);
        printf("degree of vertex %d is %d\n", i + 1, degree(A, i, 5));
    }
    printf("Total degree of vertices = %d\n", sum_degree);
    printf("Total number of edges = %d\n", edges(A, n));

}