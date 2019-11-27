#ifndef __DELAY_H__
#define __DELAY_H__

/** \brief Template Class implementing a countdown timer.
 *
 */
/** \brief A template class to provide a countdown timer.
 *
 *  The Delay is using the set() member function to the required delay time.
 *  The update() member function should be called periodically to decrement the counter.
 *  The expired() member function is called to test whether the counter has reached zero.
 *
 */

template<class T>
class Delay
{
    public:
        Delay();
        ~Delay();

        /** \brief Tests whether the Delay has expired or not.
         *
         * \return A bool indication the countdown has reached zero.
         */
        bool expired();

        /** \brief Sets the Delay to the required value.
         *
         * \param  the value to set the countdown timer to.
         */
        void set( T value );

        /** \brief Decrements the countdown timer. Should be called periodically.
         *
         * \param  the value to decrement the countdown timer by..
         */
        void update( T interval );
    private:
        T m_value;
};

#include "Delay.inl"

#endif // __DELAY_H__
