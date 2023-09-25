package com.boda.xy;

import java.io.UnsupportedEncodingException;

public class StringLearn {
    /* 创建String类对象 */
    /**
     * 直接利用字符串字面值创建字符串对象
     */
    String str = "Java is cool";

    /* 文本块 */

    /**
     * 在Java15之前，对多行大块文本通常使用换行(\n)和连接符(+)表示
     * <blockquote><pre>{@code
     *     String poem = "白日依山尽\n" +
     *             "黄河入海流\n" +
     *             "   欲穷千里目,\n" +
     *             "   更上一层楼。";
     * }</pre></blockquote>
     * Java15提供了<strong>文本块</strong>(text block)的特性，对大块文本输出可以不使用连接符(+)，而是直接给出文本。
     * <p>文本块的定界符是3个双引号，在起始定界符后面可跟0个或多个空格和一个行终止符，结束符没有类似规则，如：</p>
     * <blockquote><pre>{@code
     *     String poem = """
     *             白日依山尽，
     *             黄河入海流。
     *                欲穷千里目，
     *                更上一层楼。""";}</pre></blockquote>
     */

    public static void main(String[] args) throws UnsupportedEncodingException {
        var streg = "Java很有趣";
        byte[] bytes = streg.getBytes();
        for (var elem :
                bytes) {
            System.out.println(elem);
        }
        System.out.println(new String(bytes, "UTF-8"));
    }
}
