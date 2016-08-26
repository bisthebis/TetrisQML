#ifndef TETRISDATA_H
#define TETRISDATA_H

#include <QObject>
#include <QVector>

#include "global.h"

class TetrisData : public QObject
{
    Q_OBJECT

    public:
    enum State {NOTHING = 0,
                WHITE_BOX = 1};


    public:
        explicit TetrisData(QObject *parent = 0, int width = 10, int height = 22, int numberOfHiddenRows = 2);
        //Source for default values : http://tetris.wikia.com/wiki/Tetris_Guideline

        State operator() (int x, int y) const {int i = _coordsToIndex(x, y); if (i < 0) {out() << tr("Trying to access out-of range block !") << endl; return NOTHING;} else return _board[i];}


    public slots:
        State at(int x, int y) const {return (*this)(x, y);}

        void log() const;

    signals:

    //Helper methods
    private:
        //Returns -1 if invalid position
        int _coordsToIndex(int x, int y) const {
            if (x < 0 || y < 0 || x >= _width || y >= _height)
                return -1;

            return x + y * _width;
        }



    //Private members
    private:
        QVector<State> _board; /* INVARIANT : _board.size() == _width*_height; */
        int _width;
        int _height;
        int _nHiddenRows;






};

#endif // TETRISDATA_H
