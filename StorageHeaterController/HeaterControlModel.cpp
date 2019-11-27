#include "HeaterControlModel.h"
#include "Defines.h"
#include <chrono>

namespace StorageHeaterControl
{
    HeaterControlModel::HeaterControlModel( const int_fast64_t &interval )
    : m_listeners{}, m_currentState{ false }, m_timer{}, m_interval{ interval }, m_running{ true }, m_thread{ HeaterControlModel::timedLoop, this }, m_lock{}
    {
        m_thread.detach();
    }

    HeaterControlModel::~HeaterControlModel()
    {
        m_running = false;
        if( m_thread.joinable() )
        {
            m_thread.join();
        }
    }

    void HeaterControlModel::setSchedule( const std::vector<bool> &schedule )
    {
        m_lock.lock();
        m_schedule.clear();

        for( bool eachBool : schedule )
        {
            m_schedule.push_back( std::move( eachBool ) );
        }
        m_lock.unlock();
        processSchedule();
    }

    void HeaterControlModel::fireModelChanged()
    {
        for( auto listener : m_listeners )
        {
            listener->modelChanged();
        }
    }

    bool HeaterControlModel::getCurrentState()
    {
        return m_currentState;
    }

    void HeaterControlModel::addListener( IModelListener *listener )
    {
        if( listener )
        {
            m_listeners.push_back( std::move( listener ) );
        }
    }

    void HeaterControlModel::processSchedule()
    {
        m_lock.lock();
        if( ! m_schedule.empty() )
        {
            setCurrentState( m_schedule.front() );
            m_schedule.pop_front();
        }
        m_lock.unlock();
        m_timer.set( m_interval );
    }

    void HeaterControlModel::setCurrentState( bool state )
    {
        m_currentState = state;
        fireModelChanged();
    }

    void HeaterControlModel::timedLoop()
    {
        auto then{ std::chrono::steady_clock::now() };

        while( m_running )
        {
            std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

            auto now{ std::chrono::steady_clock::now() };
            int_fast64_t elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>( now - then ).count();

            m_timer.update( elapsed_us );

            if( m_timer.expired() )
            {
                processSchedule();
            }

            then = now;
        }
    }
}
