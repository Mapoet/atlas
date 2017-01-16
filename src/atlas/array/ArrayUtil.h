/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an size_tergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#pragma once

#include "atlas/array/ArrayShape.h"
#include "atlas/array/ArrayStrides.h"
#include "atlas/array/ArrayLayout.h"
#include "atlas/array/ArrayIdx.h"
#include "atlas/array/ArraySpec.h"

//------------------------------------------------------------------------------------------------------

namespace atlas {
namespace array {

template<typename T> struct remove_const          { typedef T type; };
template<typename T> struct remove_const<T const> { typedef T type; };

template<typename T> struct add_const          { typedef const typename remove_const<T>::type type; };
template<typename T> struct add_const<T const> { typedef const T type; };

class ArrayDataStore
{
public:
  virtual ~ArrayDataStore() {}
  virtual void clone_to_device() const = 0;
  virtual void clone_from_device() const = 0;
  virtual bool valid() const = 0;
  virtual void sync() const = 0;
  virtual bool is_on_host() const = 0;
  virtual bool is_on_device() const = 0;
  virtual void reactivate_device_write_views() const = 0;
  virtual void reactivate_host_write_views() const = 0;
  virtual void* void_data_store() = 0;
};

//------------------------------------------------------------------------------------------------------

} // namespace array
} // namespace atlas
