#include <limits.h> 
#include <stdbool.h> 
#include <stdio.h> 
// So luong dinh cua do thi
#define V 5 
  
//Su dung 1 ham de tim dinh co gia tri khoa toi thieu, tu tap hop cac dinh
int minKey(int key[], bool mstSet[]) 
{ 
    // Khoi tao gia tri min
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
  
    return min_index; 
} 
  
// Khoi tao 1 ham de in MST duoc luu tru trong parent[]

int printMST(int parent[], int graph[V][V]) 
{ 
    printf("Edge \tWeight\n"); 
    for (int i = 1; i < V; i++) 
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  
// Xay dung va in MST cho bieu do duoc bieu dien bang cach su dung bieu dien ma tran ke
void primMST(int graph[V][V]) 
{ 
    // Mang de luu tru MST
    int parent[V]; 
    // Cac gia tri duoc dung de chon canh co chieu dai toi thieu
    int key[V]; 
    // Bieu dien tap hop cac dinh chua duoc bao gom trong MST 
    bool mstSet[V]; 
  
    // Khoi tao moi key co gia tri la INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    key[0] = 0; 
    parent[0] = -1; // Luon con Nut dau tien luon la goc cua bieu do
  
    for (int count = 0; count < V - 1; count++) { 
       
        int u = minKey(key, mstSet); 
  
        mstSet[u] = true; 
  
        for (int v = 0; v < V; v++)   
           
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
  
    printMST(parent, graph); 
} 
  
int main() 
{ 
    /* Bieu do
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | /     \ | 
    (3)-------(4) 
            9         */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
  
    // In ra man hinh
    primMST(graph); 
  
    return 0;
}
