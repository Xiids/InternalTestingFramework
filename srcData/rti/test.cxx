

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from test.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "testPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "test.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- TestType: 

TestType::TestType() :
    m_timestamp_sec_ (0) ,
    m_timestamp_usec_ (0u)  {

}   

TestType::TestType (int32_t timestamp_sec_,uint32_t timestamp_usec_):
    m_timestamp_sec_(timestamp_sec_), 
    m_timestamp_usec_(timestamp_usec_) {
}

void TestType::swap(TestType& other_)  noexcept 
{
    using std::swap;
    swap(m_timestamp_sec_, other_.m_timestamp_sec_);
    swap(m_timestamp_usec_, other_.m_timestamp_usec_);
}  

bool TestType::operator == (const TestType& other_) const {
    if (m_timestamp_sec_ != other_.m_timestamp_sec_) {
        return false;
    }
    if (m_timestamp_usec_ != other_.m_timestamp_usec_) {
        return false;
    }
    return true;
}

bool TestType::operator != (const TestType& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const TestType& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "timestamp_sec: " << sample.timestamp_sec ()<<", ";
    o << "timestamp_usec: " << sample.timestamp_usec ();
    o <<"]";
    return o;
}

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::TestType > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member TestType_g_tc_members[2]=
                {

                    {
                        (char *)"timestamp_sec",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"timestamp_usec",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode TestType_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"TestType", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        TestType_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for TestType*/

                if (is_initialized) {
                    return &TestType_g_tc;
                }

                is_initialized = RTI_TRUE;

                TestType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                TestType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                TestType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                TestType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                TestType_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                TestType_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                TestType_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                TestType_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                TestType_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                TestType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                TestType_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                TestType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                TestType_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                TestType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                TestType_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                TestType_g_tc._data._sampleAccessInfo = sample_access_info();
                TestType_g_tc._data._typePlugin = type_plugin_info();    

                return &TestType_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::TestType *sample;

                static RTIXCdrMemberAccessInfo TestType_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo TestType_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &TestType_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::TestType);
                if (sample == NULL) {
                    return NULL;
                }

                TestType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->timestamp_sec() - (char *)sample);

                TestType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->timestamp_usec() - (char *)sample);

                TestType_g_sampleAccessInfo.memberAccessInfos = 
                TestType_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::TestType);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        TestType_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        TestType_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                TestType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                TestType_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::TestType >;

                TestType_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &TestType_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin TestType_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &TestType_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::TestType >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::TestType >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::TestType >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::TestTypePlugin_new,
                ::TestTypePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::TestType >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::TestType& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TestTypePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TestTypePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::TestType >::from_cdr_buffer(::TestType& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TestTypePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::TestType from cdr buffer");
        }

        void topic_type_support< ::TestType >::reset_sample(::TestType& sample) 
        {
            sample.timestamp_sec(0);
            sample.timestamp_usec(0u);
        }

        void topic_type_support< ::TestType >::allocate_sample(::TestType& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
