// 21. Delegation

fun main(args:Array<String>) {
    val human = Human(KoreanName(), Man())

}

interface Name
class KoreanName : Name     //   성 먼저 읽는 스타일의 이름
class AmericanName : Name   // 이름 먼저 읽는 스타일의 이름


interface Gender
class Man : Gender
class Woman : Gender


// Human2 클래스를 축약하면 Human 처럼 된다.
class Human (name:Name, gender:Gender) : Name by name, Gender by gender
class Human2
{
    // 위임(delegation)이란 사용자에게 들키지 않고,
    // 멤버로써 해당 클래스의 기능을 사용하는 것.
    // 위임하지 않고 해당 클래스의 기능을 사용하려면, 상속(inheritance)해야 한다.
    private val name:Name
    private val gender:Gender
    constructor(name: Name, gender: Gender)
    {
        this.name = name
        this.gender = gender
    }
}