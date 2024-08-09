#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int matriz[6][7] = {0}; // Iniciando a matriz vazia
int currentPlayer = 1;  // Jogador atual, 1 -> player1, 2 -> player2
int player1Color = 250; // Cor do jogador 1: Vermelho
int player2Color = 240; // Cor do jogador 2: Amarelo

void escolherFichas(SDL_Renderer *renderer) {
    // Desenha fichas de cores ao lado do tabuleiro
    SDL_Rect fichaP1 = {480, 50, 50, 50};
    SDL_Rect fichaP2 = {480, 150, 50, 50};

    // Cor da ficha do jogador 1
    SDL_SetRenderDrawColor(renderer, player1Color, 0, 0, 255);
    SDL_RenderFillRect(renderer, &fichaP1);

    // Cor da ficha do jogador 2
    SDL_SetRenderDrawColor(renderer, player2Color, 250, 50, 255);
    SDL_RenderFillRect(renderer, &fichaP2);
}

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Conect 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 560, 560, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
            {
                int mouse_x = event.button.x;
                int mouse_y = event.button.y;

                // Verifica se o jogador está selecionando a cor da ficha
                if (mouse_x > 480 && mouse_x < 530 && mouse_y > 50 && mouse_y < 100)
                {
                    // Clicou na ficha do jogador 1 (vermelho)
                    currentPlayer = 1;
                }
                else if (mouse_x > 480 && mouse_x < 530 && mouse_y > 150 && mouse_y < 200)
                {
                    // Clicou na ficha do jogador 2 (amarelo)
                    currentPlayer = 2;
                }
                else if (mouse_x < 480)
                {
                    // Clique no tabuleiro
                    int x = mouse_x / 80; // 80 é o tamanho da célula
                    for (int i = 5; i >= 0; i--)
                    { // Percorre as linhas de baixo para cima
                        if (matriz[i][x] == 0)
                        {
                            matriz[i][x] = currentPlayer;
                            if (currentPlayer == 1)
                            {
                                currentPlayer = 2; // Próximo jogador
                            }
                            else
                            {
                                currentPlayer = 1;
                            }
                            break;
                        }
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Fundo branco
        SDL_RenderClear(renderer);

        for (int i = 0; i < 6; i++)
        { // Percorre as linhas
            for (int j = 0; j < 7; j++)
            { // Percorre as colunas
                SDL_Rect rect = {j * 80, i * 80, 80, 80};
                if (matriz[i][j] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Células vazias em preto
                }
                else if (matriz[i][j] == 1)  //se for o jogaodr 1
                {
                    SDL_SetRenderDrawColor(renderer, player1Color, 0, 0, 255); // PLAYER 1 -> Cor escolhida para Vermelho
                }
                else if (matriz[i][j] == 2)  //se for o jogador2
                {
                    SDL_SetRenderDrawColor(renderer, player2Color, 250, 50, 255); // PLAYER 2 -> Cor escolhida para Amarelo
                }
                SDL_RenderFillRect(renderer, &rect); // Desenha com a cor escolhida
            }
        }

        escolherFichas(renderer); // Atualiza as cores das fichas ao lado do tabuleiro
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}