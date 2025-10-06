#ifndef USEFUL_FUNCTION_CHEST_H_INCLUDED
#define USEFUL_FUNCTION_CHEST_H_INCLUDED
#include <string>
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
    Transformers menor;
    int pos_menor;
    for (int i=0; i<n;i++){
        menor = bot [i];
        pos_menor = i;
        for ( int j=i+1; j<n; j++){
            if (bot[j].designacion < menor.designacion){
                menor = bot [j];
                pos_menor = j;
            }
        }
        bot [pos_menor] = bot [i];
        bot [i]= menor;
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

void mostrar_transformer (Transformers bot){
    cout << "Designacion: "<< bot.designacion << endl;
    cout << "Tipo: "<< bot.tipo << endl;
    mostrar_relacionesvect(bot.relaciones,bot.numero_de_relaciones);
    mostrar_stats(bot.stats);
    mostrar_fecha(bot.creacion);
}


#endif // USEFUL_FUNCTION_CHEST_H_INCLUDED
