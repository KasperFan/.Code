package com.boda.xy;

public class Mutton implements Eatable {
    /**
     * 'com.boda.xy.Mutton' 中的 'howToEat()' 与 'com.boda.xy.Eatable' 中的 'howToEat()' 冲突；尝试分配较弱的访问权限('package-private')；曾为 'public'
     * */
    @Override
    public String howToEat() {
        return "烤羊肉串";
    }
}
