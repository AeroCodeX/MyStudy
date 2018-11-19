// 13. Loop with Label

fun main(args:Array<String>) {
    //! 라벨에 continue 또는 break 명령을 걸면,
    //! 라벨에서 가장 가까운 반복문에 영향을 끼친다.


    outerLoop1@for(i in 1..3)
        for (j in 0..1)
        {
            println("$i $j")
            if (i == 2) break@outerLoop1 // 외부 반복문에 break
        }
    // print "1 0"
    // print "1 1"
    // print "2 0"


    outerLoop2@for(i in 1..3)
        for(j in 0..1)
        {
            println("$i $j")
            if (i == 2) continue@outerLoop2 // 외부 반복문에 continue
        }
    // print "1 0"
    // print "1 1"
    // print "2 0"
    // print "3 0"
    // print "3 1"
}