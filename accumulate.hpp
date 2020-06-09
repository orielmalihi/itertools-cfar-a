// #pragma once

// #include <iostream>
// #include <string>
// // #include <vector>

// namespace itertools
// {
   
//     template <typename T, typename ITR>
//     class accumulate
//     {
//     private:
//         T m_container;

//     public:
//         /* the iterator */
//         class Iterator
//         {
//         public:
//             Iterator(ITR from, ITR to);
//             const int &operator*() const;
//             Iterator &operator++();
//             bool operator!=(const Iterator &other) const;

//         private:
//             ITR m_begin;
//             ITR m_end;
//             int m_current_sum = 0;
//         };

//     public:
//         /* accumulate methods - decleration */
//         accumulate(T container);
//         Iterator begin() const;
//         Iterator end() const;
//     };

//     /* accumulate methods - implementation */
//     template <typename T, typename ITR>
//     accumulate<T, ITR>::accumulate(T container) : m_container(container) {}

//     template <typename T, typename ITR>
//     accumulate<T,ITR>::Iterator::Iterator(ITR from , ITR to):
//     m_begin(from),
//     m_end(to){}

//     template <typename T, typename ITR>
//     typename accumulate<T,ITR>::Iterator &accumulate<T, ITR>::Iterator::operator++()
//     {
//         m_current_sum += *m_begin;
//         ++m_begin;
//         return *this;
//     }

//     template <typename T, typename ITR>
//     const int &accumulate<T, ITR>::Iterator::operator*() const
//     {
//         return m_current_sum;
//     }

//     template <typename T, typename ITR>
//     bool accumulate<T, ITR>::Iterator::operator!=(const accumulate::Iterator &other) const
//     {
//         return m_begin!=m_end;
//     }

//     template <typename T, typename ITR>
//     typename accumulate<T, ITR>::Iterator accumulate<T, ITR>::begin() const
//     {
//         return accumulate<T,ITR>::Iterator{m_container.begin(), m_container.end()};
//     }

//     template <typename T, typename ITR>
//     typename accumulate<T, ITR>::Iterator accumulate<T, ITR>::end() const
//     {
//         return accumulate<T,ITR>::Iterator{m_container.end(), m_container.end()};
//     }



// } // namespace itertools




// *******************************************************************************************



#pragma once

#include <iostream>
#include <string>
// #include <vector>

namespace itertools
{
   
    template <typename T>
    class accumulate
    {
    private:
        T m_container;

    public:
        /* the iterator */
        class Iterator
        {
        public:
            Iterator(typename T::Iterator from,typename T::Iterator to);
            const int &operator*() const;
            Iterator &operator++();
            bool operator!=(const Iterator &other) const;

        private:
            typename T::Iterator m_begin;
            typename T::Iterator m_end;
            int m_current_sum = 0;
        };

    public:
        /* accumulate methods - decleration */
        accumulate(T container);
        Iterator begin() const;
        Iterator end() const;
    };

    /* accumulate methods - implementation */
    template <typename T>
    accumulate<T>::accumulate(T container) : m_container(container) {}

    template <typename T>
    accumulate<T>::Iterator::Iterator(typename T::Iterator from,typename T::Iterator to):
    m_begin(from),
    m_end(to){}

    template <typename T>
    typename accumulate<T>::Iterator &accumulate<T>::Iterator::operator++()
    {
        m_current_sum += *m_begin;
        ++m_begin;
        return *this;
    }

    template <typename T>
    const int &accumulate<T>::Iterator::operator*() const
    {
        return m_current_sum;
    }

    template <typename T>
    bool accumulate<T>::Iterator::operator!=(const accumulate<T>::Iterator &other) const
    {
        return m_begin!=other.m_begin;
    }

    template <typename T>
    typename accumulate<T>::Iterator accumulate<T>::begin() const
    {
        return accumulate<T>::Iterator{m_container.begin(), m_container.end()};
    }

    template <typename T>
    typename accumulate<T>::Iterator accumulate<T>::end() const
    {
        return accumulate<T>::Iterator{m_container.end(), m_container.end()};
    }



} // namespace itertools
