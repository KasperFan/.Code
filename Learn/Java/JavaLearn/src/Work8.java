//定义一个Movable移动接口，包含move, speedUp和stop三个方法
interface Movable {
    //移动方法，参数是方向，无返回值
    void move(String direction);

    //提速方法，参数是增加的速度，返回新的速度
    double speedUp(double increment);

    //停止方法，无参数，返回停止的时间
    double stop();
}

//定义一个抽象类Vehicle，表示交通工具，包含color和speed两个属性，以及相关的构造方法，getter和setter方法，和一个计算距离的普通方法
abstract class Vehicle {
    //颜色属性
    private String color;
    //速度属性
    private double speed;

    //无参构造方法，将颜色设为白色，速度设为0
    public Vehicle() {
        this.color = "white";
        this.speed = 0;
    }

    //有参构造方法，根据参数设置颜色和速度
    public Vehicle(String color, double speed) {
        this.color = color;
        this.speed = speed;
    }

    //获取颜色的方法
    public String getColor() {
        return color;
    }

    //设置颜色的方法
    public void setColor(String color) {
        this.color = color;
    }

    //获取速度的方法
    public double getSpeed() {
        return speed;
    }

    //设置速度的方法
    public void setSpeed(double speed) {
        this.speed = speed;
    }

    //计算距离的方法，参数是时间，返回距离
    public double getDistance(double time) {
        return speed * time;
    }
}

//定义一个类Automobile，表示汽车，继承自Vehicle类，实现Movable接口
class Automobile extends Vehicle implements Movable {
    //构造方法，调用父类的构造方法
    public Automobile(String color, double speed) {
        super(color, speed);
    }

    //实现移动方法，打印汽车的移动方向
    public void move(String direction) {
        System.out.println("汽车向" + direction + "移动");
    }

    //实现提速方法，增加速度，并返回新的速度
    public double speedUp(double increment) {
        setSpeed(getSpeed() + increment);
        return getSpeed();
    }

    //实现停止方法，将速度设为0，并返回停止的时间，假设为5秒
    public double stop() {
        setSpeed(0);
        return 5;
    }
}

//定义一个类Train，表示火车，继承自Vehicle类，实现Movable接口
class Train extends Vehicle implements Movable {
    //构造方法，调用父类的构造方法
    public Train(String color, double speed) {
        super(color, speed);
    }

    //实现移动方法，打印火车的移动方向
    public void move(String direction) {
        System.out.println("火车向" + direction + "移动");
    }

    //实现提速方法，增加速度，并返回新的速度
    public double speedUp(double increment) {
        setSpeed(getSpeed() + increment);
        return getSpeed();
    }

    //实现停止方法，将速度设为0，并返回停止的时间，假设为10秒
    public double stop() {
        setSpeed(0);
        return 10;
    }
}

//定义一个类Airplane，表示飞机，继承自Vehicle类，实现Movable接口
class Airplane extends Vehicle implements Movable {
    //构造方法，调用父类的构造方法
    public Airplane(String color, double speed) {
        super(color, speed);
    }

    //实现移动方法，打印飞机的移动方向
    public void move(String direction) {
        System.out.println("飞机向" + direction + "移动");
    }

    //实现提速方法，增加速度，并返回新的速度
    public double speedUp(double increment) {
        setSpeed(getSpeed() + increment);
        return getSpeed();
    }

    //实现停止方法，将速度设为0，并返回停止的时间，假设为15秒
    public double stop() {
        setSpeed(0);
        return 15;
    }
}

//定义一个测试类，测试这些交通工具的使用
public class Work8 {
    public static void main(String[] args) {
        //创建一个汽车对象，颜色为红色，速度为60
        Automobile car = new Automobile("red", 60);
        //打印汽车的颜色和速度
        System.out.println("汽车的颜色是：" + car.getColor());
        System.out.println("汽车的速度是：" + car.getSpeed());
        //调用汽车的移动方法，参数为前
        car.move("前");
        //调用汽车的提速方法，参数为20，打印新的速度
        System.out.println("汽车提速后的速度是：" + car.speedUp(20));
        //调用汽车的停止方法，打印停止的时间
        System.out.println("汽车停止的时间是：" + car.stop());

        //创建一个火车对象，颜色为蓝色，速度为120
        Train train = new Train("blue", 120);
        //打印火车的颜色和速度
        System.out.println("火车的颜色是：" + train.getColor());
        System.out.println("火车的速度是：" + train.getSpeed());
        //调用火车的移动方法，参数为后
        train.move("后");
        //调用火车的提速方法，参数为30，打印新的速度
        System.out.println("火车提速后的速度是：" + train.speedUp(30));
        //调用火车的停止方法，打印停止的时间
        System.out.println("火车停止的时间是：" + train.stop());

        //创建一个飞机对象，颜色为白色，速度为600
        Airplane airplane = new Airplane("white", 600);
        //打印飞机的颜色和速度
        System.out.println("飞机的颜色是：" + airplane.getColor());
        System.out.println("飞机的速度是：" + airplane.getSpeed());
        //调用飞机的移动方法，参数为上
        airplane.move("上");
        //调用飞机的提速方法，参数为100，打印新的速度
        System.out.println("飞机提速后的速度是：" + airplane.speedUp(100));
        //调用飞机的停止方法，打印停止的时间
        System.out.println("飞机停止的时间是：" + airplane.stop());
    }
}

