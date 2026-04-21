#include <iostream>
#include <fstream>
#include <string>
#include <ctime>



struct Parqueadero{
    std::string Placa;
    int Tipo;
    time_t TiempoEntrada;
    bool Ocupado = false;
};

Parqueadero parqueaderos[32][32];

struct Values{
    int CarroVh = 230;
    int MotoVh = 161;
    int BiciVh = 10;
};


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

    std::string Disponible = "\033[1;38;2;255;255;255;48;2;0;255;0m";
    std::string Ocupado = "\033[1;38;2;255;255;255;48;2;255;255;0m";
    std::string NoDisponible = "\033[1;38;2;255;255;255;48;2;255;0;0m";


    std::string CFini = "\033[0m";
};

int Dinero = 0;

void AcutalizarSistema(){
    std::cout << "\033[2J\033[H";
}

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

void Generar_PMapa(std::string matriz[32][32]){
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
    
    PintarEnHorizontal(0, 30, 29, P, matriz); matriz[29][30] = U; // Fila 30 (Matriz[29])
    PintarEnHorizontal(0, 30, 28, P, matriz); matriz[28][30] = U; // Fila 29 (Matriz[28])
    PintarEnHorizontal(0, 30, 26, P, matriz); matriz[26][30] = U; // Fila 27 (Matriz[26])
    PintarEnHorizontal(0, 30, 25, P, matriz); matriz[25][30] = U; // Fila 26 (Matriz[25])
    PintarEnHorizontal(0, 30, 24, P, matriz); matriz[24][30] = U; // Fila 25 (Matriz[24])
    PintarEnHorizontal(0, 30, 22, P, matriz); matriz[22][30] = U; // Fila 23 (Matriz[22])
    PintarEnHorizontal(0, 30, 21, P, matriz); matriz[21][30] = U; // Fila 22 (Matriz[21])
    PintarEnHorizontal(0, 30, 20, P, matriz); matriz[20][30] = U; // Fila 21 (Matriz[20])

    PintarEnHorizontal(0, 30, 18, U, matriz); PintarEnHorizontal(15, 30, 18, D, matriz); matriz[18][30] = I; // Fila 19 (Matriz[18])
    PintarEnHorizontal(0, 30, 17, U, matriz); PintarEnHorizontal(15, 30, 17, Pd, matriz);  matriz[17][30] = I; // Fila 18 (Matriz[17])

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

void MostrarMapa(std::string matriz[32][32]){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            std::cout << matriz[i][j];
        }
        std::cout << "\n";
    }
}

bool IsCarro(int r, int c, bool esDis){
    Mapa M;
    if(esDis){
        if((r == 10 || r == 11) && (c >= 4 && c <=14) && (c != 3 && c != 6 && c !=9 && c!=12)){
            return true;
        }

        // Universal
        if((r == 10 || r == 11) && (c >=20 && c <= 28) && c != 22 && c != 24 && c != 27){
            return true;
        }

        if(c == 30 && r >= 20 && r  <= 30){
            return true;
        }
        
        if((r == 17 || r == 18) && (c >= 17 && c<=28) && c!=19 && c!=22 && c!=24 && c!=26){
            return true;
        }
        return false;
    }


    if((r >=20 && r <=29) && r!=23 && r!=27 && (c >=4 && c <= 29) && c !=6 && c!=9 && c!=12 && c!=15 && c!=16 && c!=19 && c!=22 && c!=24 && c!=27){
        return true;
    }
    return false;
}

bool IsMoto(int r, int c, bool){
    Mapa M;
    if((r == 2 || r == 3 || r == 4 ) && c!= 1 && c!= 3 && c!= 6 && c!= 9 && c!= 12 && c!= 15  && c!= 16 && c!= 19 && c!=22 && c!=24 && c!= 27 && c!= 29){
        return true;
    }

     // Universal
     if((r == 10 || r == 11) && (c >=20 && c <= 28) && c != 22 && c != 24 && c != 27){
         return true;
    }

    if(c == 30 && r >= 20 && r  <= 30){
         return true;
     }
        
    return false;
}

bool IsBici(int r, int c, bool){
    Mapa M;

    if(c == 2 && r>=2 && r<=29 && r !=5 && r!=9 && r!=12 && r!=16 && r!=19 && r!=23 && r!=27){
        return true;
    }

    if(c == 30 && r >=2 && r<=11){
        return true;
    }

    // Universal
    if((r == 10 || r == 11) && (c >=20 && c <= 28) && c != 22 && c != 24 && c != 27){
        return true;
    }

    if(c == 30 && r >= 20 && r  <= 30){
         return true;
    }
        
    return false;
}



