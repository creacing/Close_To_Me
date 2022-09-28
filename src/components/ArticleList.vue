<template>
  <div class="segments posts">
    <article class="item show" v-for="article in articles" :key="article">
      <div class="cover">
        <a :href="article.path" itemprop="url" :title="article.title">
          <img :data-src="article.imgSrc" :src="article.imgSrc" data-loaded="true" class="lozaded" />
        </a>
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
          <a :href="article.path" itemprop="url" :title="article.title">{{ article.title }}</a>
        </h3>
        <div class="excerpt">{{ article.description }}</div>
        <div class="meta footer">
          <span>
            <a :href="article.path" :title="article.title">
              <i class="ic i-flag"></i>
              {{ article.title }}
            </a>
          </span>
        </div>
        <a :href="article.path" itemprop="url" :title="article.title" class="btn">more...</a>
      </div>
    </article>
  </div>
</template>

<script setup>
import { store } from "@/stores/store.js";
import { toRefs } from 'vue'
const state = store();
const { posts } = toRefs(state);
const articles = posts
</script>
