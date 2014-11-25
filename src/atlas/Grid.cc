/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "eckit/memory/Factory.h"
#include "eckit/memory/Builder.h"
#include "eckit/config/Resource.h"

#include "atlas/Mesh.h"
#include "atlas/Grid.h"
#include "atlas/Tesselation.h"
#include "atlas/GridSpecParams.h"

using namespace eckit;

namespace atlas {


//------------------------------------------------------------------------------------------------------

Grid::Ptr Grid::create(const Params& p )
{
  return Grid::Ptr( Factory<Grid>::instance().get( p["grid_type"] ).create(p) );
}


Grid::Ptr Grid::create(const GridSpec& g)
{
  GridSpecParams p( g );
  return Grid::Ptr( Factory<Grid>::instance().get( p["grid_type"] ).create(p) );
}

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::lonlat( std::vector<double>& crd )
{
  crd.resize(npts()*2);
  lonlat(crd.data());
}

void Grid::build_mesh() const
{
  if( ! mesh_ )
  {
    mesh_.reset( new Mesh() );
    mesh_->grid( const_cast<Grid&>(*this) );
    Tesselation::build_mesh( *this, *mesh_ );
  }
}

Mesh& Grid::mesh()
{
  build_mesh();
  return *mesh_;
}

const Mesh& Grid::mesh() const
{
  build_mesh();
  return *mesh_;
}

//------------------------------------------------------------------------------------------------------

Grid::BoundBox Grid::make_global_bounding_box()
{
  return Grid::BoundBox( 90., -90., 360. - degrees_eps(), 0. );
}

Grid::BoundBox Grid::make_bounding_box(const Params& p)
{
  if( p.get("bbox_s").isNil() )
    return Grid::make_global_bounding_box();

  return BoundBox( p["bbox_n"],
                   p["bbox_s"],
                   p["bbox_e"],
                   p["bbox_w"] ).
                   global(false);
}

double Grid::degrees_eps()
{
  /// default is 1E-3 because
  /// some bugs in IFS means we need a lower resolution epsilon when decoding from grib2

  static double eps = eckit::Resource<double>( "$ATLAS_DEGREES_EPSILON;GridDegreesEps", 1E-3 );
  return eps;
}

//------------------------------------------------------------------------------------------------------


} // namespace atlas
