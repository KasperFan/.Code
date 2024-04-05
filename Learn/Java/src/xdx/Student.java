package xdx;

public class Student extends People {
    private String stuID;
    private int score;

    public Student(String name, String sex, String ID, String stuID, int score) {
        super(name, sex, ID);
        this.stuID = stuID;
        this.score = score;
    }

    public String getStuID() {
        return stuID;
    }

    public void setStuID(String stuID) {
        this.stuID = stuID;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    // 方法重写（方法覆盖）
    @Override
    public void sayHello() {
        System.out.println("Hi, my name is " + name + " ,my sex is " + sex + " ,my stuID is "+stuID);
    }
}
