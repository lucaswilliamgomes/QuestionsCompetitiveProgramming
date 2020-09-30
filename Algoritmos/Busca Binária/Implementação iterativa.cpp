// A busca binária é uma forma menos complexa para achar
// um elemento em um vetor. 
// Complexidade = O(log de n na base 2) onde n é o tamanho do vetor;


int buscabinaria (int vetor[], int tam, int valor){
    int esquerda = 0, direita = tam-1, meio;

    while (esquerda <= direita){
        meio = (esquerda + direita) / 2;
        if (vetor[meio] == valor) return meio;
        else if (vetor[meio] < valor) esquerda = meio + 1;
        else if (vetor[meio] > valor) direita = meio - 1;
    }

    return -1;  // Não encontrado
}