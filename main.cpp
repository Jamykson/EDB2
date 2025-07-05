#include <iostream>
#include <vector>
#include <iomanip>
#include "algoritmos_ordenação.h"
#include "gerador_vetores.h"

int main() {
    int tamanho_vetor, opcao;

    std::cout << "Informe o tamanho do vetor: ";
    std::cin >> tamanho_vetor;

    std::cout << "Escolha o tipo de vetor:\n";
    std::cout << "1 - Aleatório\n";
    std::cout << "2 - Quase ordenado\n";
    std::cout << "3 - Inversamente ordenado\n";
    std::cout << "Sua escolha: ";
    std::cin >> opcao;

    std::vector<int> vetor_base;

    switch (opcao) {
        case 1:
            vetor_base = gerar_vetor_aleatorio(tamanho_vetor);
            break;
        case 2:
            vetor_base = gerar_vetor_quase_ordenado(tamanho_vetor);
            break;
        case 3:
            vetor_base = gerar_vetor_inversamente_ordenado(tamanho_vetor);
            break;
        default:
            std::cerr << "Escolha inválida!\n";
            return 1;
    }

    std::vector<int> vetor_bubble    = vetor_base;
    std::vector<int> vetor_selection = vetor_base;
    std::vector<int> vetor_insertion = vetor_base;
    std::vector<int> vetor_quick     = vetor_base;
    std::vector<int> vetor_merge     = vetor_base;

    ResultadoOrdenacao resultado_bubble    = bubble_sort(vetor_bubble);
    ResultadoOrdenacao resultado_selection = selection_sort(vetor_selection);
    ResultadoOrdenacao resultado_insertion = insertion_sort(vetor_insertion);
    ResultadoOrdenacao resultado_quick     = quick_sort(vetor_quick);
    ResultadoOrdenacao resultado_merge     = merge_sort(vetor_merge);

    std::cout << "\nResultados para n = " << tamanho_vetor << "\n";
    std::cout << std::left << std::setw(15) << "Algoritmo"
              << std::setw(12) << "Trocas"
              << std::setw(15) << "Comparações"
              << "Tempo (ms)" << "\n";

    std::cout << std::string(50, '-') << "\n";

    std::cout << std::left << std::setw(15) << "Bubble Sort"
              << std::setw(12) << resultado_bubble.trocas
              << std::setw(15) << resultado_bubble.comparacoes
              << resultado_bubble.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Selection Sort"
              << std::setw(12) << resultado_selection.trocas
              << std::setw(15) << resultado_selection.comparacoes
              << resultado_selection.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Insertion Sort"
              << std::setw(12) << resultado_insertion.trocas
              << std::setw(15) << resultado_insertion.comparacoes
              << resultado_insertion.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Quick Sort"
              << std::setw(12) << resultado_quick.trocas
              << std::setw(15) << resultado_quick.comparacoes
              << resultado_quick.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Merge Sort"
              << std::setw(12) << resultado_merge.trocas
              << std::setw(15) << resultado_merge.comparacoes
              << resultado_merge.tempo_ms << "\n";

    return 0;
}
