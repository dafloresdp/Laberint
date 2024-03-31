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
    srand(time(0));  //Amb aquest rand es genera una posició de sortida i de jugador aleatòries, tenint en compte els valors fixos dels límits de mapa.

    posicioJugadorX = rand() % FILES;
    posicioJugadorY = rand() % COLUMNES;

    do
    {
        posicioSortidaX = rand() % FILES;
        posicioSortidaY = rand() % COLUMNES;
           //Quan es verifiqui que les posicions cartesianes de jugador i sortida son correctes, es "randomitzarà" un laberint.
    }
    while (posicioSortidaX == posicioJugadorX && posicioSortidaY == posicioJugadorY);

    sleep_for(1s);
}

void mostrarLaberint(int& posicioJugadorX, int& posicioJugadorY)  //Generació de laberint amb bucles for que imprimiran cada línia.
{
{
    for (int i = 0; i < FILES; ++i)
    {
        for (int j = 0; j < COLUMNES; ++j)
        {
            if (i == posicioJugadorX && j == posicioJugadorY)  //Si la posició de x i y és J o S s'escribiren les lletres mencionades en comptes dels '#'.
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

bool movimentValid(int x, int y)   //Aquí es verifica el moviment vàlid. Si no no hi hauràn canvis.
{
    return x >= 0 && x < FILES && y >= 0 && y < COLUMNES;
}

void moureJugador(char direccio, int& posicioJugadorX, int& posicioJugadorY)  //Moviments de jugador. En cas de que premi...
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

bool esTrampa(int x, int y, int trampa1X, int trampa1Y, int trampa2X, int trampa2Y) //Aquí es verifica si s'ha caigut en una trampa.
{
    return (x == trampa1X && y == trampa1Y) || (x == trampa2X && y == trampa2Y); //Retorn d'informació.
}

int distanciaMesCurta(int jugadorX, int jugadorY, int sortidaX, int sortidaY, int trampa1X, int trampa1Y, int trampa2X, int trampa2Y)
 //S'implementa un reconegut en amplada per determinar la distància més curta entre la sortida i el jugador, assignant al jugador un "0".
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

    return dist[sortidaX][sortidaY]; //Retorn de distància.
}

int camiMesCurt(int x, int y) //Es fa un retorn de la distància o camí més curt tenint en compte les trampes.
{
    int trampa1X = 5, trampa1Y = 4;
    int trampa2X = 2, trampa2Y = 6;

    return distanciaMesCurta(x, y, posicioSortidaX, posicioSortidaY, trampa1X, trampa1Y, trampa2X, trampa2Y);
}

void crearTrampes(int& posicioJugadorX, int& posicioJugadorY, int& posicioSortidaX, int& posicioSortidaY, int& trampa1X, int& trampa1Y, int& trampa2X, int& trampa2Y)
{    //Aquí es creen les trampes.
    srand(time(0));

    int deltaX = posicioSortidaX - posicioJugadorX;
    int deltaY = posicioSortidaY - posicioJugadorY;

    do
    {
        trampa1X = posicioJugadorX + rand() % (deltaX + 1); //Com sempre randomizers...
        trampa1Y = posicioJugadorY + rand() % (deltaY + 1); //Amb els +1, deltaY i whiles, ens assegurem que les trampes no coincideixin amb el jugador o la sortida.
    }
    while ((trampa1X == posicioJugadorX && trampa1Y == posicioJugadorY) || (trampa1X == posicioSortidaX && trampa1Y == posicioSortidaY)); 

    do
    {
        trampa2X = posicioJugadorX + rand() % (deltaX + 1);
        trampa2Y = posicioJugadorY + rand() % (deltaY + 1);
    }
    while ((trampa2X == posicioJugadorX && trampa2Y == posicioJugadorY) || (trampa2X == posicioSortidaX && trampa2Y == posicioSortidaY) || (trampa2X == trampa1X && trampa2Y == trampa1Y));
}

void mostrarTrampes(int& posicioJugadorX, int& posicioJugadorY, int& trampa1X, int& trampa1Y, int& trampa2X, int& trampa2Y) //Imprimim les trampes i taulell.
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
    int posicioJugadorX, posicioJugadorY; //Interfície del joc.

    char mode;
    cout << "Entra en el mode (normal = n, God-mode = *): "; //Opcions.
    cin >> mode;

    if (mode == 'n'||mode== 'N') //Mode normal i crida de les funcions i voids.
    {
        generarLaberint(posicioJugadorX, posicioJugadorY);
        crearTrampes(posicioJugadorX, posicioJugadorY, posicioSortidaX, posicioSortidaY, trampa1X, trampa1Y, trampa2X, trampa2Y);

        char moviment;
        bool haPerdut = false;

        do //En cas de caiguda en una trampa.
        {
            if ((posicioJugadorX == trampa1X && posicioJugadorY == trampa1Y) || (posicioJugadorX == trampa2X && posicioJugadorY == trampa2Y))
            {
                cout << "Has caigut en una trampa! Has perdut." << endl;
                haPerdut = true;
                break;
            }

            mostrarTrampes(posicioJugadorX, posicioJugadorY, trampa1X, trampa1Y, trampa2X, trampa2Y); //Impressió taulell.

            cout << "Endavant! Et mous amb w/a/s/d. Bona sort! " << endl;
            cout << "Insereix el teu moviment: ";
            cin >> moviment;

            moureJugador(moviment, posicioJugadorX, posicioJugadorY);

            system("cls");
        }
        while (posicioJugadorX != posicioSortidaX || posicioJugadorY != posicioSortidaY);

        if (!haPerdut) //Si no hem perdut, hem guanyat :-)
        {
            cout << "Has arribat a la sortida! Felicitats!" << endl;
        }
    }
    else if (mode == '*') //Entrem en mode Déu!
    {
        cout << "Introdueix les coordenades de la sortida (x y): ";  //Tú fas input d'on vols cada ítem.
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
                haPerdut = true; //Aquí "haPerdut" és cert, ja que hem caigut en una trampa.
                break;
            }

            mostrarTrampes(posicioJugadorX, posicioJugadorY, trampa1X, trampa1Y, trampa2X, trampa2Y);

            cout << "Endavant! Et mous amb w/a/s/d. Bona sort! " << endl;
            cout << "Insereix el teu moviment: ";
            cin >> moviment;

            moureJugador(moviment, posicioJugadorX, posicioJugadorY);

            system("cls"); //Rentat de memòria.
        }
        while (posicioJugadorX != posicioSortidaX || posicioJugadorY != posicioSortidaY);

        if (!haPerdut) //Si no hem perdut, hem guanyat!
        {
            cout << "Has arribat a la sortida! Felicitats!" << endl;
        }
    }
    else
    {
        cout << "Mode no reconegut." << endl; //Qualsevol caràcter, o combinació de caracters que no sigui "n" o "*".
    }

    return 0;
}

