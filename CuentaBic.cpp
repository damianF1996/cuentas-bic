#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
using namespace std;

struct Tarjeta {
	char CuentaID[10];
	int FechaCreacion;
	bool Activa;
	int Saldo;
	int NroCliente;
};
struct Movimiento {
	int MovimientoID;
	int FechaHora;
	int Monto;
	int CuentaID;
};

void ListarUsuarios(); 
void AgregarUsuario();
int EliminarUsuario(char Cuenta[]);
int BuscarUsuario(char Cuenta[]);
int  main () {
	FILE*archivo;
	int opcion = 0;
	while(opcion!=6) {
	cout<<" 1 - Listado de usuarios "<< endl;
	cout<<" 2 - Agregar un nuevo usuario "<< endl;
	cout<<" 3 - Eliminar una cuenta (por id) "<< endl;
	cout<<" 4 - Buscar por id de la cuenta y mostrar "<< endl;
	cout<<" 5 - Listar cuentas activas por saldo descendente "<< endl;
	cout<<" 6 - Salir y guardar cambios "<< endl;
	cout<<" Elija una opcion: "<< endl;
	cin >>opcion;
	char cuentaBuscada[10];
	switch (opcion){
		case 1:
			 ListarUsuarios();
			break;
		case 2:	
			AgregarUsuario();
			break;
		case 3:
			cout<<"Ingrese el numero de Cuenta que desea borrar: "<<endl;
			cin>>cuentaBuscada;
			EliminarUsuario(cuentaBuscada);
			break;
		case 4:
			cout<<"Ingrese el numero de Cuenta que desea buscar: "<<endl;
			cin>>cuentaBuscada;
			BuscarUsuario(cuentaBuscada);
			break;
		case 5:	
			break;
		case 6:
			break;
		default:
			break;		
	}
	cout <<" ----------- "<< endl;
	}
	fclose (archivo);
	return 0;
}

void ListarUsuarios(){
	FILE*archivo;
	archivo=fopen("Cuentas.BIC","rb");
	Tarjeta t;

	while(fread(&t,sizeof(Tarjeta),1,archivo)){
		cout<<"Numero de Cuenta: "<<t.CuentaID<<endl;
		cout<<"Fecha de creacion: "<<t.FechaCreacion<<endl;
	if(t.Activa){
		 cout<<"Cuenta Activa: Si"<<endl;
	}else{
		cout<<"Cuenta Activa: No"<<endl;
	}
		cout<<"El saldo de la tarjeta es: "<<t.Saldo<<endl;
		cout<<"El numero de cliente es: "<<t.NroCliente<<endl;
		cout<<"-------------------------------"<<endl;
	}
		fclose(archivo);
	} 

void AgregarUsuario(){

	FILE*archivo;
	archivo=fopen("Cuentas.BIC","ab");
	Tarjeta t;
	cout<<"Ingrese el numero de la tarjeta:"<<endl;
	cin>>t.CuentaID;
	cout<<"Ingrese su Fecha de Creacion:"<<endl;
	cin>>t.FechaCreacion;
	cout<<"Ingrese estado de la tarjeta: (True=Activa o 1 o False=Desactivada o 0)"<<endl;
	cin>>t.Activa;
	cout<<"Ingrese el saldo de la cuenta:"<<endl;
	cin>>t.Saldo;
	cout<<"Ingrese el numero de cliente:"<<endl;
	cin>>t.NroCliente;
	fwrite(&t,sizeof(Tarjeta),1,archivo);
	fclose(archivo);
}

int EliminarUsuario(char Cuenta[]){
	FILE*archivo;
	int encontrado = 0;
	Tarjeta t;
	if(archivo = fopen("Cuentas.BIC","rb+")){
		while(!encontrado && fread(&t,sizeof(Tarjeta),1,archivo)){
			if(strcmp(Cuenta,t.CuentaID)==0){
				encontrado=1;
				t.Activa=false;
				fseek(archivo,sizeof(Tarjeta),SEEK_CUR);
				fwrite(&t,sizeof(Tarjeta),1,archivo);
			}
		}
		if(!encontrado){
			cout << "No se encontro la persona a borrar." << endl;
		}
		fclose(archivo);
    	return 1;
	}
	return 0;
}

int BuscarUsuario(char Cuenta[]){
	FILE*archivo;
	int encontrado = 0;
	Tarjeta t;
	if(archivo = fopen("Cuentas.BIC","rb+")){
		while(!encontrado && fread(&t,sizeof(Tarjeta),1,archivo)){
			if(strcmp(Cuenta,t.CuentaID)==0){
				encontrado = 1;
                cout << "****** Datos de la cuenta *******" << endl;
                cout << "CuentaID: " << t.CuentaID << endl;
                cout << "Fecha de Creacion: " << t.FechaCreacion << endl;
                cout << "Saldo: " << t.Saldo << endl;
                cout << "Nro de Cliente: " << t.NroCliente << endl;
                if(t.Activa){
                	cout << "Activa: Si"<< endl;
				}else{
					cout << "Activa: No"<< endl;
				}
				fwrite(&t,sizeof(Tarjeta),1,archivo);
			}
		}
		if(!encontrado){
			cout << "No se encontro la persona a borrar." << endl;
		}
		fclose(archivo);
    	return 1;
	}
	return 0;
}
