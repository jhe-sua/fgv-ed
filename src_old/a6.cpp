#include "ArrDinamico.h"

using namespace emap;

int main()
{
    ListaDinamica* p = inicializar(4);
    append(p, 40);
    append(p, 40);
    append(p, 40);
    append(p, 40);
    display(p);
    append(p, 40);
    display(p);
    deletar(p);
    return 0;
}
