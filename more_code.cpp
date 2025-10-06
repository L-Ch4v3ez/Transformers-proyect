#include <iostream>
#include <string>
#include <thread>
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
    transformers[0]={"Optimus Prime", "Autobot", 1, {"Megatron", "enemistad"}, {10, 10, 8, 10, 8}};
    transformers[1]={"Megatron", "Decepticon", 1, {"Optimus Prime", "enemistad"}, {9, 9, 5, 9, 10}};
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
        case 1:{
            int bot_num=2;
            leer_bots(transformers, bot_num);
            bot_num ++;
            menu();
            break;}
        case 2:{
            string to_find;
            cout <<"Designacion del bot:"<<endl;
            getline(cin,to_find);
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
