#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

TEST_CASE("test MagicalContainer and spacial iterators") {
    
    MagicalContainer container;
    MagicalContainer ::AscendingIterator ascending(container);
    MagicalContainer ::SideCrossIterator side(container);
    MagicalContainer ::PrimeIterator prime(container);
    

    CHECK(container.size() == 0);

    // Test adding elements and size()    
    CHECK_NOTHROW(container.addElement(5));
    container.addElement(2);
    container.addElement(3);
    container.addElement(17);
    container.addElement(6);
    container.addElement(7);
    CHECK(container.size() == 6);

    // Test get element
    CHECK_NOTHROW(container.getElement(0));

    // Test removing elements
    CHECK_NOTHROW(container.removeElement(2));
    container.removeElement(3);
    CHECK(container.size() == 4);
    
    // Trying to remove a non-existent element
    CHECK_THROWS(container.removeElement(10)); 
    CHECK(container.size() == 4);

    // Trying to add the same integers twice
    // CHECK_THROWS(container.addElement(2)); 
    // CHECK(container.size() == 4);

    // Test iterators
    unsigned int index = 0;
    for (auto itasc = ascending.begin(); itasc!=ascending.end();++itasc){
        CHECK(container.getElement(index)==*itasc);
        ++index;
    }


    auto itside = side.begin();
    CHECK(container.getElement(0)==*itside); //first one
    ++itside;
    CHECK(container.getElement(1)==*itside); // last one
    ++itside;
    CHECK(container.getElement(3)==*itside); // one after first one
    ++itside;   
    CHECK(container.getElement(2)==*itside); // one before last one


    auto itprime = prime.begin();
    CHECK(container.getElement(0)==*itprime); // 5 is prime
    ++itprime;
    CHECK(container.getElement(1)==*itprime); // 17 is prime
    ++itprime;
    CHECK(container.getElement(3)==*itprime); // 7 is prime

    // Test copy constructor

    MagicalContainer containerCopy = container;
    MagicalContainer ::AscendingIterator ascending2(containerCopy);
    MagicalContainer ::SideCrossIterator side2(containerCopy);
    MagicalContainer ::PrimeIterator prime2(containerCopy);

    CHECK(containerCopy.size() == container.size());

    index = 0;
    for (auto itasc2 = ascending2.begin(); itasc2!=ascending2.end();++itasc2){
        CHECK(container.getElement(index)==*itasc2);
        ++index;
    }

    auto itside2 = side2.begin();
    CHECK(container.getElement(0)==*itside2); //first one
    ++itside2;
    CHECK(container.getElement(1)==*itside2); // last one
    ++itside2;
    CHECK(container.getElement(3)==*itside2); // one after first one
    ++itside2;   
    CHECK(container.getElement(2)==*itside2); // one before last one


    auto itprime2 = prime2.begin();
    CHECK(container.getElement(0)==*itprime2); // 5 is prime
    ++itprime2;
    CHECK(container.getElement(1)==*itprime2); // 17 is prime
    ++itprime2;
    CHECK(container.getElement(3)==*itprime2); // 7 is prime


    //check equality and non-equality of iterators

        MagicalContainer::AscendingIterator id(container);
        auto it1 =id.begin();

        MagicalContainer::AscendingIterator id1(container);
        auto it2 =id1.begin();

        MagicalContainer::AscendingIterator id2(container);
        auto it3 =id2.end();

        CHECK(it1 == it2);
        CHECK(it1 != it3);
        CHECK(it2 != it3);
        ++it1;
        CHECK(it1 != it2);
        CHECK(it2 != it3);

        while (it1 != it1.end()) 
            ++it1;
        
        CHECK(it1 == it3);

        while (it2 != it2.end()) 
            ++it2;
        
        CHECK(it2 == it3);

}
