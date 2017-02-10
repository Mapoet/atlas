#ifndef atlas_RotatedLonLatProjection_H
#define atlas_RotatedLonLatProjection_H

#include "atlas/grid/projection/LonLatProjection.h"

namespace atlas {
namespace grid {
namespace projection {

class RotatedLonLatProjection: public LonLatProjection, public Rotated {

public:
    // constructor
    RotatedLonLatProjection(const eckit::Parametrisation& p);

    // copy constructor
    RotatedLonLatProjection( const RotatedLonLatProjection& rhs );

    // clone method
    virtual Projection *clone() const ;

    // class name
    static std::string className() { return "atlas.RotatedLonLatProjection"; }
    static std::string projection_type_str() {return "rotatedLonLat";}
    virtual std::string virtual_projection_type_str() const {return "rotatedLonLat";}

    // projection and inverse projection
    eckit::geometry::LLPoint2 coords2lonlat(eckit::geometry::Point2) const;
    eckit::geometry::Point2 lonlat2coords(eckit::geometry::LLPoint2) const;

    // purely regional? - no!
    bool isRegional() { return false; }  // lonlat can be global

    // specification
    virtual eckit::Properties spec() const;

};

}  // namespace projection
}  // namespace grid
}  // namespace atlas


#endif
