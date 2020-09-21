# explode-like-php
It provide like php explode function, but it is parameter variable referencing by a std::list&lt;string>.


``c++
    list<string> pTest1;
    string pTest2("1234567890123가05가나4567890123456789");
    string pTest3 = "가나";
    char pTest4[] = {'0','5'};
    explodeLikePHP(pTest1, pTest2, pTest3);
`
