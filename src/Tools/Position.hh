/* 
 * File:   Position.hh
 * Author: Aymeric
 *
 * Created on 26 mai 2013, 18:37
 */

#ifndef POSITION_HH
#define	POSITION_HH

namespace Tools
{
    class Position
    {
    public:
        Position();
        Position(int x, int y);
        virtual ~Position();
    private:
        int x;
        int y;

    public:
        void setY(int y);
        int getY() const;
        void setX(int x);
        int getX() const;
    };
}
#endif	/* POSITION_HH */

