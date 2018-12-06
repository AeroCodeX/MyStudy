import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import java.io.File

fun main(args: Array<String>)
{
    val mapper   = jacksonObjectMapper()
    val articles = ArrayList<Article>()

    // Add elem to collection.
    (1..3).forEach { n ->
        articles.add(
            Article(
                "MyArticle $n",
                System.currentTimeMillis(),
                0,
                "Hello, Jackson! $n"))
    }


    // Convert Collection to JSON.
    mapper
        .writerWithDefaultPrettyPrinter()
        .writeValue(
            File("./my_articles.json"),
            articles
        )
}