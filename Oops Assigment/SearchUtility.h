#ifndef SEARCH_UTILITY_H
#define SEARCH_UTILITY_H

#include <vector>
#include <algorithm>

using namespace std;

// Generic template function to search for pointer items within a vector using a custom condition
template <typename T, typename Predicate>
T* findItem(const vector<T*>& items, Predicate pred) {
    // auto ki jagah compiler ke liye exact iterator type likhi hai
    typename vector<T*>::const_iterator it = find_if(items.begin(), items.end(), pred);
    
    if (it != items.end()) {
        return *it;
    }
    return NULL; // nullptr ki jagah NULL use kiya hai
}

#endif
