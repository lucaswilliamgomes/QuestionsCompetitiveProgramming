#include <stdio.h>
#define MAXN 100005

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Cria arrays temporários
    int L[n1], R[n2];
 
    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Começamos o merge dos dois array (L[] e R[]) de volta para o array arr[]
 
    // Index inicial do primeiro subarray
    int i = 0;
 
    // Index inicial do segundo subarray
    int j = 0;
 
    // index inicial da submatriz merged
    int k = l;
    
    // Aqui acontece o merge
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copia os elementos restantes de L [], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copie os elementos restantes de R [], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


int main() {
    
    int arr[MAXN], n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}