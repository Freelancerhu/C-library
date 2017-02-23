#include <cassert>

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <list>

namespace F{
//Non-modifying sequence operations
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
    
    template <class InputIt, class T>
    InputIt find (InputIt first, InputIt last, const T& value){
        for(; first != last; ++first){
            if (*first == value)
                return first;
        }
        return last;
    }
    
    template <class InputIt, class UnaryPredicate>
    InputIt find_if( InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first){
            if (p(*first))
                return first;
        }
        return last;
    }
    
    template <class InputIt, class UnaryPredicate>
    InputIt find_if_not ( InputIt first, InputIt last, UnaryPredicate q) {
       for (; first != last; ++first){
           if (!q(*first)){
               return first;
           }
       }
        return last;
    }
    
    template <class ForwardIt1, class ForwardIt2>
    ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, 
                      ForwardIt2 s_first, ForwardIt2 s_last){
        for(; first != last; ++first){
            ForwardIt1 temp1 = first;
            ForwardIt2 temp2 = s_first;
            while(temp1 != last && temp2 != s_last && *temp1 == *temp2) {
                ++temp1;
                ++temp2;
            }
            if (temp2 == s_last)
                return first;
        }
        return last;
        
    }
    
    template <class ForwardIt1, class ForwardIt2, class BinaryPredicate>
    ForwardIt1 search (ForwardIt1 first, ForwardIt1 last,
                      ForwardIt2 s_first, ForwardIt2 s_last, BinaryPredicate p) {
        for(; first != last; ++first){
            ForwardIt1 temp1 = first;
            ForwardIt2 temp2 = s_first;
            while(temp1 != last && temp2 != s_last && p(*temp1, *temp2)){
                ++temp1;
                ++temp2;
            }
            if (temp2 == s_last)
                return first;
        }
        return last;
    }
    
    template <class ForwardIt1, class ForwardIt2>
    ForwardIt1 find_end (ForwardIt1 first, ForwardIt1 last, 
                         ForwardIt2 s_first, ForwardIt2 s_last) {
        if (s_first == s_last)
            return last;
        ForwardIt1 res = last;
        for (; ; ++first) {
            ForwardIt1 temp = search(first, last, s_first, s_last);
            if (temp == last) {
                return res;
            } else { 
                res = temp; 
                first = temp; 
            }
        }
        return res;
    }
    
    template <class ForwardIt1, class ForwardIt2, class BinaryPredicate>
    ForwardIt1 find_end (ForwardIt1 first, ForwardIt1 last, 
                        ForwardIt2 s_first, ForwardIt2 s_last, BinaryPredicate p) {
        if (s_first == s_last)
            return last;
        ForwardIt1 res = last;
        for (;; ++first) {
            ForwardIt1 temp = search(first, last, s_first, s_last, p);
            if (temp == last){
                return res;
            } else {
                res = temp;
                first = temp;
            }
        }
        return res;
    }
    
    template <class InputIt, class ForwardIt>
    InputIt find_first_of ( InputIt first, InputIt last,
                          ForwardIt s_first, ForwardIt s_last) {
        if (s_first == s_last){
            return last;
        }
        for(; first != last; ++first){
            for(; s_first != s_last; ++s_first){
                if( *first == *s_first){
                    return first;
                }
            }
        }
        return last;
    }
    
    template <class InputIt, class ForwardIt, class BinaryPredicate>
    InputIt find_first_of(InputIt first, InputIt last,
                         ForwardIt s_first, ForwardIt s_last, BinaryPredicate p){
        if (s_first == s_last){
            return last;
        }
        for(; first != last; ++first){
            for(; s_first != s_last; ++s_first){
                if(p(*first, *s_first)){
                    return first;
                }
            }
        }
        return last;
    }
    
    template <class ForwardIt>
    ForwardIt adjacent_find ( ForwardIt first, ForwardIt last) {
        if (first == last)
            return last;
        for(; first != last; ++first){
            ForwardIt temp = first;
            if (*temp == *(++temp))
                return first;
        }
        return last;
    }
    
    template <class ForwardIt, class BinaryPredicate>
    ForwardIt adjacent_find ( ForwardIt first, ForwardIt last,
                             BinaryPredicate p){
        if (first == last)
            return last;
        for(; first != last; ++first) {
            ForwardIt temp = first;
            if (p(*temp, *(++temp)))
                return first;
        }
        return last;
    }
    
    template <class ForwardIt, class Size, class T>
    ForwardIt search_n( ForwardIt first, ForwardIt last, Size count, const T& value) {
        if (first == last)
            return last;
        for (; first != last; ++first) {
            ForwardIt temp = first;
            Size tempCount = 0;
            while( temp != last && *temp == value && tempCount != count){
                ++tempCount;
                ++temp;
            }
            if( tempCount == count)
                return first;
        }
        return last;
    }
    
    template <class ForwardIt, class Size, class T, class BinaryPredicate>
    ForwardIt search_n (ForwardIt first, ForwardIt last, 
                        Size count, const T& value, BinaryPredicate v) {
        if (first == last)
            return last;
        for (; first != last; ++first){
            ForwardIt temp = first;
            Size tempCount = 0;
            while (temp != last && p(*first, value) && tempCount != count){//*first?
                ++temp;
                ++tempCount;
            }
            if(tempCount == count)
                return first;
        }
        return last;
    }
    
    
