#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;
/*
struct Tarjeta{
	int TarjetaID;
	int FechaCreacion;
	bool Activa;
	int Saldo;
	int NroCliente;
};
struct Movimiento{
	int MovimientoID;
	int FechaHora;
	int Monto;
	int CuentaID;
};
*/
/*
void ListarUsuarios(int);*/
void AgregarUsuario();

int main(){
	FILE *archivo;
	int opcion=0;
	
	time_t t = time(0);
	tm* now = localtime(&t);
    cout<< (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<< "\n";
	cout<<t<<endl;
    
	
	while (opcion!=6){
		//archivo = fopen("personas.txt","a"); es para poder guardar datos sin sobrescribir.
		//archivo = fopen("personas.txt","r"); es para traer los datos del archivo.
	cout<<"1 - Listado de usuarios"<<endl;
	cout<<"2 - Agregar un nuevo usuario"<<endl;
	cout<<"3 - Eliminar una cuenta(por id)"<<endl;
	cout<<"4 - Buscar por id de la cuenta y mostrar"<<endl;
	cout<<"5 - Listar cuentas activas por saldo descendente"<<endl;
	cout<<"6 - Salir y guardar cambios"<<endl;
	cout<<"Elija una opcion: "<<endl;
	cin>>opcion;
	switch(opcion){
		case 1:
			//ListarUsuarios();
			break;
		case 2:	
			AgregarUsuario();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:	
			break;
		case 6:
			break;
		default:
			break;		
	}
	cout<<"-----------"<<endl;
	}
	fclose(archivo);
	return 0;
}
/*
void ListarUsuarios(int n){
	struct Persona personas
	for(int j = 0;j<n;j++){
		cout<<"Nombre: "<<personas[j].NombreyApellido<<endl;
		cout<<"Edad: "<<personas[j].edad<<endl;
		cout<<"-----------------"<<endl;
	}
}*/
void AgregarUsuario(){
		int i;
		int id=0;
		int fecha=0;
		bool activa;
		int saldo;
		int nroCliente;
		
		time_t t = time(0);
		tm* now = localtime(&t);
		int year= (now->tm_year + 1900);
		int month=(now->tm_mon + 1);
		int day=(now->tm_mday);
		cout<<"Ingrese id de tarjeta: "<<endl;
		cin>>id;
		cout<<"Cuenta activa: "<<endl;
		cin>>activa;
		cout<<"Ingrese saldo: "<<endl;
		cin>>saldo;
		cout<<"Ingrese el numero del cliente: "<<endl;
		cin>>nroCliente;
		
		
}
