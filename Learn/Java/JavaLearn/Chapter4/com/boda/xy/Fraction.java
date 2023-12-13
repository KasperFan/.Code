package com.boda.xy;

public class Fraction {
    private int numer, denom;

    public Fraction() {
        numer = 0;
        denom = 1;
    }

    public Fraction(int numer) {
        this.numer = numer;
        this.denom = 1;
    }

    public Fraction(int numer, int denom) {
        this.numer = numer;
        this.denom = denom;
        this.normalize();
    }

    public int getNumer() {
        return numer;
    }

    public int getDenom() {
        return denom;
    }

    public Fraction add(Fraction fr) {
        return new Fraction(this.numer * fr.denom + fr.numer * this.denom, this.denom * fr.denom);
    }

    public Fraction subtract(Fraction fr) {
        return new Fraction(this.numer * fr.denom - fr.numer * this.denom, this.denom * fr.denom);
    }

    public Fraction multiply(Fraction fr) {
        return new Fraction(this.numer * fr.numer, this.denom * fr.denom);
    }

    public Fraction divide(Fraction fr) {
        return multiply(new Fraction(fr.denom, fr.numer));
    }

    private int gcd() {
        int x = Math.abs(numer);
        int y = Math.abs(denom);
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    public void normalize() {
        if (this.denom == 0)
            throw new RuntimeException("分数的分母不能为0!");
        else if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
        int diviser = gcd();
        numer /= diviser;
        denom /= diviser;
    }

    @Override
    public String toString() {
//        if (denom != 1) {
//            return numer + "/" + denom;
//        } else return String.valueOf(numer);
        return denom == 1 ? String.valueOf(numer) : numer + "/" + denom;
    }
}
