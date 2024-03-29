// Generated by gencpp from file mpu6050/ResetIMURequest.msg
// DO NOT EDIT!


#ifndef MPU6050_MESSAGE_RESETIMUREQUEST_H
#define MPU6050_MESSAGE_RESETIMUREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mpu6050
{
template <class ContainerAllocator>
struct ResetIMURequest_
{
  typedef ResetIMURequest_<ContainerAllocator> Type;

  ResetIMURequest_()
    : command(false)  {
    }
  ResetIMURequest_(const ContainerAllocator& _alloc)
    : command(false)  {
  (void)_alloc;
    }



   typedef uint8_t _command_type;
  _command_type command;





  typedef boost::shared_ptr< ::mpu6050::ResetIMURequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mpu6050::ResetIMURequest_<ContainerAllocator> const> ConstPtr;

}; // struct ResetIMURequest_

typedef ::mpu6050::ResetIMURequest_<std::allocator<void> > ResetIMURequest;

typedef boost::shared_ptr< ::mpu6050::ResetIMURequest > ResetIMURequestPtr;
typedef boost::shared_ptr< ::mpu6050::ResetIMURequest const> ResetIMURequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mpu6050::ResetIMURequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mpu6050::ResetIMURequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mpu6050::ResetIMURequest_<ContainerAllocator1> & lhs, const ::mpu6050::ResetIMURequest_<ContainerAllocator2> & rhs)
{
  return lhs.command == rhs.command;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mpu6050::ResetIMURequest_<ContainerAllocator1> & lhs, const ::mpu6050::ResetIMURequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mpu6050

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mpu6050::ResetIMURequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mpu6050::ResetIMURequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu6050::ResetIMURequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "01134d7a2df15c0112a6a1d7df9d666d";
  }

  static const char* value(const ::mpu6050::ResetIMURequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x01134d7a2df15c01ULL;
  static const uint64_t static_value2 = 0x12a6a1d7df9d666dULL;
};

template<class ContainerAllocator>
struct DataType< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mpu6050/ResetIMURequest";
  }

  static const char* value(const ::mpu6050::ResetIMURequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool command\n"
;
  }

  static const char* value(const ::mpu6050::ResetIMURequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ResetIMURequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mpu6050::ResetIMURequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mpu6050::ResetIMURequest_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.command);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MPU6050_MESSAGE_RESETIMUREQUEST_H
