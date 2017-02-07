/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "Auto.hpp"

const Strings dummy_strings;
const Ints dummy_ints;

Auto::Auto()
    : names_(dummy_strings)
    , colors_(dummy_strings)
    , release_years_(dummy_ints)
    , max_speeds_(dummy_ints)
    , costs_(dummy_ints)
{
}

Auto::Auto(
    const Strings& names,
    const Strings& colors,
    const Ints& release_years,
    const Ints& max_speeds,
    const Ints& costs
)
    : names_(names)
    , colors_(colors)
    , release_years_(release_years)
    , max_speeds_(max_speeds)
    , costs_(costs)
{
}

void Auto::printInfo(int ID) const {
    std::cout << "***" << names_[ID] << "***" << std::endl;
    std::cout << "Parameters: " << std::endl;
    std::cout << "* Color " << colors_[ID] << std::endl;
    std::cout << "* Release year " << release_years_[ID] << std::endl;
    std::cout << "* Maximum speed " << max_speeds_[ID] << std::endl;
    std::cout << "* Cost " << costs_[ID] << std::endl;
}

template<typename Element, typename List>
void Auto::searchImplementation(
    const Element& el,
    const List& list
) const {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == el) {
            printInfo(i);
        }
    }
}

template<typename Element>
void Auto::search(int search_type, const Element& el) const {
    // dummy
}

#define CASE(search_type, param) \
    case search_type: \
        searchImplementation(el, param); \
        break;

template<>
void Auto::search<int>(int search_type, const int& el) const {
    switch (search_type) {
        CASE(BY_RELEASE_YEAR, release_years_);
        CASE(BY_MAX_SPEED, max_speeds_);
        CASE(BY_COST, costs_);
    }
}

template<>
void Auto::search<std::string>(
    int search_type,
    const std::string& el
) const {
    switch (search_type) {
        CASE(BY_NAME, names_);
        CASE(BY_COLOR, colors_);
    }
}

#undef CASE

template
void Auto::search<int>(int, const int&) const;

template
void Auto::search<std::string>(int, const std::string&) const;

Auto::~Auto() {
}
