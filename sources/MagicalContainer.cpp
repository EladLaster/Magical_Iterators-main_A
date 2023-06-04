#include <iostream>
#include <vector>
#include <cmath>
#include "MagicalContainer.hpp"

namespace ariel{

void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

void MagicalContainer::removeElement(int element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

int MagicalContainer::size() const {
        return elements.size();
    }

int MagicalContainer::getElement(unsigned int index) const {
    if (index < 0 || static_cast<std::vector<int>::size_type>(index) >= elements.size()) {
        throw std::out_of_range("Index out of range");
    }
    return elements[static_cast<std::vector<int>::size_type>(index)];
}

// AscendingIterator


bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &cont == &other.cont && index == other.index;
    }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return index > other.index;
    }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return index < other.index;
    }

int MagicalContainer::AscendingIterator::operator*() const {
        return cont.elements[static_cast<std::vector<int>::size_type>(index)];
    }

bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {
    return (*this > other) || (*this == other);
}

bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {
    return (*this < other) || (*this == other);
}



// SideCrossIterator

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return &cont == &other.cont && index == other.index;
    }

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return index > other.index;
    }

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return index < other.index;
    }

int MagicalContainer::SideCrossIterator::operator*() const {
        return cont.elements[static_cast<std::vector<int>::size_type>(index)];
    }


bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {
    return (*this > other) || (*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {
    return (*this < other) || (*this == other);
}

// PrimeIterator

bool MagicalContainer::PrimeIterator::isPrime(int num) const {
        if (num < 2)
            return false;
        for (int i = 2; i <= std::sqrt(num); ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &cont == &other.cont && index == other.index;
    }

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return index > other.index;
    }

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return index < other.index;
    }

int MagicalContainer::PrimeIterator::operator*() const {
        return cont.elements[static_cast<std::vector<int>::size_type>(index)];
    }


bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {
    return (*this > other) || (*this == other);
}

bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {
    return (*this < other) || (*this == other);
}

}
