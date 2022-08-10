#include <ComGen.h>
#include <iostream>
#include <fstream>

ComGen::ComGen (const std::string& statioName, 
                const std::string& devId, const int revYear,
                const int format)
    {
    mStationName = statioName;
    mDevName = devId;
    mRevYear = revYear;
    mFileFormat = format;
    }

bool ComGen::createComtradeFile (const std::string& filename)
    {
    bool ret = false;

    std::ofstream comFile;
    comFile.open (filename.c_str ());

    comFile << mStationName << "," << mDevName << "," << mRevYear << "\n";

    comFile << (mAnalogChannels + mDigitalChannels) << ","
        << mAnalogChannels << "A" << mDigitalChannels << "D" 
        << "\n";

    for (std::list <AnalogChannelInfo>::iterator i = 
        mAIChannels.begin (); i != mAIChannels.end (); ++i)
        {
        comFile << i->mIndex << "," << i->mChannelId << "," << 
            i->mPhaseId << "," << i->mCircuitMon << ","
            << i->mMultiplier << "," << i->mOffset << "\n";
        }
    return (ret);
    }