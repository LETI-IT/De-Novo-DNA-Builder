#ifndef GRAPHALLOCATOR
#define GRAPHALLOCATOR

/*
 * Allow to allocate items for items for graph
 */
template<class T>
class GraphAllocator : public std::allocator<T>
{
public:
    typedef size_t size_type;
    typedef T* pointer;
    typedef const T* const_pointer;

    template<class E>
    struct rebind
    {
        typedef GraphAllocator<E> other;
    };

    pointer allocate(size_type n, const void* hint=0)
    {
        T* t = (T*) malloc(n * sizeof(T));
        return t;
    }

    void deallocate(pointer p, size_type n)
    {
        free(p);
    }

    GraphAllocator() throw(): std::allocator<T>()
    {
    }

    GraphAllocator(const GraphAllocator& a) throw(): std::allocator<T>(a){}

    template<class V>
    GraphAllocator(const GraphAllocator<V> &a) throw(): std::allocator<T>(a){}
    ~GraphAllocator() throw() {}
};


#endif // GRAPHALLOCATOR

