// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful


template <typename Iterator>
void my_selection_sort( Iterator begin, Iterator end) {

    Iterator minIt;
    Iterator it2;

    // First iteration
    for(Iterator it = begin; it != end; ++it)
    {
        minIt = it;
        it2 = it;
        ++it2;

        // Second iteration from first one to find the minimum
        for(; it2 != end; ++it2)
        {
            // If a minimum is find
            if(*it2 < *minIt)
                minIt = it2;
        }

        // swap the min to the it place
        auto temp = *it;
        *it = *minIt;
        *minIt = temp;
    }
}