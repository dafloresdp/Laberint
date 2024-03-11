#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Variables globals: les hem declarat fora del main i de totes les funcions perquè les necessitem al llarg del tot
*  el programa. És recomanable utilitzar el mínim de variables globals possible, per evitar errors difícils de detec-
*  tar al llarg del codi. */
const int FILES = 10; //'const' és una clàusula de seguretat per evitar que aquesta variable es canviï al llarg del programa.
const int COLUMNES = 10; //'const' és una clàusula de seguretat per evitar que aquesta variable es canviï al llarg del programa.
int posicioSortidaX;
int posicioSortidaY;

// ESPECIFICACIÓ generarLaberint():
// Pre: -
// Post: Es determina el valor de les variables següents:
//       posicioJugadorX, posicioJugadorY -> posició X,Y inicial del jugador/a (variables per referència)
//       posicioSortidaX, posicioSortidaY -> posició X,Y de la sortida del laberint (variables globals)
//       Impornat: es garanteix que (posicioJugadorX, posicioJugadorY) != (posicioSortidaX, posicioSortidaY)
void generarLaberint(int& posicioJugadorX, int& posicioJugadorY) {
    srand(time(0)); // Inicialitzar la llavor per a la generació aleatòria
    //Utilitzeu la funció rand(); per crear un nombre aleatori.
    int r = rand(); //r és un nombre aleatori

    //Programeu la vostra funció aquí.

}

// ESPECIFICACIÓ mostrarLaberint():
// Pre: Les variables posicioJugadorX, posicioJugadorY, posicioSortidaX, posicioSortidaY han estat inicialitzades en
//      valors entre 0 i FILES-1, i 0 i COLUMNES-1.
// Post: S'imprimeix el taulell del laberint:
//       A cada posició lliure s'imprimeix '#'
//       A la posició (x,y) = (posicioJugadorX, posicioJugadorY) s'imprimeix 'J'
//       A la posició (x,y) = (posicioSortidaX, posicioSortidaY) s'imprimeix 'S'
void mostrarLaberint(int& posicioJugadorX, int& posicioJugadorY) {

    //Programeu la vostra funció aquí.

}

// ESPECIFICACIÓ movimentValid():
// Pre: -
// Post: Retorna 'true' si el moviment proposat a la posició (x,y) està dins del taulell.
//       Altrament, retorna 'false'.
bool movimentValid(int x, int y) {

    //Programeu la vostra funció aquí.

}


// ESPECIFICACIÓ moureJugador():
// Pre: Les variables posicioJugadorX, posicioJugadorY, posicioSortidaX, posicioSortidaY han estat inicialitzades en
//      valors entre 0 i FILES-1, i 0 i COLUMNES-1; direccio és un caràcter dels següents: 'w'/'W', 'a'/'A', 'd/D',
//      's'/'S'
// Post: Es canvia la posició del jugador segons el moviment descrit a la variable direccio.
void moureJugador(char direccio, int& posicioJugadorX, int& posicioJugadorY) {

    //Programeu la vostra funció aquí.

}

// ESPECIFICACIÓ camiMesCurt():
// Pre: 0 <= x < FILES; 0 <= y < COLUMNES; les variables posicioSortidaX, posicioSortidaY han estat inicialitzades en
//      valors entre 0 i FILES-1, i 0 i COLUMNES-1
// Post: Es retorna la quantitat de moviments que s'han de fer en el camí més curt per arribar a la posició de sortida
//       des de la posició (x, y)
int camiMesCurt(int x, int y) {

    //Programeu la vostra funció aquí.

}

int main() {

    //Programeu aquí el codi per aconseguir que el joc funcioni.

    //Observació: Utilitzeu la funció següent abans d'imprimir el laberint per aconseguir que s'actualitzi després de
    // cada moviment
    system("cls"); //En cas que feu servir Windows
    system("clear"); //En cas que feu servir Mac / Linux

}
