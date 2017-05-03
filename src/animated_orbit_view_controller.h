#ifndef RVIZ_ANIMATED_ORBIT_VIEW_CONTROLLER_H
#define RVIZ_ANIMATED_ORBIT_VIEW_CONTROLLER_H

#include "rviz/default_plugin/view_controllers/orbit_view_controller.h"

namespace rviz_animated_view
{

/**
 * \brief An rotating orbital camera
 */
class AnimatedOrbitViewController: public rviz::OrbitViewController 
{
Q_OBJECT
public:
  AnimatedOrbitViewController();

  virtual void reset();
protected:
  virtual void update(float dt, float ros_dt);
  rviz::FloatProperty* rotation_speed_property_;
  rviz::BoolProperty* do_rotation_property_;
};

}

#endif // RVIZ_ANIMATED_VIEW_CONTROLLER_H
