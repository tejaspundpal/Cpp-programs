#include<iostream>
#include<stdlib.h>
using namespace std;

class shape1
{
    float l,b;
     protected:
    float r;
    
  public:	
   float s;
   shape();
       float s_area();
    void set_side(float);
    float get_side();
};

shape::shape()
{
   cout<<"constructor is called"<<endl;
   s = 0;
}
void shape:: set_side(float s)
{
   this->s = s;
}
float shape:: get_side()
{
   return s;
}
float shape::s_area()
{
   float area;
   area = s*s;
   return area;
}

class area:public shape
{
   float base;
   float height;
   
   public;

   area();
   float t_area();
   float rect_area();
   void set_b_h(float ,float );
   float get_base();
   float gete_height();
};

void area::set_b_h(float b,float h)
{
   this->base = base;
   this->height = height;
} 

float area::get_base()
{
   return base;
}

float area::get_height()
{
   return height;
}

void area::t_area()
{
   float area;
   area = 0.5 * base * height;
   return area;
}

/*float area::rect_area()
{
   float area;
   area = l * b
   return area;
}*/

int main()
{
    shape s;
    area a;
    s.set_side(5.5);
    s.s_area();

return 0;
}




















