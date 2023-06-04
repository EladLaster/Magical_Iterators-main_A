#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

TEST_CASE("test MagicalContainer and spacial iterators") {
    
    MagicalContainer container;
    MagicalContainer ::AscendingIterator ascending(container);
    MagicalContainer ::SideCrossIterator side(container);
    MagicalContainer ::PrimeIterator prime(container);

    // Test adding elements and size()
    
    CHECK(container.size() == 0);
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
    CHECK_THROWS(container.addElement(2)); 
    CHECK(container.size() == 4);

    // Test iterators
    
    unsigned int index = 0;
    for (auto itasc = ascending.begin(); itasc!=ascending.end();++itasc){
        CHECK(container.getElement(index)==*itasc);
        ++index;
    }

    index = 0;
    for (auto itside = side.begin(); itside != side.end(); ++itside) {
        CHECK(container.getElement(index)==*itside);
        ++index;
    }

    index = 0;
    for (auto itprime = prime.begin(); itprime!= prime.end(); ++itprime) {
        CHECK(container.getElement(index)==*itprime);
        ++index;
    }

    // Test copy constructor

    MagicalContainer containerCopy = container;
    MagicalContainer ::AscendingIterator ascending2(containerCopy);
    MagicalContainer ::SideCrossIterator side2(containerCopy);
    MagicalContainer ::PrimeIterator prime2(containerCopy);

    CHECK(containerCopy.size() == container.size());

    index = 0;
    for (auto itasc2 = ascending.begin(); itasc2!=ascending.end();++itasc2){
        CHECK(container.getElement(index)==*itasc2);
        ++index;
    }

    index = 0;
    for (auto itside2 = side.begin(); itside2 != side.end(); ++itside2) {
        CHECK(container.getElement(index)==*itside2);
        ++index;
    }

    index = 0;
    for (auto itprime2 = prime.begin(); itprime2!= prime.end(); ++itprime2) {
        CHECK(container.getElement(index)==*itprime2);
        ++index;
    }
    //check equality and non-equality of iterators that point different containers

    MagicalContainer container1;
    container1.addElement(2);
    container1.addElement(8);
    container1.addElement(3);
    container1.addElement(1);
    container1.addElement(9);

    MagicalContainer container2;
    container2.addElement(2);
    container2.addElement(8);
    container2.addElement(3);
    container2.addElement(1);
    container2.addElement(9);


    MagicalContainer ::AscendingIterator ascending3(container1);
    MagicalContainer ::AscendingIterator ascending4(container2);

    CHECK(ascending3 == ascending4);
    container1.addElement(19);
    
    MagicalContainer container3;
    container3.addElement(2);
    container3.addElement(8);
    container3.addElement(3);
    container3.addElement(1);
    container3.addElement(9);
    container3.addElement(19);
    MagicalContainer ::AscendingIterator ascending5(container3);

    CHECK(ascending3 != ascending5);

}
