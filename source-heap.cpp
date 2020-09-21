/**
 * title        Explode like PHP in c++
 * param        std::list<string>& box          It'll get referenced that std::list string object
 * param        std::string fuckYouText         It make required stuff by this text
 * param        char limit[]                    It divide string by this and that may be able to using null
 * param        const std::size_t limitSize     Limit array size
 * desc         It provide like php explode function, but it is parameter variable reference by a std::list<string>.
 * return       void
 * author       me
 * date         20:18 09.02.2020 / 09:39 09.18.2020 / 03:19 09.19.2020 / 22:29 09.20.2020
 * Dependence   std::list, std::string
 * */

void explodeLikePHP(std::list<string>& box, std::string fuckYouText, char limit[], const std::size_t limitSize)
{
    //section of declare
    bool breakPointFlag(false);
    bool isNotFoundLimitorLefts(true);
    const std::size_t stringLength = fuckYouText.size();
    const std::size_t limitLength = limitSize;
    const unsigned int I_multiByt(3);
    std::string xc;

    //new-type stack initialize(3D)
    char ***localCharsetStorage = new char**[stringLength];

    //declaring multidimensional array
    for(unsigned int d1i(0);d1i<stringLength;++d1i)
    {
        localCharsetStorage[d1i] = new char*[I_multiByt];
        for(unsigned int d2i(0);d2i<I_multiByt;++d2i) 
            localCharsetStorage[d1i][d2i] = new char[limitLength];
    };

    //prepare consumable charset putting
    for ( unsigned int pwi(0); pwi<(stringLength); ++pwi )
        for ( unsigned int mdi(0); mdi<(I_multiByt); ++mdi )
            for ( unsigned int ldi(0); ldi<(limitLength); ++ldi )
                localCharsetStorage[pwi][mdi][ldi] = fuckYouText[pwi+mdi+ldi];

    for (int xcIdx(0);xcIdx<limitLength;++xcIdx) xc+=limit[xcIdx];

    for( unsigned int ci(0); ci<stringLength; ++ci )
    {
        for ( unsigned int mdi(0); mdi<(I_multiByt); ++mdi )
        {
            std::string yc;
            for ( unsigned int ldi(0); ldi<(limitLength); ++ldi ) yc += localCharsetStorage[ci][mdi][ldi];
            
            //Important condition
            if (xc.compare(yc) == 0) {
                breakPointFlag = true;
                isNotFoundLimitorLefts = false;
                box.push_back(fuckYouText.substr(0,ci+mdi));
                std::string dummyStr;
                for(unsigned int eraseIdx(ci+mdi+limitLength); eraseIdx<stringLength; ++eraseIdx) dummyStr += fuckYouText[eraseIdx];
                fuckYouText.clear();
                fuckYouText = std::move(dummyStr);
                
                //clear multidimensional char array
                for(unsigned int d1i(0);d1i<stringLength;++d1i)
                    for(unsigned int d2i(0);d2i<I_multiByt;++d2i)
                        delete[] localCharsetStorage[d1i][d2i];
                for(unsigned int d1i(0);d1i<stringLength;++d1i)
                    delete[] localCharsetStorage[d1i];
                delete[] localCharsetStorage;
                //re-call next level
                explodeLikePHP(box, fuckYouText, limit, limitLength);
            }
            if (breakPointFlag == true) break;
        };
        if (breakPointFlag == true) break;
    };

    //if is may be cannot comparable or last compare.
    if (isNotFoundLimitorLefts == true) box.push_back(fuckYouText);
};
void explodeLikePHP(std::list<string>& box, std::string fuckYouText, const std::string& limit)
{
    const std::size_t size = limit.size();
    char c_limit[size];
    for(unsigned int i(0);i<size;++i) c_limit[i] = limit[i];
    explodeLikePHP(box, fuckYouText, c_limit, size);
};
