import java.util.Scanner;

public class Exec5 {
    static class Person {
        private String ID;//身份证号码
        private String name;//姓名
        private String gender;//性别
        private int age;//年龄
        private String phone;//联系电话
        public Person() {
        }
        public Person(String iD, String name, String gender, int age, String phone) {
            super();
            ID = iD;
            this.name = name;
            this.gender = gender;
            this.age = age;
            this.phone = phone;
        }
        public String getID() {
            return ID;
        }
        public void setID(String iD) {
            ID = iD;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
        public String getGender() {
            return gender;
        }
        public void setGender(String gender) {
            this.gender = gender;
        }
        public int getAge() {
            return age;
        }
        public void setAge(int age) {
            this.age = age;
        }
        public String getPhone() {
            return phone;
        }
        public void setPhone(String phone) {
            this.phone = phone;
        }
        public void introduce() {
            System.out.print("大家好，我是"+name+"，今年"+age+"岁。");
        }
    }
    static class Poor extends Person {
        private String address;//家庭住址
        private String reason;//致贫原因
        private String state;//脱贫状态
        private int number;//家庭人口
        private int income;//年人均收入
        public Poor() {
            super();
        }
        public Poor(String iD,String name, String gender, int age, String phone, String address, String reason, String state,int number,int income) {
            super(iD,name, gender, age, phone);
            this.address = address;
            this.reason = reason;
            this.state = state;
            this.number = number;
            this.income=income;
        }
        /**
         * 重写introduce方法
         */
        @Override
        public void introduce() {
            super.introduce();
            System.out.println("家住"+address+",家里有"+number+"口人，"+reason+"致贫。");
        }
        /**
         * 根据脱贫标准，修改脱贫状态
         * @param standard 表示脱贫标准
         */
        public void setState(int standard) {
            if(income>standard) {
                state="已脱贫";
            }
            else if(income<standard && state.equals("已脱贫")) {
                state="返贫";
            }
        }
        public String getState() {
            return state;
        }
    }
    static class Helper extends Person {
        private String workUnit;//工作单位
        private String politicalOutlook;//政治面貌
        private Poor[] targetOfAids;//帮扶对象
        private int numberOfHelpers;//帮扶数
        public Helper() {
        }
        public Helper(String iD, String name, String gender, int age, String phone, String workUnit,
                      String politicalOutlook) {
            super(iD, name, gender, age, phone);
            this.workUnit = workUnit;
            this.politicalOutlook = politicalOutlook;
            targetOfAids=new Poor[30];
        }
        @Override
        public void introduce() {
            super.introduce();
            System.out.println("来自"+workUnit+",我是一名"+politicalOutlook+",我共帮扶"+numberOfHelpers+"户贫困户，其中已脱贫数为："+this.getNumberOfRelief()+"户");
        }
        /**
         * 修改帮扶对象的脱贫状态
         */
        public void setState() {
            System.out.println("请输入今年的脱贫标准：");
            Scanner input=new Scanner(System.in);
            int standard=input.nextInt();
            for(int i=0;i<this.numberOfHelpers;i++) {
                targetOfAids[i].setState(standard);
            }
        }
        /**
         * 增加帮扶对象
         * @param poor
         */
        public void addTargetOfAid(Poor poor) {
            this.targetOfAids[numberOfHelpers++]=poor;
        }
        /**
         * 统计脱贫人数
         * @return 脱贫人数
         */
        public int getNumberOfRelief() {
            int count=0;
            for(int i=0;i<this.numberOfHelpers;i++) {
                if("已脱贫".equals(targetOfAids[i].getState())) {
                    count++;
                }
            }
            return count;
        }
    }
    static class Test {
        public static void main(String[] args) {
            Poor[] poors=new Poor[5];
            poors[0]=new Poor("370000XXXXXXXXXXX1","张三","男",45,"136XXXXXXX1","桃花村","因病","未脱贫",3,1500);
            poors[1]=new Poor("370000XXXXXXXXXXX2","李四","男",35,"137XXXXXXX1","桃花村","因残","未脱贫",4,1700);
            poors[2]=new Poor("370000XXXXXXXXXXX3","王五","男",48,"138XXXXXXX1","桃花村","缺资金","未脱贫",3,4000);
            poors[0].introduce();
            Helper helper=new Helper("37000019XXXXXXXXX4","赵六","男",35,"139XXXXXX12","民政局","中共党员");
            helper.addTargetOfAid(poors[0]);
            helper.addTargetOfAid(poors[2]);
            helper.setState();
            helper.introduce();
        }
    }

}


