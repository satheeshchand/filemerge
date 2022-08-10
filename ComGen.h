#ifndef ComGen_h
#define ComGen_h

#include <string>
#include <list>

using namespace std;

struct AnalogChannelInfo
    {
    /* Critial */
    unsigned int mIndex;
    std::string mChannelId;
    std::string mUnit;
    float mMultiplier; // TODO check it again!
    float mOffset;
    /* Non-Critical */
    std::string mPhaseId;
    std::string mCircuitMon;

    AnalogChannelInfo ()
        {
        mIndex = 0;
        mMultiplier = 0.00;
        mOffset = 0;
        }
    };

struct DigitalChannelInfo
    {
    };

enum ComFileFormat
    {
    FormatSingleFile,
    FormatMultipleFile
    };
enum RevYear
    {
    RevYear1991,
    RevYear1999,
    RevYear2013
    };
class ComGen
    {
    public:
    /**
     * Constructor for Comtrade generation class object. Following parameters
     * are required.
     * @param statioName :- <br> Station Name </br> is the name of the substation or the location of the 
     * substation or the place where the files have been recorded. Critical, 
     * alphanumeric, minimum length = 0 characters, maximum length = 64 characters.
     */
        ComGen (const std::string& statioName, 
            const std::string& devId, const int revYear,
            const int format = FormatMultipleFile);
    /* Min = 1 Max = 999999 */
    void setNumAnalogChannels (const unsigned int num);
    void setNumDigitalChannels (const unsigned int num);
    void setAnalogChannels (std::list <AnalogChannelInfo>& channels);
    bool createComtradeFile (const std::string& filename);
    private:
        ComGen () {}
        int mFileFormat;
        std::string mStationName;
        std::string mDevName;
        int mRevYear;
        unsigned int mAnalogChannels;
        unsigned int mDigitalChannels;
        std::list <AnalogChannelInfo> mAIChannels;
        std::list <DigitalChannelInfo> mDIChannels;
    };

inline void ComGen::setNumAnalogChannels (const unsigned int num)
    { mAnalogChannels = num; }

inline void ComGen::setNumDigitalChannels (const unsigned int num)
    { mDigitalChannels = num; }

inline void ComGen::setAnalogChannels (std::list <AnalogChannelInfo>& channels)
    { mAIChannels = channels; }

#endif