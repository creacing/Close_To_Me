<template>
  <div class="posts article">
    <article
      class="item show article--content"
      v-for="article in articles"
      :key="article"
    >
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
          class="btn article--btn"
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

<style scoped lang='scss'>
.article > .article--content + .article--content {
  margin-top: 0.625rem;
}
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

.posts {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}

.posts > .item {
  display: flex;
  border-radius: 0.625rem;
  width: calc(100% - 2rem);
  min-width: calc(100% - 2rem);
  border-radius: 0.5rem;
  box-shadow: 0 0.625rem 1.875rem -0.9375rem var(--box-bg-shadow);
  transition: all 0.2s ease-in-out 0s;
}

@media (max-width: 767px) {
  .posts > .item {
    flex-direction: column;
    height: -webkit-fit-content;
    height: -moz-fit-content;
    height: fit-content;
    max-height: -webkit-fit-content;
    max-height: -moz-fit-content;
    max-height: fit-content;
  }
}

.posts > .item:hover {
  box-shadow: 0 0 2rem var(--box-bg-shadow);
}

.posts .info {
  position: relative;
  /* width: 50%; */
  width: 100%;
  /* padding: 1rem 1.5rem 3rem 0; */
  padding: 1rem 1.5rem 3rem !important;
  perspective: 62.5rem;
}

@media (max-width: 767px) {
  .posts .info {
    width: 100%;
    height: 14rem;
    padding: 0 1rem 3rem;
  }
}

.posts .info .meta {
  display: flex;
  justify-content: flex-end;
  margin: 0;
}

@media (max-width: 767px) {
  .posts .info .meta .item:not(:first-child) {
    display: none;
  }
}

.posts .info h3 {
  text-overflow: ellipsis;
  overflow: hidden;
  white-space: nowrap;
  margin: 0.625rem 0;
  color: var(--primary-color);
}

.posts .info .excerpt {
  overflow: hidden;
  font-size: 0.875em;
  max-height: 5rem;
  display: -webkit-box;
  -webkit-box-orient: vertical;
  -webkit-line-clamp: 3;
  text-overflow: ellipsis;
}

.posts > .item:nth-child(even) {
  flex-direction: row-reverse;
}

@media (max-width: 767px) {
  .posts > .item:nth-child(even) {
    flex-direction: column;
  }
}

.posts > .item:nth-child(even) .cover {
  margin-right: auto;
  margin-left: 1.5rem;
  -webkit-clip-path: polygon(0 0, 100% 0, 100% 100%, 8% 100%);
  clip-path: polygon(0 0, 100% 0, 100% 100%, 8% 100%);
  border-radius: 0 0.625rem 0.625rem 0;
}

@media (max-width: 767px) {
  .posts > .item:nth-child(even) .cover {
    width: 100%;
    margin: auto;
    -webkit-clip-path: polygon(0 0, 100% 0, 100% 100%, 0 92%);
    clip-path: polygon(0 0, 100% 0, 100% 100%, 0 92%);
    border-radius: 0.625rem 0.625rem 0 0;
  }
}

.posts > .item:nth-child(even) .info {
  padding: 1rem 0 3rem 1.5rem;
}

@media (max-width: 767px) {
  .posts > .item:nth-child(even) .info {
    padding: 0 1rem 3rem;
  }
}

.posts > .item:nth-child(even) .info .meta {
  justify-content: flex-start;
}

.posts > .item:nth-child(even) .btn {
  left: 0;
  right: auto;
  /* border-radius: 0 1rem; */
  border-radius: 0 0.25rem;
  background-image: linear-gradient(
    to right,
    var(--color-orange) 0,
    var(--color-pink) 100%
  );
}

.posts > .item:nth-child(even) .meta.footer {
  right: 0.5rem;
  justify-content: flex-start;
}

.posts > .item:nth-child(even):hover .cover img {
  transform: scale(1.05) rotate(-1deg);
}
</style>
