#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

//Estrutura para representar a leitura de um sensor

struct LeituraSensor {
    int idLeitura;
    float temperatura;
    bool statusAlerta;
};

//Função para simular a leitura do sensor de hardware

float lerTemperaturaHardware() {
  
    //Simula variação de temperatura entre 20°C e 90°C
  
    return 20.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 70.0f));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    std::vector<LeituraSensor> historico;
    const float LIMITE_TEMPERATURA = 75.0f; //Limiar de alerta em °C
    const int TOTAL_LEITURAS = 10;

    std::cout << "=================================================\n";
    std::cout << "   SISTEMA DE MONITORAMENTO EMBARCADO (SIMULADOR)\n";
    std::cout << "=================================================\n\n";

    for (int i = 1; i <= TOTAL_LEITURAS; ++i) {
        float tempAtual = lerTemperaturaHardware();
        bool emAlerta = tempAtual > LIMITE_TEMPERATURA;

        LeituraSensor leitura = {i, tempAtual, emAlerta};
        historico.push_back(leitura);

        std::cout << "[Leitura " << i << "] Temp: " << tempAtual << "°C ";
        if (emAlerta) {
            std::cout << "--> [ALERTA: Superaquecimento Detectado!]\n";
        } else {
            std::cout << "--> [OK: Operacao Normal]\n";
        }

        //Aguarda 1 segundo entre leituras para simular loop em tempo real
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    //Resumo final do monitoramento
    std::cout << "\n-------------------------------------------------\n";
    std::cout << "RELATORIO FINAL DE OPERACAO\n";
    std::cout << "-------------------------------------------------\n";
    int ocorrenciasAlerta = 0;
    for (const auto& reg : historico) {
        if (reg.statusAlerta) ocorrenciasAlerta++;
    }

    std::cout << "Total de leituras executadas: " << TOTAL_LEITURAS << "\n";
    std::cout << "Total de alertas emitidos: " << ocorrenciasAlerta << "\n";
    std::cout << "Status geral da maquina: " 
              << (ocorrenciasAlerta > 3 ? "CRITICO (Requer Manutencao)" : "ESTAVEL") << "\n";

    return 0;
}
