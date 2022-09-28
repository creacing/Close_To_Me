import {getPosts} from './posts.mjs'
import fs from 'fs'
async function main(){
  const posts = await getPosts()
   
  fs.writeFileSync('data.json',JSON.stringify(posts))
}

main()


