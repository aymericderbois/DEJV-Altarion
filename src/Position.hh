/* 
 * File:   Position.hh
 * Author: Aymeric
 *
 * Created on 26 mai 2013, 18:37
 */

#ifndef POSITION_HH
#define	POSITION_HH

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
    void SetY(int y);
    int GetY() const;
    void SetX(int x);
    int GetX() const;
};

#endif	/* POSITION_HH */

