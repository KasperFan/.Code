package xdx;

// Arrays类被包含于xdx包内
public class Arrays {
    //    static 意为静态的，在一个类的内部，只有静态的才能调用静态的

    public static void main(String[] args) {
        // 引用类型（C语言指针）
        /*
        * int *p = (int *)malloc(sizeof(int))
        * */
//        int long double float char
//        String Scanner
        People zhang = new People("张三", "男", "4523452346354");
        zhang.sayHello();
        // 多态
        People li = new Student("李四", "男", "452345as4", "123456", 45);
        li.sayHello();
        People[] peoples = new People[10];
        for (int i = 0; i < peoples.length; i++) {
            peoples[i] = new People();
        }
        System.out.println(peoples[4].getName());
    }
}
