#ifndef WORLDMAP_H
#define WORLDMAP_H


#include <libxml/tree.h>
#include "obstacle.h"
#include "region.h"

class WorldMap {
public:
    WorldMap( int width, int height );
    ~WorldMap();

    bool load_obstacle_info( std::vector< std::vector<Point2D> > polygons);
    bool init();
    bool _init_points();
    bool _init_rays();
    bool _init_segments();
    bool _init_regions();

    bool _is_in_obstacle( Point2D point );
    bool _is_in_obs_bk_lines( Point2D point );


    virtual void to_xml( const std::string& filename )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    virtual void from_xml( const std::string& filename );
    virtual void from_xml( xmlNodePtr root );

    std::vector<Point2D> _intersect( Segment2D seg, std::vector<Segment2D> segments );
    Point2D* _find_intersection_with_boundary( Ray2D* p_ray );

    int get_width() const { return _map_width; }
    int get_height() const { return _map_height; }

    Point2D get_central_point() const { return _central_point; }
    std::vector<Obstacle*> get_obstacles() const { return _obstacles; }

private:
    int _map_width;
    int _map_height;

    int _sample_width_scale;
    int _sample_height_scale;

    std::vector<Line2D>             _obs_bk_pair_lines;
    std::vector<Segment2D>          _boundary_lines;
    std::vector<Obstacle*>          _obstacles;
    std::vector<LineSubSegmentSet*> _line_segments;
    std::vector<SubRegionSet*>      _regionSets;


    Point2D                _central_point;
    Segment2D              _x_min_line;
    Segment2D              _x_max_line;
    Segment2D              _y_min_line;
    Segment2D              _y_max_line;
};

std::ostream& operator<<( std::ostream& out, const WorldMap& other );

#endif // WORLDMAP_H