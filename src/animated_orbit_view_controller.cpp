#include <stdint.h>

#include "rviz/properties/bool_property.h"
#include "rviz/properties/float_property.h"

#include "animated_orbit_view_controller.h"

using namespace rviz;

namespace rviz_animated_view
{

AnimatedOrbitViewController::AnimatedOrbitViewController()
  : OrbitViewController()
{
  rotation_speed_property_ = new FloatProperty( "Rotation Speed", 0.0f, "Speed of the rotation around the orbit point.", this );
  do_rotation_property_ = new BoolProperty ( "Rotate", false, "Activate roataion.", this );
}

void AnimatedOrbitViewController::reset()
{
  OrbitViewController::reset();
  rotation_speed_property_->setFloat( 0.0f );
  do_rotation_property_->setBool( false );
}


void AnimatedOrbitViewController::update(float dt, float ros_dt)
{
  FramePositionTrackingViewController::update( dt, ros_dt );
  if (do_rotation_property_->getBool()) {
      float yaw = yaw_property_->getFloat();
      yaw += rotation_speed_property_->getFloat() * dt;
      yaw_property_->setFloat(yaw);
  }
  updateCamera();
}

} // end namespace rviz_animated_view

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS( rviz_animated_view::AnimatedOrbitViewController, rviz::ViewController )
