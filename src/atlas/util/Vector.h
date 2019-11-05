/*
 * (C) Copyright 2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#pragma once

#include "atlas/library/config.h"
#include "atlas/runtime/Exception.h"

namespace atlas {

template< typename T >
class vector {
public:
    using iterator = T*;
    using const_iterator = T const*;
    vector() : data_( nullptr ), size_( 0 ) {}
    vector( idx_t N ) : data_( new T[N] ), size_( N ) {}
    vector( idx_t N, const T& value ) : vector(N) {
        for( idx_t i=0; i<size_; ++i ) {
            data_[i] = value;
        }
    }
    vector( vector&& other ) : data_( other.data_ ), size_( other.size_ ) {
        other.data_ = nullptr;
        other.size_ = 0;
    }
    ~vector() {
        if( data_ ) {
          delete[] data_;
        }
    }
    T& at(idx_t i) { return data_[i]; }
    T const& at(idx_t i) const { return data_[i]; }
    T& operator[](idx_t i) { return data_[i]; }
    T const& operator[](idx_t i) const { return data_[i]; }
    const T* data() const { return data_; }
    T* data() { return data_; }
    idx_t size() const { return size_; }
    template< typename Iter >
    void assign( const Iter& begin, const Iter& end ) {
        ATLAS_NOTIMPLEMENTED;
    }
    const_iterator begin() const { return data_; }
    const_iterator end() const { return data_+size_; }
    iterator begin() { return data_; }
    iterator end() { return data_+size_; }
    const_iterator cbegin() const { return data_; }
    const_iterator cend() const { return data_+size_; }
private:
    T* data_;
    idx_t size_;
};

}  // namespace atlas
