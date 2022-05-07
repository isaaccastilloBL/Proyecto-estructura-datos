#include<iostream>
#include<fstream>
#include<pwd.h>
#include<string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <filesystem>
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
void print_image(string name);

int main(){
	ifstream archivo("museos.txt");
	if(archivo.is_open()){
		archivo.close();
	}
	else{
		system("python3 ./download_file.py");	
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
	cout<<"                   Welcome "+getUserName()<<endl;
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

string getUserName(){
    string userName;
    struct passwd *pw;
    pw = getpwuid(getuid());
    userName = pw->pw_name;
    return userName;

}
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
			system("python ./download_file.py");
			break;
		case 4:
			exit(1);
		default:
			cout<<"Ingresa una opcion valida"<<endl;
			generate_menu();
			break;
	}
}

void get_museos(){
	int contador=0;
    	string nombreArchivo="museos.txt";
    	ifstream archivo(nombreArchivo.c_str());
    	string linea;
	string name_image;
    	while (getline(archivo, linea)) {
		if(contador==0 or contador==7 or contador==14 or contador==21 or contador==28 or contador==35 or contador==42 or contador==49 or contador==56 or contador==63){
			name_image=linea;
			print_image(name_image);
		}else{
        		cout << linea << endl;
		}
		contador++;
    	}
}

void busqueda(string palabra){
    	string linea = "Museo: " + palabra;
	string name_image=palabra;
	string extension=".jpg";
	name_image+=extension;
	print_image(name_image);
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
				getline(archivo,linea);
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

void print_image(string name){
	string command="kitty +kitten icat ";
	command+=name;
	char buffer[100];
	strcpy(buffer,command.c_str());
	system(buffer);
}
