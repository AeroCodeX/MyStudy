import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import com.fasterxml.jackson.module.kotlin.readValue
import java.io.File

fun main(args: Array<String>)
{
    val mapper= jacksonObjectMapper()
    val articles = mapper.readValue<ArrayList<Article>>(File("./my_articles.json"))

    println(articles)
}