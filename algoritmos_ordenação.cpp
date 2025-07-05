#include "algoritmos_ordenação.h"
#include <chrono>
#include <algorithm>

ResultadoOrdenacao bubble_sort(std::vector<int>& dados) {
    int tamanho = dados.size();
    int total_trocas = 0;
    int total_comparacoes = 0;

    auto tempo_inicio = std::chrono::high_resolution_clock::now();

    for (int indice_externo = 0; indice_externo < tamanho - 1; indice_externo++) {
        for (int indice_interno = 0; indice_interno < tamanho - indice_externo - 1; indice_interno++) {
            total_comparacoes++;
            if (dados[indice_interno] > dados[indice_interno + 1]) {
                std::swap(dados[indice_interno], dados[indice_interno + 1]);
                total_trocas++;
            }
        }
    }

    auto tempo_fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_total = tempo_fim - tempo_inicio;

    return { total_trocas, total_comparacoes, duracao_total.count() };
}
ResultadoOrdenacao insertion_sort(std::vector<int>& dados) {
    int tamanho = dados.size();
    int total_trocas = 0;
    int total_comparacoes = 0;

    auto tempo_inicio = std::chrono::high_resolution_clock::now();

    for (int atual = 1; atual < tamanho; atual++) {
        int elemento_chave = dados[atual];
        int anterior = atual - 1;

        while (anterior >= 0) {
            total_comparacoes++;
            if (dados[anterior] > elemento_chave) {
                dados[anterior + 1] = dados[anterior];
                total_trocas++;
                anterior--;
            } else {
                break; 
            }
        }

        dados[anterior + 1] = elemento_chave;
    }

    auto tempo_fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_total = tempo_fim - tempo_inicio;

    return { total_trocas, total_comparacoes, duracao_total.count() };
}
ResultadoOrdenacao selection_sort(std::vector<int>& dados) {
    int tamanho = dados.size();
    int total_trocas = 0;
    int total_comparacoes = 0;

    auto tempo_inicio = std::chrono::high_resolution_clock::now();

    for (int atual = 0; atual < tamanho - 1; atual++) {
        int indice_minimo = atual;
        for (int proximo = atual + 1; proximo < tamanho; proximo++) {
            total_comparacoes++; 
            if (dados[proximo] < dados[indice_minimo]) {
                indice_minimo = proximo;
            }
        }
        if (indice_minimo != atual) {
            std::swap(dados[atual], dados[indice_minimo]);
            total_trocas++;
        }
    }

    auto tempo_fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_total = tempo_fim - tempo_inicio;

    return { total_trocas, total_comparacoes, duracao_total.count() };
}
int dividir_quick(std::vector<int>& dados, int inicio, int fim, int& total_comparacoes, int& total_trocas) {
    int pivo = dados[fim];
    int esquerda = inicio;
    int direita = fim - 1;

    while (direita >= esquerda) {
        while (esquerda <= direita && dados[esquerda] < pivo) {
            total_comparacoes++;
            esquerda++;
        }
        while (esquerda <= direita && dados[direita] > pivo) {
            total_comparacoes++;
            direita--;
        }

        if (direita >= esquerda) {
            std::swap(dados[esquerda], dados[direita]);
            total_trocas++;
            esquerda++;
            direita--;
        }
    }

    std::swap(dados[esquerda], dados[fim]);
    total_trocas++;
    return esquerda;
}
void quick_sort_recursivo(std::vector<int>& dados, int inicio, int fim, int& total_comparacoes, int& total_trocas) {
    if (inicio < fim) {
        int posicao_pivo = dividir_quick(dados, inicio, fim, total_comparacoes, total_trocas);
        quick_sort_recursivo(dados, inicio, posicao_pivo - 1, total_comparacoes, total_trocas);
        quick_sort_recursivo(dados, posicao_pivo + 1, fim, total_comparacoes, total_trocas);
    }
}

ResultadoOrdenacao merge_sort(std::vector<int>& dados) {
    int total_comparacoes = 0;
    int total_trocas = 0;

    auto tempo_inicio = std::chrono::high_resolution_clock::now();

    merge_sort_recursivo(dados, 0, dados.size() - 1, total_comparacoes, total_trocas);

    auto tempo_fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_total = tempo_fim - tempo_inicio;

    return { total_trocas, total_comparacoes, duracao_total.count() };
}
ResultadoOrdenacao quick_sort(std::vector<int>& dados) {
    int total_comparacoes = 0;
    int total_trocas = 0;

    auto tempo_inicio = std::chrono::high_resolution_clock::now();

    quick_sort_recursivo(dados, 0, dados.size() - 1, total_comparacoes, total_trocas);

    auto tempo_fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_total = tempo_fim - tempo_inicio;

    return { total_trocas, total_comparacoes, duracao_total.count() };
}
void intercalar_merge(std::vector<int>& dados, int inicio, int meio, int fim, int& total_comparacoes, int& total_trocas) {
    int indice_esquerda = inicio;
    int indice_direita = meio + 1;

    std::vector<int> temporario;
    temporario.reserve(fim - inicio + 1);

    while (indice_esquerda <= meio && indice_direita <= fim) {
        total_comparacoes++;
        if (dados[indice_esquerda] <= dados[indice_direita]) {
            temporario.push_back(dados[indice_esquerda]);
            indice_esquerda++;
        } else {
            temporario.push_back(dados[indice_direita]);
            indice_direita++;
        }
        total_trocas++; 
    }

    while (indice_esquerda <= meio) {
        temporario.push_back(dados[indice_esquerda]);
        indice_esquerda++;
        total_trocas++;
    }

    while (indice_direita <= fim) {
        temporario.push_back(dados[indice_direita]);
        indice_direita++;
        total_trocas++;
    }

    for (int k = 0; k < temporario.size(); ++k) {
        dados[inicio + k] = temporario[k];
        total_trocas++; 
    }
}
void merge_sort_recursivo(std::vector<int>& dados, int inicio, int fim, int& total_comparacoes, int& total_trocas) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort_recursivo(dados, inicio, meio, total_comparacoes, total_trocas);
        merge_sort_recursivo(dados, meio + 1, fim, total_comparacoes, total_trocas);
        intercalar_merge(dados, inicio, meio, fim, total_comparacoes, total_trocas);
    }
}


