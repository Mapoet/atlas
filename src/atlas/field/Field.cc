/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <typeinfo>
#include <sstream>
#include <stdexcept>
#include "eckit/exception/Exceptions.h"
#include "eckit/memory/ScopedPtr.h"
#include "atlas/grid/Grid.h"
#include "atlas/mesh/Mesh.h"
#include "atlas/field/Field.h"
#include "atlas/field/FieldCreator.h"
#include "atlas/functionspace/FunctionSpace.h"
#include "atlas/runtime/ErrorHandling.h"


namespace atlas {
namespace field {

// -------------------------------------------------------------------------
// Static functions

Field* Field::create(const eckit::Parametrisation& params)
{
  std::string creator_factory;
  if( params.get("creator",creator_factory) )
  {
    eckit::ScopedPtr<field::FieldCreator> creator
        (field::FieldCreatorFactory::build(creator_factory,params) );
    return creator->create_field(params);
  }
  else
    throw eckit::Exception("Could not find parameter 'creator' "
                           "in Parametrisation for call to Field::create()");

  return 0;
}

Field* Field::create(
    const std::string& name,
    array::DataType           datatype,
    const array::ArrayShape&  shape)
{
  return new Field(name,datatype,shape);
}

Field* Field::create( const std::string& name, array::Array* array )
{
  return new Field(name,array);
}

// -------------------------------------------------------------------------

Field::Field(
    const std::string& name,
    array::DataType           datatype,
    const array::ArrayShape&  shape) :
  name_(name),
  nb_levels_(0)
{
  functionspace_ = new functionspace::NoFunctionSpace();
  functionspace_->attach();
  array_ = array::Array::create(datatype,shape);
  array_->attach();
}


Field::Field(const std::string& name, array::Array* array):
  name_(name), nb_levels_(0)
{
  functionspace_ = new functionspace::NoFunctionSpace();
  functionspace_->attach();
  array_ = array;
  array_->attach();
}

Field::~Field()
{
  functionspace_->detach();
  if( functionspace_->owners() == 0 )
    delete functionspace_;

  array_->detach();
  if( array_->owners() == 0 )
    delete array_;
}

void Field::dump(std::ostream& os) const
{
  print(os);
  array_->dump(os);
}

namespace {

template< typename T >
std::string vector_to_str(const std::vector<T>& t)
{
  std::stringstream s;
  s << '[';
  for(size_t i = 0; i < t.size(); i++) {
      if (i != 0)
          s << ',';
      s << t[i];
  }
  s << ']';
  return s.str();
}


}

void Field::print(std::ostream& os) const
{
  os << "Field[name=" << name()
     << ",datatype=" << datatype().str()
     << ",size=" << size()
     << ",shape=" << vector_to_str( shape() )
     << ",strides=" << vector_to_str( strides() )
     << ",bytes=" << bytes()
     << ",metadata=" << metadata()
     << "]";
}

std::ostream& operator<<( std::ostream& os, const Field& f)
{
  f.print(os);
  return os;
}

void Field::resize(const array::ArrayShape& shape)
{
    array_->resize(shape);
}

void Field::insert(size_t idx1, size_t size1 )
{
    array_->insert(idx1,size1);
}


void Field::set_functionspace(const functionspace::FunctionSpace &functionspace)
{
  functionspace_->detach();
  if( functionspace_->owners() == 0 )
    delete functionspace_;

  functionspace_ = const_cast<functionspace::FunctionSpace*>(&functionspace);

  // In case functionspace is not attached, increase owners, so that
  // this field will not manage its lifetime.
  if( functionspace_->owners() == 0 ) functionspace_->attach();

  functionspace_->attach();
}


template <> const float* Field::data() const
{
  try {
    return array_->data<float>();
  } catch( const eckit::BadCast& e ) {
    std::stringstream msg;
    msg << "Could not cast data for field " << name()
        << " with datatype " << array_->datatype().str() << " to "
        << array::DataType::str<float>();
    throw eckit::BadCast(msg.str(),Here());
  }
  return 0;
}
template <> float* Field::data()
{
  return const_cast<float*>(const_cast<const Field&>(*this).data<float>());
}

template <> const double* Field::data() const
{
  try {
    return array_->data<double>();
  } catch( const eckit::BadCast& e ) {
    std::stringstream msg;
    msg << "Could not cast data for field " << name()
        << " with datatype " << array_->datatype().str() << " to "
        << array::DataType::str<double>();
    throw eckit::BadCast(msg.str(),Here());
  }
  return 0;
}
template <> double* Field::data()
{
  return const_cast<double*>(const_cast<const Field&>(*this).data<double>());
}

template <> const int* Field::data() const
{
  try {
    return array_->data<int>();
  } catch( const eckit::BadCast& e ) {
    std::stringstream msg;
    msg << "Could not cast data for field " << name()
        << " with datatype " << array_->datatype().str() << " to "
        << array::DataType::str<int>();
    throw eckit::BadCast(msg.str(),Here());
  }
  return 0;
}
template <> int* Field::data()
{
  return const_cast<int*>(const_cast<const Field&>(*this).data<int>());
}

template <> const long* Field::data() const
{
  try {
    return array_->data<long>();
  } catch( const eckit::BadCast& e ) {
    std::stringstream msg;
    msg << "Could not cast data for field " << name()
        << " with datatype " << array_->datatype().str() << " to "
        << array::DataType::str<long>();
    throw eckit::BadCast(msg.str(),Here());
  }
  return 0;
}
template <> long* Field::data()
{
  return const_cast<long*>(const_cast<const Field&>(*this).data<long>());
}


// ------------------------------------------------------------------
// C wrapper interfaces to C++ routines

Field* atlas__Field__create(eckit::Parametrisation* params)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(params);
    Field* field = Field::create(*params);
    ASSERT(field);
    return field;
  );
  return 0;
}

