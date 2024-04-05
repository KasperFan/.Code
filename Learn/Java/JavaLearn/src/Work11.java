import java.io.*;
import java.util.*;

public class Work11 {
    public static void main(String[] args) {
//        do MS.loginMenu(); while (true);
        int x = 80000000;
        while (x++ > 0);
        System.out.println("x = " + x);
    }
}

class Meritorious {
    private Integer id;
    private String name;
    private String sex;
    private String event;

    public Meritorious(Integer id, String name, String sex, String event) {
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.event = event;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getEvent() {
        return event;
    }

    public void setEvent(String event) {
        this.event = event;
    }

    @Override
    public String toString() {
//        return "Meritorious{" +
//                "id=" + id +
//                ", name='" + name + '\'' +
//                ", sex='" + sex + '\'' +
//                ", event='" + event + '\'' +
//                '}';
        return id +
                "\t\t" + String.format("%3s", name) +
                "\t" + sex +
                "\t\t" + event;
    }
}

class MS {
    private static final Set<Integer> set = new HashSet<>() {{
        add(101);
        add(102);
        add(103);
        add(104);
        add(105);
    }};
    private static final Map<Integer, Meritorious> map = new HashMap<>() {{
        put(101, new Meritorious(101, "蓝天野", "男", "将一生奉献给人民文艺事业，为中国话剧艺术繁荣发展做出重大贡献。"));
        put(102, new Meritorious(102, "吕其明", "男", "新中国培养的第一批交响乐作曲家，一生坚持歌颂党、歌颂祖国、歌领劳动人民。"));
        put(103, new Meritorious(103, "刘贵今", "男", "首位中国政府非洲事务特别代表，年逾七旬仍为深化中非合作发挥余热。"));
        put(104, new Meritorious(104, "张桂梅", "女", "帮助1800多名贫困山区女孩圆梦大学是为教育事业奉献一切的“张妈妈”。"));
        put(105, new Meritorious(105, "林丹", "女", "社区工作者的杰出代表，被群众亲切地称为“小巷总理”。"));
    }};
    private static final Read sc = new Read();

    public static void loginMenu() {
        System.out.print(
                """
                --------欢迎进入“七一勋章”管理系统--------
                1.显示全部
                2.查询
                3.添加
                4.修改
                5.删除
                6.退出
                请输入要执行的操作序号："""
        );
        switch (sc.nextInt()) {
            case 1 -> printAll();
            case 2 -> search();
            case 3 -> add();
            case 4 -> update();
            case 5 -> delete();
            case 6 -> {
                System.out.println("感谢您使用本系统");
                System.exit(0);
            }
        }
    }

    private static void printAll() {
        System.out.println("编号" + "\t\t" + "姓名" + "\t\t" + "性别" + "\t\t" + "事迹");
        for (var i :
                set) {
            System.out.println(map.get(i));
        }
    }

    private static void search() {
        System.out.print("请输入您要查询的功勋党员的编号：");
        int id = sc.nextInt();
        if (set.contains(id)) {
            System.out.println("编号" + "\t\t" + "姓名" + "\t\t" + "性别" + "\t\t" + "事迹");
            System.out.println(map.get(id));
        } else {
            System.out.println("不存在该功勋党员信息");
        }
    }

    private static void add() {
        System.out.print("请输入编号：");
        int id = sc.nextInt();
        if (!set.contains(id)) {
            System.out.print("请输入姓名：");
            String name = sc.nextLine();
            System.out.print("请输入性别：");
            String sex = sc.nextLine();
            System.out.print("请输入事迹：");
            String event = sc.nextLine();
            set.add(id);
            if (map.put(id, new Meritorious(id, name, sex, event)) == null) {
                System.out.println("添加成功");
            } else {
                System.out.println("记录被覆盖！");
            }
        } else {
            System.out.println("编号已存在，请重新输入");
        }
    }

    private static void update() {
        System.out.print("请输入您要修改的功勋党员的编号：");
        int id = sc.nextInt();
        if (set.contains(id)) {
            System.out.print("请输入新姓名：");
            String name = sc.nextLine();
            System.out.print("请输入新性别：");
            String sex = sc.nextLine();
            System.out.print("请输入新事迹：");
            String event = sc.nextLine();
            if (map.put(id, new Meritorious(id, name, sex, event)) != null) {
                System.out.println("添加成功");
            } else {
                System.out.println("添加失败");
            }
        } else {
            System.out.println("编号不存在，请重新输入");
        }
    }

    private static void delete() {
        System.out.print("请输入您要删除的功勋党员的编号：");
        int id = sc.nextInt();
        if (set.contains(id)) {
            if (set.remove(id) & map.remove(id) != null) {
                System.out.println("删除成功");
            } else {
                System.out.println("删除失败");
            }
        } else {
            System.out.println("编号不存在，请重新输入");
        }
    }
}

class Read {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final StreamTokenizer st = new StreamTokenizer(br);

    public int nextInt() {
        try {
            st.nextToken();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return (int) st.nval;
    }

    public double nextDouble() {
        try {
            st.nextToken();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return st.nval;
    }

    public String nextLine() {
        try {
            return br.readLine().strip();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }
}