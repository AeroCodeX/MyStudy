// 05. Loop
fun main(args:Array<String>)
{
    //! while
    var cnt = 0
    while(cnt < 100) {
        cnt++
    }


    //! for
    for(i in 1..10) { }     // 구간 [1, 10]에 대해 반복, i는 1씩 증가
    for(i in 1 until 100){} // 구간 [1, 10)에 대해 반복, i는 1씩 증가.
    for(i in 2..10 step 2) { }     // 구간 [1, 10]에 대해 반복,  i는 2씩 증가
    for(i in 10 downTo 2) {}       // 10부터 시작해서,  i는 2씩 감소
}