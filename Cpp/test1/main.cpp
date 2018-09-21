#include <iostream>
// #include <string>

using namespace std;

/***************************
 ** Line class
 ***************************/

class Line
{
  private:
    /* data */
    double fLength;

  public:
    Line(/* args */);
    ~Line();
    void setLenght(double length);
    double getLenght();
};

Line::Line(/* args */)
{
    // void constructor
    cout << "Object is being created" << endl;
}

Line::~Line()
{
    // void destructor
    cout << "Object is being distructed" << endl;
}

void Line::setLenght(double length)
{
    fLength = length;
}

double Line::getLenght()
{
    return fLength;
}

/******************************
 ** Interface / abstract class
 ******************************/
class Shape
{
  public:
    // pure virtual function providing interface framework.
    virtual int getArea() = 0;
    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }
    Shape()
    {
        cout << "Creating shape" << endl;
    };
    ~Shape()
    {
        cout << "Removing shape" << endl;
    };

  protected:
    int width;
    int height;
};

/******************************
 ** Derived classes
 ******************************/
class Rectangle : public Shape
{
  public:
    int getArea(){
        return (width * height);
    }
    Rectangle(){
        cout << "Creating rectangle" << endl;
    }
    ~Rectangle(){
        cout << "Removing rectangle" << endl;
    }
};

class Triangle : public Shape
{
  public:
    int getArea(){
        return (width * height) / 2;
    }
    Triangle(){
        cout << "Creating triangle" << endl;
    }
    ~Triangle(){
        cout << "Removing triangle" << endl;
    }
};

/***************************
 ** Main
 ***************************/

int main(int argc, char const *argv[])
{
    /***********************************
     * string class
     ***********************************/
    string name = "Fra";
    cout << "Hello World " << name
         << ". Your name is " << name.size()
         << " letters long." << endl;

    /***********************************
     * create an object from Line class
     ***********************************/
    Line l1;
    l1.setLenght(2.0);
    cout << "Line object length: " << l1.getLenght() << endl;

    /***********************************
     * Polymorphism and Inheritance
     ***********************************/
    Shape *shape_p;
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);
    shape_p = &Rect;
    // Print the area of the object.
    cout << "Total Rectangle area: " << shape_p->getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);
    shape_p = &Tri;

    // Print the area of the object.
    cout << "Total Triangle area: " << shape_p->getArea() << endl;

    return 0;
}