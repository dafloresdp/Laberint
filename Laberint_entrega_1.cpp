#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int FILES = 10;
const int COLUMNES = 10;
int posicioSortidaX;
int posicioSortidaY;

void generarLaberint(int& posicioJugadorX, int& posicioJugadorY)
{
    srand(time(0));
    //Amb aquest rand es genera una posició de sortida i de jugador aleatòries, tenint en compte els valors fixos dels límits de mapa.

    posicioJugadorX = rand() % FILES;
    posicioJugadorY = rand() % COLUMNES;

    do
    {
        posicioSortidaX = rand() % FILES;
        posicioSortidaY = rand() % COLUMNES;

        //Quan es verifiqui que les posicions cartesianes de jugador i sortida son correctes, es "randomitzarà" un laberint.
    }
    while (posicioSortidaX == posicioJugadorX && posicioSortidaY == posicioJugadorY);
}

void mostrarLaberint(int& posicioJugadorX, int& posicioJugadorY)      //Generació de laberint amb bucles for que imprimiran cada línia.
{
    for (int i = 0; i < FILES; ++i)
    {
        for (int j = 0; j < COLUMNES; ++j)
        {
            if (i == posicioJugadorX && j == posicioJugadorY)    //Si la posició de x i y és J o S s'escribiren les lletres mencionades en comptes dels '#'.
            {
                cout << 'J';
            }
            else if (i == posicioSortidaX && j == posicioSortidaY)
            {
                cout << 'S';
            }
            else
            {
                cout << '#';
            }
            cout << ' ';
        }
        cout << endl;
    }
}

bool movimentValid(int x, int y)     //Aquí es verifica el moviment vàlid. Si no no hi hauràn canvis.
{
    return x >= 0 && x < FILES && y >= 0 && y < COLUMNES;
}

void moureJugador(char direccio, int& posicioJugadorX, int& posicioJugadorY)   //Moviments de jugador. En cas de que premi...
{
    switch (direccio)
    {
    case 'w':
    case 'W':
        if (movimentValid(posicioJugadorX - 1, posicioJugadorY))
        {
            --posicioJugadorX;
        }
        break;
    case 'a':
    case 'A':
        if (movimentValid(posicioJugadorX, posicioJugadorY - 1))
        {
            --posicioJugadorY;
        }
        break;
    case 'd':
    case 'D':
        if (movimentValid(posicioJugadorX, posicioJugadorY + 1))
        {
            ++posicioJugadorY;
        }
        break;
    case 's':
    case 'S':
        if (movimentValid(posicioJugadorX + 1, posicioJugadorY))
        {
            ++posicioJugadorX;
        }
        break;
    }
}

int camiMesCurt(int x, int y)
{
    //Retornar distància
    return abs(x - posicioSortidaX) + abs(y - posicioSortidaY);
}

int main()
{
    int posicioJugadorX, posicioJugadorY;
//Crida als voids. En aquest cas creació del mapa/laberint.
    generarLaberint(posicioJugadorX, posicioJugadorY);

    char moviment;
    do    //Mostra el laberint generat
    {
        mostrarLaberint(posicioJugadorX, posicioJugadorY);

        cout << "Endavant! Et mous amb w/a/s/d. Bona sort! " << endl;
        cout << "Insereix el teu moviment: ";
        cin >> moviment;


        moureJugador(moviment, posicioJugadorX, posicioJugadorY);

        //Esborrar la pantalla perquè es vegi la nova posició del jugador
        system("cls");
    }
    while (posicioJugadorX != posicioSortidaX || posicioJugadorY != posicioSortidaY);   //Mentre la posició del jugador sigui diferent a la de sortida.

    cout << "Has arribat a la sortida! Felicitats!" << endl; //Felicitats!! Has superat el nivell!


    return 0;
}

