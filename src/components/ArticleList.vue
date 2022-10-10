<template>
  <div class="segments posts article">
    <article class="item show article--content" v-for="article in articles" :key="article">
      <div class="info article--info">
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
        </div>
        <h3>
          <RouterLink :to="`article${article.path}`" :title="article.title">
            {{
            article.title
            }}
          </RouterLink>
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
          class="btn article--btn"
        >more...</RouterLink>
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

<style scoped lang='scss'>
.article > .article--content:nth-child(even) .article--btn {
  transform: translate(-1rem, -0.5rem);
}

.article > .article--content:nth-child(odd) .article--btn {
  transform: translate(1rem, -0.5rem);
}
.article > .article--content:nth-child(even) .article--btn::after {
  content: "";
  position: absolute;
  top: -1rem;
  left: 0;
  width: 0;
  height: 0;
  background-color: transparent;
  border-style: solid;
  border-width: 0 0 1rem 1rem;
  border-color: transparent;
  border-bottom-color: var(--color-orange);
  filter: brightness(0.9);
}
.article > .article--content:nth-child(odd) .article--btn::after {
  content: "";
  position: absolute;
  top: -1rem;
  right: 0;
  width: 0;
  height: 0;
  background-color: transparent;
  border-style: solid;
  border-width: 1rem 0 0 1rem;
  border-color: transparent;
  border-left-color: var(--color-orange);
  filter: brightness(0.9);
}
</style>
