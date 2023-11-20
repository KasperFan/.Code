public class Work6 {
    static class People {
        private String name;
        private String sex;
        private int age;
        private String phone;

        public People() {
        }

        public People(String name, String sex, int age, String phone) {
            this.name = name;
            this.sex = sex;
            this.age = age;
            this.phone = phone;
        }

        public void setName(String name) {
            this.name = name;
        }

        public void setSex(String sex) {
            this.sex = sex;
        }

        public void setAge(int age) {
            this.age = age;
        }

        public void setPhone(String phone) {
            this.phone = phone;
        }

        public String getName() {
            return name;
        }

        public String getSex() {
            return sex;
        }

        public int getAge() {
            return age;
        }

        public String getPhone() {
            return phone;
        }

        public void show() {
            System.out.println("姓名 : " + this.name);
            System.out.println("性别 : " + this.sex);
            System.out.println("年龄 : " + this.age);
            System.out.println("电话号码 : " + this.phone);
        }
    }

    class PoorHousehold extends People {
        private String ID;
        private String houseAddress;
        private int membersCount;
        private String poorReason;
        private boolean outPoorStatus;

        public PoorHousehold() {
        }

        public PoorHousehold(String name, String sex, int age, String phone, String ID, String houseAddress, int membersCount, String poorReason, boolean outPoorStatus) {
            super(name, sex, age, phone);
            this.ID = ID;
            this.houseAddress = houseAddress;
            this.membersCount = membersCount;
            this.poorReason = poorReason;
            this.outPoorStatus = outPoorStatus;
        }

        public void setID(String ID) {
            this.ID = ID;
        }

        public void setHouseAddress(String houseAddress) {
            this.houseAddress = houseAddress;
        }

        public void setMembersCount(int membersCount) {
            this.membersCount = membersCount;
        }

        public void setPoorReason(String poorReason) {
            this.poorReason = poorReason;
        }

        public void setOutPoorStatus(boolean outPoorStatus) {
            this.outPoorStatus = outPoorStatus;
        }

        public String getID() {
            return ID;
        }

        public String getHouseAddress() {
            return houseAddress;
        }

        public int getMembersCount() {
            return membersCount;
        }

        public String getPoorReason() {
            return poorReason;
        }

        public boolean isOutPoorStatus() {
            return outPoorStatus;
        }

        @Override
        public void show() {
            super.show();
            System.out.println("身份证号 : " + this.ID);
            System.out.println("家庭住址 : " + this.houseAddress);
            System.out.println("家庭人口 : " + this.membersCount);
            System.out.println("贫困原因 : " + this.poorReason);
            System.out.println("脱贫状态 : " + this.outPoorStatus);
        }

        public void povertyClaim() {
            outPoorStatus = outPoorStatus ? false : true;
        }
    }

    class ResidentVillageCadre extends People {
        private String unit;
        private String job;
        private PoorHousehold objectOfHelp;
        private String methodOfHelp;
        private String addressOfHelp;

        public ResidentVillageCadre() {
        }

        public ResidentVillageCadre(String name, String sex, int age, String phone, String unit, String job, PoorHousehold objectOfHelp, String methodOfHelp, String addressOfHelp) {
            super(name, sex, age, phone);
            this.unit = unit;
            this.job = job;
            this.objectOfHelp = objectOfHelp;
            this.methodOfHelp = methodOfHelp;
            this.addressOfHelp = addressOfHelp;
        }

        public void setUnit(String unit) {
            this.unit = unit;
        }

        public void setJob(String job) {
            this.job = job;
        }

        public void setObjectOfHelp(PoorHousehold objectOfHelp) {
            this.objectOfHelp = objectOfHelp;
        }

        public void setMethodOfHelp(String methodOfHelp) {
            this.methodOfHelp = methodOfHelp;
        }

        public void setAddressOfHelp(String addressOfHelp) {
            this.addressOfHelp = addressOfHelp;
        }

        public String getUnit() {
            return unit;
        }

        public String getJob() {
            return job;
        }

        public PoorHousehold getObjectOfHelp() {
            return objectOfHelp;
        }

        public String getMethodOfHelp() {
            return methodOfHelp;
        }

        public String getAddressOfHelp() {
            return addressOfHelp;
        }

        @Override
        public void show() {
            super.show();
            System.out.println("单位 : " + unit);
            System.out.println("职务 : " + job);
        }

        public void policyIntroduction() {
            System.out.println("帮扶措施 : " + methodOfHelp);
            System.out.println("帮扶地址 : " + addressOfHelp);
        }
    }
}
