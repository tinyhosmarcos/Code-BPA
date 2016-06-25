


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
