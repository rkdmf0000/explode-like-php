# explode-like-php
It provide like php explode function, but it is parameter variable referencing by a std::list&lt;string>.

`망할 문자열 짜르는 함수입니다 줜나 쓸머없이 멀티바이트를 1바이트로 쪼개서 비교합니다(멀티바이트 지원한다는 이야기) cpp 연습하던중 호구같이 딴길로 새버려서 나온 부산물입니다 ㅠ` 
```c++
/**
 * title        Explode like PHP in c++
 * param        std::list<string>& box      It'll get referenced that std::list string object
 * param        std::string fuckYouText     It make required stuff by this text
 * param        const char limit            it divide string by this and that may be able to using null
 * desc         It provide like php explode function, but it is parameter variable referencing by a std::list<string>.
 * return       void
 * author       me
 * date         20:18 09.02.2020 / 09:39 09.18.2020 / 03:19 09.19.2020 / 22:29 09.20.2020
 * Dependence   std::list, std::string
 * */
```

```c++
    list<string> pTest1;
    string pTest2("1234567890123가05가나4567890123456789");
    string pTest3 = "가나";
    char pTest4[] = {'0','5'};
    explodeLikePHP(pTest1, pTest2, pTest3);
```

```text
string limit size : 1
buff :: 1234567890123가05가나4567890123456789
limit Length : 6
buff :: 4567890123456789
limit Length : 6
Check array
Index 1:1234567890123가05
Index 2:4567890123456789
```
