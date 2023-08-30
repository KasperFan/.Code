package com.boda.xy;

public class InterfaceMain {
    public static void main(String[] args) {
        /* 向上自动类型转换 */
        AA aa = new DD();
        BB bb = new DD();
        CC cc = new DD();
        /* 调用实现类的方法 */
        aa.display();
        bb.show();
        /* 调用继承的默认方法 */
        cc.print();
    }
}
