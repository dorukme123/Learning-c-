#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;
class  vect
{
private:
 float x,y,z,w;
public:
 vect** ZEROVECTOR();
 static char sBuffer[38];
 char* toString();
 vect (void);
 vect (float,float,float);
 vect (vect&);
 ~vect();
 vect  operator+(vect&);
 vect  operator-(vect&);
 float    dotProduct(vect&);
 void  operator=(vect&);
 int  operator==(vect&);
 vect  operator*(vect&);
 vect  operator*(float);
 float length();
 void normalize();
};
vect::vect (float xi,float yi,float zi){
 x=xi;
 y=yi;
 z=zi;
 w=1.0f;
}
vect::vect (vect& a){
 x=a.x;
 y=a.y;
 z=a.z;
 w=a.w;
}
vect::~vect(){}

vect  vect::operator+(vect& a){
 return vect(x +a.x,y +a.y,z +a.z);
}

vect  vect::operator-(vect& a){
 return vect(x -a.x,y -a.y,z -a.z);
}

float    vect::dotProduct(vect& a){
 return x*a.x+y*a.y+z*a.z;
}
char vect::sBuffer[38];

char* vect::toString(){
 sprintf_s(sBuffer,38,"(%f,%f,%f,%f)",x,y,z,w);
 return sBuffer;
}

int vect::operator==(vect& a){

 return (x==a.x && y==a.y && z==a.z);
}

vect::vect (void){
 x=0.0f;
 y=0.0f;
 z=0.0f;
 w=1.0f;
}

void vect::operator=(vect& a){
 x=a.x;
 y=a.y;
 z=a.z;
 w=a.w;
}

vect vect::operator*(vect& a){
 return vect(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-a.x*y);
}

vect vect::operator*(float a){
 return vect(x*a,y*a,z*a);
}

 float vect::length(){
 return sqrt(x*x+y*y+z*z);
 }

 void vect::normalize()
 {

 float len = length();
 x = x/len;
 y = y/len;
 z = z/len;
 w=1.0f;
 }

int main()
{
 vect i,j,k;
 vect a,b,c;
 i = vect(5.0f,0.0f,0.0f);
 j = vect(0.0f,6.0f,0.0f);
 i.normalize();
 j.normalize();
 k = i*j;
 if(i.length() != 1.0f){
  cout << "Error";
  getchar();
 }
 if(j.length() != 1.0f){
  cout << "Error";
  getchar();
 }
 if(k.length() != 1.0f){
  cout << "Error";
  getchar();
 }
 if(!(k == CVector(0.0f,0.0f,1.0f))){
  cout << "Error";
  getchar();
 }
 if(!(((i*k)*5.0f)==j*(-5.0f))){
  cout << "Error";
  getchar();
 }
 if(!(c-c==ZEROVECTOR)){
  cout << "Error";
  getchar();
 }
 c = vect(8.0f,5.0f,-1.0f);
 b = c;
 if(!(b==c)){
  cout << "Error";
  getchar();
 }
 c = vect(8.0f,5.0f,-1.0f);
 if(a=c+c,b=c*2.0f,!(a==b)){
  cout << "Error";
  getchar();
 }
 cout << "everything works\n";
 getchar();
return;
}
