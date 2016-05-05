#ifndef MANIPULATOR
#define MANIPULATOR


namespace framing
{
    struct framing_proxy
    {
        explicit framing_proxy(std::ostream& os) : os(os) {}

        template<typename T>
        friend std::ostream& operator<<(framing_proxy const& f, T const& t)
        {
            return f.os << "{" << t << "}";
        }

    private:
        std::ostream& os;
    };

    struct framing_creator {} frame;
    framing_proxy operator<<(std::ostream& os, framing_creator)
    {
        return framing_proxy(os);
    }
}

#endif // MANIPULATOR

