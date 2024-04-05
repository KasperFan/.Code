import java.time.LocalDate;

//程序5.12.1 Satellite.java
//卫星类Satellite
class Satellite {
    private int number;//卫星编号
    private LocalDate LaunchDate;//发射日期
    private String rocket;//运载火箭
    private String orbit;/*轨道类型,北斗导航卫星全球星座由地球静止轨道（GEO）卫星、倾斜地球同步轨道（IGSO）卫星和中圆地球轨道（MEO）卫星三种轨道卫星组成*/
    private String type;/*卫星类型，包括北斗1号系统，北斗2号系统，北斗3号试验系统，北斗3号系统*/

    public Satellite() {
    }

    public Satellite(int number, LocalDate launchDate, String rocket, String orbit, String type) {
        super();
        this.number = number;
        LaunchDate = launchDate;
        this.rocket = rocket;
        this.orbit = orbit;
        this.type = type;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public LocalDate getLaunchDate() {
        return LaunchDate;
    }

    public void setLaunchDate(LocalDate launchDate) {
        LaunchDate = launchDate;
    }

    public String getRocket() {
        return rocket;
    }

    public void setRocket(String rocket) {
        this.rocket = rocket;
    }

    public String getOrbit() {
        return orbit;
    }

    public void setOrbit(String orbit) {
        this.orbit = orbit;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    /**
     * @return 卫星名称
     */
    public String getName() {
        /*北斗一号系统的四颗卫星都称为北斗导航试验卫星，北斗二号发射的第一颗卫星通常称为北斗导航一号星，人们常说的北斗55颗星是指北斗二号系统和北斗三号系统运行和建设过程中发射卫星的总数*/
        String name = "";
        if (number < 5) {
            name = "第" + number + "颗北斗导航试验卫星";
        } else {
            name = "第" + (number - 4) + "颗北斗导航卫星";
        }
        return name;
    }

    public void showInfo() {
        System.out.println(this.getName() + "\t" + this.getLaunchDate() + "\t" + this.getRocket() + "\t" + this.getOrbit());
    }
}

//程序5.12.3 Beidou.java
/*北斗类Beidou*/
class Beidou {
    private int number; //编号
    private String start; //启动时间
    private String finish;//建成时间
    private Satellite[] satellites; //包含的卫星
    private int count = 0;//卫星数量

    public Beidou() {
    }

    public Beidou(int number, String start, String finish) {
        super();
        this.number = number;
        this.start = start;
        this.finish = finish;
    }

    public Beidou(int number, String start, String finish, Satellite[] satellites) {
        this.number = number;
        this.start = start;
        this.finish = finish;
        this.satellites = satellites;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getStart() {
        return start;
    }

    public void setStart(String start) {
        this.start = start;
    }

    public String getFinish() {
        return finish;
    }

    public void setFinish(String finish) {
        this.finish = finish;
    }

    public Satellite[] getSatellites() {
        return satellites;
    }

    public void setSatellites(Satellite[] satellites) {
        this.satellites = satellites;
    }

    public void addSatellites(Satellite satellite) {
        this.satellites[count++] = satellite;
    }

    public void showInfo() {
        System.out.println("北斗" + this.getNumber() + "号系统从" + this.getStart() + "开始建设到" + this.finish + "建成，包括" + this.getSatellites().length + "颗卫星。");
        System.out.println("部分卫星信息如下：");
        System.out.println("卫星名称\t\t" + "发射时间\t" + "\t运载火箭\t" + "轨道\t");
        int i = 0;
        while (this.getSatellites()[i] != null) {
            this.getSatellites()[i].showInfo();
            i++;
        }
        System.out.println();
    }
}

//程序5.12.4 BeidouSystem.java
/*北斗系统类BeidouSystem*/
public class BeidouSystem {
    public static void main(String[] args) {
        Beidou[] beidous = new Beidou[3];
        //北斗系统从开始建设到全面组网一共发射了59颗卫星，其中北斗一号系统发射了4颗卫星，
        //北斗二号系统发射了20颗，北斗三号系统发射了35颗。
        Satellite[] satellites = new Satellite[59];
        beidous[0] = new Beidou(1, "1994年", "2003年", new Satellite[4]);
        beidous[1] = new Beidou(2, "2004年", "2012年", new Satellite[20]);
        beidous[2] = new Beidou(3, "2009年", "2020年", new Satellite[35]);
        //创建北斗一号系统的4颗卫星
        satellites[0] = new Satellite(1, LocalDate.of(2000, 10, 31), "CZ-3A", "GEO", "北斗1号系统");
        satellites[1] = new Satellite(2, LocalDate.of(2003, 05, 25), "CZ-3A", "GEO", "北斗1号系统");
        satellites[2] = new Satellite(5, LocalDate.of(2007, 04, 14), "CZ-3A", "MEO", "北斗2号系统");
        satellites[3] = new Satellite(6, LocalDate.of(2009, 04, 15), "CZ-3C", "GEO", "北斗2号系统");
        satellites[4] = new Satellite(22, LocalDate.of(2015, 07, 25), "CZ-3B", "MEO", "北斗3号试验系统");
        satellites[5] = new Satellite(23, LocalDate.of(2015, 07, 25), "CZ-3B", "MEO", "北斗3号试验系统");
        satellites[6] = new Satellite(28, LocalDate.of(2017, 11, 05), "CZ-3B", "MEO", "北斗3号系统");
        satellites[7] = new Satellite(29, LocalDate.of(2017, 11, 05), "CZ-3B", "MEO", "北斗3号系统");
        int i = 0;
        while (satellites[i] != null) {
            int x = satellites[i].getType().charAt(2) - '1';
            beidous[x].addSatellites(satellites[i]);
            i++;
        }
        beidous[0].showInfo();
        beidous[1].showInfo();
        beidous[2].showInfo();
    }
}

