#include <cassert>

#include <iterator>
#include <random>
#include <utility>
#include <vector>

namespace F{
template < class InputIt, class UnaryPredicate>
    bool all_of( InputIt first, InputIt last, UnaryPredicate p){
        for(; first != last; ++first){
            if(*first != p){
                return false;
            }
        }
        return true;
    }

    template <class InputIt, class UnaryPredicate>
    bool any_of( InputIt first, InputIt last, UnaryPredicate p){
        for(; first != last; ++first){
            if(*first == p)
                return true;
        }
        return false;
    }

    template <class InputIt, class UnaryPredicate>
    bool none_of( InputIt first, InputIt last, UnaryPredicate p){
        for(; first != last; ++first){
            if(*first == p)
                return false;
        }
        return true;
    }

    template <class InputIt, class UnaryFunction>
    UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f){
        for(; first != last; ++first)
            f(*first);
        return f;
    }

    template <class InputIt, class T>
    typename std::iterator_traits<InputIt>::difference_type
        count( InputIt first, InputIt last, const T &value) {
        auto current = 0;
        for(; first != last; ++first){
            if(*first == value){
                ++current;
            }
        }
        return current;
    }
    
    template <class InputIt, class UnaryPredicate>
    typename std::iterator_traits<InputIt>::difference_type
        count_if( InputIt first, InputIt last, UnaryPredicate p){
        auto current = 0;
        for(; first != last; ++first){
            if(p(*first) == true){
                ++current;
            }
        }
        return current;
    }
    
    template <class InputIt1, class InputIt2>
    std::pair<InputIt1, InputIt2> mismatch( InputIt1 first1, InputIt1 last1, InputIt2 first2) {
        for (; first1 != last1, first2 != first2 + (last1 - first1); ++first1, ++first2) {
            if (*first1 != *first2)
                return std::make_pair(first1, first2);
        }
        //return std::make_pair(first1, first2);
        return {first1, first2};
    }
    
    
    template <class InputIt1, class InputIt2, class BinaryPredicate>
    std::pair<InputIt1, InputIt2> mismatch( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
        for (; first1 != last1, first2 != first2 + (last1 - first1); ++first1, ++first2) {
            if(p(*first1, *first2) != true)
                return std::make_pair(first1, first2);
        }
        return std::make_pair(first1, first2);
    }
    
    template <class InputIt1, class InputIt2> 
        bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
        for (; first1 != last1, first2 != first2 + (last1 - first1); ++first1, ++first2) {
            if( *first1 != *first2)
                return false;
        }
        return true;
    }
    
    template <class InputIt1, class InputIt2, class BinaryPredicate>
        bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate P) {
        for (; first1 != last1, first2 != first2 + (last1 - first1); ++first1, ++first2) {
            if( !p(*first1, *first2))
                return false;
        }
        return true;
        
    }
    
} // namespace F



namespace X {
template <class ForwardIterator, class Size, class T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T &val) {
    for (; first != last; ++first) {
        auto current = first;
        while (current != last && *current == val && current-first<count)
            ++current;
        if (current-first == count)
            return first;
    }
    return last;
}
    
template <class ForwardIterator, class Size, class T, class BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T &val,
                          BinaryPredicate p) {
    for (; first != last; ++first) {
        auto current = first;
        while (current != last && p(*first, val) && current-first<count)
            ++current;
        if (current-first == count)
            return first;
    }
    return last;
}
    
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2) {
    for (; first1 != last1; ++first1) {
        auto current1 = first1;
        auto current2 = first2;
        while (current1 != last1 && current2!=last2 && *current1 == * current2) {
            ++current1;
            ++current2;
        }
        
        if (current2 == last2)
            return first1;
    }
    return last1;
}
    
template <class ForwardIterator1, class ForwardIterator2, class UnaryPredicate>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2,
                        UnaryPredicate p) {
    for (; first1 != last1; ++first1) {
        auto current1 = first1;
        auto current2 = first2;
        while (current1 != last1 && current2!=last2 && p(*current1, *current2)) {
            ++current1;
            ++current2;
        }
        
        if (current2 == last2)
            return first1;
    }
    return last1;
}

template <class ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last) {
    if (first == last)
        return last;
    
    for (auto next = std::next(first); next!=last; ++next, ++first)
        if (*next == *first)
            return first;
    return last;
}
    
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, UnaryPredicate p) {
    if (first == last)
        return last;
    
    for (auto next = std::next(first); next!=last; ++next, ++first)
        if (p(*next, *first))
            return first;
    return last;
}
    
template <class InputIterator, class ForwardIterator>
ForwardIterator find_first_of(InputIterator first1, InputIterator last1,
                               ForwardIterator first2, ForwardIterator last2) {
    for (; first1 != last1; ++first1)
        for (auto current = first2; current != last2; ++current)
            if (*first1 == *current)
                return first1;
    return last1;
}
    
