// Retorna o MDC de um numero por meio de recursao

int mdc (int a, int b) {
    if (b == 0) return a;
    else return mdc(b, a % b); 
}

// Usando operador ternário
int mdc (int a, int b) {
    return (b == 0) ? a : mdc (b, a % b);
}