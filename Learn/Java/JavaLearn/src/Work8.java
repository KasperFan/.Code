public class Work8 {
    public interface Movable {

    }
    public abstract class Vehicle {
        private String color;
        private double speed;

        public Vehicle() {
        }

        public Vehicle(String color, double speed) {
            this.color = color;
            this.speed = speed;
        }

        public void setColor(String color) {
            this.color = color;
        }

        public void setSpeed(double speed) {
            this.speed = speed;
        }

        public String getColor() {
            return color;
        }

        public double getSpeed() {
            return speed;
        }
    }
}
