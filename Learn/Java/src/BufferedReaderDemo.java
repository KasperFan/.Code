import java.io.*;

public class BufferedReaderDemo {
    public static void main(String[] args) throws IOException {
        //创建一个BufferedReader对象，用于从标准输入流中读取文本数据
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //读取一行文本
        String line = br.readLine();
        //打印读取到的文本
        System.out.println("您输入了：" + line);
        //将读取到的文本转换为字符数组
        char[] chars = line.toCharArray();
        //将字符数组的前三个字符返回到输入缓冲区
//        br.unread(chars, 0, 3);
        //再次读取一行文本
        String line2 = br.readLine();
        //打印读取到的文本
        System.out.println("您再次输入了：" + line2);
    }
}
