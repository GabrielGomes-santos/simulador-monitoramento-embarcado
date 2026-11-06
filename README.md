Para praticar lógica de programação e dar os meus primeiros passos no ecossistema de sistemas embarcados, desenvolvi um simulador de monitoramento em C++.
A ideia principal do projeto foi simular o comportamento de um dispositivo real (como um microcontrolador ou um terminal de PDV) que faz a leitura contínua 
de um sensor de temperatura em tempo real. 
O programa gera leituras aleatórias dentro de uma faixa operacional, armazena esses dados em estruturas (structs e vectors), e verifica se o equipamento
ultrapassou um limite crítico de temperatura.
Caso o limite seja ultrapassado, o sistema dispara um alerta de superaquecimento. No final da execução, ele exibe um relatório resumido com o total de leituras,
quantidade de alertas e o status geral da máquina (estável ou crítico).
Escolhi fazer esse projeto para exercitar conceitos fundamentais de C++, como alocação de dados em memória, laços de repetição e manipulação de tempo, unindo
minha base lógica com a lógica de funcionamento de hardwares e sistemas de missão crítica.
