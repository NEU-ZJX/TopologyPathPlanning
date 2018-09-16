#include "topologyPathPlanning/spatialinfer/InbetweenRelationFunction.hpp"

using namespace std;
using namespace topologyPathPlanning::homotopy;

namespace topologyPathPlanning {

namespace topologyinference {

InBetweenRelationFunction::InBetweenRelationFunction() {
  mp_obstacles.clear();
}

InBetweenRelationFunction::~InBetweenRelationFunction() {
  mp_obstacles.clear();
}

vector< pair<ReferenceFrame*, bool> > InBetweenRelationFunction::get_rules( ReferenceFrameSet* p_reference_frame_set ) {
  vector< pair<ReferenceFrame*, bool> > rules;

  if( p_reference_frame_set ) {
    // check whether there is a reference frame connecting to reference frames
    for( unsigned int i=0; i<p_reference_frame_set->getReferenceFrames().size(); i++ ) {
      ReferenceFrame* p_ref = p_reference_frame_set->getReferenceFrames()[i];
      if( p_ref ) {
        if( p_ref->mpLineSubsegment ) {
          if( p_ref->mpLineSubsegment->isConnected( mp_obstacles[0] ) &&
              p_ref->mpLineSubsegment->isConnected( mp_obstacles[1] ) ) {
            rules.push_back( make_pair( p_ref, true ) );
          }
        }    
      }
    }
    if( rules.size() == 0 ) {
      for( unsigned int i=0; i<p_reference_frame_set->getReferenceFrames().size(); i++ ) {
        ReferenceFrame* p_ref = p_reference_frame_set->getReferenceFrames()[i];
        if( p_ref ) {
          if( p_ref->mpLineSubsegment ) {
            if( p_ref->mpLineSubsegment->isConnected( mp_obstacles[0] ) &&
                p_ref->mpLineSubsegment->mIsConnectedToCentralPoint ) {

              rules.push_back( make_pair( p_ref, true ) );
            }
            else if( p_ref->mpLineSubsegment->isConnected( mp_obstacles[1] ) &&
                     p_ref->mpLineSubsegment->mIsConnectedToCentralPoint ) {
              rules.push_back( make_pair( p_ref, true ) );
            }
          }
        }
      }
    }
  }
  return rules;  
}

string InBetweenRelationFunction::get_name() {
  string name = "IN_BETWEEN(";
  for(unsigned int i=0; i<mp_obstacles.size(); i++) {
    if( i < mp_obstacles.size()-1 ) {
      name += mp_obstacles[i]->getName() + ",";
    }
    else{
      name += mp_obstacles[i]->getName();
    }
  }  
  name += ")";
  return name;
}

} // topologyinference

} // topologyPathPlanning
