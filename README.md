MultiSet of generic elements T. A MultiSet is like a data set that can contain duplicates: e.g., S={1,4,6,4,9,4,7,10,12}. The MultiSet is implemented in such a way as to minimize memory usage i.e., you do not have to store duplicates of an element. Referring to the previous example, '4' is stored only once knowing, however, that there are three occurrences of '4' in S.
Apart from the essential methods for the class (including knowing the total number of elements, adding/removing elements, counting occurrences of an element, etc...), the following features have been implemented:
1. The construction of a MultiSet also from a sequence of generic data Q identified by a pair of generic iterators. This constructor takes as input: the start sequence iterator, the end sequence iterator. Leave it to the compiler to handle the data conversion between Q and T.
2. A read-only iterator (choose category) that returns a <value, occurrences> pair The iterator must return all elements of the MultiSet. That is, duplicates must be returned in the correct number. In the example case of S it could be a sequence of values like: 1 4 4 6 9 7 10 12
3. The comparison operator== between two MultiSets that returns true sif the two MultiSets (of the same type) contain the same elements with the same number of occurrences of duplicates.
4. The contains method that, given an element of type T, returns true if the element exists in the MultiSet.
5. The global operator<< function to send on std::ostream the contents of the MultiSet in the form: {<X1, occurrencesX1>, <X2, occurrencesX2>,...,<XN, occurrencesXN>}

- The order of the elements in the MultiSet is not relevant.
- Removal of an element X occurs when the number of occurrences of that element becomes zero.
- Elements in the MultiSet are immutable. Once inserted, they do not change value.
