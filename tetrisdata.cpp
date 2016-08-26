#include "tetrisdata.h"

TetrisData::TetrisData(QObject *parent, int width, int height, int numberOfHiddenRows) :
    QObject(parent),
    _board(width * height, TetrisData::State::NOTHING),
    _width(width),
    _height(height),
    _nHiddenRows(numberOfHiddenRows)
{

}


void TetrisData::log() const
{
    const TetrisData& src = *this; //To allo operator() without being ugly
    out() << tr("Outputting current grid. Dimension : %1x%2. Hidden (upper) rows : %3").arg(_width).arg(_height).arg(_nHiddenRows)
          << endl;

    for (int y = 0; y <  _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            out() << src(x, y) << ' ';
        }
        out() << endl;
    }
}
