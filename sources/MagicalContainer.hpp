#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
namespace ariel{

class MagicalContainer {
private:
    vector<int> elements;

public:

    MagicalContainer() = default;
    ~MagicalContainer() = default;
    void addElement(int elem);
    void removeElement(int elem);
    int size() const;
    int getElement(unsigned int index) const;

    // ------------------ tidy -------------------

    MagicalContainer(const MagicalContainer& other) = default;
    MagicalContainer& operator=(const MagicalContainer& other) = default;
    MagicalContainer(MagicalContainer&& other) = default;
    MagicalContainer& operator=(MagicalContainer&& other) = default;

    // AscendingIterator
    class AscendingIterator {
    private:
        MagicalContainer& cont;
        vector<int>::size_type index;

    public:
        AscendingIterator(MagicalContainer& cont) : cont(cont), index(0) {}

        AscendingIterator(const AscendingIterator& other) : cont(other.cont), index(other.index) {}

        ~AscendingIterator() = default;


        bool operator==(const AscendingIterator& other) const;

        bool operator!=(const AscendingIterator& other) const;

        bool operator>(const AscendingIterator& other) const;

        bool operator<(const AscendingIterator& other) const;

        bool operator>=(const AscendingIterator& other) const;

        bool operator<=(const AscendingIterator& other) const;

        int operator*() const;


        AscendingIterator& operator=(const AscendingIterator& other) {
            if (this != &other) {
                cont = other.cont;
                index = other.index;
            }
            return *this;
        }
        AscendingIterator& operator++() {
            ++index;
            return *this;
        }
        AscendingIterator begin() {
        return AscendingIterator(cont);
        }

        AscendingIterator end() {
                AscendingIterator iterator(cont);
                iterator.index = cont.elements.size();
                return iterator;
        }

    };

    

    // SideCrossIterator
    class SideCrossIterator {
    private:
        MagicalContainer& cont;
        vector<int>::size_type index;

    public:
        SideCrossIterator(MagicalContainer& cont) : cont(cont), index(0){}

        SideCrossIterator(const SideCrossIterator& other) : cont(other.cont), index(other.index){}
       
        ~SideCrossIterator() = default;

        bool operator==(const SideCrossIterator& other) const;

        bool operator!=(const SideCrossIterator& other) const;

        bool operator>(const SideCrossIterator& other) const;

        bool operator<(const SideCrossIterator& other) const;

        bool operator>=(const SideCrossIterator& other) const;

        bool operator<=(const SideCrossIterator& other) const;

        int operator*() const;

        SideCrossIterator& operator=(const SideCrossIterator& other) {
            if (this != &other) {
                cont = other.cont;
                index = other.index;
            }
            return *this;
        }
        SideCrossIterator& operator++() {
            index ++;
            return *this;
        }
    
        SideCrossIterator begin() {
            return SideCrossIterator(cont);
        }

        SideCrossIterator end() {
                SideCrossIterator iterator(cont);
                iterator.index = cont.elements.size();
                return iterator;
        }
        
    };

    // PrimeIterator
    class PrimeIterator {
    private:
        MagicalContainer& cont;
        vector<int>::size_type index;
        bool isPrime(int num) const;

    public:
        PrimeIterator(MagicalContainer& cont) : cont(cont), index(0) {
            while (index < cont.size() && !isPrime(cont.elements[index])){
                ++index;
            }
        }

        PrimeIterator(const PrimeIterator& other) : cont(other.cont), index(other.index) {}

        ~PrimeIterator() = default;

        bool operator==(const PrimeIterator& other) const;

        bool operator!=(const PrimeIterator& other) const;

        bool operator>(const PrimeIterator& other) const;

        bool operator<(const PrimeIterator& other) const;

        bool operator>=(const PrimeIterator& other) const;

        bool operator<=(const PrimeIterator& other) const;

        int operator*() const;

        PrimeIterator& operator=(const PrimeIterator& other) {
            if (this != &other) {
                cont = other.cont;
                index = other.index;
            }
            return *this;
        }

        PrimeIterator& operator++() {
            do {
                ++index;
            } while (index < cont.size() && !isPrime(cont.elements[index]));
            return *this;
        }

        PrimeIterator begin() {
            return PrimeIterator(cont);
        }

        PrimeIterator end() {
                PrimeIterator iterator(cont);
                iterator.index = cont.elements.size();
                return iterator;
        }

    };
};

}