void atlas__Field__delete (Field* This)
{
  delete This;
}

const char* atlas__Field__name (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return This->name().c_str();
  );
  return 0;
}

void atlas__Field__datatype (Field* This, char* &datatype, int &size, int &allocated)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    std::string s = This->datatype().str();
    size = s.size()+1;
    datatype = new char[size];
    strcpy(datatype,s.c_str());
    allocated = true;
  );
}

int atlas__Field__size (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return This->size();
  );
  return 0;
}

int atlas__Field__rank (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return This->rank();
  );
  return 0;
}

int atlas__Field__kind (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return This->datatype().kind();
  );
  return 0;
}


double atlas__Field__bytes (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return This->bytes();
  );
  return 0;
}

int atlas__Field__levels (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return This->levels();
  );
  return 0;
}

util::Metadata* atlas__Field__metadata (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return &This->metadata();
  );
  return 0;
}

int atlas__Field__has_functionspace(Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return (This->functionspace() != 0);
  );
  return 0;
}

functionspace::FunctionSpace* atlas__Field__functionspace (Field* This)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    return &This->functionspace();
  );
  return 0;
}


void atlas__Field__shapef (Field* This, int* &shape, int &rank)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    shape = const_cast<int*>(&This->shapef().front());
    rank = This->shapef().size();
  );
}

void atlas__Field__data_shapef_int (Field* This, int* &field_data, int* &field_bounds, int &rank)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    field_data = &This->data<int>()[0];
    field_bounds = const_cast<int*>(&(This->shapef()[0]));
    rank = This->shapef().size();
  );
}

void atlas__Field__data_shapef_long (Field* This, long* &field_data, int* &field_bounds, int &rank)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    field_data = &This->data<long>()[0];
    field_bounds = const_cast<int*>(&(This->shapef()[0]));
    rank = This->shapef().size();
  );
}

void atlas__Field__data_shapef_float (Field* This, float* &field_data, int* &field_bounds, int &rank)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    field_data = &This->data<float>()[0];
    field_bounds = const_cast<int*>(&(This->shapef()[0]));
    rank = This->shapef().size();
  );
}

void atlas__Field__data_shapef_double (Field* This, double* &field_data, int* &field_bounds, int &rank)
{
  ATLAS_ERROR_HANDLING(
    ASSERT(This);
    field_data = &This->data<double>()[0];
    field_bounds = const_cast<int*>(&(This->shapef()[0]));
    rank = This->shapef().size();
  );
}

// ------------------------------------------------------------------

} // namespace field
} // namespace atlas
