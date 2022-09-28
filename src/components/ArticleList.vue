<template>
  <div class="segments posts">
    <article class="item show" v-for="article in articles" :key="article">
      <div class="cover">
        <RouterLink to="/post" :title="article.title" @click="toArticleDetail(article)">
          <img :data-src="article.imgSrc" :src="article.imgSrc" class="lozaded" />
        </RouterLink>
      </div>
      <div class="info">
        <div class="meta">
          <span class="item" :title="article.date">
            <span class="icon">
              <i class="ic i-calendar"></i>
            </span>
            <time :datetime="article.date">{{ article.date }}</time>
          </span>
          <span class="item" title="本文字数">
            <span class="icon">
              <i class="ic i-pen"></i>
            </span>
            <span>{{ article.fontNums }}</span>
            <span class="text">字</span>
          </span>
          <span class="item" title="阅读时长">
            <span class="icon">
              <i class="ic i-clock"></i>
            </span>
            <span>{{ article.readTime }}</span>
          </span>
        </div>
        <h3>
          <RouterLink
            to="/post"
            :title="article.title"
            @click="toArticleDetail(article)"
          >{{ article.title }}</RouterLink>
        </h3>
        <div class="excerpt">{{ article.description }}</div>
        <div class="meta footer">
          <span>
            <RouterLink to="/post" :title="article.title" @click="toArticleDetail(article)">
              <i class="ic i-flag"></i>
              {{ article.title }}
            </RouterLink>
          </span>
        </div>
        <RouterLink
          to="/post"
          :title="article.title"
          class="btn"
          @click="toArticleDetail(article)"
        >more...</RouterLink>
      </div>
    </article>
  </div>
</template>

<script setup>
import { store } from "@/stores/store.js";
import { toRefs, watch } from 'vue'
import { RouterLink } from "vue-router";

const state = store();
const articles = state.posts

const toArticleDetail = (article) => {
  state.currentArticle = article
}
</script>
