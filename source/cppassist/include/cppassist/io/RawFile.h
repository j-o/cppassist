
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
*    Raw data file loader
*
*    This class allows for loading raw data (e.g., textures) from files. You have to exactly know
*    how to interpret the content of the file, e.g., you need to know the format and size of the
*    texture, the file does not provide this information. To create raw textures, you can use
*    for example glraw (https://github.com/cginternals/glraw).
*/
class CPPASSIST_API RawFile
{
public:
    /**
    *  @brief
    *    Constructor
    */
    RawFile();

    /**
    *  @brief
    *    Destructor
    */
    ~RawFile();

    /**
    *  @brief
    *    Load file contents
    *
    *  @param[in] path
    *    Path to the file to load
    *
    *  @remarks
    *    Uses the passed file path and store it for subsequent reloads.
    */
    bool load(const std::string & filePath);

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


protected:
    /**
    *  @brief
    *    Load contents from file path
    *
    *  @return
    *    'true' if loaded was successful, 'false' else
    */
    bool readFile();


protected:
    std::string m_filePath; ///< File path
    std::string m_data;     ///< Loaded file contents
    bool        m_valid;    ///< Validity of loaded file contents
};


} // namespace cppassist
