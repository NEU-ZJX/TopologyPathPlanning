#ifndef TOPOLOGYPATHPLANNING_TARRTS_MLVIZUTIL_HPP
#define TOPOLOGYPATHPLANNING_TARRTS_MLVIZUTIL_HPP

#include <CGAL/squared_distance_2.h>
#include <QPoint>
#include "topologyPathPlanning/homotopy/WorldDatatype.hpp"

namespace topologyPathPlanning {

namespace tarrts {

  inline QPoint toQPoint( homotopy::Point2D point ) {
    double x = CGAL::to_double( point.x() );
    double y = CGAL::to_double( point.y() );
    return QPoint((int)x, (int)y ); 
  }
 
  inline QPoint toQPoint( POS2D pos ) {
    return QPoint(pos[0], pos[1]);
  }

  inline homotopy::Point2D toPoint2D( QPoint pos ) {
    return homotopy::Point2D( pos.x(), pos.y() );
  }

} // tarrts

} // topologyPathPlanning

#endif // TOPOLOGYPATHPLANNING_TARRTS_MLVIZUTIL_HPP
