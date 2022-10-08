<template>
  <div class="segments posts">
    <article class="item show" v-for="article in articles" :key="article">
      <div class="cover">
        <RouterLink :to="`article${article.path}`" :title="article.title">
          <img
            :data-src="article.imgSrc"
            :src="article.imgSrc"
            class="lozaded"
          />
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
            <span>{{ article.fontNum }}</span>
            <span class="text">字</span>
          </span>
          <!-- <span class="item" title="阅读时长">
            <span class="icon">
              <i class="ic i-clock"></i>
            </span>
            <span>{{ article.readTime }}</span>
          </span>-->
        </div>
        <h3>
          <RouterLink :to="`article${article.path}`" :title="article.title">{{
            article.title
          }}</RouterLink>
        </h3>
        <div class="excerpt">{{ article.description }}</div>
        <div class="meta footer">
          <span>
            <RouterLink :to="`article${article.path}`" :title="article.title">
              <i class="ic i-flag"></i>
              {{ article.title }}
            </RouterLink>
          </span>
        </div>
        <RouterLink
          :to="`article${article.path}`"
          :title="article.title"
          class="btn"
          >more...</RouterLink
        >
      </div>
    </article>
  </div>
</template>

<script setup>
import { defineProps, toRefs } from "vue";
import { RouterLink } from "vue-router";
const props = defineProps({
  articles: {
    type: Array,
    default: () => [],
  },
});

const { articles } = toRefs(props);
</script>