template <class InputIterator, class ForwardIterator, class BinaryPredicate>
ForwardIterator find_first_of(InputIterator first1, InputIterator last1,
                               ForwardIterator first2, ForwardIterator last2,
                               BinaryPredicate p) {
    for (; first1 != last1; ++first1)
        for (auto current = first2; current != last2; ++current)
            if (p(*first1, *current))
                return first1;
    return last1;
}
    
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
                          ForwardIterator2 first2, ForwardIterator2 last2) {
    auto result1 = search(first1, last1, first2, last2);
    while (result1 != last1) {
        auto end = result1;
        std::advance(end, last2-first2);
        
        auto result2 = search(end, last1, first2, last2);
        if (result2 == last1)
            return result1;
        result1 = result2;
    }
    
    return last1;
}
    
template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
                          ForwardIterator2 first2, ForwardIterator2 last2,
                          BinaryPredicate p) {
    auto result1 = search(first1, last1, first2, last2, p);
    while (result1 != last1) {
        auto end = result1;
        std::advance(end, last2-first2);
        
        auto result2 = search(end, last1, first2, last2, p);
        if (result2 == last1)
            return result1;
        result1 = result2;
    }
    
    return last1;
}
    
} // namespace X


namespace test {
    using namespace X;
    using namespace F;
    
    void test_search_n() {
        std::vector<int> vtr{1,1,2,3,4,5,6,6,6,7,8,8};
        auto binary_predicate = [](int x, int y){return x==y;};
        
        { // middle
            auto result = search_n(vtr.cbegin(), vtr.cend(), 3, 6);
            assert(result == vtr.cbegin() + 6);
            
            result = search_n(vtr.cbegin(), vtr.cend(), 3, 6, binary_predicate);
            assert(result == vtr.cbegin() + 6);
        }
        
        { // begin
            auto result = search_n(vtr.cbegin(), vtr.cend(), 2, 1);
            assert(result == vtr.cbegin());
        }
        
        { // end
            auto result = search_n(vtr.cbegin(), vtr.cend(), 2, 8);
            assert(result == vtr.cend() - 2);
        }
        
        { // non existe
            auto result = search_n(vtr.cbegin(), vtr.cend(), 3, 8);
            assert(result == vtr.cend());
            
            result = search_n(vtr.cbegin(), vtr.cend(), 4, 6);
            assert(result == vtr.cend());
        }
        
        { // empty container
            std::vector<int> vtr;
            auto result = search_n(vtr.cbegin(), vtr.cend(), 1, 1);
            assert(result == vtr.cend());
        }
    }
    
    void test_search() {
        std::vector<int> vtr{1, 2, 3, 2, 3, 4, 5};
        auto binary_predicate = [](int x, int y){return x==y;};
        
        { // middle
            std::vector<int> vtr2{2, 3, 4};
            auto result = search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cbegin() + 3);
            
            result = search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend(), binary_predicate);
            assert(result == vtr.cbegin() + 3);
        }
        
        { // begin
            std::vector<int> vtr2{1, 2, 3};
            auto result = search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cbegin());
        }
        
        { // end
            std::vector<int> vtr2{2, 3, 4, 5};
            auto result = search(vtr.begin(), vtr.end(), vtr2.begin(), vtr2.end());
            assert(result == vtr.cbegin() + 3);
        }
        
        { // non existe
            std::vector<int> vtr2{1, 1};
            auto result = search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cend());
        }
        
        { // empty container
            std::vector<int> vtr2{};
            std::vector<int> vtr3{};
            
            auto result = search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cend());
            
            result = search(vtr2.cbegin(), vtr2.cend(), vtr3.cbegin(), vtr3.cend());
            assert(result == vtr2.cend());
            
            result = search(vtr2.cbegin(), vtr2.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr2.cend());
        }
    }
    
    void test_all_of() {
        using namespace F;
        std::vector<int> vtr{3,3,3,3,3,3};
        
        { // true
            auto res = all_of(vtr.cbegin(), vtr.cend(), 3);
            assert(res == true);
        }
        
        { // false
            auto res = all_of(vtr.cbegin(), vtr.cend(), 2);
            assert(res == false);
        }
    }
    
    void test_any_of() {
        using namespace F;
        std::vector<int> vtr{1,2,3,4,5,6};
        
        { // true
            auto res = any_of(vtr.cbegin(), vtr.cend(), 3);
            assert(res == true);
        }
        
        { // false
            auto res = any_of(vtr.cbegin(), vtr.cend(), 7);
            assert(res == false);
        }
    }
    
    void test_none_of() {
        using namespace F;
        std::vector<int> vtr{1,2,3,4,5,6};
        
        { // true
            auto res = none_of(vtr.cbegin(), vtr.cend(), 7);
            assert(res == true);
        }
        
        { // false
            auto res = none_of(vtr.cbegin(), vtr.cend(), 3);
            assert(res == false);
        }
    }
    
    
}




int main() {
    test::test_all_of();
    test::test_none_of();
    test::test_any_of();
    
    test::test_search_n();
    return 0;
}







































