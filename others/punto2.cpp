#include <iostream>
void f1(void);
void f2(void);
void f3(void);
void f4(void);




int main()
{
  
  f1();
  f2();
  f3();
  f4();

  return 0;
}

void f1(void)
{
  //double b = 1; con las banderas el compilador encuentra problemático que no se use esta variable
  double *z = new double [100] {0.0};  //tiene que ser "new double" en lugar de "new char" 
  //double a = 2; con las banderas el compilador encuentra problemático que no se use esta variable
  z[0] = 25; //"-1" no corresponde a ningún índice del arreglo, se cambia por 0 para asignarle valor al 1er elemento. (Valgrind: invalid write of size 8)
  delete [] z;
}

void f2(void)
{
  char *y = new char [10];
  y[9] = 'a';  //"9" en lugar de "10" para el último elemento del arreglo, ya que los índices del arreglo van de 0 a 9. (Valgrind: invalid write of size)
  delete [] y; //faltaba liberar memoria (Valgrind)
}

void f3(void)
{
  int x = 0; //no se había inicializado
  if(x == 0)  //"x = 0" no vale como expresión lógica
    {
      std::cout << "X is zero: " << x <<"\n";
    }
}

void f4(void)
{
  int x = 0; //no se había inicializado
  std::cout << "x = " << x << "\n";
  int j = 0;
  int a[10] {77}; //se inicializó (1er elemento 77, el resto 0s), teniendo en cuenta el error mostrado por Valgrind, ver línea 56)
  for ( int i = 0; i <= 9; ++i ) {  //i tiene que correr hasta 9, para que no se salga del arreglo, y es preferible inicializar el contador en el for
    j += a[i];
  }
  
  if ( j == 77 ) //"j = 77" no vale como expresión lógica (Valgrind: "Conditional jump or move depends on uninitialised value(s)")
    std::cout << "hello there\n";
}
