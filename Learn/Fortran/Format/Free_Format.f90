! · 没有规定每一行的第几个字符有什么作用
! · 注意：
!   - 符号!后面的文本都是注释
!   - 每行可以编写132个字符
!   - 行号放在每行程序的最前面
!   - 一行程序代码的最后如果是符号 & ，代表下一行程序会和这一行连接（必要）。
!     如果一行程序代码的开头是符号 & ，代表它会和上一行程序连接（非必要）
! 自由格式：Free Format
program main
    implicit none
    write(*,*) "Hello" ! 这也是注解
    write(*,*) &
    "Hello"
    wr&
    ! ite(*,*) "Hello"
    ! 14 |     wr&
    !    |     1
    !Error: Unclassifiable statement at (1)
    &ite(*,*) "Hello"
end