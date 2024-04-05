import java.util.Scanner;
public class Exec6 {
    //定义接口
    static interface Movable {
        public abstract void move();
    }
    //定义抽象类
    static abstract class Vehicle implements Movable{
        private int speed;//速度
        private double time;//时间
        private double s;//距离
        public Vehicle() {
            super();
        }
        //带参数的构造方法，只需指定速度和时间即可获得距离
        public Vehicle(int speed, double time) {
            super();
            this.speed = speed;
            this.time = time;
            this.s=speed*time;
        }
        public int getSpeed() {
            return speed;
        }
        public void setSpeed(int speed) {
            this.speed = speed;
        }
        public double getTime() {
            return time;
        }
        public void setTime(double time) {
            this.time = time;
        }
        public double getS() {
            s=speed*time; //距离=速度*时间
            return s;
        }
        public abstract void showInfo();
    }
    //定义Car子类
    static class Car extends Vehicle{
        private String brand;//汽车品牌
        public Car() {

        }
        //带参数的构造方法
        public Car(String brand,int speed, double time) {
            super(speed, time);//调用父类的带参数的构造方法
            this.brand = brand;
        }
        @Override //实现接口中的move方法
        public void move() {
            System.out.println("汽车在公路上行驶");
        }
        @Override //实现抽象类中的showInfo方法
        public void showInfo() {
            System.out.println("汽车品牌为："+brand);
            System.out.println("汽车以时速"+this.getSpeed()+"千米/小时的速度行驶了"+this.getTime()+"小时，行驶的路程为："+this.getS()+"千米");
        }
    }
    //定义Train子类
    static class Train extends Vehicle {
        private String number;//车次
        public Train() {

        }
        public Train(String number,int speed, double time) {
            super(speed, time);//调用父类的带参数的构造方法
            this.number = number;
        }

        @Override //实现接口中的move方法
        public void move() {
            System.out.println("火车在轨道上行驶");
        }
        @Override //实现抽象类中的showInfo方法
        public void showInfo() {
            System.out.println("火车车次为："+number);
            System.out.println("火车以时速"+this.getSpeed()+"千米/小时的速度行驶了"+this.getTime()+"小时，行驶的路程为："+this.getS()+"千米");
        }
    }
    //定义Plane子类
    static class Plane extends Vehicle{
        private String flight;//航班
        public Plane() {

        }
        public Plane(String flight,int speed, double time) {
            super(speed, time);//调用父类的带参数的构造方法
            this.flight = flight;
        }
        @Override //实现接口中的move方法
        public void move() {
            System.out.println("飞机在天上飞行");
        }
        @Override //实现抽象类中的showInfo方法
        public void showInfo() {
            System.out.println("飞机的航班号为："+flight);
            System.out.println("飞机以时速"+this.getSpeed()+"千米/小时的速度飞行了"+this.getTime()+"小时，飞行的路程为："+this.getS()+"千米");
        }
    }
    //定义测试类
    static class Test {
        public static void main(String[] args) {
            Vehicle veh=null;
            System.out.println("请选择您要乘坐的交通工具：1-汽车  2-火车  3-飞机");
            Scanner input=new Scanner(System.in);
            int type=input.nextInt();
            switch(type) {
                case 1: veh=new Car("红旗",120,1.5);break;
                case 2: veh=new Train("G206",300,1.5);break;
                case 3: veh=new Plane("CA1576",900,1.5);break;
                default:System.out.println("输入有误！");
            }
            if(veh!=null) {
                veh.move();
                veh.showInfo();
            }
        }
    }

}
