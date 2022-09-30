<template>
  <div class="cards">
    <section
      v-for="card in Cards"
      :key="card"
      class="item show"
      :class="mouseOverFlag?'active':''"
      @mouseenter="onMouseOver"
      @mouseleave="onMouseOut"
    >
      <div class="cover" :data-background-image="card.backgroundImage">
        <h2 class="title">{{card.title}}</h2>
        <span>{{card.subTitle}}</span>
      </div>
      <div class="info">
        <div class="ribbon">
          <a :href="card.typePath" :title="card.title">{{card.title}}</a>
        </div>
        <div class="inner">
          <ul class="posts">
            <li v-for="post in card.posts">
              <a :title="post.title" :href="post.postPath">{{post.title}}</a>
            </li>
          </ul>
          <div class="meta footer">
            <span>
              <a :href="card.subTitlePath" :title="card.subTitle">
                <i class="ic i-flag"></i>
                {{card.subTitle}}
              </a>
            </span>
            <span>
              <i class="ic i-file"></i>
              {{card.childrenNum}} 个子项，{{card.articlesNum}} 篇文章
            </span>
          </div>
          <a :href="card.typePath" :title="card.title" class="btn">more...</a>
        </div>
      </div>
    </section>
  </div>
</template>
<script setup>
import { ref } from "@vue/reactivity"

const mouseOverFlag = ref(false)
const onMouseOver = () => {
  mouseOverFlag.value = true
}
const onMouseOut = () => {
  mouseOverFlag.value = false
}
const Cards = [{
  backgroundImage: "//cdn.jsdelivr.net/gh/amehime/shoka@30732f13/computer-science/note/cover.jpg",
  title: "二进制杂谈",
  subTitle: '计算机科学',
  typePath: '/categories/computer-science/note/',
  posts: [
    { title: 'Theme Shoka Documentation', postPath: "/categories/computer-science/note/theme-shoka-doc/" },
    { title: 'V2Yume配置记录', postPath: "/computer-science/note/v2yume-setup-log/" },
  ],
  subTitlePath: '/categories/computer-science/',
  childrenNum: '1',
  articlesNum: '6'
}]
</script>
