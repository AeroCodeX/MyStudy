// 19. Enum Class

fun main(args:Array<String>) {
    var p = ProcessStatus.Created
    for(i in 0..4)
    {
        println("$p ${p.stat}")
        p = p.next()
    }
    println(ProcessStatus.Created < ProcessStatus.Ready) // true → Ready 가 Created 보다 뒤에 있음


    // print "Created -1"
    // print "Ready 0"
    // print "Running 1"
    // print "Exit 2"
    // print "Ready 0"
    // print "true"
}


enum class ProcessStatus(val stat: Int){
    //! 각각의 상수에 기본 생성자를 정의할 수 있다.
    Created(-1){
        //! 각각의 상수에 익명 클래스를 정의할 수 있다.
        override fun next(): ProcessStatus = ProcessStatus.Ready
    },
    Ready(0){
        override fun next(): ProcessStatus = ProcessStatus.Running
    },
    Running(1){
        override fun next(): ProcessStatus = ProcessStatus.Exit
    },
    Exit(2){
        override fun next(): ProcessStatus = ProcessStatus.Ready
    };

    //! 각각의 상수는 아래의 추상 메소드를 구현해야 한다.
    abstract fun next() :ProcessStatus
}
