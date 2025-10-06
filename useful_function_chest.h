#ifndef USEFUL_FUNCTION_CHEST_H_INCLUDED
#define USEFUL_FUNCTION_CHEST_H_INCLUDED
#include <string>
#define m 30
#include "modificar_funcion.h"
using namespace std;

struct Fecha{
       int day;
       int month;
       int year;
};
struct TechSpech {
    int strenght;
    int intelligence;
    int speed;
    int endurance;
    int firepower;
};
struct Relacion {
    string designacion_1;
    string amistad;
};
struct Transformers {
    string designacion;
    string tipo;
    int numero_de_relaciones;
    Relacion relaciones [m];
    TechSpech stats;
    Fecha creacion;
};

void ordenar_nombre(Transformers bot[], int n){
   bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (bot[j].designacion > bot[j + 1].designacion) {
                swap(bot[j], bot[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int searching_string(Transformers bot[], string search, int n){
    cout << "searching"<<endl;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(bot[mid].designacion == search){
            return mid;
        }
        else if(bot[mid].designacion < search){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

void leer_relaciones (Relacion relacion[], int n){
    cout << "Con quienes tiene relacion?: ('amistad', 'neutral', 'enemistad') " << endl;
    for (int i=0; i<n; i++){
        cin.ignore();
        getline (cin, relacion[i].designacion_1);
        cout << "   Estado: ";
        getline (cin, relacion[i].amistad);
    }
    cout << endl;
}
void leer_fecha(Fecha &date){
     cout<<"Fecha de creacion: (DD/MM/YYYY)"<<endl;
     cin>> date.day >> date.month >> date.year;
}
void get_stats (TechSpech &stats){
     cout << "Strenght: "<<endl; cin >> stats.strenght;
     cout << "Intelligence: "<<endl; cin >> stats.intelligence;
     cout << "Speed: "<<endl; cin >> stats.speed;
     cout << "Endurance: "<<endl; cin >> stats.endurance;
     cout << "Firepower: "<<endl; cin >> stats.firepower;
}
void leer_bot (Transformers bot[], int i){
    cout << "Designacion: ";
    getline (cin, bot[i].designacion);
    cout << "Tipo: ";
    getline (cin, bot[i].tipo);
    cout << "Numero de relaciones: " ;
    cin >> bot[i].numero_de_relaciones ;
    leer_relaciones (bot[i].relaciones,bot[i].numero_de_relaciones);
    get_stats (bot[i].stats);
    leer_fecha(bot[i].creacion);
}
void mostrar_relacionesvect (Relacion relacion[], int n){
    for (int i=0; i<n; i++){
        cout <<endl<< " #" << i+1 << " ";
        cout << relacion[i].designacion_1<<endl;
        cout << ".   Estado: ";
        cout << relacion[i].amistad<<endl;
    }
    cout << endl;
}
void mostrar_stats(TechSpech &stats){
    cout << "Strenght: "<< stats.strenght << endl;
    cout << "Intelligence: "<< stats.intelligence << endl;
    cout << "Speed: "<< stats.speed << endl;
    cout << "Endurance: "<< stats.endurance << endl;
    cout << "Firepower: "<<stats.firepower << endl;
}
void mostrar_fecha(Fecha &date){
     cout << date.day <<"/"<<date.month<<"/"<<date.year<<endl;
}
void mostrar_transformers (Transformers bot[], int n){
    for (int i=0;i<n;i++){
    cout << "Designacion: "<< bot[i].designacion << endl;
    cout << "Tipo: "<< bot[i].tipo << endl;
    mostrar_relacionesvect(bot[i].relaciones,bot[i].numero_de_relaciones);
    mostrar_stats(bot[i].stats);
    mostrar_fecha(bot[i].creacion);
    }
}

void mostrar_transformer (Transformers bot){
    cout << "Designacion: "<< bot.designacion << endl;
    cout << "Tipo: "<< bot.tipo << endl;
    mostrar_relacionesvect(bot.relaciones,bot.numero_de_relaciones);
    mostrar_stats(bot.stats);
    mostrar_fecha(bot.creacion);
}

void modificar_bot(Transformers &bot) {
    int opcion;
    do {
        cout << "\n=== MODIFICAR BOT: " << bot.designacion << " ===\n";
        cout << "1. Cambiar designacion\n";
        cout << "2. Cambiar tipo\n";
        cout << "3. Modificar relaciones\n";
        cout << "4. Modificar stats\n";
        cout << "5. Modificar fecha de creacion\n";
        cout << "6. Salir\n";
        cout << "Elige opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
        case 1:
            cout << "Nueva designacion: ";
            getline(cin, bot.designacion);
            break;
        case 2:
            cout << "Nuevo tipo: ";
            getline(cin, bot.tipo);
            break;
        case 3:
            cout << "Numero de relaciones: ";
            cin >> bot.numero_de_relaciones;
            cin.ignore();
            leer_relaciones(bot.relaciones, bot.numero_de_relaciones);
            break;
        case 4:
            get_stats(bot.stats);
            break;
        case 5:
            leer_fecha(bot.creacion);
            break;
        case 6:
            cout << "Saliendo de modificacion...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while(opcion != 6);
}

void menu(Transformers transformers[], int &bot_num) {
    int option = 0;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Registrar un bot\n";
        cout << "2. Info de un bot\n";
        cout << "3. FIGHT\n";
        cout << "4. Modificar bot \n";
        cout << "5. Power Down (Exit) \n";
        cout << "Elige opcion: ";
        cin >> option;
        cin.ignore();

        switch(option) {
        case 1: {
            leer_bot(transformers, bot_num);
            /*for(int i=0; i < transformers[bot_num].numero_de_relaciones; i++) {
                int pos = searching_string(
                    transformers,
                    transformers[bot_num].relaciones[i].designacion_1,
                    bot_num+1
                );

            }*/
                bot_num++;
            break;
        }
        case 2: { // info
            ordenar_nombre(transformers, bot_num);
            string to_find;
            cout <<"Designacion del bot: ";
            getline(cin, to_find);

            int pos = searching_string(transformers, to_find, bot_num);
            cout << "Ingresaste: " << to_find
                 << " whose position is: " << pos << endl;

            if (pos > -1) {
                mostrar_transformer(transformers[pos]);
            } else {
                cout << "No existe" << endl;
            }
            break;
        }
        case 3:{

            }

        case 4: {
            ordenar_nombre(transformers, bot_num);
            string to_find;
            cout << "Designacion del bot a modificar: ";
            getline(cin, to_find);

            int pos = searching_string(transformers, to_find, bot_num);
            if (pos > -1) {
            modificar_bot(transformers[pos]);
    } else {
        cout << "No existe ese bot.\n";
    }
    break;
}
        case 5:
            cout << "Saliendo del menu...\n";
            break;
        default:
            cout << "Opcion invalida, intenta otra vez. :( \n";
        }
    } while(option != 5);
}

#endif // USEFUL_FUNCTION_CHEST_H_INCLUDED
