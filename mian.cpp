#include <ComGen.h>


void main ()
    {
    std::list <AnalogChannelInfo> chList;
    
    ComGen myFile ("mycom", "1234", RevYear2013);

    
    myFile.setNumAnalogChannels (10);
    myFile.setNumDigitalChannels (12);
    
    for (int i = 0; i < 10; i++)
        {
        char test [32];
        AnalogChannelInfo obj;
        obj.mIndex = i;
        sprintf (test, "%d", i);
        obj.mChannelId = std::string ("MyID") + std::string (test);
        obj.mUnit = "kV";
        obj.mMultiplier = 1.001;
        chList.push_back (obj);
        }

    myFile.setAnalogChannels (chList);


    myFile.createComtradeFile ("Test.ctff");

    }