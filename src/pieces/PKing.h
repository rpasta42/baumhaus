#ifndef PKING_H
#define PKING_H

#include "../CPos.h"
#include "CPiece.h"
#include "../CSquare.h"
#include <vector>

class PKing : public CPiece
{
    public:
        PKing(bool colorI);
        virtual ~PKing();
        std::vector<int> getSquareOn();

    protected:

    private:
};

#endif // PKING_H
