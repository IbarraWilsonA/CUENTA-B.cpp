#include <iostream>
using namespace std;

struct Fecha {
	short anio;
	short dia;
	short mes;
};
// clase Cuenta
class Cuenta {

public:  //Atributos
	float interes;
	Fecha fc;

	//constructores y tiene el mismo nombre de la clase
	Cuenta();
	Cuenta(float m, float i);

	// metodos de acceso
	string getNombre();
	void setNombre(string n);
	void setSaldo(float s);
	float getSaldo();

	// Metodos de funciones, metodos de comportamiento
	void depositar(float x);
	void retirar(float m);
	float retiro_Completo(float m);
	void transferir(float m, Cuenta &c);
	void mostrar();

private:
	int Nro_cuenta;
	string nombre;
	float saldo;
};

//constructores y tiene el mismo nombre de la clase

Cuenta::Cuenta()
{
	saldo = 100;
	interes = 10;
	nombre = "ALAN IBARRA";
	Nro_cuenta = 124030;
	fc.anio = 2022; fc.mes = 05; fc.dia = 28;
}

Cuenta::Cuenta(float m, float i)
{
	saldo = m;
	interes = i;
	nombre = "SARELY ROGRIGUEZ";
	Nro_cuenta = 102560;
	fc.anio = 2022; fc.mes = 05; fc.dia = 28;
}

string Cuenta::getNombre() // get para obtener, mutador
{
	return nombre;
}

void Cuenta::setNombre(string n) // set para enviar e cambiar, accesor
{
	nombre = n;
}

void Cuenta::setSaldo(float s)
{
	saldo = s;
}

float Cuenta::getSaldo()
{
	return saldo;
}

void Cuenta::depositar(float x)
{
	saldo = saldo + x;
}

void Cuenta::retirar(float m)
{
	saldo = saldo - m;
}

float Cuenta::retiro_Completo(float m)
{
	saldo = saldo - m;
	return saldo;
}

void Cuenta::transferir(float m, Cuenta& c)
{
	//c.setSaldo(c.getSaldo() + m);
	c.depositar(m);
	retirar(m);
}

void Cuenta::mostrar()
{
	cout << "Numero de Cuenta " << Nro_cuenta << endl;
	cout << "El saldo es: " << saldo << endl;
	cout << "Propietario " << nombre << endl;
	cout << "Fecha de Creacion " << fc.anio << "/" << fc.mes << "/" << fc.dia << endl;
	cout << "Interes " << interes << endl;

}

int main(int argc, char* argv[]) {
	Fecha f1;
	Cuenta c1, c2(100, 10);
	Cuenta* cuenta_Actual;
	//c1.setNombre("Juanito");
	int opcion;
	char operacion;
	float monto;

	while (true)
	{
		cout << "SELECIONE UNA OPCION" << endl;
		cout << "1 -> Manejar Cuenta 1 " << endl;
		cout << "2 -> Manejar Cuenta 2 " << endl;
		cin >> opcion;

		if (opcion == 1) {
			cuenta_Actual = &c1;
		}
		else {
			if (opcion == 2) {
				cuenta_Actual = &c2;
			}
			else {
				break;
			}
		}
		cout << " QUE ACCION DESEA ASER " << endl;
		cout << " a -> Depositar" << endl;
		cout << " b -> Retirar " << endl;
		cout << " c -> Transferir " << endl;
		cout << " d -> Ver Cuenta " << endl;
		cin >> operacion;

		switch (operacion)
		{
		case 'a':
			cout << " INTRODUSCA EL MONTO QUE DESEA DEPOSITAR " << endl;
			cin >> monto;
			cuenta_Actual->depositar(monto);
			break;
		case 'b':
			cout << "INTRODUSCA EL MONTO QUE  DESEA RETIRAR " << endl;
			cin >> monto;
			cuenta_Actual->retirar(monto);
			break;
		case 'c':
			cout << " INTRODUSCA EL MONTO QUE DESEA TRANSFERIR " << endl;
			cin >> monto;
			if (opcion == 1)
				cuenta_Actual->transferir(monto, c2);
			if (opcion == 2)
				cuenta_Actual->transferir(monto, c1);
			break;
		case 'd':
			cuenta_Actual->mostrar();
			break;
		default:
			cout << " OPCION INVALIDA " << endl;

		}
	}
	return 0;
}