#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;   //Temps i distàncies.
using namespace std::chrono_literals;

//Declarem
const int FILES = 10;
const int COLUMNES = 10;
int posicioSortidaX;
int posicioSortidaY;
int trampa1X, trampa1Y;
int trampa2X, trampa2Y;

void crearTrampes(int& posicioJugadorX, int& posicioJugadorY, int& trampaX, int& trampaY)
{
    trampaX = rand() % FILES;  //Randomitzem trampes.
    trampaY = rand() % COLUMNES;

    while ((trampaX == posicioJugadorX && trampaY == posicioJugadorY) || (trampaX == posicioSortidaX && trampaY == posicioSortidaY))
    {
        trampaX = rand() % FILES;
        trampaY = rand() % COLUMNES;
    }
}

void generarLaberint(int& posicioJugadorX, int& posicioJugadorY)
{
    srand(time(0));

    posicioJugadorX = rand() % FILES;  //Randomitzem posició de Player.
    posicioJugadorY = rand() % COLUMNES;

    do
    {
        posicioSortidaX = rand() % FILES; //Randomitzem sortida.
        posicioSortidaY = rand() % COLUMNES;
    }
    while (posicioSortidaX == posicioJugadorX && posicioSortidaY == posicioJugadorY);

    // Generació de trampes entre jugador i sortida.
    crearTrampes(posicioJugadorX, posicioJugadorY, trampa1X, trampa1Y);
    crearTrampes(posicioJugadorX, posicioJugadorY, trampa2X, trampa2Y);

    // Ensenyem trampes. Creació de mapa.
    for (int i = 0; i < FILES; ++i)
    {
        for (int j = 0; j < COLUMNES; ++j)
        {
            if ((i == trampa1X && j == trampa1Y) || (i == trampa2X && j == trampa2Y))
            {
                cout << 'O';
            }
            else if (i == posicioJugadorX && j == posicioJugadorY)
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

    // Fem espera de 2 segons
    sleep_for(2s);

    // Refresc de pantalla uan vegada han sigut ensenyades les trampes.
    system("cls");
}

int camiMesCurt(int x, int y)
{
    // Càlculs per veure la distància entre sortida i trampes.
    int distanceToExit = abs(x - posicioSortidaX) + abs(y - posicioSortidaY);
    int distanceToTrap1 = abs(x - trampa1X) + abs(y - trampa1Y);
    int distanceToTrap2 = abs(x - trampa2X) + abs(y - trampa2Y);

    // Mirem si alguna tramps és més a prop que la sortida.
    if (distanceToTrap1 < distanceToExit || distanceToTrap2 < distanceToExit)
    {
        cout << "Has caigut en una trampa! GAME OVER!" << endl;
        return -1; // Has mort! (BE)
    }

    // Retorn de la distància que estem de la sortida.
    return distanceToExit;
}
int main()
{
    int posicioJugadorX, posicioJugadorY;

    generarLaberint(posicioJugadorX, posicioJugadorY);

    char moviment;
    do
    {
mostrarLaberint(posicioJugadorX, posicioJugadorY);

        cout << "Endavant! Et mous amb w/a/s/d. Bona sort! " << endl;
        cout << "Insereix el teu moviment: ";
        cin >> moviment;

        moureJugador(moviment, posicioJugadorX, posicioJugadorY);

        // Fem Clean de pantalla.
        system("cls");

        // Ha caigut el jugador en alguna trampa?
        int shortestPath = camiMesCurt(posicioJugadorX, posicioJugadorY);
        if (shortestPath == -1)
        {
            return 0; // End game
        }

        // Hem arribat a la sortida?
        if (posicioJugadorX == posicioSortidaX && posicioJugadorY == posicioSortidaY)
        {
            cout << "Has arribat a la sortida! Felicitats!" << endl;
            return 0; // Fi del joc. Felicitats! (GE)
        }
    }
    while (true);

    return 0;
}
