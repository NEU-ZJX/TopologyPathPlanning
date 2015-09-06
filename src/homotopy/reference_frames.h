#ifndef REFERENCE_FRAMES_H
#define REFERENCE_FRAMES_H

#include "worldmap.h"
#include "string_grammar.h"
#include "homotopic_grammar.h"

typedef enum {
    STRING_GRAMMAR_TYPE,
    HOMOTOPIC_GRAMMAR_TYPE
} grammar_type_t;

class ReferenceFrame {
public:
  ReferenceFrame();
  virtual ~ReferenceFrame();
  
  std::string m_name; 
  Segment2D   m_segment;
};

class ReferenceFrameSet {

public:
    ReferenceFrameSet( WorldMap* p_world_map );
    virtual ~ReferenceFrameSet();

    StringGrammar* get_string_grammar( SubRegion* p_init, SubRegion* p_goal );
    HomotopicGrammar* get_homotopic_grammar( SubRegion* p_init, SubRegion* p_goal );

    std::string get_character_id( Point2D start, Point2D end, grammar_type_t type );

private:
    WorldMap*                    _p_world_map;
    std::vector<ReferenceFrame*> _reference_frames;
};

#endif // REFERENCE_FRAMES_H