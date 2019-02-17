#ifndef KAA_TYPES_H
#define KAA_TYPES_H

#include <cstddef>
#include <cstdint>
#include <chrono>

namespace kaa
{
	typedef std::chrono::system_clock::time_point ktime_t;

    enum Min_Ver { ZERO = 0 };
    enum Maj_Ver { ONE = 1 };
    
    // A record header. Every 'data record' will have a versioned header to 
    // enable 
    struct Header
    {
        Maj_Ver     m_maj_ver; // major header version
        Min_Ver     m_min_ver; // minor header version
        std::size_t m_size; // count of bytes
        std::time_t m_creation_time; // time of record creation
    };
    
    struct Record
    {
        Header				m_header;
        const std::byte*    m_data;
    };
    
    struct StreamHeader
    {
        
        enum        file_structure { PLAIN_TEXT, CIPHER_TEXT, JSON, XML, YML, RAW_BYTES, BASE64 };
        
        Maj_Ver			m_maj_ver;
        Min_Ver			m_min_ver;
        uint64_t		m_size;
        ktime_t			m_creation_time;
        uint64_t        m_record_count;
        file_structure  m_type;
		std::string		m_stream_name;
		uint16_t		m_year;
		uint16_t		m_month;
		uint16_t		m_day;
    };

};

#endif // KAA_TYPES_H
