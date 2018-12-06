import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import java.io.File

fun main(args: Array<String>)
{
    val mapper  = jacksonObjectMapper()
    val article = Article("MyArticle", System.currentTimeMillis(), 0, "Hello, Jackson!")

    // Object to JSON.
    mapper
        .writerWithDefaultPrettyPrinter()
        .writeValue(
            File("./my_article.json"),
            article
        )
}