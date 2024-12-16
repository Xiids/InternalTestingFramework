

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from test.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef test_1147917550_hpp
#define test_1147917550_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport TestType {
  public:
    TestType();

    TestType(
        int32_t m1,
        double m2,
        const std::string& m3);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    TestType (TestType&&) = default;
    TestType& operator=(TestType&&) = default;
    TestType& operator=(const TestType&) = default;
    TestType(const TestType&) = default;
    #else
    TestType(TestType&& other_) OMG_NOEXCEPT;  
    TestType& operator=(TestType&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int32_t& m1() OMG_NOEXCEPT {
        return m_m1_;
    }

    const int32_t& m1() const OMG_NOEXCEPT {
        return m_m1_;
    }

    void m1(int32_t value) {
        m_m1_ = value;
    }

    double& m2() OMG_NOEXCEPT {
        return m_m2_;
    }

    const double& m2() const OMG_NOEXCEPT {
        return m_m2_;
    }

    void m2(double value) {
        m_m2_ = value;
    }

    std::string& m3() OMG_NOEXCEPT {
        return m_m3_;
    }

    const std::string& m3() const OMG_NOEXCEPT {
        return m_m3_;
    }

    void m3(const std::string& value) {
        m_m3_ = value;
    }

    void m3(std::string&& value) {
        m_m3_ = std::move(value);
    }

    bool operator == (const TestType& other_) const;
    bool operator != (const TestType& other_) const;

    void swap(TestType& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_m1_;
    double m_m2_;
    std::string m_m3_;

};

inline void swap(TestType& a, TestType& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TestType& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< TestType > {
            NDDSUSERDllExport static std::string value() {
                return "TestType";
            }
        };

        template<>
        struct is_topic_type< TestType > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< TestType > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const TestType& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(TestType& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(TestType& sample);

            NDDSUSERDllExport 
            static void allocate_sample(TestType& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< TestType > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< TestType > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // test_1147917550_hpp

