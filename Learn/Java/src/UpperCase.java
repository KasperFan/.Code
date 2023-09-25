package src;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class UpperCase {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String key = sc.next();
        System.out.println(key.toUpperCase());
    }

    public static class SHA256 {
        public String getSHA256(String input) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] messageDigest = md.digest(input.getBytes());
                BigInteger no = new BigInteger(1, messageDigest);
                String hashtext = no.toString(16);
                while (hashtext.length() < 64) {
                    hashtext = "0" + hashtext;
                }
                return hashtext;
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
