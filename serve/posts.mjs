import { globby } from "globby";
import matter from "gray-matter";
import fs from "fs-extra";
import MarkdownIt from "markdown-it";

const md = new MarkdownIt();


export async function getPosts() {
  let paths = await getPostMDFilePaths();
  let posts = await Promise.all(
    paths.map(async (item) => {
      const MDFileContent = await fs.readFile(item, "utf-8");


      let { data, content } = matter(MDFileContent);
      data.content = md.render(content)
      data.description = content.slice(0, 200)
      data.description = data.description.replace(/[\`+\#+]/g, '')

      data.date = new Date(data.date).toJSON().split('T')[0]
      data.filePath = `/${item.replace(".md", ".html")}`

      data.fontNum = content.length
      data = myFrontMatter(data)
      return data
    })
  );
  posts.sort((a, b) => b.date.split('-').join('') - a.date.split('-').join(''));
  // console.log('posts',posts[0]);
  return posts;
}

async function getPostMDFilePaths() {
  //match global file globaly
  let paths = await globby(["**.md"], {
    ignore: ["node_modules", "README.md"],
  });

  return paths.filter((item) => {
    return item.startsWith("posts")
  });
}

function myFrontMatter(data) {
  return {
    path: data.filePath,
    title: data.title,
    date: data.date,
    fontNum: data.fontNum,
    description: data.description,
    tags: data.tags,
    imgSrc:
      "https://tva1.sinaimg.cn/mw690/6833939bly1gicitzannuj20zk0m8b29.jpg",
    content: data.content
  }
}
