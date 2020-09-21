### 배열 73,854 길이 근처까지 차면 터져 죽음 해결방안 찾는중
### heap으로 변경했음 한계치 증가
### heap으로 쓰고 다 쓴 배열 지움 한계치 없어짐 와오!

# explode-like-php
It provide like php explode function, but it is parameter variable referencing by a std::list&lt;string>.

`망할 문자열 짜르는 함수입니다 줜나 쓸머없이 멀티바이트를 1바이트로 쪼개서 비교합니다(멀티바이트 지원한다는 이야기) cpp 연습하던중 호구같이 딴길로 새버려서 나온 부산물입니다 ㅠ` 
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
