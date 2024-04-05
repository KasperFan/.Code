import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        int a = sc.nextInt(),
        Student dhr = new Student(001, "杜浩然");
        dhr.exam();
        System.out.println(dhr.score);
    }
}
/*
* struct Student {
*   int id;
*   String name;
*   int score;
* }
* Student stu; // 声明
* stu.id = // 修改（被动）
* */
class Student{
    int id;
    String name;
    double score;

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void exam() {
        this.score = Math.random() * 100;
    }
}
// 123 456 Hello,World!
