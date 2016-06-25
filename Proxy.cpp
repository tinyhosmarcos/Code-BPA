

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






/**************************************************************

Adapter.- convierte la interfaz de una clase en otra que esperan los clientes.

***************************************************************/

typedef int Coordenada;
typedef int Dimension;

// interfaz deseada
class Rectangulo
{
  public:
    virtual void draw() = 0;
};

// componente heredado
class  RectanguloHeredado
{
  public:
    RectanguloHeredado(Coordenada x1, Coordenada y1, Coordenada x2, Coordenada y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout << "Rectangulo Heredado:  creacion.  (" << x1_ << "," << y1_ << ") => ("
          << x2_ << "," << y2_ << ")" << endl;
    }
    void oldDraw()
    {
        cout << "Rectangulo Heredado:  ViejoDibujo.  (" << x1_ << "," << y1_ <<
          ") => (" << x2_ << "," << y2_ << ")" << endl;
    }
  private:
    Coordenada x1_;
    Coordenada y1_;
    Coordenada x2_;
    Coordenada y2_;
};

// Adaptador
class RectanguloAdaptador: public Rectangulo, private RectanguloHeredado
{
  public:
    RectanguloAdaptador(Coordenada x, Coordenada y, Dimension w, Dimension h):
      RectanguloHeredado(x, y, x + w, y + h)
    {
        cout << "Rectangulo Adaptador: creacion.  (" << x << "," << y <<
          "), anchura = " << w << ", altura = " << h << endl;
    }
    virtual void draw()
    {
        cout << "Rectangulo Adaptador: Dibujo..." << endl;
        oldDraw();
    }
};

int main()
{
  Rectangulo *r = new RectanguloAdaptador(120, 200, 60, 40);
  r->draw();
}

/**************************************************************
Output

Rectangulo Heredado:  creacion. (120,200) => (180,240)
Rectangulo Adaptador: creacion. (120,200), anchura = 60, altura = 40
Rectangulo Adaptador: Dibujo...
Rectangulo Heredado:  ViejoDibujo.(120,200) => (180,240)

***************************************************************/
