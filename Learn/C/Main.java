public class Main {
    public static class Person {

        String name, id, sex;

        public Person(String name, String id, String sex) {
            this.name = name;
            this.id = id;
            this.sex = sex;
        }

        public void show() {
            System.out.println("Hi, I'm " + name);
        }
    }
    
    public static class Student extends Person {
    
        double score;

        public Student(String name, String id, String sex, double score) {
            super(name, id, sex);
            this.score = score;
        }

        @Override
        public void show() {
            System.out.println("Hi, I'm " + name + "My score is " + score);
        }
    }
    public static void main(String... args) {
        Person per = new Student("Xiaoming", "001", "男", 3.14);
        per.show();
    }
}