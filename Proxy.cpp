

/**************************************************************

Proxy.- Proporciona un representante o sustituto de otro
objeto para controla el acceso a este.

***************************************************************/

class Person
{
    string nameString;
    static string list[]; //objeto o la variable se asignan cuando se inicia el programa y se desasignan cuando finaliza el programa
    static int next;
  public:
    Person()
    {
        nameString = list[next++];
    }
    string name()
    {
        return nameString;
    }
};
string Person::list[] =
{
  "Tom", "Dick", "Harry", "Bubba"
};
int Person::next = 0;

class CajaChicaProtegida
{
    int total;
  public:
    CajaChicaProtegida()
    {
        total = 500;
    }

    bool retirar(int cantidad)
    {
        if (cantidad > total)
          return false;
        total -= cantidad;
        return true;
    }
    int getBalance()
    {
        return total;
    }
};

class DineroGastos
{
    CajaChicaProtegida coso;
  public:
    bool retirar(Person &p, int cantidad)
    {
        if (p.name() == "Tom" || p.name() == "Harry" || p.name() == "Bubba")
          return coso.retirar(cantidad);
        else
          return false;
    }
    int getBalance()
    {
        return coso.getBalance();
    }
};

/*
int main()
{
  DineroGastos pc;
  Person trabajadores[4];
  for (int i = 0, cantidad = 100; i < 4; i++, cantidad += 100)
    if (!pc.retirar(trabajadores[i], cantidad))
      cout << "No hay dinero para " << trabajadores[i].name() << '\n';
    else
      cout << cantidad << " Soles para " << trabajadores[i].name() << '\n';
  cout << "El saldo restante es " << pc.getBalance() << '\n';
}
*/

/**************************************************************
Output

100 Soles para Tom
No hay dinero para Dick
300 Soles para Harry
No hay dinero para Bubba
El saldo restante es 100

***************************************************************/



