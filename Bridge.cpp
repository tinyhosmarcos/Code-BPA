#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


/**************************************************************

Bridge.- Desacopla una abstraccion de su implementacion de modo
de modo que ambas puedan variar de forma independiente.

***************************************************************/



class TimeImp {
  public:
    TimeImp(int hr, int min) {
        hr_ = hr;
        min_ = min;
    }
    virtual void tell() {
        cout << "time is " << hr_ << "-" << min_ << endl;
    }
  protected:
    int hr_, min_;
};

class CivilianTimeImp: public TimeImp {
  public:
    CivilianTimeImp(int hr, int min, int pm): TimeImp(hr, min) {
        if (pm)
          strcpy(whichM_, " PM");
        else
          strcpy(whichM_, " AM");
    }

    /* virtual */
    void tell() {
        cout << "time is " << hr_ << ":" << min_ << whichM_ << endl;
    }
  protected:
    char whichM_[4];
};

class ZuluTimeImp: public TimeImp {
  public:
    ZuluTimeImp(int hr, int min, int zone): TimeImp(hr, min) {
        if (zone == 5)
          strcpy(zone_, " hora estandar del Este");
        else if (zone == 6)
          strcpy(zone_, " Hora Estandar del Centro");
    }

    /* virtual */
    void tell() {
       cout << "time is " << hr_ << ";" << min_ << zone_ << endl;
    }
  protected:
    char zone_[30];
};

class Time {
  public:
    Time(){}
    Time(int hr, int min) {
        imp_ = new TimeImp(hr, min);
    }
    virtual void tell() {
        imp_->tell();
    }
  protected:
    TimeImp *imp_;
};

class CivilianTime: public Time {
  public:
    CivilianTime(int hr, int min, int pm) {
        imp_ = new CivilianTimeImp(hr, min, pm);
    }
};

class ZuluTime: public Time {
  public:
    ZuluTime(int hr, int min, int zone) {
        imp_ = new ZuluTimeImp(hr, min, zone);
    }
};

/*
int main()
{
  Time *times[3];
  times[0] = new Time(14, 30);
  times[1] = new ZuluTime(14, 30, 6);
  times[2] = new CivilianTime(2, 30, 1);
  for (int i = 0; i < 3; i++)
    times[i]->tell();
}
*/

/**************************************************************

Output

time is 14-30
time is 14;30 Hora Estandar del Centro
time is 2:30 PM

***************************************************************/





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
