/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "atlas/Nodes.h"
#include "atlas/field/FieldT.h"

using atlas::field::FieldT;

namespace atlas {

//------------------------------------------------------------------------------------------------------

Nodes::Nodes(size_t _size) :
  FunctionSpace("nodes",make_shape(_size,FunctionSpace::UNDEF_VARS))
{
  global_index_ = &add( new FieldT<gidx_t>("glb_idx",   make_shape(size(),1)) );
  remote_index_ = &add( new FieldT<int   >("remote_idx",make_shape(size(),1)) );
  partition_    = &add( new FieldT<int   >("partition", make_shape(size(),1)) );
  ghost_        = &add( new FieldT<int   >("ghost",     make_shape(size(),1)) );
  halo_         = &add( new FieldT<int   >("halo",      make_shape(size(),1)) );
  topology_     = &add( new FieldT<int   >("topology",  make_shape(size(),1)) );
  lonlat_       = &add( new FieldT<double>("lonlat",    make_shape(size(),2)) );

  add( new FieldT<int>("flags", make_shape(size(),1)) );


  ArrayView<gidx_t,1> glb_idx( global_index() );
  ArrayView<int   ,1> part( partition() );
  ArrayView<int   ,1> flags( field("flags") );

  for(size_t n=0; n<size(); ++n)
  {
    glb_idx(n) = 1+n;
    part(n) = eckit::mpi::rank();
    flags(n) = 0;
  }
  metadata().set("nb_owned",size());
  metadata().set<long>("type",static_cast<int>(Entity::NODES));
}


Field& Nodes::add( Field* field )
{
  ASSERT( field != NULL );
  ASSERT( ! field->name().empty() );

  if( has_field(field->name()) ) {
    std::stringstream msg;
    msg << "Trying to add field '"<<field->name()<<"' to Nodes, but Nodes already has a field with this name.";
    throw eckit::Exception(msg.str(),Here());
  }
  fields_[field->name()] = eckit::SharedPtr<Field>(field);
  return *field;
}

void Nodes::remove_field(const std::string& name)
{
  if( ! has_field(name) )
  {
    std::stringstream msg;
    msg << "Trying to remove field `"<<name<<"' in Nodes, but no field with this name is present in Nodes.";
    throw eckit::Exception(msg.str(),Here());
  }
  fields_.erase(name);
}


const Field& Nodes::field(const std::string& name) const
{
  if( ! has_field(name) )
  {
    std::stringstream msg;
    msg << "Trying to access field `"<<name<<"' in Nodes, but no field with this name is present in Nodes.";
    throw eckit::Exception(msg.str(),Here());
  }
  return *fields_.find(name)->second;
}

Field& Nodes::field(const std::string& name)
{
  return const_cast<Field&>(static_cast<const Nodes*>(this)->field(name));
}

void Nodes::resize( size_t size )
{
  FunctionSpace::resize(make_shape(size, FunctionSpace::shape(1)));

//  dof_ = size;
//  for( FieldMap::iterator it = fields_.begin(); it != fields_.end(); ++it )
//  {
//    Field& field = *it->second;
//    ArrayShape shape = field.shape();
//    shape[0] = size_;
//    field.resize(shape);
//  }
}

const Field& Nodes::field(size_t idx) const
{
  size_t c;
  for( FieldMap::const_iterator it = fields_.begin(); it != fields_.end(); ++it )
  {
    if( idx == c )
    {
      const Field& field = *it->second;
      return field;
    }
    c++;
  }
}
Field& Nodes::field(size_t idx)
{
  return const_cast<Field&>(static_cast<const Nodes*>(this)->field(idx));
}

void Nodes::print(std::ostream& os) const
{
    os << "Nodes[\n";
    os << "\t size=" << size() << ",\n";
    os << "\t fields=\n";
    for(size_t i = 0; i < nb_fields(); ++i)
    {
        os << "\t\t" << field(i);
        if( i != nb_fields()-1 )
          os << ",";
        os << "\n";
    }
    os << "]";
}

//-----------------------------------------------------------------------------

extern "C" {
int atlas__Nodes__size (Nodes* This)
{
  ASSERT(This);
  return This->size();
}
void atlas__Nodes__resize (Nodes* This, int size)
{
  ASSERT(This);
  return This->resize(size);
}
int atlas__Nodes__nb_fields (Nodes* This)
{
  ASSERT(This);
  return This->nb_fields();
}

Field* atlas__Nodes__add (Nodes* This, Field* field)
{
  ASSERT(This);
  ASSERT(field);
  return &This->add(field);
}

void atlas__Nodes__remove_field (Nodes* This, char* name)
{
  ASSERT(This);
  This->remove_field(std::string(name));
}

int atlas__Nodes__has_field (Nodes* This, char* name)
{
  ASSERT(This);
  return This->has_field(std::string(name));
}

Field* atlas__Nodes__field_by_name (Nodes* This, char* name)
{
  ASSERT(This);
  return &This->field(std::string(name));
}

Field* atlas__Nodes__field_by_idx (Nodes* This, int idx)
{
  ASSERT(This);
  return &This->field(idx);
}

Metadata* atlas__Nodes__metadata(Nodes* This)
{
  ASSERT(This);
  return &This->metadata();
}

void atlas__Nodes__str (Nodes* This, char* &str, int &size)
{
  std::stringstream ss;
  ss << *This;
  std::string s = ss.str();
  size = s.size();
  str = new char[size+1];
  strcpy(str,s.c_str());
}

}


}  // namespace atlas

