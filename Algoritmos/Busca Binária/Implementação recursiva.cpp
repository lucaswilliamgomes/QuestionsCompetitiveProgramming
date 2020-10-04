// A busca binária é uma forma menos complexa para achar
// um elemento em um array ordenado. 
// Complexidade = O(log de n na base 2) onde n é o tamanho do vetor;

int buscaBinaria (int vetor[], int valor, int esquerda, int direita){
    int meio = (direita + esquerda) / 2;

    if (vetor[meio] == valor) return meio;

    if (esquerda >= direita) return -1; // Não encontrado
    else {
        if (vetor[meio] > valor) {
            return buscaBinaria (vetor, valor, meio + 1, direita);
        }
        if (vetor[meio] < valor) {
            return buscaBinaria (vetor, valor, esquerda, meio - 1);
        }
    }

}