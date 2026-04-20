#include <iostream>
#include <fstream>
#include <string>


struct Mapa{
    std::string rue_V = "  |  ";
    std::string rue_H = " --- ";
    std::string Universal = " [U] ";  
    std::string par = " [P] ";
    std::string pdis = " [P] ";
    std::string dis = "/ / /";

    std::string velo = " [B] ";
    std::string moto = " [M] ";

    std::string np = "/ / /";
    std::string wall = " MUR ";
    std::string ent = "ENTRY";
    std::string sal = "SORTI";
};

struct Diseno{
    std::string CRue = "\033[1;38;2;255;255;255;48;2;47;47;47m";
    std::string CEnt = "\033[1;38;2;0;0;255;48;2;255;255;255m";
    std::string CEnd = "\033[1;38;2;0;255;0;48;2;255;255;255m";
    std::string Cnp = "\033[1;38;2;255;255;0;48;2;0;0;0m";
    std::string Cwall = "\033[38;2;255;255;255;48;2;192;70;87m";

    std::string CPar = "\033[1;38;2;0;0;0;48;2;120;120;120m";
    std::string CPD = "\033[1;38;2;255;255;255;48;2;135;206;235m";
    std::string CDis = "\033[1;38;2;255;255;255;48;2;135;206;235m";

    std::string CFini = "\033[0m";
};

auto AdaptarTexto = [](std::string texto, std::string CIn, std::string CFin , int ancho){
    int AnchoV = texto.length();

    std::string solve = CIn + texto + CFin;
    if(AnchoV >= ancho){
        return solve;
    }
    return solve + std::string(ancho - AnchoV, ' ');
};

auto PintarEnHorizontal = [](int inicio, int hasta, int n , std::string celda, std::string matriz[32][32]){
    for(int i= inicio; i < hasta; i++){
        matriz[n][i] = celda;
    }
};

auto PintarEnVertical = [](std::string celda, std::string matriz[32][32], int n){
    matriz[1][n] = celda;
    matriz[2][n] = celda;
    matriz[3][n] = celda;
    matriz[4][n] = celda;
    matriz[5][n] = celda;
    matriz[6][n] = celda;
    matriz[7][n] = celda;
    matriz[8][n] = celda;
    matriz[9][n] = celda;
    matriz[10][n] = celda;
    matriz[11][n] = celda;
    matriz[12][n] = celda;
    matriz[13][n] = celda;
    matriz[14][n] = celda;
    matriz[15][n] = celda;
    matriz[16][n] = celda;
    matriz[17][n] = celda;
    matriz[18][n] = celda;
    matriz[19][n] = celda;
    matriz[20][n] = celda;
    matriz[21][n] = celda;
    matriz[22][n] = celda;
    matriz[23][n] = celda;
    matriz[24][n] = celda;
    matriz[25][n] = celda;
    matriz[26][n] = celda;
    matriz[27][n] = celda;
    matriz[28][n] = celda;
    matriz[29][n] = celda;
    matriz[30][n] = celda;
};

