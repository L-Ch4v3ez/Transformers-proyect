#include <iostream>
#define TAM 50
#include <cstring>

using namespace std;

struct Fecha {
    int ano;
    int mes;
    int dia;
};

struct Relacion {
    string designacion_1; // nombre del bot con quien se relaciona
    string amistad; // de A como buena amistad hasta F de pesima relacion
 };

struct Transformers {
    string designacion; // nombre con cual se identifica el transformers
    string tipo; // es bot comun o es prime
    int nivel_de_fuerza; // de 1 a 100 como max
    int numero_de_relaciones;
    Relacion relaciones [TAM]; // con que bots se comunica
    Fecha fecha_de_creacion; // cuanto tiempo lleva existiendo, calcular talvez
};

void leer_relacionesvect (Relacion relacion[], int n){

    cout << "Con quienes tiene relacion?: " << endl;
    for (int i=0; i<n; i++){
        cout << " #" << i+1 << " ";
        cin >> relacion[i].designacion_1;
        cout << "   Estado: ";
        cin >> relacion [i].amistad;
    }
    cout << endl;
}
void mostrar_relacionesvect (Relacion relacion[], int n){
    for (int i=0; i<n; i++){
        cout << " #" << i+1 << " ";
        cout << relacion[i].designacion_1;
        cout << ".   Estado: ";
        cout << relacion [i].amistad;
    }
    cout << endl;
}

void Leer_Transformers (Transformers bot){
    cout << "Designacion: ";
    getline (cin, bot.designacion);
    cout << endl;

    cout << "Tipo: ";
    getline (cin, bot.tipo);
    cout << endl;

    cout << "Nivel de fuerza: ";
    cin >> bot.nivel_de_fuerza;
    cout << endl;

    cout << "Numero de relaciones: " ;
    cin >> bot.numero_de_relaciones ;
    cout << endl;

    leer_relacionesvect (bot.relaciones,bot.numero_de_relaciones);

    cout << "Fecha de creacion: " <<endl;
    cout << "Anio de creacion: ";
    cin >> bot.fecha_de_creacion.ano;
    cout << "Mes de creacion: ";
    cin >> bot.fecha_de_creacion.mes;
    cout << "Dia de creacion: ";
    cin >> bot.fecha_de_creacion.dia;
    cout << endl;

}

void Mostrar_Transformers (Transformers &bot){
    cout << "Designacion: ";
    cout << bot.designacion << endl;

    cout << "Tipo: ";
    cout << bot.tipo << endl;

    cout << "Nivel de fuerza: ";
    cout << bot.nivel_de_fuerza;

    mostrar_relacionesvect(bot.relaciones,bot.numero_de_relaciones);

    cout << "Fecha de creacion: ";
    cout << bot.fecha_de_creacion.ano << "/" << bot.fecha_de_creacion.mes  << "/" << bot.fecha_de_creacion.dia;
    cout << endl;

}



int main()
{
    Transformers bot;
    Leer_Transformers(bot);
    Mostrar_Transformers(bot);
}
