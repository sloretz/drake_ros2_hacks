#ifndef DRAKE_ROS_SYSTEMS__SERIALIZER_INTERFACE_HPP_
#define DRAKE_ROS_SYSTEMS__SERIALIZER_INTERFACE_HPP_

#include <drake/common/value.h>

#include <memory>

#include <rclcpp/serialized_message.hpp>
#include <rosidl_typesupport_cpp/message_type_support.hpp>

namespace drake_ros_systems
{
class SerializerInterface
{
public:
  virtual
  rclcpp::SerializedMessage
  serialize(const drake::AbstractValue & abstract_value) const = 0;

  virtual
  bool
  deserialize(
    const rclcpp::SerializedMessage & message,
    drake::AbstractValue & abstract_value) const = 0;

  virtual
  std::unique_ptr<drake::AbstractValue>
  create_default_value() const = 0;

  virtual
  const rosidl_message_type_support_t *
  get_type_support() const = 0;
};
}  // namespace drake_ros_systems
#endif  // DRAKE_ROS_SYSTEMS__SERIALIZER_INTERFACE_HPP_