void Generar_PMapa(){
    Mapa texto;
    Diseno Color;
    int ancho = 0;

    std::string rV = AdaptarTexto(texto.rue_V, Color.CRue, Color.CFini, ancho);
    std::string rH = AdaptarTexto(texto.rue_H, Color.CRue, Color.CFini, ancho);

    std::string P = AdaptarTexto(texto.par, Color.CPar, Color.CFini, ancho);
    std::string Pd = AdaptarTexto(texto.pdis, Color.CPD, Color.CFini, ancho);
    std::string D = AdaptarTexto(texto.dis, Color.CDis, Color.CFini, ancho);
    std::string B = AdaptarTexto(texto.velo, Color.CPar, Color.CFini, ancho);
    std::string M = AdaptarTexto(texto.moto, Color.CPar, Color.CFini, ancho);
    std::string U = AdaptarTexto(texto.Universal, Color.CPar, Color.CFini, ancho);

    std::string W = AdaptarTexto(texto.wall, Color.Cwall, Color.CFini, ancho);
    std::string E = AdaptarTexto(texto.ent, Color.CEnt, Color.CFini, ancho);
    std::string S = AdaptarTexto(texto.sal, Color.CEnd, Color.CFini, ancho);
    std::string I = AdaptarTexto(texto.np, Color.Cnp, Color.CFini, ancho);
   

    std::string matriz[32][32];
    PintarEnHorizontal(0, 30, 29, P, matriz); matriz[29][30] = U; // Fila 30 (Matriz[29])
    PintarEnHorizontal(0, 30, 28, P, matriz); matriz[28][30] = U; // Fila 29 (Matriz[28])
    PintarEnHorizontal(0, 30, 26, P, matriz); matriz[26][30] = U; // Fila 27 (Matriz[26])
    PintarEnHorizontal(0, 30, 25, P, matriz); matriz[25][30] = U; // Fila 26 (Matriz[25])
    PintarEnHorizontal(0, 30, 24, P, matriz); matriz[24][30] = U; // Fila 25 (Matriz[24])
    PintarEnHorizontal(0, 30, 22, P, matriz); matriz[22][30] = U; // Fila 23 (Matriz[22])
    PintarEnHorizontal(0, 30, 21, P, matriz); matriz[21][30] = U; // Fila 22 (Matriz[21])
    PintarEnHorizontal(0, 30, 20, P, matriz); matriz[20][30] = U; // Fila 21 (Matriz[20])

    PintarEnHorizontal(0, 30, 18, P, matriz); PintarEnHorizontal(15, 30, 18, D, matriz); matriz[18][30] = I; // Fila 19 (Matriz[18])
    PintarEnHorizontal(0, 30, 17, P, matriz); PintarEnHorizontal(15, 30, 17, Pd, matriz);  matriz[17][30] = I; // Fila 18 (Matriz[17])

    PintarEnHorizontal(0, 30, 16, P, matriz); matriz[16][30] = I; // Fila 17 (Matriz[16])
    PintarEnHorizontal(0, 30, 15, P, matriz); matriz[15][30] = I; // Fila 16 (Matriz[15])
    PintarEnHorizontal(0, 30, 14, P, matriz); matriz[14][30] = I; // Fila 15 (Matriz[14])
    PintarEnHorizontal(0, 30, 13, P, matriz); matriz[13][30] = I; // Fila 14 (Matriz[13])

    PintarEnHorizontal(0, 30, 11, D, matriz);PintarEnHorizontal(15, 30, 11, U, matriz) ; matriz[11][30] = B; // Fila 12 (Matriz[11])
    PintarEnHorizontal(0, 30, 10, Pd, matriz); PintarEnHorizontal(15, 30, 10, U, matriz); matriz[10][30] = B; // Fila 11 (Matriz[10])
    

    PintarEnHorizontal(0, 30, 8, P, matriz); matriz[9][30] = B; // Fila 9 (Matriz[8])
    PintarEnHorizontal(0, 30, 8, P, matriz); matriz[8][30] = B; // Fila 9 (Matriz[8])
    PintarEnHorizontal(0, 30, 7, P, matriz); matriz[7][30] = B; // Fila 8 (Matriz[7])
    PintarEnHorizontal(0, 30, 6, P, matriz); matriz[6][30] = B; // Fila 7 (Matriz[6])
    PintarEnHorizontal(0, 30, 4, M, matriz); matriz[4][30] = B; // Fila 5(Matriz[4])
    PintarEnHorizontal(0 , 30, 3, M, matriz); matriz[3][30] = B; // Fila 4(Matriz[3])
    PintarEnHorizontal(4, 30, 2, M, matriz); matriz[2][30] = B; // Fila 3(Matriz[2])
    PintarEnVertical(B, matriz, 2); // Columna 3 (Matriz[n][2])
    PintarEnHorizontal(1, 12, 1, rH, matriz); PintarEnHorizontal(13, 19, 1, I, matriz); matriz[1][19] = P; PintarEnHorizontal(20, 22, 1, I, matriz); matriz[1][23] = I; PintarEnHorizontal(25, 27, 1, I, matriz) ; PintarEnHorizontal(28, 31, 1, I, matriz);
    // Fila 2(Matriz[1])
    PintarEnHorizontal(0, 32, 0, W, matriz); // Fila 1 (Matriz[0])

    PintarEnHorizontal(1, 29, 5, rH, matriz); matriz[5][30] = B; // Fila 6 (Matriz[5])
    PintarEnHorizontal(1 , 29, 9, rH, matriz); // Fila 10 (Matriz[9])
    PintarEnHorizontal(1, 31, 12, rH, matriz); // Fila 13 (Matriz[12])
    PintarEnHorizontal(1 , 29, 16, rH, matriz); // Fila 17(Matriz[16])
    PintarEnHorizontal(1 , 31, 19, rH, matriz); // Fila 20(Matriz[19])
    PintarEnHorizontal(1 , 30, 23, rH, matriz); matriz[23][30] = U; // Fila 24(Matriz[23])
    PintarEnHorizontal(1 , 30, 27, rH, matriz); matriz[27][30] = U;// Fila 28(Matriz[27])
    PintarEnHorizontal(1, 30, 30, rH, matriz); matriz[30][30] = U; // Fila 31(Matriz[30])
    PintarEnHorizontal(0, 32, 31, W, matriz); // Fila 32 (Matriz[31])

   
         // Columnas a pintar
    PintarEnVertical(W, matriz, 0); // Columna 1 (Matriz[n][0]); Pintar Pared.
    PintarEnVertical(W, matriz, 31); // Columna 32 (Matriz[n][31]); Pintar Pared.

    PintarEnVertical(rV, matriz, 1); // Columna 2 (Matriz[n][1]); Pintar Calles Verticales
    PintarEnVertical(rV, matriz, 3); // Columna 4 (Matriz[n][3]); Pintar Calles Verticales
    PintarEnVertical(rV, matriz, 6); // Columna 7 (Matriz[n][6]); Pintar Calles Verticales
    PintarEnVertical(rV, matriz, 9); // Columna 10 (Matriz[n][9]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 12); // Columna 13 (Matriz[n][12]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 15); // Columna 16(Matriz[n][15]);  Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 16); // Columna 17 (Matriz[n][16]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 19); // Columna 18 (Matriz[n][19]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 22); // Columna 21 (Matriz[n][22]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 24); // Columna 23 (Matriz[n][23]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 27); // Columna 26 (Matriz[n][27]); Pintar Calles Verticales.
    PintarEnVertical(rV, matriz, 29); // Columna 28 (Matriz[n][29]); Pintar Calles Verticales.


    matriz[0][12] = E;
    matriz[19][31] = E;
    matriz[0][19] = S;
    matriz[12][31] = S;
    matriz[1][22] = P; matriz[1][24] = P; matriz[1][27] = P; matriz[1][29] = P;
 
    // Pintar matriz
     for(int i=0; i < 32; i++){
        for(int j=0; j < 32; j++){
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }
}

void RegistroDeVehiculos(){

}

void SistemaDeCobro(){

}

void SistemaDeDisponibilidad(){
    
}

int Menu(){
    int Opcion;
    std::cout << "*|BIENVENIDO AL SIMULADOR DE PARQUEADERO|*";
    std::cout << "MENU:";
    std::cout << "";
}

void run(){
    

}

int main(){
   Generar_PMapa();
}
