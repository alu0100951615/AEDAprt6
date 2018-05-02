#include "DNI.hpp"
#include <iostream>

DNI::DNI():
dni_(0),
base_(0),
medio(0)
{
}

DNI::DNI(int& d):
dni_(d)
{}

DNI::DNI(DNI& x){
   dni_=x.dni_;
   medio=x.medio;
}

int DNI::get_base(){
     return dni_;
}

void DNI::generar_dni(){
     // srand(base_+);
      dni_=rand()%300000;
}

DNI DNI::operator=(const DNI& x){
   dni_=x.dni_;
   return *this;
}

DNI DNI::operator=(const int& x){
   dni_=x;
   return *this;
}



bool DNI::operator==(DNI& x){
            medio=medio+1;
        if (dni_==x.get_base()){
            return true;
        }
        else {
            return false;
        }

}

bool DNI::operator!=(DNI& x){
            medio=medio+1;
        if (dni_!=x.get_base()){
            return true;
        }
        else {
            return false;
        }

}

bool DNI::operator<(DNI& x){
           medio=medio+1;
        if (dni_<x.get_base()){
            return true;
        }
        else {
            return false;
        }
}

bool DNI::operator>(DNI& x){
            medio=medio+1;
        if (dni_>x.get_base()){
            return true;
        }
        else {
            return false;
        }
}
bool DNI::operator<(int& x){
            medio=medio+1;
     if (dni_<x){
            return true;
        }
        else {
            return false;
        }
}

bool DNI::operator>(int& x){
            medio=medio+1;
     if (dni_>x){
            return true;
        }
        else {
            return false;
        }
}

Index_t DNI::operator%(int& x){
         Index_t aux;

         aux=dni_%x;
         return aux;

}

DNI DNI::operator/(int& x){
         Index_t aux;
         DNI aux2;
         aux=dni_/x;
         aux2=aux;
         return *this;

}

int DNI::get_medio(){
        return medio;
}