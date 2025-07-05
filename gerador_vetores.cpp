#include "gerador_vetores.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

std::vector<int> gerar_vetor_aleatorio(int quantidade) {
    std::vector<int> vetor(quantidade);
    std::iota(vetor.begin(), vetor.end(), 0); // preenche de 0 a quantidade - 1

    unsigned semente = std::chrono::steady_clock::now().time_since_epoch().count();
    std::shuffle(vetor.begin(), vetor.end(), std::default_random_engine(semente));

    return vetor;
}

std::vector<int> gerar_vetor_quase_ordenado(int quantidade) {
    std::vector<int> vetor(quantidade);
    std::iota(vetor.begin(), vetor.end(), 0);

    unsigned semente = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine gerador(semente);

    for (int i = 0; i < quantidade / 10; ++i) {
        int posicao1 = gerador() % quantidade;
        int posicao2 = gerador() % quantidade;
        std::swap(vetor[posicao1], vetor[posicao2]);
    }

    return vetor;
}

std::vector<int> gerar_vetor_inversamente_ordenado(int quantidade) {
    std::vector<int> vetor(quantidade);
    for (int i = 0; i < quantidade; ++i) {
        vetor[i] = quantidade - i;
    }
    return vetor;
}
