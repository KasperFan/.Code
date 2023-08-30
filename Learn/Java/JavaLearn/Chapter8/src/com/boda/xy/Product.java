package com.boda.xy;

import java.util.Objects;

public class Product {
    private Integer id;
    private String name;
    private String brand;
    private double price;

    public Product() {
    }

    public Product(Integer id, String name, String brand, double price) {
        this.id = id;
        this.name = name;
        this.brand = brand;
        this.price = price;
    }

    @Override
    public boolean equals(Object obj) {
//        return super.equals(obj);
        return Objects.equals(this, obj);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, brand, price);
    }

    @Override
    public String toString() {
        return "Product{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", brand='" + brand + '\'' +
                ", price=" + price +
                '}';
    }
}
