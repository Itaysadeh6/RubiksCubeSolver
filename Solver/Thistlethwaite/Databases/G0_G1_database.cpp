#include "G0_G1_database.h"

uint32_t G0_G1_Database::getIndex(const Rubiks& cube) const
{
    using EEDGE = Rubiks::EEDGE;

    // for each of the 11 edges (12th can be assumed www.ryanheise.com/cube/cube_laws.html)
    // get the orientation (0/1) and convert the binary permutation to a decimal number

    // permutation based on position on the cube, not edge indices
    std::array<uint8_t, 11> orientationPerm = {
        cube.getEdgeOrientation({ cube.getColour(EEDGE::RB), cube.getColour(EEDGE::BR) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::RF), cube.getColour(EEDGE::FR) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::RU), cube.getColour(EEDGE::UR) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::RD), cube.getColour(EEDGE::DR) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::LB), cube.getColour(EEDGE::BL) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::LF), cube.getColour(EEDGE::FL) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::LU), cube.getColour(EEDGE::UL) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::LD), cube.getColour(EEDGE::DL) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::UB), cube.getColour(EEDGE::BU) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::UF), cube.getColour(EEDGE::FU) }),
        cube.getEdgeOrientation({ cube.getColour(EEDGE::DB), cube.getColour(EEDGE::BD) }),
    };

    // convert to decimal
    return
       (orientationPerm[0]  +
        orientationPerm[1]  * 2 +
        orientationPerm[2]  * 4 +
        orientationPerm[3]  * 8 +
        orientationPerm[4]  * 16 +
        orientationPerm[5]  * 32 +
        orientationPerm[6]  * 64 +
        orientationPerm[7]  * 128 +
        orientationPerm[8]  * 256 +
        orientationPerm[9]  * 512 +
        orientationPerm[10] * 1024);
}