package com.boda.xy;

class Animal {
    private String name = "大熊猫";
    private void display(){
        System.out.println("My name is " + name);
    }
    public static void main(String[] args) {
        Animal a = new Animal();
        /* 'name' 在 'com.boda.xy.Animal' 中具有 private 访问权限 */
        System.out.println("a.name = " + a.name);
        /* 'display()' 在 'com.boda.xy.Animal' 中具有 private 访问权限 */
        a.display();
    }
}
public class AnimalDemo {
    public static void main(String[] args) {
        Animal a = new Animal();
        /**
         * 私有成员不能在类外访问
         * */
        /* 'name' 在 'com.boda.xy.Animal' 中具有 private 访问权限 */
//        System.out.println("a.name = " + a.name);
        /* 'display()' 在 'com.boda.xy.Animal' 中具有 private 访问权限 */
//        a.display();
    }
}
