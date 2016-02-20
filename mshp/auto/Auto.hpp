/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef AUTO_HPP_
#define AUTO_HPP_

#include <bits/stdc++.h>

enum SearchType {
    BY_NAME,
    BY_COLOR,
    BY_RELEASE_YEAR,
    BY_MAX_SPEED,
    BY_COST
};

typedef std::vector<std::string> Strings;
typedef std::vector<int> Ints;

class Auto {
public:
    Auto();

    Auto(
        const Strings& names,
        const Strings& colors,
        const Ints& release_years,
        const Ints& max_speeds,
        const Ints& costs
    );

    void printInfo(int ID) const;

    template<typename Element>
    void search(int search_type, const Element& el) const;

    ~Auto();

private:
    template<typename Element, typename List>
    void searchImplementation(
        const Element& el,
        const List& list
    ) const;

    Strings names_;
    Strings colors_;
    Ints release_years_;
    Ints max_speeds_;
    Ints costs_;
};

#endif
