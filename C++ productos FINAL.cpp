#include <iostream>
#include <string>
#include <iomanip>
#include <vector>



typedef enum{
  
  SALIR=0,
  INGRESO,
  MOSTRAR,
  ELIMINAR
}opcion_t;

using namespace std;

class producto {       
  
  public:             // Especificador de acceso
    string nombre;    // Atributo
    int precio;       // Atributo
    string marca;     // Atributo
    
    producto(vector<producto> & p2){   
      cout<<"Nombre del producto: ";
      cin>>this->nombre;
      cout<<"Precio del producto: ";
      cin>>this->precio;
      cout<<"Marca del producto: ";
      cin>>this->marca;
      p2.push_back(*this);

    }
};
void ingresarProductos(int &cantTotal, vector<producto>& p)
{
            cout << "\n¿Cuantos productos quiere ingresar?" << endl;
            int n;
            cin >> n;
            cantTotal = cantTotal + n;
            
            for (int i=1; i<=n; i++)
            { 
              cout<<"\nProducto "<<i<<":\n";
              producto s(p);

            }
}

void mostrarCuadro(int cantTotal, vector<producto> p){
  if(p.size()==0){
    cout << "No se ha ingresado ningún producto." << endl;
  }else{
    cout << setw(10) << "ID" << setw(10) << "nombre" << setw(10) << "precio" << setw(10) << "marca" << endl;
    for(int j=0;j<cantTotal;j++){
      cout << setw(10) << j  << setw(10) << p[j].nombre << setw(10) << p[j].precio << setw(10) << p[j].marca << endl;
    }
  }
  for(int k=0;k!=1;){
    cout << "ingrese '1' para volver al menu. " << endl;
    cin >> k;
  }
}
void eliminarProducto(int &cantTotal, vector<producto> &p){
  cout << "\n¿Que producto desea eliminar?" << endl;
  int n;
  cin >> n;
  if(n<=cantTotal){
    p.erase (p.begin()+n);
    cantTotal--;
  }else{
    cout << "No existe un producto con esa ID" << endl;
  }
}

/*class comestible: public producto {
  public:
    string vencimiento;
    bool sinTacc;
}*/

int main() {
  int opcion;
  int cantTotal = 0;
  vector<producto> p;

  do{
    cout << "\n\nMenu de Opciones" << endl;
    cout << "1. Ingresar nuevos productos" << endl;
    cout << "2. Ver productos" << endl;
    cout << "3. Eliminar producto" << endl;
    cout << "0. Salir" << endl;
      
    cout << "\nIntroduzca una opcion: ";
    cin >> opcion;
      
    switch (opcion){
      
      case INGRESO:
            ingresarProductos(cantTotal, p);
            break;
      case MOSTRAR:
            mostrarCuadro(cantTotal, p); 
            break;
      case ELIMINAR:
            eliminarProducto(cantTotal, p);
            break;
      case SALIR: 
            break;
      default:
            cout << "La entrada no es valida";
            break;
    }
  }while(opcion!=SALIR);
  return 0;
}


