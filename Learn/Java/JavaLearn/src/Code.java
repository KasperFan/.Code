import java.io.*;

public class Code {
    public static void main(String... args) {
        PrintWriter put = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.err)));
        byte[] bytes = {-26, -104, -91, -27, -73, -78, -27, -67, -110, -26, -99,
                -91, -17, -68, -116, -25, -100, -117, -25, -66, -114, -28, -70, -70, -27,
                -92, -76, -28, -72, -118, -17, -68, -116, -24, -94, -123, -24, -94, -123,
                -26, -104, -91, -27, -71, -95, -29, -128, -126, 10, -26, -105, -96, -25,
                -85, -81, -23, -93, -114, -23, -101, -88, -17, -68, -116, -26, -100, -86,
                -24, -126, -81, -26, -108, -74, -27, -80, -67, -28, -67, -103, -27, -81,
                -110, -29, -128, -126, 10, -27, -71, -76, -26, -105, -74, -25, -121, -107,
                -27, -83, -112, -17, -68, -116, -26, -106, -103, -28, -69, -118, -27, -82,
                -75, -26, -94, -90, -27, -120, -80, -24, -91, -65, -27, -101, -83, -29, -128,
                -126, 10, -26, -75, -111, -26, -100, -86, -24, -66, -87, -17, -68, -116, -23,
                -69, -124, -26, -97, -111, -24, -115, -112, -23, -123, -110, -17, -68, -116,
                -26, -101, -76, -28, -68, -96, -23, -99, -110, -23, -97, -83, -27, -96, -122,
                -25, -101, -104, -17, -68, -97, 10, 32, 32, 32, 32, -27, -115, -76, -25, -84,
                -111, -28, -72, -100, -23, -93, -114, -17, -68, -116, -28, -69, -114, -26,
                -83, -92, -28, -66, -65, -24, -106, -80, -26, -94, -123, -26, -97, -109, -26,
                -97, -77, -17, -68, -116, -26, -101, -76, -26, -78, -95, -28, -70, -101, -23,
                -105, -78, -29, -128, -126, 10, 32, 32, 32, 32, -23, -105, -78, -26, -105, -74,
                -27, -113, -120, -26, -99, -91, -23, -107, -100, -23, -121, -116, -17, -68,
                -116, -24, -67, -84, -27, -113, -104, -26, -100, -79, -23, -94, -100, -29,
                -128, -126, 10, 32, 32, 32, 32, -26, -72, -123, -26, -124, -127, -28, -72, -115,
                -26, -106, -83, -17, -68, -116, -23, -105, -82, -28, -67, -107, -28, -70, -70,
                -28, -68, -102, -24, -89, -93, -24, -65, -98, -25, -114, -81, -17, -68, -97, 10,
                32, 32, 32, 32, -25, -108, -97, -26, -128, -107, -24, -89, -127, -24, -118, -79,
                -27, -68, -128, -24, -118, -79, -24, -112, -67, -17, -68, -116, -26, -100, -99,
                -26, -99, -91, -27, -95, -98, -23, -101, -127, -27, -123, -120, -24, -65, -104,
                -29, -128, -126, 10,};
        try {
            put.print(new String(bytes, "UTF-8"));
            put.flush();
        } catch (Exception ignored) {
        }
    }
}