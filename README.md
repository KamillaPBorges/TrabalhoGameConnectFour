Conect 4 - Jogo de Conect 4 em C com SDL2
Descrição
Este programa é uma implementação simples do jogo Conect 4 utilizando a biblioteca SDL2 para renderização gráfica. 
Conect 4 é um jogo de tabuleiro para dois jogadores onde o objetivo é alinhar quatro fichas consecutivas da mesma cor, seja na horizontal, vertical ou diagonal.

Requisitos
SDL2 Library: Este programa requer a instalação da biblioteca SDL2. Certifique-se de que ela esteja instalada e configurada corretamente no seu sistema.
Como Compilar
Para compilar o programa, utilize o seguinte comando no terminal:

bash
Copiar código
gcc -o conect4 conect4.c -lSDL2
Este comando irá gerar um executável chamado conect4.

Como Executar
Para executar o programa, utilize o comando:

bash
Copiar código
./conect4
Como Jogar
Selecionando a Cor da Ficha:

No lado direito do tabuleiro, você verá duas fichas. A ficha superior representa a cor do jogador 1 (Vermelho) e a ficha inferior representa a cor do jogador 2 (Amarelo).
Clique na ficha da cor desejada para selecionar o jogador ativo.
Jogando:

Clique no tabuleiro (à esquerda das fichas coloridas) para soltar uma ficha na coluna escolhida.
A ficha cairá na posição mais baixa disponível da coluna.
O jogo alterna automaticamente entre os dois jogadores.
Objetivo:

O objetivo é alinhar quatro fichas da sua cor consecutivamente, seja na horizontal, vertical ou diagonal.
Controles
Mouse:
Clique esquerdo para selecionar a cor da ficha e para posicionar uma ficha no tabuleiro.
Fechar o Jogo:
Para fechar o jogo, clique no botão de fechar a janela.
Personalização
Você pode modificar as cores dos jogadores editando as variáveis player1Color e player2Color no código-fonte. Estas variáveis controlam as cores das fichas dos jogadores 1 e 2,
respectivamente.

Dependências
SDL2
Certifique-se de que a SDL2 esteja instalada no seu sistema antes de compilar e executar o programa.


Este programa foi desenvolvido como um exemplo simples de uso da SDL2 para criar jogos 2D em C.

