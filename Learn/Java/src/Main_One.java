//public class Main_One {
//
//    public static void main(String ... args) {
//        var me = new OldGuys() {
//            private boolean isSleeping = false;
//            public void sleep() { this.isSleeping = true;}
//            public void getUp() { this.isSleeping = false;}
//            public void solveProblem(Exception e) {
//                if (this.isSleeping) {this.getUp();}
//                System.out.println("解决Bug");
//            }
//        };
//        var freshMan = new Freshes() {
//            public void throwException(OldGuys o) {
//                o.solveProblem(new Exception());
//            }
//        };
//
//        me.sleep();
//        freshMan.throwException(me);
//    }
//}