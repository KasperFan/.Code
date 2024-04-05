class HealthCodeException extends Exception {
    public HealthCodeException() {
    }

    public HealthCodeException(String message) {
        super(message);
    }
}

class TripCodeException extends Exception {
    public TripCodeException() {
    }

    public TripCodeException(String message) {
        super(message);
    }
}

public class Work10 {
    public static void healthCodeCheck(String code) throws HealthCodeException {
        if (code.equals("红码") || code.equals("黄码")) {
            throw new HealthCodeException(code+"人员，禁止进入校园。");
        }
    }

    public static void tripCodeCheck(String code) throws TripCodeException {
        if (code.contains("*")) {
            throw new TripCodeException("行程码带'*'人员，禁止进入校园。");
        }
    }

    public static void main(String[] args) {
        try {
            healthCodeCheck("黄码");
            tripCodeCheck("济南*");
        } catch (HealthCodeException | TripCodeException e) {
            throw new RuntimeException(e);
        }
    }
}
