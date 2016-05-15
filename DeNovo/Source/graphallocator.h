#ifndef GRAPHALLOCATOR
#define GRAPHALLOCATOR

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
//        std::cout << "Alloc " << n * sizeof(T) << " bytes." << std::endl; //!
        T* t = (T*) malloc(n * sizeof(T));
        return t;

//        fprintf(stderr, "Alloc %d bytes.\n", n * sizeof(T));
//        return std::allocator<T>::allocate(n, hint);
    }

    void deallocate(pointer p, size_type n)
    {
//        std::cout << "Dealloc " << n * sizeof(T) << " bytes (" << p << ")." << std::endl; //!
        free(p);

//        fprintf(stderr, "Dealloc %d bytes (%p).\n", n * sizeof(T), p);
//        return std::allocator<T>::deallocate(p, n);
    }

    GraphAllocator() throw(): std::allocator<T>()
    {
//        std::cout << "Init allocator" << std::endl; //!
//        fprintf(stderr, "Init allocator\n");
    }

    GraphAllocator(const GraphAllocator& a) throw(): std::allocator<T>(a){}

    template<class V>
    GraphAllocator(const GraphAllocator<V> &a) throw(): std::allocator<T>(a){}
    ~GraphAllocator() throw() {}
};


#endif // GRAPHALLOCATOR

