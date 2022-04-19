#include<iostream>
#include<fstream>
//#include<pwd.h>
#include<string>
#include <iostream>
#include <fstream>
#include <cstdio>
//#include <filesystem>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

string palabra;

string getUserName();
void generate_menu();
void actions(int option);
string encriptar(string cadena);
string desencriptar(string cadena);
void get_museos();
void busqueda(string palabra);

int main(){
	//cout<<"Ingrese una cadena de caracteres: ";
    //string cadena;
    //getline(cin,cadena);
    //string cadena_encriptada=encriptar(cadena);
    //string cadena_desencriptada=desencriptar(cadena_encriptada);
    //cout<<"La cadena encriptada es: "<<cadena_encriptada<<endl;
    //cout<<"La cadena desencriptada es: "<<cadena_desencriptada<<endl;

	ifstream archivo("museos.txt");
	if(archivo.is_open()){
		archivo.close();
	}
	else{
		system("python ./download_file.py");	
	}

	while (true)
	{
		generate_menu();
	}

	return 0;
}


void  generate_menu(){
	int opcion=0;
	cout<<"+---------------------------------------------------------+"<<endl;
	//cout<<"                   Welcome "+getUserName()<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"+  __   __  __   __  _______  _______  _______  _______   +"<<endl;
	cout<<"+ |  |_|  ||  | |  ||       ||       ||       ||       |  +"<<endl;
	cout<<"+ |       ||  | |  ||  _____||    ___||   _   ||  _____|  +"<<endl;
	cout<<"+ |       ||  |_|  || |_____ |   |___ |  | |  || |_____   +"<<endl;
	cout<<"+ |       ||       ||_____  ||    ___||  |_|  ||_____  |  +"<<endl;
	cout<<"+ | ||_|| ||       | _____| ||   |___ |       | _____| |  +"<<endl;
	cout<<"+ |_|   |_||_______||_______||_______||_______||_______|  +"<<endl;
	cout<<"+                                                         +"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"+  Sistema de Informacion de Museos del Estado de Hidalgo +"<<endl;
	cout<<"+                Selecciona una opcion                    +"<<endl;
	cout<<"+ [1] Ver Museos                                          +"<<endl;
	cout<<"+ [2] Buscar Museo                                        +"<<endl;
	cout<<"+ [3] Actualizar Lista de Museos                          +"<<endl;
	cout<<"+ [4] Salir                                               +"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"+ [*]Angeles Campero Ofir Neftali                         +"<<endl;
	cout<<"+ [*]Castillo Alarcon Isaac                               +"<<endl;
	cout<<"+ [*]Mera Priego Alonso Jezrael                           +"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cin>>opcion;
	actions(opcion);
}

/*
string getUserName(){
    string userName;
    struct passwd *pw;
    pw = getpwuid(getuid());
    userName = pw->pw_name;
    return userName;

}
*/
void actions(int option){
	switch(option){
		case 1:
			cout<<"Opcion 1"<<endl;
			get_museos();
			break;
		case 2:
			cout<<"Opcion 2"<<endl;
			cout<<"Ingrese un museo: ";
			cin>>palabra;
			busqueda(palabra);
			break;
		case 3:
			cout<<"Opcion 3"<<endl;
			break;
		case 4:
			cout<<"Opcion 4"<<endl;
			system("python ./download_file.py");
			break;
		default:
			cout<<"Ingresa una opcion valida"<<endl;
			generate_menu();
			break;
	}
}

string encriptar(std::string cadena){
    string cadena_encriptada;
    int i;
    for(i=0;i<cadena.size();i++){
        cadena_encriptada+=cadena[i]+1;
    }
    return cadena_encriptada;
}

string desencriptar(std::string cadena){
    std::string cadena_desencriptada;
    int i;
    for(i=0;i<cadena.size();i++){
        cadena_desencriptada+=cadena[i]-1;
    }
    return cadena_desencriptada;
}

void get_museos(){
    //system("python ./download_file.py");
    string nombreArchivo="museos.txt";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
}

void busqueda(string palabra){
    string linea = "Museo: " + palabra;
    string nombreArchivo="museos.txt";
    ifstream archivo(nombreArchivo.c_str());
    
    if(archivo.is_open()){
        while(getline(archivo,linea)){
            if(linea.find(palabra)!=string::npos){
                cout<<linea<<endl;
                getline(archivo,linea);
                cout<<linea<<endl;
                getline(archivo,linea);
                cout<<linea<<endl;
            }
        }
        archivo.close();
    }
    else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
}