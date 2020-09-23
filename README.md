> ### SOURCE : https://github.com/rkdmf0000/explode-like-php/blob/master/source-heap.cpp

# explode-like-php
It provide like php explode function, but it is parameter variable referencing by a std::list<string>.
that is being compared step by a byte!
and any BIG string is not problem
    
```c++
/**
 * title        Explode like PHP in c++
 * param        std::list<string>& box          It'll get referenced that std::list string object
 * param        std::string fuckYouText         It make required stuff by this text
 * param        char limit[]                    It divide string by this and that may be able to using null
 * param        const std::size_t limitSize     Limit array size
 * desc         It provide like php explode function, but it is parameter variable referencing by a std::list<string>.
 * return       void
 * author       me
 * date         20:18 09.02.2020 / 09:39 09.18.2020 / 03:19 09.19.2020 / 22:29 09.20.2020
 * Dependence   std::list, std::string, std::size_t or unsigned int
 * */
```

`실행`
```c++
    list<string> pTest1;
    string pTest2("12345가067890123가05가나다4567890가0123456가0789");
    string pTest3 = "가0";
    char pTest4[] = {'0','5'};
    explodeLikePHP(pTest1, pTest2, pTest3);
```

`검증`
```c++
    cout << "Check array" << '\n';
    list<string>::iterator testIter1;
    int testIdx(0);
    for (testIter1=pTest1.begin();testIter1!=pTest1.end();++testIter1)
    {
        ++testIdx;
        cout << "Index " << testIdx << ":" << *testIter1 << '\n';
    }
```

`결과`
```text
string limit size : 4
buff :: 12345가067890123가05가나다4567890가0123456가0789
limit Length : 4
buff :: 67890123가05가나다4567890가0123456가0789
limit Length : 4
buff :: 5가나다4567890가0123456가0789
limit Length : 4
buff :: 123456가0789
limit Length : 4
buff :: 789
limit Length : 4
Check array
Index 1:12345
Index 2:67890123
Index 3:5가나다4567890
Index 4:123456
Index 5:789
```
