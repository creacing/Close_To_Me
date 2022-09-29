import { defineStore } from 'pinia'
import * as data from './../../serve/data.json'

const posts = data.default
const postLen = posts.length

function getPostsDic(){
  const postsDic = new Map()
  for(const post of posts){
    postsDic.set(post.path,post)
  }

  return postsDic
}

function getTags(){
  const tags = new Set()
  for(const post of posts){
    tags.add(...post.tags)
  }

  return tags
}

// useStore 可以是 useUser、useCart 之类的任何东西
// 第一个参数是应用程序中 store 的唯一 id
export const store = defineStore('main', {
  state: () => {
    return {
      isSidebar: false,
      postsDic:getPostsDic(),
      tags: getTags(),
      currentArticle: {},
      posts,
      postLen
    }
  },
})