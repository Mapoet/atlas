#include "atlas/atlas.h"
#include "atlas/grid/grids.h"
#include "atlas/mesh/Mesh.h"
#include "atlas/mesh/generators/Structured.h"
#include "atlas/mesh/actions/BuildXYZField.h"
#include "atlas/util/io/Gmsh.h"
#include "eckit/config/Resource.h"

using namespace std;
using namespace eckit;
using namespace atlas;
using namespace atlas::grid::global;
using namespace atlas::mesh;

int main(int argc, char *argv[])
{
    atlas_init(argc, argv);

    string gridID    = Resource<string>("--grid"     , string("N32"));
    string visualize = Resource<string>("--visualize", string("2D") );

    SharedPtr<Structured> Structured( Structured::create(gridID) );

    mesh::generators::Structured meshgenerator;
    SharedPtr<Mesh> mesh( meshgenerator.generate(*Structured) );

    util::io::Gmsh gmsh;
    gmsh.options.set("info", true);
    if (visualize == "3D")
    {
        actions::BuildXYZField("xyz")(*mesh);
        gmsh.options.set("nodes", std::string("xyz"));
    }
    gmsh.write(*mesh, "mesh.msh");

    atlas_finalize();

    return 0;
}