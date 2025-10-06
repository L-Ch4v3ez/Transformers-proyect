#include <iostream>
#include <string>
#include <thread>
#include "useful_function_chest.h"
#define m 30

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
    for (int i = 1; i < n; ++i) {
        string key = bot[i].designacion;
        int j = i - 1;
        while (j >= 0 && bot[j].designacion > key) {
            bot[j + 1] = bot[j];
            j = j - 1;
        }
        bot[j + 1].designacion = key;
    }
}

int searching_string(Transformers bot[], string x, int n){
    cout << "searching"<<endl;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(bot[mid].designacion == x){
            return mid;
        }
        else if(bot[mid].designacion < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

void leer_relaciones (Relacion relacion[], int n){
    cout << "Con quienes tiene relacion?: (amistosa, neutral, enemistad) " << endl;
    for (int i=0; i<n; i++){
        cin>>relacion[i].designacion_1;
        cout << "   Estado: ";
        cin>>relacion[i].amistad;
    }
    cout << endl;
}
void leer_fecha(Fecha date){
     cout<<"Fecha de creacion: (DD/MM/YYYY)"<<endl;
     cin>> date.day >> date.month >> date.year;
}
void get_stats (TechSpech stats){
     cout << "Strenght: "<<endl; cin >> stats.strenght;
     cout << "Intelligence: "<<endl; cin >> stats.intelligence;
     cout << "Speed: "<<endl; cin >> stats.speed;
     cout << "Endurance: "<<endl; cin >> stats.endurance;
     cout << "Firepower: "<<endl; cin >> stats.firepower;
}
void leer_bots (Transformers bot[], int i){
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
void mostrar_stats(TechSpech stats){
    cout << "Strenght: "<< stats.strenght << endl;
    cout << "Intelligence: "<< stats.intelligence << endl;
    cout << "Speed: "<< stats.speed << endl;
    cout << "Endurance: "<< stats.endurance << endl;
    cout << "Firepower: "<<stats.firepower << endl;
}
void mostrar_fecha(Fecha date){
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
void menu(){
    cout << "   MENU"<< endl;
    cout <<"1. Registrar un bot"<<endl;
    cout <<"2. Info de un bot"<<endl;
    cout <<"3. Fight!!!"<<endl;
    cout <<"4. Power Down (exit)"<<endl;
    cout <<"your choice: ";
}

int main()
{
    Transformers transformers[m];
    transformers[0]={"Optimus Prime", "Autobot", 2, {{"Megatron", "enemistad"},{"Bumblebee", "amistad"}}, {10, 10, 8, 10, 8}};
    transformers[1]={"Megatron", "Decepticon", 1, {"Optimus Prime", "enemistad"}, {9, 9, 5, 9, 10}};
    transformers[2]={"Prowl", "Autobot", 1, {"Shockwave", "enemistad"}, {9, 9, 5, 9, 10}};
    transformers[3]={"Shockwave", "Decepticon", 1, {"Prowl", "enemistad"}, {9, 10, 7, 9, 9}};
    transformers[4]={"Bumblebee", "Autobot", 2, {{"Starscream", "enemistad"},{"Optimus Prime", "amistad"}}, {9, 9, 5, 9, 10}};
    transformers[5]={"Starscream", "Decepticon", 1, {"Bumblebee", "enemistad"}, {9, 9, 5, 9, 10}};
    int option;
    string title = " TRANSFORMERS BATTLEGROUNDS !!!!!";
    cout <<"Welcome to"<<endl;
    for (int i = 0; i <title.size(); i++)
    {
        cout << title[i];
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    menu(); cin >>option;

    while(option != 4){
        switch (option){
        case 1:{ // registrar
            int bot_num=6;
            leer_bots(transformers, bot_num);
            // see if any bots have new relations, use numero de relaciones
            for(int i=0;i<transformers[bot_num].numero_de_relaciones;i++){
                int pos =searching_string(transformers,transformers[bot_num].relaciones[i].designacion_1,bot_num);
                // pos is the bot that we have to register to
                // we are looking for the names of the bots named in the relations of the newly registered bot
                // now we have to register the new relations to those bots
            }
            bot_num ++;
            menu();
            break;}
        case 2:{ // info
            ordenar_nombre(transformers,bot_num);// IT WORKSS >:D
            string to_find;
            cin.ignore();
            cout <<"Designacion del bot:"<<endl;
            getline(cin,to_find);
            int pos =searching_string(transformers,to_find,bot_num);
            cout << "Ingresaste: "<< to_find << " whose position is: "<< pos<<endl;
            mostrar_transformer(transformers,pos);
            cin.ignore();
            menu();
            break;}
        case 3:{
            menu();
            break;}
        }
    }
    return 0;
}