void ElegirCelda(std::string Matriz[32][32], int Tipo, bool IsDis, std::string Placa){
    int r, c;
    Diseno D;

    bool(*validador)(int, int, bool);

    switch(Tipo){
        case 1: validador = IsCarro; break;
        case 2: validador = IsMoto; break;
        case 3: validador = IsBici; break;
    }

    do{
        std::cout << "Por favor indica al coordenada del parqueadero donde va a ubicar el carro: \n";
        std::cout << "Tenga en cuenta las siguientes coordenadas: \n";
        std::cout << "Las filas: 0, 1, 5 9 12 16 19 23 27 30 31 \n";
        std::cout << "Las columnas: 1 ,3 ,6 ,9 ,12 ,15 ,16 ,19 ,22 ,24 ,27 y 29 no las tome ya que son calles. \n";
        std::cout << "\033[1;38;2;128;0;128m" << "Zona de bicicletas '[B]': \n (Matriz[r][2] Columna 2, excepto r = 5, 9 , 12, 16, 19, 23, 27, 30) y \n (Matriz[r][30] Columna 30, donde r = filas desde la 2 hasta la 11) \n" << D.CFini;
        std::cout << "\033[1;38;2;127;255;212m Zona de Motos '[M]': \n Matriz[r]; donde r son las filas 2 a la 4, y 6 a la 8. \n \033[0m";
        std::cout << "\033[1;38;2;255;0;255m Zona Universal '[U]': \n Matriz[r][c] (donde r = 10 y 11, ; c = 17 al 28) y \n (Matriz[r][c] donde r= 17 y 18 ; c= 4 al 14)\n \033[0m";
        std::cout << "\033[1:38;2;0;0;255m Zona de Discapacitados: \n Matriz[r][c] (donde r= 10 y 11; c = 4 al 14) y \n Matriz[r][c] (donde r = 17 y 18 ; c= 17 al  28) \n \033[0m";
        std::cout << "Fila [r]: "; std::cin >> r;
        std::cout << "Columna [c]: "; std::cin >> c;

        if(r < 0 || r >=32 || c < 0 || c >= 32){
        std::cout << "\033[1;38;2;255;0;0m Coordenadas fuera del rango permitido (0 - 31) \n \033[0m";
        continue;
    }
        
        if(!validador(r, c, IsDis)){
            std::cout << "\n" <<"\033[1;4;38;2;255;0;0m Eleccion no valida." << D.CFini << "\n" ;
            continue;
        }

        if(parqueaderos[r][c].Ocupado){
            std::cout << "\033[1;4;2;255;255;0m Ese espacio ya esta ocupado \n \033[0m";
            continue;
        }

        std::string pre;
        if(Tipo == 1) pre = "C";
        if(Tipo == 2) pre = "M";
        if(Tipo == 3) pre = "B";
 
        parqueaderos[r][c].Placa = Placa;
        parqueaderos[r][c].Tipo = Tipo;
        parqueaderos[r][c].TiempoEntrada = time(0);
        parqueaderos[r][c].Ocupado = true;

        Matriz[r][c] = D.Ocupado + pre + Placa + D.CFini;
        break;
    }while(true);

}

void SistemaDeDisponibilidad(std::string Matriz[32][32], int Tipo, bool IsDis){
    Diseno D;

    bool(*validador)(int, int,  bool);
    switch(Tipo){
        case 1: validador = IsCarro; break;
        case 2: validador = IsMoto; break;
        case 3: validador = IsBici; break;
    }

    for(int i=0; i < 32; i++){
        for(int j=0; j<32; j++){
            if(!validador(i, j, IsDis)){
                std::cout << D.NoDisponible << Matriz[i][j] << D.CFini;
            }else if(parqueaderos[i][j].Ocupado){
                std::cout << D.Ocupado << Matriz[i][j] << D.CFini;
                }else{
                std::cout << D.Disponible << Matriz[i][j] << D.CFini;
            }
        }
        std::cout << "\n";
    }
}

