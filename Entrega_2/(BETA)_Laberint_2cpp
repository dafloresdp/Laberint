#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

const int FILES = 10;
const int COLUMNES = 10;
int posicioSortidaX;
int posicioSortidaY;
int trampa1X, trampa1Y;
int trampa2X, trampa2Y;

void generarLaberint(int& posicioJugadorX, int& posicioJugadorY)
{
    srand(time(0));

    posicioJugadorX = rand() % FILES;
    posicioJugadorY = rand() % COLUMNES;

    do
    {
        posicioSortidaX = rand() % FILES;
        posicioSortidaY = rand() % COLUMNES;
    }
    while (posicioSortidaX == posicioJugadorX && posicioSortidaY == posicioJugadorY);

    sleep_for(1s);
}

void mostrarLaberint(int& posicioJugadorX, int& posicioJugadorY)
{
    for (int i = 0; i < FILES; ++i)
    {
        for (int j = 0; j < COLUMNES; ++j)
        {
            if (i == posicioJugadorX && j == posicioJugadorY)
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
    sleep_for(1s);
}

bool movimentValid(int x, int y)
{
    return x >= 0 && x < FILES && y >= 0 && y < COLUMNES;
}

void moureJugador(char direccio, int& posicioJugadorX, int& posicioJugadorY)
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

bool esTrampa(int x, int y, int trampa1X, int trampa1Y, int trampa2X, int trampa2Y)
{
    return (x == trampa1X && y == trampa1Y) || (x == trampa2X && y == trampa2Y);
}

int distanciaMesCurta(int jugadorX, int jugadorY, int sortidaX, int sortidaY, int trampa1X, int trampa1Y, int trampa2X, int trampa2Y)
{
    vector<vector<int>> dist(FILES, vector<int>(COLUMNES, -1));
    dist[jugadorX][jugadorY] = 0;

    vector<pair<int, int>> moviments = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int d = 0; d < FILES * COLUMNES; ++d)
    {
        for (int i = 0; i < FILES; ++i)
        {
            for (int j = 0; j < COLUMNES; ++j)
            {
                if (dist[i][j] == d)
                {
                    for (const auto& moviment : moviments)
                    {
                        int nouX = i + moviment.first;
                        int nouY = j + moviment.second;
                        if (nouX >= 0 && nouX < FILES && nouY >= 0 && nouY < COLUMNES && dist[nouX][nouY] == -1 && !esTrampa(nouX, nouY, trampa1X, trampa1Y, trampa2X, trampa2Y))
                        {
                            dist[nouX][nouY] = d + 1;
                        }
                    }
                }
            }
        }
    }

    return dist[sortidaX][sortidaY];
}

int camiMesCurt(int x, int y)
{
    int trampa1X = 5, trampa1Y = 4;
    int trampa2X = 2, trampa2Y = 6;

    return distanciaMesCurta(x, y, posicioSortidaX, posicioSortidaY, trampa1X, trampa1Y, trampa2X, trampa2Y);
}

void crearTrampes(int& posicioJugadorX, int& posicioJugadorY, int& posicioSortidaX, int& posicioSortidaY, int& trampa1X, int& trampa1Y, int& trampa2X, int& trampa2Y)
{
    srand(time(0));

    int deltaX = posicioSortidaX - posicioJugadorX;
    int deltaY = posicioSortidaY - posicioJugadorY;

    do
    {
        trampa1X = posicioJugadorX + rand() % (deltaX + 1);
        trampa1Y = posicioJugadorY + rand() % (deltaY + 1);
    }
    while ((trampa1X == posicioJugadorX && trampa1Y == posicioJugadorY) || (trampa1X == posicioSortidaX && trampa1Y == posicioSortidaY));

    do
    {
        trampa2X = posicioJugadorX + rand() % (deltaX + 1);
        trampa2Y = posicioJugadorY + rand() % (deltaY + 1);
    }
    while ((trampa2X == posicioJugadorX && trampa2Y == posicioJugadorY) || (trampa2X == posicioSortidaX && trampa2Y == posicioSortidaY) || (trampa2X == trampa1X && trampa2Y == trampa1Y));
}

void mostrarTrampes(int& posicioJugadorX, int& posicioJugadorY, int& trampa1X, int& trampa1Y, int& trampa2X, int& trampa2Y)
{
    for (int i = 0; i < FILES; ++i)
    {
        for (int j = 0; j < COLUMNES; ++j)
        {
            if (i == posicioJugadorX && j == posicioJugadorY)
            {
                cout << 'J';
            }
            else if (i == posicioSortidaX && j == posicioSortidaY)
            {
                cout << 'S';
            }
            else if ((i == trampa1X && j == trampa1Y) || (i == trampa2X && j == trampa2Y))
            {
                cout << 'O';
            }
            else
            {
                cout << '#';
            }
            cout << ' ';
        }
        cout << endl;
    }
    sleep_for(1s);
}

int main()
{
    int posicioJugadorX, posicioJugadorY;

    char mode;
    cout << "Entra en el mode (normal = n, God-mode = *): ";
    cin >> mode;

    if (mode == 'n')
    {
        generarLaberint(posicioJugadorX, posicioJugadorY);
        crearTrampes(posicioJugadorX, posicioJugadorY, posicioSortidaX, posicioSortidaY, trampa1X, trampa1Y, trampa2X, trampa2Y);

        char moviment;
        bool haPerdut = false;

        do
        {
            if ((posicioJugadorX == trampa1X && posicioJugadorY == trampa1Y) || (posicioJugadorX == trampa2X && posicioJugadorY == trampa2Y))
            {
                cout << "Has caigut en una trampa! Has perdut." << endl;
                haPerdut = true;
                break;
            }

            mostrarTrampes(posicioJugadorX, posicioJugadorY, trampa1X, trampa1Y, trampa2X, trampa2Y);

            cout << "Endavant! Et mous amb w/a/s/d. Bona sort! " << endl;
            cout << "Insereix el teu moviment: ";
            cin >> moviment;

            moureJugador(moviment, posicioJugadorX, posicioJugadorY);

            system("cls");
        }
        while (posicioJugadorX != posicioSortidaX || posicioJugadorY != posicioSortidaY);

        if (!haPerdut)
        {
            cout << "Has arribat a la sortida! Felicitats!" << endl;
        }
    }
    else if (mode == '*')
    {
        cout << "Introdueix les coordenades de la sortida (x y): ";
        cin >> posicioSortidaX >> posicioSortidaY;
        cout << "Introdueix les coordenades de la primera trampa (x y): ";
        cin >> trampa1X >> trampa1Y;
        cout << "Introdueix les coordenades de la segona trampa (x y): ";
        cin >> trampa2X >> trampa2Y;

        cout << "Introdueix les coordenades del jugador (x y): ";
        cin >> posicioJugadorX >> posicioJugadorY;

        char moviment;
        bool haPerdut = false;

        do
        {
            if ((posicioJugadorX == trampa1X && posicioJugadorY == trampa1Y) || (posicioJugadorX == trampa2X && posicioJugadorY == trampa2Y))
            {
                cout << "Has caigut en una trampa! Has perdut." << endl;
                haPerdut = true;
                break;
            }

            mostrarTrampes(posicioJugadorX, posicioJugadorY, trampa1X, trampa1Y, trampa2X, trampa2Y);

            cout << "Endavant! Et mous amb w/a/s/d. Bona sort! " << endl;
            cout << "Insereix el teu moviment: ";
            cin >> moviment;

            moureJugador(moviment, posicioJugadorX, posicioJugadorY);

            system("cls");
        }
        while (posicioJugadorX != posicioSortidaX || posicioJugadorY != posicioSortidaY);

        if (!haPerdut)
        {
            cout << "Has arribat a la sortida! Felicitats!" << endl;
        }
    }
    else
    {
        cout << "Mode no reconegut." << endl;
    }

    return 0;
}

