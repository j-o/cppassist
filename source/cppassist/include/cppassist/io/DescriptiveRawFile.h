#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <map>

#include <cppassist/cppassist_api.h>


namespace cppassist
{


/**
*  @brief
*    Raw data with header file loader
*
*    This class allows for loading raw data (e.g., textures) from files with additional header information.
*    You have to exactly know how to interpret the content of the file, probably using the information
*    of the header to parametrize the content interpretion.
*/
class CPPASSIST_API DescriptiveRawFile
{
public:
    static uint16_t s_signature; ///< Magic file signature to detect descriptive raw files with header information


    /**
    *  @brief
    *    Enumeration to all known data types of header properties
    */
    enum class PropertyType : unsigned char
	{
        Unknown	= 0,
        Integer = 1,
        Double	= 2,
        String	= 3
    };


    /**
    *  @brief
    *    Constructor
    */
    DescriptiveRawFile();

    /**
    *  @brief
    *    Destructor
    */
    ~DescriptiveRawFile();

    /**
    *  @brief
    *    Load file contents
    *
    *  @param[in] path
    *    Path to the file to load
    *  @param[in] parseProperties
    *    Flag whether to parse or omit header information
    *
    *  @remarks
    *    Uses the passed file path and store it for subsequent reloads.
    */
    bool load(const std::string & filePath, bool parseProperties = true);

    /**
    *  @brief
    *    Reloads file contents
    *
    *  @remarks
    *    Uses the last passed file path to load.
    */
    bool reload();

    /**
    *  @brief
    *    Get plain C pointer to file contents
    *
    *  @return
    *    Plain C pointer to file contents if successfully loaded, 'nullptr' else
    */
    const char * data() const;

    /**
    *  @brief
    *    Get number of bytes in file
    *
    *  @return
    *    Number of bytes in file if successfully loaded, '0' else
    */
    size_t size() const;

    /**
    *  @brief
    *    Get validity of file contents
    *
    *  @return
    *    'true' if file contents could get successfully loaded, 'false' else
    */
    bool isValid() const;

    /**
    *  @brief
    *    Get file path
    *
    *  @return
    *    File path
    */
    const std::string & filePath() const;
    
    /**
    *  @brief
    *    Get string property
    *
    *  @param[in] key
    *    The key to identify the property
    *
    *  @return
    *    The string property
    */
    const std::string & stringProperty(const std::string & key) const;

    /**
    *  @brief
    *    Get integer property
    *
    *  @param[in] key
    *    The key to identify the property
    *
    *  @return
    *    The integer property
    */
    int32_t intProperty(const std::string & key) const;

    /**
    *  @brief
    *    Get floating-point property
    *
    *  @param[in] key
    *    The key to identify the property
    *
    *  @return
    *    The floating-point property
    */
    double doubleProperty(const std::string & key) const;
    
    /**
    *  @brief
    *    Get availability of string property
    *
    *  @param[in] key
    *    The key to identify the property
    *
    *  @return
    *    'true' if string property with given name exists, 'false' else
    */
    bool hasStringProperty(const std::string & key) const;

    /**
    *  @brief
    *    Get availability of integer property
    *
    *  @param[in] key
    *    The key to identify the property
    *
    *  @return
    *    'true' if integer property with given name exists, 'false' else
    */
    bool hasIntProperty(const std::string & key) const;

    /**
    *  @brief
    *    Get availability of floating-point property
    *
    *  @param[in] key
    *    The key to identify the property
    *
    *  @return
    *    'true' if floating-point property with given name exists, 'false' else
    */
    bool hasDoubleProperty(const std::string & key) const;


protected:
    /**
    *  @brief
    *    Load contents from file path
    *
    *  @param[in] parseProperties
    *    Wether to load the header or omit it
    *
    *  @return
    *    'true' if loaded was successful, 'false' else
    */
    bool readFile();
    
    /**
    *  @brief
    *    Read properties from stream.
    *
    *  @param[in] ifs
    *    The stream to read from
    *  @param[in] offset
    *    The offset of the next section
    *
    *  @remarks
    *    Reads from stream until position is the given offset.
    */
    void readProperties(std::ifstream & ifs, uint64_t offset);
    
    /**
    *  @brief
    *    Read raw data from stream
    *
    *  @param[in] ifs
    *    The stream to read from
    *  @param[in] offset
    *    The start offset
     */
    void readRawData(std::ifstream & ifs, uint64_t offset);


protected:
    std::string m_filePath;        ///< File path
    std::string m_data;            ///< Loaded file contents
    bool        m_parseProperties; ///< Whether to parse properties
    bool        m_valid;           ///< Validity of loaded file contents

    std::map<std::string, std::string> m_stringProperties; ///< Loaded string properties
    std::map<std::string, int32_t>     m_intProperties;    ///< Loaded integer properties
    std::map<std::string, double>      m_doubleProperties; ///< Loaded floating-point properties
};


} // namespace cppassist
