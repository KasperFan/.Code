abstract class Person {
    public abstract String getName();

    public int getID() {
        return 0;
    }
}

interface Identified {
    public String getName();

    public default int getID() {
        return Math.abs(hashCode());
    }
}

class Employee extends Person implements Identified {
    @Override
    public String getName() {
        return null;
    }
}

interface Eatable {
    String eat(String food);
}

abstract class Animal {
    public abstract void feed(String food);
}

class Dog extends Animal implements Eatable {

    @Override
    public void feed(String food) {
        System.out.println(eat(food));
    }

    @Override
    public String eat(String food) {
        if (food.equals("骨头")) {
            return "汪汪～";
        } else {
            return "呜呜~";
        }
    }
}

class Cat extends Animal implements Eatable {

    @Override
    public void feed(String food) {
        System.out.println(eat(food));
    }

    @Override
    public String eat(String food) {
        if (food.equals("小鱼")) {
            return "喵喵～";
        } else {
            return "呜呜~";
        }
    }
}

public class Work9 {
    public static void main(String[] args) {
        Dog dog = new Dog();
        Cat cat = new Cat();
        dog.feed("骨头"); dog.feed("小鱼");
        cat.feed("小鱼"); cat.feed("骨头");
    }
}
