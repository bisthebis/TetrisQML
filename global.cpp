#include "global.h"

QTextStream& out()
{
    static QTextStream stream(stdout);
    return stream;
}

QTextStream& in()
{
    static QTextStream stream(stdin);
    return stream;
}
