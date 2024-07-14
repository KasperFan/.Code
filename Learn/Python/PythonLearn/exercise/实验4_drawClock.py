from turtle import *
from datetime import *


def skip(step: float):
    penup()
    forward(step)
    pendown()


# 建立钟表的外框
def setup_clock(radius: float):
    reset()
    pensize(7)
    for i in range(60):
        skip(radius)
        if i % 5 == 0:
            forward(20)
            skip(-radius - 20)
        else:
            dot(5)
            skip(-radius)
        right(6)


# 注册turtle形状，建立名字为name的形状
def make_hand(name, length):
    reset()
    skip(-0.1 * length)
    # 开始记录多边形的顶点
    begin_poly()
    forward(1.1 * length)
    # 停止记录多边形的顶点,并与第一个顶点相连
    end_poly()
    # 返回最后记录的多边形
    hand_form = get_poly()
    # 注册形状，命名为name
    register_shape(name, hand_form)


def init():
    global secHand, minHand, hurHand, printer
    # 重置turtle指针向北
    mode("logo")
    secHand = Turtle()
    make_hand("secHand", 125)
    secHand.shape("secHand")
    minHand = Turtle()
    make_hand("minHand", 130)
    minHand.shape("minHand")
    hurHand = Turtle()
    make_hand("hurHand", 90)
    hurHand.shape("hurHand")
    # shapesize第一个参数没看到什么用，第二个参数表示几倍的长度，第3个参数表示3倍的宽度
    # speed(0)是最快
    for hand in secHand, minHand, hurHand:
        hand.shapesize(1, 1, 3)
        hand.speed(0)
    # 建立并输出文字的turtle对象，printer对象只是显示文字不显示路径，所以一直是penup和hideturtle
    printer = Turtle()
    printer.hideturtle()
    printer.penup()


def week(t):
    week = ["星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期七"]
    return week[t.weekday()]


def Day(t):
    return "%s %d %d" % (t.year, t.month, t.day)


def Tick():
    t = datetime.today()
    second = t.second + t.microsecond * 0.000001
    minute = t.minute + t.second / 60.0
    hour = t.hour + t.minute / 60.0
    secHand.setheading(second * 6)
    minHand.setheading(minute * 6)
    hurHand.setheading(hour * 30)

    tracer(False)
    printer.fd(70)
    printer.write(week(t), align="center", font=("Courier", 14, "bold"))
    printer.back(130)
    printer.write(Day(t), align="center", font=("Courier", 14, "bold"))
    printer.home()
    tracer(True)

    ontimer(Tick, 100)  # 100ms后继续调用Tick


def main():
    # 关闭动画
    tracer(False)
    init()
    setup_clock(200)
    # 开启动画
    tracer(True)
    Tick()
    done()


if __name__ == "__main__":
    main()
