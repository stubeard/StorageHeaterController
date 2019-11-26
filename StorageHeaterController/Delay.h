#ifndef __DELAY_H__
#define __DELAY_H__

/** \brief Template Class implementing a countdown timer.
 *
 */

template<class T>
class Delay
{
    public:
        Delay();
        ~Delay();
        bool expired();
        void set( T value );
        void update( T interval );
    private:
        T m_value;
};

#include "Delay.inl"

#endif // __DELAY_H__
