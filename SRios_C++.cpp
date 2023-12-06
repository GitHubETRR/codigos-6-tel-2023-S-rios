#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class producto {       
  public:             // Especificador de acceso
    string nombre;     // Atributo
    int precio;       // Atributo
    string marca;     // Atributo
    producto(vector<producto> & p1,producto s){   
      cout<<"Nombre del producto: ";
      cin>>s.nombre;
      cout<<"Precio del producto: ";
      cin>>s.precio;
      cout<<"Marca del producto: ";
      cin>>s.marca;
      p1.push_back(s);
    }
};

int main() {
  int opcion;
  int n;
  int cantTotal = 0;
  int i;
  vector<producto> p;
  do{
    cout << "\n\nMenu de Opciones" << endl;
    cout << "1. Ingresar nuevos productos" << endl;
    cout << "2. Ver productos" << endl;
    cout << "3. Eliminar producto" << endl;
    cout << "0. Salir" << endl;
        
    cout << "\nIngrese una opcion: ";
    cin >> opcion;
        
    switch (opcion){
      case 0: //Esto tiene que estar porque sino hace lo que hay en default antes de terminar
      break;
      case 1:
        cout << "\n¿Cuantos productos quiere introducir?" << endl;
        cin >> n;
        cantTotal = cantTotal + n;
        for (int i=0; i<n; i++) { 
          cout<<"\nProducto "<<i<<":\n";
          producto s(p, s);
        }

      break;
      case 2:
        cout << setw(10) << "ID" << setw(10) << "nombre" << setw(10) << "precio" << setw(10) << "marca" << endl;
        for(int j=0;j<cantTotal;j++){
          cout << setw(10) << j  << setw(10) << p[j].nombre << setw(10) << p[j].precio << setw(10) << p[j].marca << endl;
        }
        for(int k=0;k!=1;){
          cout << "ingrese '1' para volver al menu. " << endl;
          cin >> k;
        }
      break;
      case 3:
      cout << "\n¿Que producto desea eliminar?" << endl;
      cin >> n;
      if(n<=cantTotal){
        p.erase (p.begin()+n);
        cantTotal--;
      }else{
        cout << "No existe un producto con esa ID" << endl;
      }
      break;
      default:
        cout << "La entrada no es valida";
      break;
    }
  }while(opcion!=0);
  return 0;
}








