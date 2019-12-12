template<class T>
std::vector<std::thread*> Timer<T>::g_threads{};

template<class T>
void Timer<T>::JoinAllThreads()
{
    for( std::thread *thread : Timer<T>::g_threads )
    {
        if( thread->joinable() )
        {
            thread->join();
        }
    }
}