void RegistroDeVehiculos(std::string Matriz[32][32]){
    Diseno D;
    std::string Nombre, Placa;
    int ID; int Tipo;  bool EsDis=false;
    std::cout << "\033[1;4;38;2;0;0;255m" << "Has decidido registrar un vehiculo nuevo." << D.CFini << "\n";
    std::cout << "Por favor indique el nombre del cliente para el registro: ";
    std::cin >> Nombre;
    std::cout << "Por favor indique el numero de documento: ";
    std::cin >> ID;
    std::cout << "Por favor indique el tipo de vehiculo: \n";
    std::cout << "Marque 1. Si el vehiculo es un carro/camioneta. \n" << "Marque 2. Si el vehiculo es una moto. \n" << "Marque 3. Si el vehiculo es una bicicleta \n";
    std::cout << "Tipo de vehiculo: ";
    std::cin >> Tipo;
    
    if(Tipo == 1){
        std::cout << "\033[1;4;2;135;206;250m El vehiculo tiene permiso de discapacidad(preferencial)? 1/0: \033[0m";
        std::cin >> EsDis;
    }

    if(Tipo != 3){
        do{
            std::cout << "Por favor indique la placa del vehiculo (4 Digitos): ";
            std::cin >> Placa;
        }while(Placa.length() != 4);
    }else{
        std::string IDs = std::to_string(ID);
        if(IDs.length() >=4){
            Placa = IDs.substr(IDs.length()-4);
        }else{
            Placa = IDs;
        }
    }

    AcutalizarSistema();
    SistemaDeDisponibilidad(Matriz, Tipo, EsDis);
    ElegirCelda(Matriz, Tipo, EsDis, Placa);

    AcutalizarSistema();
    MostrarMapa(Matriz);  
    
}

int SistemaDeCobro(int tipo, int tiempo){
    Values V;
    if(tipo == 1) return V.CarroVh * tiempo;
    if(tipo == 2) return V.MotoVh * tiempo;
    if(tipo == 3) return V.BiciVh * tiempo;
    return 0;
}

void CheckOut(std::string Matriz[32][32]){
    int r, c;
    Mapa M;
    Diseno D;

    std::cout << "\033[1;4;2;0;0;255m Has elegido Hacer Check-out de un vehiculo. \n \033[0m";
    std::cout << "Posicion del vehiculo: \n";
    std::cout << "Fila: ";
    std::cin >> r;
    std::cout << "Columna: ";
    std::cin >> c;

    if(r < 0 || r > 32 || c < 0 || c >= 32){
        std::cout << "\033[1;4;2;255;0;0m Coordenadas no validas. \n \033[0m";
        return;
    }

    std::string celda = Matriz[r][c];
    if(!parqueaderos[r][c].Ocupado){
        std::cout << "\033[1;4;2;255;0;0m No hay vehiculo en esa posicion. \n \033[0m";
        return;
    }

    time_t TSalida = time(0);
    time_t TEntrada = parqueaderos[r][c].TiempoEntrada;

    int Tiempo = TSalida - TEntrada;
    int min = Tiempo / 60;
    if(min < 1) min = 1;

    

    int valor = SistemaDeCobro(parqueaderos[r][c].Tipo, min);
    std::cout << "\033[1;4;2;0;255;0m Total a pagar $ \033[0m" << valor << "\n";
    valor += valor;

    if(parqueaderos[r][c].Tipo == 1) Matriz[r][c] = D.CPar + M.par + D.CFini;
    else if(parqueaderos[r][c].Tipo == 2) Matriz[r][c] = D.CPar + M.moto + D.CFini;
    else Matriz[r][c] = D.CPar + M.velo + D.CFini;

    parqueaderos[r][c].Ocupado = false;
    std::cout << "\033[1;4;2;0;255;0m  El vehiculo ha salido correctamente. \n \033[0m";
}

int Lore(){
    int op;
    std::cout << "\033[1m *|BIENVENIDO AL SIMULADOR DE PARQUEADERO|* \033[0m \n";
    std::cout << "1. Registrar un nuevo vehiculo. \n";
    std::cout << "2. Hacer Check-out de un vehiculo. \n";
    std::cout << "3. Ver la disponibilidad del parqueadero. \n";
    std::cout << "4. Salir del programa. \n";
    std::cout << "Por favor indique su opcion: ";
    std::cin >> op;
    return op;
}

void run(){
    Diseno D;
    std::string matriz[32][32];
    Generar_PMapa(matriz);
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            parqueaderos[i][j].Ocupado = false;
        }
    }
    int Opcion;

    do{
        Opcion = Lore();
        switch(Opcion){
        case 1:{
            RegistroDeVehiculos(matriz); 
            break;
        };
        case 2:{
            CheckOut(matriz);
            break;
        }
        case 3:{
            SistemaDeDisponibilidad(matriz, 1, true);
            break;
        }
        case 4:{
            std::cout << "\033[1;4;038;2;0;255;0m" <<"Has salido del simulador." << D.CFini  << "\n";
        }
    }
    }while(Opcion != 4);
    
}

int main(){
    run();
}