//Modifying sequence operations
    template <class InputIt, class OutputIt>
    OutputIt copy ( InputIt first, InputIt last, OutputIt d_first) {
        for (; first != last; ++first, ++d_first){
             *d_first = *first;
       }
        return d_first;
    }
    
    template < class InputIt, class OutputIt, class UnaryPredicate>
    OutputIt copy_if( InputIt first, InputIt last, OutputIt d_first,
                    UnaryPredicate pred) {
        for(; first != last; ++first) {
            if(pred(*first)){
                *d_first = *first;
                ++d_first;
            }
        }
        return d_first;
    }
    
    template <class InputIt, class Size, class OutputIt>
    OutputIt copy_n (InputIt first, Size count, OutputIt result) {
        for(; count > 0; --count, ++first, ++result){
            *result = *first;
        }
        return result;
    }
    
    template <class BidirIt1, class BidirIt2>
    BidirIt2 copy_backward (BidirIt1 first, BidirIt1 last, 
                            BidirIt2 d_last) {
        for(; first != last; ) {
            *--d_last = *(--last);
        }
        return d_last;
    }
    
    template <class InputIt, class OutputIt>
    OutputIt move ( InputIt first, InputIt last, OutputIt d_first) {
        for (; first != last; ++first)
            *d_first++ = std::move(*first);
        return d_first;
    }
    
    template <class BidirIt1, class BidirIt2>
    BidirIt2 move_backward ( BidirIt1 first, BidirIt1 last, BidirIt2 d_last) {
        for (; first != last; ) {
            *(--d_last) = std::move(*--last);
        }
        return d_last;
    }
    
    template <class ForwardIt, class T>
    void fill ( ForwardIt first, ForwardIt last, const T& value) {
        for(; first != last; ++first) {
            *first = value;
        }
    }
    
    template <class OutputIt, class Size, class T>
    void fill_n ( OutputIt first, Size count, const T& value) {
        for (; count > 0; ++first, --count) {
            *first = value;
        }
    }
    /*
    template <class OutputIt, class Size, class T>
    OutputIt fill_n ( OutputIt first, Size count, const T& value) {
        for (; count > 0; ++first, --count) {
            *first = value;
        }
        return first;
    }
    */
    
    template <class InputIt, class OutputIt, class UnaryOperation>
    OutputIt transform ( InputIt first1, InputIt last1, OutputIt d_first,
                       UnaryOperation unary_op) {
        for(; first1 != last1; ++first1) {
            *d_first = unary_op(*first1);
            ++d_first;
        }
        return d_first;
    }
    
    template <class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
    OutputIt transform ( InputIt1 first1, InputIt1 last1, InputIt2 first2,
                       OutputIt d_first, BinaryOperation binary_op) {
        for(; first1 != last1; ++first1, ++first2) {
            *d_first = binary_op(*first1, *first2);
            ++d_first;
        }
        return d_first;
    }
    
    template <class ForwardIt, class Generator>
    void generate ( ForwardIt first, ForwardIt last, Generator g) {
        for (; first != last; ++first) {
            *first = g();
        }
    }
    
    template <class OutputIt, class Size, class Generator>
    OutputIt generate_n (OutputIt first, Size count, Generator g) {
        for(; count > 0; --count, ++first) {
            *first = g();
        }
        return first;
    }
    
    template <class InputIt, class OutputIt, class T>
    OutputIt remove_copy ( InputIt first, InputIt last, OutputIt d_first,
                         const T& value) {
        for (; first != last; ++first) {
            if ( *first != value) {
                *d_first = *first;
                ++d_first;
            }
        }
        return d_first;
    }
    
    template <class InputIt, class OutputIt, class UnaryPredicate>
    OutputIt remove_copy_if (InputIt first, InputIt last, OutputIt d_first,
                            UnaryPredicate p) {
        for (; first != last; ++first) {
            if (!p(*first)){
                *d_first = *first;
                ++d_first;
            }
        }
        return d_first;
        
    }
    
    template <class T>
    void swap (T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
    
    template <class ForwardIt1, class ForwardIt2>
    ForwardIt2 swap_ranges ( ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2) {
        for(; first1 != last1; ++first1) {
            auto temp = *first1;
            *first1 = *first2;
            *first2 = temp;
            ++first2;
        }
        return first2;
    }
    
    template <class ForwardIt1, class ForwardIt2>
    void iter_swap(ForwardIt1 a, ForwardIt2 b) {
        auto temp = *a;
        *a = *b;
        *b = temp;
    }
    
    template <class BidirIt>
    void reverse ( BidirIt first, BidirIt last) {
        for (auto i = 0; i < (last - first)/2; ++i) {
            auto temp = *(first + i);
            *(first + i) = *((last - i) - 1);
            *((last - i) - 1) = temp;
        }
    }
    
    template <class BidirIt, class OutputIt>
    OutputIt reverse_copy(BidirIt first, BidirIt last, OutputIt d_first) {
        for(last -= 1; last >= first; --last) {
            *d_first = *last;
            ++d_first;
        }
        return d_first;
    }
    
    //template <class ForwardIt>
    //ForwardIt rotate( ForwardIt first, ForwardIt n_First, ForwardIt last) {
        
        
   // }
        
} // namespace F
//TODO : remove, remove_if swap_ranges(auto?) 





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
        while (current1 != last1 && current2 != last2 && *current1 == *current2) {
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
        while (current1 != last1 && current2 != last2 && p(*current1, *current2)) {
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
            auto result = X::search_n(vtr.cbegin(), vtr.cend(), 3, 6);
            assert(result == vtr.cbegin() + 6);
            
            result = X::search_n(vtr.cbegin(), vtr.cend(), 3, 6, binary_predicate);
            assert(result == vtr.cbegin() + 6);
        }
        
        { // begin
            auto result = X::search_n(vtr.cbegin(), vtr.cend(), 2, 1);
            assert(result == vtr.cbegin());
        }
        
        { // end
            auto result = X::search_n(vtr.cbegin(), vtr.cend(), 2, 8);
            assert(result == vtr.cend() - 2);
        }
        
        { // non existe
            auto result = X::search_n(vtr.cbegin(), vtr.cend(), 3, 8);
            assert(result == vtr.cend());
            
            result = X::search_n(vtr.cbegin(), vtr.cend(), 4, 6);
            assert(result == vtr.cend());
        }
        
        { // empty container
            std::vector<int> vtr;
            auto result = X::search_n(vtr.cbegin(), vtr.cend(), 1, 1);
            assert(result == vtr.cend());
        }
    }
    
    void test_search() {
        std::vector<int> vtr{1, 2, 3, 2, 3, 4, 5};
        auto binary_predicate = [](int x, int y){return x==y;};
        
        { // middle
            std::vector<int> vtr2{2, 3, 4};
            auto result = X::search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cbegin() + 3);
            
            result = X::search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend(), binary_predicate);
            assert(result == vtr.cbegin() + 3);
        }
        
        { // begin
            std::vector<int> vtr2{1, 2, 3};
            auto result = X::search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cbegin());
        }
        
        { // end
            std::vector<int> vtr2{2, 3, 4, 5};
            auto result = X::search(vtr.begin(), vtr.end(), vtr2.begin(), vtr2.end());
            assert(result == vtr.cbegin() + 3);
        }
        
        { // non existe
            std::vector<int> vtr2{1, 1};
            auto result = X::search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cend());
        }
        
        { // empty container
            std::vector<int> vtr2{};
            std::vector<int> vtr3{};
            
            auto result = X::search(vtr.cbegin(), vtr.cend(), vtr2.cbegin(), vtr2.cend());
            assert(result == vtr.cend());
            
            result = X::search(vtr2.cbegin(), vtr2.cend(), vtr3.cbegin(), vtr3.cend());
            assert(result == vtr2.cend());
            
            result = X::search(vtr2.cbegin(), vtr2.cend(), vtr2.cbegin(), vtr2.cend());
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
  //  test::test_all_of();
  //  test::test_none_of();
  //  test::test_any_of();
    
  //  test::test_search_n();
    
    
    
    std::vector<int> A = {0,1,2,3,4,5,6};
    std::vector<int> B;
    F::copy(A.begin(), A.end(), std::back_inserter(B));
    
    F::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::string in = "1234567890";
    std::string out;
    F::copy_n(in.begin(), 4, std::back_inserter(out));
    std::cout << out << std::endl;
    
    std::vector<int> C(15);
    F::copy_backward(A.begin(), A.end(), C.end());
    for ( auto x : C)
        std::cout << x << std::endl;
    
    
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    F::fill_n(v1.begin(), 5, -1);
 
    std::copy(begin(v1), end(v1), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    std::string s("hello");
    F::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << s << std::endl;
    
    std::vector<int> v(5);
    int n = {0};
    F::generate_n(v.begin(), 3, [&n]{ return n++; });
 
    std::cout << "v: ";
    for (auto iv: v) {
        std::cout << iv << " ";
    }
    
    std::string str = "Text with some   spaces";
    std::cout << "before: " << str << "\n";
 
    std::cout << "after:  ";
    F::remove_copy(str.begin(), str.end(),
                     std::ostream_iterator<char>(std::cout), ' ');
    std::cout << '\n';

    int a = 5, b = 3;

    // before
    std::cout << a << ' ' << b << '\n';

    F::swap(a,b);

    // after
    std::cout << a << ' ' << b << '\n';
    
     std::vector<int> t = {1, 2, 3, 4, 5};
    std::list<int> l = {-1, -2, -3, -4, -5};
 
    F::swap_ranges(t.begin(), t.begin()+3, l.begin());
 
    for(int n : t)
       std::cout << n << ' ';
    std::cout << '\n';
    for(int n : l)
       std::cout << n << ' ';
    std::cout << '\n';
    
    
    int q[] = {4, 5, 6, 7};
    F::reverse(std::begin(q), std::end(q));
    std::cout << q[0] << q[1] << q[2] << q[3] << '\n';
    
    std::vector<int> w({1,2,3});
    for (const auto& value : w) {
        std::cout << value << " ";
    }
    std::cout << '\n';
 
    std::vector<int> destination(3);
    F::reverse_copy(std::begin(w), std::end(w), std::begin(destination));
    for (const auto& value : destination) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    return 0;
}











