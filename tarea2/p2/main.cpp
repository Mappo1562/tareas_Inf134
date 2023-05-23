#include "ABB.hpp"

int main(){
    tabb arbol;
    for (int x=1;x<90;x=x*3)
        arbol.insert(x);
    arbol.inOrden();
    cout<<"\n"<<arbol.size()<<"\n\n";
    arbol.postOrden();
    cout<<"\n";
    arbol.preOrden();
    cout<<"\n";

    int a=arbol.lower_bound(6);
    cout<<a<<"\n\n";

    if (arbol.find(9))
        cout<<"si esta en el arbol\n\n";
    else
        cout<<"no esta en el arbol\n\n";

    arbol.remove(27);
    arbol.preOrden();

    arbol.clear();
/*
    arbol.insert(28);
    arbol.insert(16);
    arbol.insert(30);
    arbol.insert(5);
    arbol.insert(25);
    arbol.insert(29);
    arbol.insert(32);
    arbol.insert(12);
    arbol.insert(20);
    arbol.insert(18);
    arbol.insert(23);

    cout<<"\n";
    cout<<"\n";
    arbol.preOrden();
    arbol.remove(28);
    cout<<"\n";cout<<"\n";
    arbol.preOrden();
*/

    return 0;
}