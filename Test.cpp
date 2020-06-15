/*
 * Test.cpp
 *
 *  Created on: 15 June 2020
 *      Author: oriel malihi
 */
#include "doctest.h"
#include <string>
#include <vector>
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"

#define EPSILON 0.00001

using namespace itertools;
using namespace std;

range my_range = range(5,10);
vector<int> vecInt = {2,4,6,8};
vector<string> vecString = {"Hello", "Bye", "Shalom"};
vector<float> vecFloat = {-1, 0.3, 5.2, -4};

template<typename T>
struct functor{
    T operator()(T a, T b){
        return (a + b)*2; 
    }
};



TEST_CASE("Range class")
{
    
    int expected = 5;
    for(auto i : my_range){
        CHECK(i==expected);
        expected++;
    }
    CHECK(expected==10);
}

TEST_CASE("accumulate class")
{
    auto my_container = accumulate(vecInt);
    int ans[] = { 2, 6, 12 ,20};
    int index = 0;
    for(auto i : my_container){
        CHECK(i==ans[index]);
        index++;
    }

    auto my_container2 = accumulate(vecFloat);
    float ans2[] = { -1, -0.7, 4.5, 0.5};
    index = 0;
    for(auto i : my_container2){
        if(i<ans2[index]+EPSILON && i> ans2[index]-EPSILON){
             CHECK(true);
        }
        else{
            CHECK(false);
        }
        index++;
    }
}

    TEST_CASE("accumulate class with Functor")
{
    auto my_container = accumulate(vecInt, functor<int>());
    int ans[] = { 2, 12, 36 , 88};
    int index = 0;
    for(auto i : my_container){
        CHECK(i==ans[index]);
        index++;
    }

    auto my_container2 = accumulate(vecFloat, functor<float>());
    float ans2[] = { -1, -1.4, 7.6, 7.2};
    index = 0;
    for(auto i : my_container2){
        if(i<ans2[index]+EPSILON && i> ans2[index]-EPSILON){
             CHECK(true);
        }
        else{
            CHECK(false);
        }
        index++;
    }
}


