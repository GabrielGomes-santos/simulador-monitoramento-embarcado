#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

struct LeituraSensor {
    int idLeitura;
    float temperatura;
    bool statusAlerta;
};


float lerTemperaturaHardware() {
  
  
    return 20.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 70.0f));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    std::vector<LeituraSensor> historico;
    const float LIMITE_TEMPERATURA = 75.0f; 
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

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

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
