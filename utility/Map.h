/*
 *  Map.h
 *  SNAPDRAGON
 *
 *  Created by Paul Hansen on 6/14/06.
 *  Copyright 2007 Stanford University. All rights reserved.
 *
 *  This file is covered by the MIT license.  See LICENSE.txt.
 *
 */

#ifndef _MAP_
#define _MAP_

#include <map>
#include <cassert>

template <typename Key, typename Value>
class Map : public std::map<Key, Value>
{
public:
    Map();
    virtual ~Map();
    
    Map(const std::map<Key, Value> & rhs);
    Map<Key, Value> & operator=(const std::map<Key, Value> & rhs);
    
    template<typename Key2>
    const Value& operator[] (const Key2& key) const;
    
    template<typename Key2>
    Value& operator[] (const Key2& key);
};


template <typename Key, typename Value>
Map<Key, Value> ::
Map()
{
}

template <typename Key, typename Value>
Map<Key, Value> ::
~Map()
{
}

template <typename Key, typename Value>
Map<Key, Value> ::
Map(const std::map<Key, Value> & rhs) :
    std::map<Key, Value>(rhs)
{
}

template <typename Key, typename Value>
Map<Key, Value> & Map<Key, Value>::
operator=(const std::map<Key, Value> & rhs)
{
    *this = rhs;
    return *this;
}

template <typename Key, typename Value>
template <typename Key2>
const Value& Map<Key, Value>::
operator[] (const Key2& key) const
{
    assert( this->count(Key(key)) != 0 );
    return (this->find(Key(key)))->second;
}

template <typename Key, typename Value>
template <typename Key2>
Value& Map<Key, Value>::
operator[] (const Key2& key)
{
    return std::map<Key, Value>::operator[](Key(key));
}





#endif

