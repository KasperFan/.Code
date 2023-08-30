import java.io.IOException;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger a = new BigInteger(Input.readString());
        BigInteger b = new BigInteger(Input.readString());
        a=a.multiply(b);
        System.out.println(a);
    }
    static class Input {
        private static char bufferChar;

        public static int readInt() {
            int result = 0;
            try {
                bufferChar = (char) System.in.read();
                while (bufferChar >= '0' && bufferChar <= '9') {
                    result = result * 10 + (bufferChar - '0');
                    bufferChar = (char) System.in.read();
                }
            } catch (IOException ignored) {
            }
            return result;
        }

        public static double readDouble() {
            int count = 0;
            double result = 0.0;
            try {
                bufferChar = (char) System.in.read();
                while ((bufferChar >= '0' && bufferChar <= '9') || bufferChar == '.') {
                    if (bufferChar == '.') {
                        break;
                    }
                    result = result * 10 + (bufferChar - '0');
                    bufferChar = (char) System.in.read();
                }
                bufferChar = (char) System.in.read();
                while (bufferChar >= '0' && bufferChar <= '9') {
                    result = result * 10 + (bufferChar - '0');
                    count++;
                    bufferChar = (char) System.in.read();
                }
                result /= Math.pow(10, count);
            } catch (IOException ignored) {
            }
            return result;
        }

        public static String readString() {
            StringBuilder stringBuffer  = new StringBuilder();
            try {
                bufferChar = (char) System.in.read();
                while ((bufferChar >= 32 && bufferChar <= 126)){
                    stringBuffer.append(bufferChar);
                    bufferChar = (char) System.in.read();
                }
            }catch (IOException ignored) {}
            return stringBuffer.toString();
        }

        public static char readChar() {
            char result = 0;
            try {
                result = (char) System.in.read();
            }catch (IOException ignored) {}
            return result;
        }
    }
}
