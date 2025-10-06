#include <iostream>
#include <string>
#include <thread>
#include "useful_function_chest.h"
#define m 30

using namespace std;


void menu(Transformers transformers[], int &bot_num) {
    int option = 0;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Registrar un bot\n";
        cout << "2. Info de un bot\n";
        cout << "3. Salir\n";
        cout << "Elige opcion: ";
        cin >> option;
        cin.ignore();

        switch(option) {
        case 1: {
            leer_bot(transformers, bot_num);
            for(int i=0; i < transformers[bot_num].numero_de_relaciones; i++) {
                int pos = searching_string(
                    transformers,
                    transformers[bot_num].relaciones[i].designacion_1,
                    bot_num+1
                );

            }
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
        case 3:
            cout << "Saliendo del menu...\n";
            break;
        default:
            cout << "Opcion invalida, intenta otra vez. :( \n";
        }
    } while(option != 3);
}

int main()
{
    Transformers transformers[m];
    transformers[0]={"Optimus Prime", "Autobot", 2, {{"Megatron", "enemistad"},{"Bumblebee", "amistad"}}, {10, 10, 8, 10, 8},{2,4,1989}};
    transformers[1]={"Megatron", "Decepticon", 1, {"Optimus Prime", "enemistad"}, {9, 9, 5, 9, 10},{5,7,1800}};
    transformers[2]={"Prowl", "Autobot", 1, {"Shockwave", "enemistad"}, {9, 9, 5, 9, 10},{5,7,1899}};
    transformers[3]={"Shockwave", "Decepticon", 1, {"Prowl", "enemistad"}, {9, 10, 7, 9, 9},{7,2,2001}};
    transformers[4]={"Bumblebee", "Autobot", 2, {{"Starscream", "enemistad"},{"Optimus Prime", "amistad"}}, {9, 9, 5, 9, 10},{6,1,2000}};
    transformers[5]={"Starscream", "Decepticon", 1, {"Bumblebee", "enemistad"}, {9, 9, 5, 9, 10},{8,9,1999}};
    int option;
    string title = " TRANSFORMERS BATTLEGROUNDS !!!!!";
    cout <<"Welcome to"<<endl;
    for (int i = 0; i <title.size(); i++)
    {
        cout << title[i];
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    int bot_num = 6;
    menu (transformers, bot_num);
    return 0;
}
