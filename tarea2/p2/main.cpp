#include "ABB.hpp"

int main(){
    tabb arbol;
    for (int x=1;x<90;x=x*3)
        arbol.insert(x);
    arbol.inOrden();
    cout<<arbol.size()<<"\n";
    return 0;
}