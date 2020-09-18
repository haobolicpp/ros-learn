// Generated by gencpp from file test_service/Person.msg
// DO NOT EDIT!


#ifndef TEST_SERVICE_MESSAGE_PERSON_H
#define TEST_SERVICE_MESSAGE_PERSON_H

#include <ros/service_traits.h>


#include <test_service/PersonRequest.h>
#include <test_service/PersonResponse.h>


namespace test_service
{

struct Person
{

typedef PersonRequest Request;
typedef PersonResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Person
} // namespace test_service


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::test_service::Person > {
  static const char* value()
  {
    return "c198113e7dd9cc5c9fd5f271c8479b39";
  }

  static const char* value(const ::test_service::Person&) { return value(); }
};

template<>
struct DataType< ::test_service::Person > {
  static const char* value()
  {
    return "test_service/Person";
  }

  static const char* value(const ::test_service::Person&) { return value(); }
};


// service_traits::MD5Sum< ::test_service::PersonRequest> should match
// service_traits::MD5Sum< ::test_service::Person >
template<>
struct MD5Sum< ::test_service::PersonRequest>
{
  static const char* value()
  {
    return MD5Sum< ::test_service::Person >::value();
  }
  static const char* value(const ::test_service::PersonRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::test_service::PersonRequest> should match
// service_traits::DataType< ::test_service::Person >
template<>
struct DataType< ::test_service::PersonRequest>
{
  static const char* value()
  {
    return DataType< ::test_service::Person >::value();
  }
  static const char* value(const ::test_service::PersonRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::test_service::PersonResponse> should match
// service_traits::MD5Sum< ::test_service::Person >
template<>
struct MD5Sum< ::test_service::PersonResponse>
{
  static const char* value()
  {
    return MD5Sum< ::test_service::Person >::value();
  }
  static const char* value(const ::test_service::PersonResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::test_service::PersonResponse> should match
// service_traits::DataType< ::test_service::Person >
template<>
struct DataType< ::test_service::PersonResponse>
{
  static const char* value()
  {
    return DataType< ::test_service::Person >::value();
  }
  static const char* value(const ::test_service::PersonResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TEST_SERVICE_MESSAGE_PERSON_H