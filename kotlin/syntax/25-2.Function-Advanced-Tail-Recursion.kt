// 25-2. Function-Advanced-Tail-Recursion


fun main(vararg args:String)
{
    println(fibo(4))

    // [Output]
    //      n=4   current=0   next=1
    //      n=3   current=1   next=1
    //      n=2   current=1   next=2
    //      n=1   current=2   next=3
    //      n=0   current=3   next=5
    //      3
}


//  꼬리재귀는 순회와 똑같은 성능을 내도록 도와준다.
//  단, 특별한 조건을 만족해야만 꼬리재귀가 허용된다.
//      * 마지막에 자기 자신이 호출되어야 한다.
tailrec fun fibo(n:Int, current:Int=0, next:Int=1) :Int
{
    // 인덱스는 0 부터 시작한다.
    // 0, 1, 1, 2 ...
    println("n=$n   current=$current   next=$next")
    return if(n==0) current else fibo(n-1, next, current+next)
}