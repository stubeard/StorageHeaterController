#ifndef __TIMER_H__
#define __TIMER_H__

#include "TimerType.h"
#include <thread>
#include <functional>
#include <chrono>
#include <vector>

/** \brief A reusable template class to provide a periodic timer.
 *
 *  The Timer is created by passing a member function, an interval and the units.
 *  Call the start() function to start the timer,
 *  and the stop() function to stop it.
 *
 */

template<class T>
class Timer
{
    public:
        Timer( std::function<void(T*,int_fast64_t)> action = timer_tick,
               int interval = 1000,
               TimerType timerType = TimerType::Milliseconds )
               : m_action{ action }, m_interval{ interval }, m_timerType{ timerType }, m_run{ false }, m_thread{}
        {

        }

        virtual ~Timer()
        {

        }

        /**
         * \brief   Starts the timer
         *
         * \param   A pointer to an instance of the class containing the timer (Automatically set by the compiler)
         * \param   A boolean indicating whether to the timer should be detached from the parent process.
         */
        void start( T *t, bool detached = false )
        {
            if( m_thread.joinable() )
            {
                stop();
                wait();
            }
            m_run = true;

            m_thread = std::thread( [ this, t ]
            {
                auto then{ std::chrono::steady_clock::now() };

                while( m_run )
                {
                    switch( m_timerType )
                    {
                        case TimerType::Microseconds : std::this_thread::sleep_for( std::chrono::microseconds( m_interval ) ); break;
                        case TimerType::Milliseconds : std::this_thread::sleep_for( std::chrono::milliseconds( m_interval ) ); break;
                        case TimerType::Seconds      : std::this_thread::sleep_for( std::chrono::seconds     ( m_interval ) ); break;
                        case TimerType::Minutes      : std::this_thread::sleep_for( std::chrono::minutes     ( m_interval ) ); break;
                        case TimerType::Hours        : std::this_thread::sleep_for( std::chrono::hours       ( m_interval ) ); break;
                    }
                    auto now{ std::chrono::steady_clock::now() };
                    int_fast64_t elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>( now - then ).count();
                    then = now;
                    m_action( t, elapsed_us );
                }
            } );

            g_threads.push_back( &m_thread );

            if( bDetached )
            {
               m_thread.detach();
            }
        }

        /**
         * \brief   Stops the timer
         *
         */
        void stop()
        {
            m_run = false;
        }

        /**
         * \brief   Waits for the timer thread to finish.
         *
         */
        void wait()
        {
            if( m_thread.joinable() )
            {
                m_thread.join();
            }
        }

        /**
         * \brief   Detaches the timer thread so it can run independently of it's parent.
         *
         */
        void detach()
        {
            if( m_thread.joinable() )
            {
                m_thread.detach();
            }
        }

        void timer_tick( int_fast64_t elapsed_us )
        {

        }

    private:
        std::function<void(T*,int_fast64_t)> m_action;
        int m_interval;
        TimerType m_timerType;

        bool m_run;
        std::thread m_thread;

        static std::vector<std::thread*> g_threads;

    public:
        /**
         * \brief   Waits for all timer threads to complete.
         *
         */
        static void JoinAllThreads();
};

#include "Timer.inl"

#endif // __TIMER_H__
