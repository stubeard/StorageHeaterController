template<class T>
Delay<T>::Delay(): m_value{ 0 }
{

}

template<typename T>
Delay<T>::~Delay()
{

}

template<typename T>
bool Delay<T>::expired()
{
    return( m_value <= 0 );
}

template<typename T>
void Delay<T>::set( T value )
{
    m_value = value;
}

template<typename T>
void Delay<T>::update( T interval )
{
    if( m_value <= interval )
    {
        m_value = 0;
    }
    else
    {
        m_value -= interval;
    }
}
