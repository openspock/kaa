#ifndef KAA_TYPES_H
#define KAA_TYPES_H

#include <cstddef>
#include <cstdint>
#include <ctime>

namespace kaa
{
    enum min_ver { ZERO = 0 };
    enum maj_ver { ONE = 1 };
    
    // A record header. Every 'data record' will have a versioned header to 
    // enable 
    struct header_t
    {
        maj_ver     m_maj_ver; // major header version
        min_ver     m_min_ver; // minor header version
        std::size_t m_size; // count of bytes
        std::time_t m_creation_time; // time of record creation
    };
    
    struct record_t
    {
        header_t            m_header;
        const std::byte*    m_data;
    };
    
    struct file_header_t
    {
        
        enum        file_structure { PLAIN_TEXT, CIPHER_TEXT, JSON, XML, YML, RAW_BYTES, BASE64 };
        
        maj_ver         m_maj_ver;
        min_ver         m_min_ver;
        std::size_t     m_size;
        std::time_t     m_creation_time;
        uint64_t        m_record_count;
        file_structure  m_type;
    };

};

#endif // KAA_TYPES_H
