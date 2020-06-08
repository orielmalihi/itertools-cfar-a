#pragma once

#include <iostream>
#include <string>
// #include <vector>

namespace itertools
{

    class range
    {
    /* range members */
    private:
        int m_start, m_end;
    public:
        /* the iterator */
        class Iterator
        {
        public:
            Iterator(int val);
            const int &operator*() const;
            Iterator &operator++();
            bool operator!=(const Iterator &other) const;

        private:
            int m_current_number = -1;
        };

    public:
        /* rane methods - decleration */
        range(int from, int to);
        Iterator begin() const ;
        Iterator end() const;
    };

    
    /* range methods - implementation */
    range::range(int from, int to):
        m_start(from),
        m_end(to){}

    range::Iterator::Iterator(int val){
        m_current_number = val;
    }  

    range::Iterator& range::Iterator::operator++(){
        m_current_number++;
        return *this;
    } 

    const int & range::Iterator::operator*() const{
        return m_current_number;
    }

    bool range::Iterator::operator!=(const range::Iterator& other) const {
        return m_current_number!=other.m_current_number;
    }

    range::Iterator range::begin() const{
        return range::Iterator{m_start};
    } 

    range::Iterator range::end() const{
        return range::Iterator{m_end};
    } 
 

} // namespace itertools
