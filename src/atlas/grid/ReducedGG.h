/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */
#ifndef atlas_grid_ReducedGG_H
#define atlas_grid_ReducedGG_H

#include <cstddef>
#include <vector>

#include "atlas/grid/Grid.h"

//-----------------------------------------------------------------------------

namespace atlas {
namespace grid {

//-----------------------------------------------------------------------------

// A gaussian grid is a latitude/longitude grid.
// The spacing of the latitudes is not regular.
// However, the spacing of the lines of latitude is symmetrical about the Equator.
// Note that there is no latitude at either Pole or at the Equator.
// A grid is usually referred to by its 'number' N, which is the number of lines of latitude between a Pole and the Equator.
// The longitudes of the grid points are defined by giving the number of points along each line of latitude.
// The first point is at longitude 0 and the points are equally spaced along the line of latitude.
// In a regular Gaussian grid, the number of longitude points along a latitude is 4*N.
// In a reduced Gaussian grid, the number of longitude points along a latitude is specified.
// Latitudes may have differing numbers of points but the grid is symmetrical about the Equator.
// A reduced gaussian grid may also be called a quasi-regular Gaussian grid.
//
// ? Global regular grids generated by interpolation have a longitude at 0 deg West.
// Latitude/longitude grids contain a line of latitude at the Equator, and gaussian grids are symmetrical about the Equator.

// land sea masks are not applied for reduced gaussian grid target grids, At the moment
//
// The Grib consist of sections  Geom, Bitmap(optional), Data
// We have following keys: numberofDataPoints,numberOfMissing,numberOf_CodedValues
// o When BitMap is present,(we have and array), it is for the global, 0 - Missing,  1- data value present
// o The bitsmap shows where we have Data values.

// Area: Do we check the area.
// Area: Can we assume area is multiple of the grids ? No.
// NPoints: is this just the grids points, or includes area points, of area does not fit grid
//          assumes it is grid points inclusive of the area.

class ReducedGG : public Grid {

public: // methods

	static std::string className() { return "atlas.grid.ReducedGG"; }
	static std::string gridTypeStr() { return "reduced_gg"; }

	ReducedGG( const eckit::Params& p );
	ReducedGG( long gaussN );

	virtual ~ReducedGG();

	virtual std::string uid() const;
	virtual std::string hash() const { return hash_;}

	virtual BoundBox boundingBox() const { return bbox_;}
	virtual size_t nPoints() const { return nbDataPoints_; }

	virtual void coordinates( std::vector<double>& ) const;
	virtual void coordinates( std::vector<Point>& ) const;

	virtual std::string gridType() const;
	virtual GridSpec spec() const;
	virtual bool same(const Grid&) const;

public: // methods

	long gaussianNumber() const { return gaussN_;}

	const std::vector<long>&  pointsPerLatitude() const { return rgSpec_;}

	void computeLatitues(std::vector<double>&) const;
	void computePoints( const std::vector<double>&, std::vector<Point>& pts ) const;
	long computeNPoints( const std::vector<double>& ) const;
	void computeNPtsPerLat( std::vector<long>& );

private: // members

	std::string          hash_;

	long                 nbDataPoints_;        ///< no of data points in grid, taking into account the bounding box
	long                 gaussN_;              ///< No of points between pole and equator

	BoundBox             bbox_;

	std::vector<long>    rgSpec_;              ///< No of points per latitude
};

//-----------------------------------------------------------------------------

} // namespace grid
} // namespace eckit

#endif
