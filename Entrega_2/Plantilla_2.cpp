#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> //NOU!
#include <thread> //NOU!
using namespace std;
using namespace std::this_thread;     // NOU!
using namespace std::chrono_literals; // NOU!

/* Variables globals: les hem declarat fora del main i de totes les funcions perquè les necessitem al llarg del tot
*  el programa. És recomanable utilitzar el mínim de variables globals possible, per evitar errors difícils de detec-
*  tar al llarg del codi. */
const int FILES = 10; //'const' és una clàusula de seguretat per evitar que aquesta variable es canviï al llarg del programa.
const int COLUMNES = 10; //'const' és una clàusula de seguretat per evitar que aquesta variable es canviï al llarg del programa.
int posicioSortidaX;
int posicioSortidaY;
int trampa1X, trampa1Y; //NOU!
int trampa2X, trampa2Y; //NOU!

// SENSE NOVETATS
void generarLaberint(int& posicioJugadorX, int& posicioJugadorY) {
    srand(time(0)); // Inicialitzar la llavor per a la generació aleatòria
    //Utilitzeu la funció rand(); per crear un nombre aleatori.
    int r = rand(); //r és un nombre aleatori

    //Programeu la vostra funció aquí.

}

// SENSE NOVETATS
void mostrarLaberint(int& posicioJugadorX, int& posicioJugadorY) {

    //Programeu la vostra funció aquí.

}

// SENSE NOVETATS
bool movimentValid(int x, int y) {

    //Programeu la vostra funció aquí.

}


//  SENSE NOVETATS
void moureJugador(char direccio, int& posicioJugadorX, int& posicioJugadorY) {

    //Programeu la vostra funció aquí.

}

// (CONSULTEU NOVETATS) ESPECIFICACIÓ camiMesCurt():
// Pre: 0 <= x < FILES; 0 <= y < COLUMNES; les variables posicioSortidaX, posicioSortidaY han estat inicialitzades en
//      valors entre 0 i FILES-1, i 0 i COLUMNES-1
// Post: Es retorna la quantitat de moviments que s'han de fer en el camí més curt per arribar a la posició de sortida
//       des de la posició (x, y) tenint en compte la posició de les trampes (NOU!)
int camiMesCurt(int x, int y) {

    //Programeu la vostra funció aquí.

}

// NOU: ESPECIFICACIÓ crearTrampes():
// Pre: 0 <= posicioJugadorX < FILES, 0 <= posicioJugadorY < COLUMNES, i 0 <= posicioSortidaX < FILES,
//      0 <= posicioSortidaY < COLUMNES
// Post: trampaX i trampaY prenen un valor dins de les ubicacions possibles (consulteu l'enunciat - fig. 3).
//       Es compleix que: (trampaX, trampaY) != (posicioJugadorX, posicioJugadorY) i que
//       (trampaX, trampaY) != (posicioSortidaX, posicioSortidaY). Programeu aquesta comprovació de forma recursiva.
void crearTrampes(int& posicioJugadorX, int& posicioJugadorY, int& trampaX, int& trampaY) {

    //Programeu la vostra funció aquí.

}

// ESPECIFICACIÓ mostrarTrampes():
// Pre-Post: aquesta funció fa el mateix que mostrarLaberint(), però també mostra les posicions de les trampes amb el
//           símbol "O".
void mostrarTrampes(int& posicioJugadorX, int& posicioJugadorY) {

    //Programeu la vostra funció aquí.

}

int main() {
    //Programeu aquí el codi per aconseguir que el joc funcioni.

    //Observació: Utilitzeu la funció següent abans d'imprimir el laberint per aconseguir que s'actualitzi després de
    // cada moviment
    system("cls"); //En cas que feu servir Windows
    system("clear"); //En cas que feu servir Mac / Linux

    //Observació: Utilitzeu la funció següent per aconseguir que l'execució s'aturi durant el temps que volgueu. En
    //  aquest exemple, l'execució s'atura durant 1s.
    //  També pot ser necessària per aconseguir que es reiniciï la llavor aleatòria srand(time(0))
    sleep_for(1s);

}
