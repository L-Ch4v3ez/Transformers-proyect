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

void ordenar_fecha(Transformers bot[], int n){
    for (int i = 1; i < n; ++i) {
         Transformers key = bot[i];
         int j = i - 1;
         while (j >= 0 && bot[j].creacion.day > key.creacion.day) {
              bot[j + 1] = bot[j];
              j= j - 1;
         }
         bot[j + 1] = key;
    }

    for (int i = 1; i < n; ++i) {
        Transformers key = bot[i];
        int j = i - 1;
        while (j >= 0 && bot[j].creacion.month > key.creacion.month) {
            bot[j + 1] = bot[j];
            j = j - 1;
        }
        bot[j + 1] = key;
    }

    for (int i = 1; i < n; ++i) {
        Transformers key = bot[i];
        int j = i - 1;
        while (j >= 0 && bot[j].creacion.year > key.creacion.year) {
            bot[j + 1] = bot[j];
            j = j - 1;
        }
        bot[j + 1] = key;
    }
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

void agrupar_decepticons_autobots (Transformers transformers[], int &bot_num){
    cout << "Autobots: \n";
    for (int i=0; i<bot_num; i++){
        if ( transformers[i].tipo == "Autobot")
        {
            cout << transformers[i].designacion << "\n";
        }
    }
    cout << endl;
    cout << "Decepticons: \n";
    for (int i=0; i<bot_num; i++){
        if ( transformers[i].tipo == "Decepticon")
        {
            cout << transformers[i].designacion << "\n";
        }
    }
}

void promedio_fuerza (Transformers transformers [], int &bot_num){
    int prom_autobot= 0;
    int sum_autobot= 0;
    int prom_decepticon =  0;
    int sum_decepticon = 0;
    for (int i=0; i<bot_num;i++){
        if (transformers[i].tipo == "Autobot"){
            sum_autobot++;
            prom_autobot = prom_autobot + transformers[i].stats.strenght ;
        }
        if (transformers[i].tipo == "Decepticon"){
            sum_decepticon++;
            prom_decepticon = prom_decepticon + transformers[i].stats.strenght ;
        }
    }
    prom_autobot = prom_autobot/sum_autobot;
    prom_decepticon = prom_decepticon/sum_decepticon;
    cout << "El promedio de fuerza de los Autobots es de: " << prom_autobot << endl;
    cout << "El promedio de fuerza de los Decepticons es de: " << prom_decepticon <<endl;
}

void fight(Transformers bots[], Transformers bot_1, Transformers bot_2){
     int prob_bot1=(bot_1.stats.strenght +bot_1.stats.speed +bot_1.stats.intelligence +bot_1.stats.firepower) * bot_1.stats.endurance;
     int prob_bot2=(bot_2.stats.strenght +bot_2.stats.speed +bot_2.stats.intelligence +bot_2.stats.firepower) * bot_2.stats.endurance;
     int total = prob_bot1+prob_bot2;
     int r = rand() % total+1;
     cout << r<<endl;
     this_thread::sleep_for(std::chrono::milliseconds(300));
     if(r <= prob_bot1){
        cout <<"Ganador: "<< bot_1.designacion<<endl;
     } else {
        cout <<"Ganador: "<< bot_2.designacion<<endl;
     }}

void menu(Transformers transformers[], int &bot_num) {
    int option = 0;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Registrar un bot\n";
        cout << "2. Info de un bot\n";
        cout << "3. FIGHT\n";
        cout << "4. Ordenar por fecha\n";
        cout << "5. Modificar bot \n";
        cout << "6. Agrupar Autobots y Decepticons \n";
        cout << "7. Promedio de fuerza \n";
        cout << "8. Power Down (Exit) \n";
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
        Transformers bot_1, bot_2;
            cout << "Choose Fighter 1:"<<endl;
            getline(cin,bot_1.designacion);
            int pos_bot_1=searching_string(transformers, bot_1.designacion,bot_num);
            cout << "Choose Fighter 2:"<<endl;
            getline(cin,bot_2.designacion);
            int pos_bot_2=searching_string(transformers, bot_2.designacion,bot_num);
            cout << bot_1.designacion << " vs " <<bot_2.designacion<<endl;
            fight(transformers,transformers[pos_bot_1],transformers[pos_bot_2]);
            break;

}
        case 4:{
            ordenar_fecha(transformers,bot_num);
            mostrar_transformers(transformers, bot_num);
            break;
            }

        case 5: {
            ordenar_nombre(transformers, bot_num);
            string to_find;
            cout << "Designacion del bot a modificar: ";
            getline(cin, to_find);

            int pos = searching_string(transformers, to_find, bot_num);
            if (pos > -1) {
            modificar_bot(transformers[pos]);
            } else
            {
            cout << "No existe ese bot.\n";
            }
            break;
            }
        case 6:{
            agrupar_decepticons_autobots(transformers,bot_num);
            break;
        }
        case 7: {
            promedio_fuerza(transformers, bot_num);
            break;
        }
        case 8:
            cout << "Saliendo del menu...\n";
            break;
        default:
            cout << "Opcion invalida, intenta otra vez. :( \n";
        }
    } while(option != 8);
}

#endif // USEFUL_FUNCTION_CHEST_H_INCLUDED
