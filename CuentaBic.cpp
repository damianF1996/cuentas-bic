# incluye  < iostream >
# incluye  < stdlib.h >
# incluye  < stdio.h >
# incluye  < ctime >


using namespace std ;

struct Tarjeta {
	int TarjetaID;
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

void ListarUsuarios (); 
void  AgregarUsuario ();

int  main () {

	int opcion = 0 ;
	
	time_t t = tiempo ( 0 );
	tm * ahora = hora local (& t);
    cout << (ahora-> tm_year + 1900 ) << ' - ' << (ahora-> tm_mon + 1 ) << ' - ' << ahora-> tm_mday << " \ n " ;
	cout << t << endl;
    
	
	while (opcion! = 6 ) {
		// archivo = fopen ("personas.txt", "a"); es para poder guardar datos sin sobrescribir.
		// archivo = fopen ("personas.txt", "r"); es para traer los datos del archivo.
	cout << " 1 - Listado de usuarios " << endl;
	cout << " 2 - Agregar un nuevo usuario " << endl;
	cout << " 3 - Eliminar una cuenta (por id) " << endl;
	cout << " 4 - Buscar por id de la cuenta y mostrar " << endl;
	cout << " 5 - Listar cuentas activas por saldo descendente " << endl;
	cout << " 6 - Salir y guardar cambios " << endl;
	cout << " Elija una opcion: " << endl;
	cin >> opcion;
	switch (opcion) {
		caso  1 :
			 ListarUsuarios ();
			romper ;
		caso  2 :	
			AgregarUsuario ();
			romper ;
		caso  3 :
			romper ;
		caso  4 :
			romper ;
		caso  5 :	
			romper ;
		caso  6 :
			romper ;
		por defecto :
			romper ;		
	}
	cout << " ----------- " << endl;
	}
	fclose (archivo);
	return  0 ;
}

void ListarUsuarios () {
FILE* archivo;
archivo=fopen("Cuentas.BIC","rb");
Tarjeta t;

 while(fread(&t,sizeof(Tarjeta),1,archivo)){
cout<<"-------------------------------"<<endl;
cout<<"Fecha de creacion:"<<endl;
cout<<t.FechaCreacion<<endl;
cout<<"Estado de la tarjeta:"<<endl;
if(t.Activa){
 cout<<"La cuenta esta activa"<<endl;
}else{
 cout<<"La cuenta no esta activa"<<endl;
}

cout<<"El saldo de la tarjeta es:"<<endl;
cout<<t.Saldo<<endl;
cout<<"El numero de cliente es:"<<endl;
cout<<t.NroCliente<<endl;
cout<<"-------------------------------"<<endl;
}
fclose(archivo);
} 
void  AgregarUsuario () {
		
		// int fecha = 0 ;
		// time_t t = tiempo ( 0 );
		// tm * ahora = hora local (& t);
		// int año = (ahora-> tm_year + 1900 );
		// int mes = (ahora-> tm_mon + 1 );
		// int día = (ahora-> tm_mday );
FILE* archivo;
archivo=fopen("Cuentas.BIC","ab");
Tarjeta t ;
cout<<"Ingrese el numero de la tarjeta:"<<endl;
cin>>t.TarjetaID;
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

