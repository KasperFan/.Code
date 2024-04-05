package xdx;

public class People {
    public static int num = 1; // static: 类变量，被这个类的所有实例对象共享
    protected String name;
    protected String sex;
    protected String ID;

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public String getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    // 形如 public/private/protected/（缺省） 这种在最前面的关键字是访问修饰符
//        public：所有的类，包括同一包内和不同包内的类都可访问
//        缺省：仅同一包内的类可访问
//        private：私密的，仅该类中的成员可访问
//        protected：受保护的

    // 构造方法：有蓝图了肯定要用来实例化具体的东西
    // 对象是类的一个实例

    // 方法重载
    public People() {
    }

    public People(String name, String sex, String ID) {
        this.name = name;
        this.sex = sex;
        this.ID = ID;
    }

    public void sayHello() {
        System.out.println("Hi, my name is " + name + " ,my sex is " + sex + " ,my ID is " + ID);
    }
}
