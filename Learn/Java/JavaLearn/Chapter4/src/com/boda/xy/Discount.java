package com.boda.xy;

/**
 * 使用new关键字可以创建对象，但Java类库中的一些类不能以这种方式实例化。
 * <p>例如，不能使用new创建java.time.LocalDate类的实例，因为它的构造方法是私有的
 * <p>但是可以使用它的一个静态方法，例如now创建该类实例:
 * <p>LocalDate today = LocalDate.now();
 * <p>这种方法称为 <strong>静态工厂方法(static factory method)</strong>
 */
public class Discount {
    /**
     * 表示折扣率的int型字段
     * <p>可以是10(小客户)，也可以是12(大客户)</p>
     */
    private int value;

    /**
     * 私有构造方法
     * <p>使用这种设计，就可以将Discount对象限制为只使用10或12，而不允许使用其它值</p>
     */
    private Discount(int value) {
        this.value = value;
    }

    /**
     * 静态工厂方法可以调用私有构造方法来创建对象，因为它们位于同一个类中。
     */

    public static Discount createSmallCustomerDiscount() {
        return new Discount(10);
    }

    /**
     * 静态工厂方法可以调用私有构造方法来创建对象，因为它们位于同一个类中。
     */

    public static Discount createBigCustomerDiscount() {
        return new Discount(12);
    }

    /**
     * 没有定义setValue()方法，不允许修改折扣率
     */
    public int getValue() {
        return value;
    }

    public static void main(String[] args) {
        /* 现在就可以通过调用它的一个静态工厂方法来构造一个Discount对象 */
        Discount discount = Discount.createBigCustomerDiscount();
        System.out.println(discount.getValue());
    }
}
